#pragma once
#include "../DontCrashEngine/DCWindow.h"
#include "../DontCrashEngine/Log.h"


class APIControler
{
public:
	enum class API
	{
		SDL = 1,
		OpenGL,
		SFML,
		DirectX
	}m_currentAPI;

public:
	void Init();
	void Run();
	void Destory();

private:

	DC_Engine::DCWindow* m_pWindow;
	DC_Engine::ActionResult m_state;
	DC_Engine::Logger* m_logger;
};

