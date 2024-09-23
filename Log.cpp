#include "Log.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <assert.h>

// Constructor creates the folder and file for logs to be saved
DC_Engine::Logger::Logger(const std::string& fileName)
{
	// Create folders for log files
	const std::string& folderPath = "Logs";

	if (std::filesystem::create_directory(folderPath))
	{
		std::cout << "Successfully Created the new folder: " << folderPath << std::endl;
	}
	else if (!std::filesystem::exists(folderPath))
	{
		std::cout << "Failed to Create new folder: " << folderPath << std::endl;
		std::abort();
	}

	
	// Create log file using the path of folder and filename
	filePath = folderPath + '/' + fileName;
	std::fstream outfile;
	outfile.open(filePath, std::ios::app);

	assert(outfile.is_open());
	if(!outfile.is_open())
	{
		std::cout << "It has failed to open up the log file." << std::endl;
	}

	outfile.close();
}

// Print the log message
void DC_Engine::Logger::Log(const std::string& message)
{
	std::cout << message << std::endl;
	
	if (!WriteLog(message))
	{
		std::cout << "It has failed to open up the log file." << std::endl;
	}

}

void DC_Engine::Logger::LogWarning(const std::string& warning, size_t warningCode)
{
	std::cout << "Warnning: " << warning << warningCode << std::endl;

	WriteLog(warning, warningCode);
}

void DC_Engine::Logger::LogError(const std::string& error, size_t errorcode)
{
	std::cout << "Error: " << error << errorcode << std::endl;

	WriteLog(error, errorcode);
}

// Write to log file
bool DC_Engine::Logger::WriteLog(const std::string& message, size_t code)
{
	std::fstream outfile;

	outfile.open(filePath, std::ios::app);

	// fail to open the log file
	assert(outfile.is_open());
	if (!outfile.is_open())
	{
		std::cout << "It has failed to open up the log file." << std::endl;
		return false;
	}
	
	outfile << message;

	if (code != 0)
		outfile << code;

	outfile << std::endl;

	outfile.close();

	return true;
}
