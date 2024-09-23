#pragma once
#include <string>

struct SDL_Window;

namespace DC_Engine
{

	enum class ActionResult
	{
		kSuccess = 0,
		kWindowInitFail = 1,
		kWindowCreateFail
	};

	struct WindowConfig
	{
		size_t width;
		size_t height;
		std::string title;
	};

	class DCWindow
	{
	protected:
		WindowConfig m_config;

	public:
		virtual ActionResult Init() = 0;

		virtual void Run() = 0;

		virtual ActionResult Destroy() = 0;
		~DCWindow() = default;

	};
}