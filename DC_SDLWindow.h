#pragma once
#include "DCWindow.h"

class DC_SDLWindow : public DC_Engine::DCWindow
{
public:
	DC_SDLWindow(size_t width, size_t height, std::string title);

	DC_Engine::ActionResult Init() override;
	DC_Engine::ActionResult Destroy() override;

	void Run() override;

private:
	DC_Engine::ActionResult Create();
	bool ProcessEvents();

private:
	SDL_Window* m_pDCWindow = nullptr;

};

