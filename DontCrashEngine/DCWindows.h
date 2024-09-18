#pragma once
#include <string>


namespace DC_Engine
{
	class SDL_Window;

	enum class ActionResault
	{
		kSuccess = 0,
		kFail = 1
	};

	class DCWindows
	{

	public:
		explicit DCWindows(size_t width, size_t height, std::string title) :m_width(width),m_height(height),m_title(title){};
		DCWindows(DCWindows&) = delete;
		DCWindows(DCWindows&&) = default;
		~DCWindows();

		ActionResault Create();
		ActionResault Init();
		ActionResault Run();
		ActionResault Destroy();

	private:
		std::string m_title;
		size_t m_width, m_height;

		SDL_Window* m_pDCWindow;
	};
}