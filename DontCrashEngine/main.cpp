#include "../DontCrashEngine/Log.h"


int main()
{
	DC_Engine::Logger engineDefaultLogger;

	DC_Engine::Logger engineLogger("Logs.log");

	engineDefaultLogger.Log("Print Text using default logger");
	engineLogger.Log("Print Text using Logs.log file");

	return 0;
}