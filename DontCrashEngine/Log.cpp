#include "Log.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include "SDL2/include/SDL.h"
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
	m_filePath = folderPath + '/' + fileName;
	std::fstream outfile;
	outfile.open(m_filePath, std::ios::app);

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

// Write to log file
bool DC_Engine::Logger::WriteLog(const std::string& message)
{
	std::fstream outfile;

	outfile.open(m_filePath, std::ios::app);

	// fail to open the log file
	assert(outfile.is_open());
	if (!outfile.is_open())
		return false;
	
	outfile << message << std::endl;
	outfile.close();

	return true;
}
