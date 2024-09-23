#include "../DontCrashEngine/Log.h"
#include "../DontCrashEngine/DCWindow.h"
#include "../DontCrashEngine/DC_SDLWindow.h"
#include "APIControler.h"

int main(int argc, char* argv[])
{
	APIControler controlDevice;

	controlDevice.Init();
	controlDevice.Run();
	controlDevice.Destory();

	return 0;
}