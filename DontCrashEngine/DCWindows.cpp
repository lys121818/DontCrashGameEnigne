#include "DCWindows.h"
#include "SDL.h"


DC_Engine::ActionResault DC_Engine::DCWindows::Create()
{
	// Create windows
	m_pDCWindow = new SDL_Window;

	return ActionResault::kSuccess;
}

DC_Engine::DCWindows::~DCWindows()
{
	Destroy();
}

DC_Engine::ActionResault DC_Engine::DCWindows::Init()
{

	return ActionResault::kSuccess;
}

DC_Engine::ActionResault DC_Engine::DCWindows::Run()
{

	return ActionResault::kSuccess;
}

DC_Engine::ActionResault DC_Engine::DCWindows::Destroy()
{

	return ActionResault::kSuccess;
}
