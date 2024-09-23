#include "APIControler.h"
#include "../DontCrashEngine/DC_SDLWindow.h"
#include "../DontCrashEngine/Log.h"

void APIControler::Init()
{
	m_logger = new DC_Engine::Logger("Logs.log");

	// User Choice
	m_pWindow = new DC_SDLWindow(1024, 768, "DontCrash");

	m_state = m_pWindow->Init();
}

void APIControler::Run()
{
	if (m_state == DC_Engine::ActionResult::kSuccess)
		m_pWindow->Run();
	else
		m_logger->LogError("It has file to create windows ErrorCode: ", (size_t)m_state);


}

void APIControler::Destory()
{
	m_pWindow->Destroy();

	delete m_logger;
}
