#include <iostream>
#include "DC_SDLWindow.h"
#include "SDL.h"

DC_SDLWindow::DC_SDLWindow(size_t width, size_t height, std::string title)
{
	m_config.title = title;
	m_config.height = height;
	m_config.width = width;
}

DC_Engine::ActionResult DC_SDLWindow::Init()
{
	DC_Engine::ActionResult result = DC_Engine::ActionResult::kSuccess;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		//std::cout << "failed to initialize SDL. Error: " << SDL_GetError() << std::endl;
		return DC_Engine::ActionResult::kWindowInitFail;
	}

	// Create windows
	result = Create();

	return result;
}

DC_Engine::ActionResult DC_SDLWindow::Destroy()
{
	SDL_DestroyWindow(m_pDCWindow);
	SDL_Quit();
	return DC_Engine::ActionResult::kSuccess;
}

void DC_SDLWindow::Run()
{
	bool quit = false;


	while (!quit)
	{
		quit = ProcessEvents();
	}
}

DC_Engine::ActionResult DC_SDLWindow::Create()
{
	m_pDCWindow = SDL_CreateWindow(m_config.title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (int)m_config.width, (int)m_config.height, 0);

	if (m_pDCWindow == nullptr)
	{
		std::cout << "failed to Create Window. Erorr: " << SDL_GetError() << std::endl;
		return DC_Engine::ActionResult::kWindowCreateFail;
	}

	return DC_Engine::ActionResult::kSuccess;
}

bool DC_SDLWindow::ProcessEvents()
{
	bool quit = false;

	SDL_Event evt;
	while (SDL_PollEvent(&evt) != 0)
	{
		switch (evt.type)
		{
			// Windows event cases
		case SDL_WINDOWEVENT:
		{
			switch (evt.window.event)
			{
			case SDL_WINDOWEVENT_CLOSE:
			{
				quit = true;

				break; // SDL_WINDOWEVENT_CLOSE
			}


			default:
				break; // switch(evt.window.event)
			}


			break; // SDL_WINDOWEVENT
		}


		default:
			break; // switch (evt.type)
		}
	}

	return quit;
}
