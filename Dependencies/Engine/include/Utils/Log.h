#pragma once

#include <string>
#include <fstream>

#include "Utils\LinkedList.h"

namespace Engine {
	namespace Utils {

		/*
		A logging class, outputs all messages to a log file
		*/
		class Log {
		private:

			// The buffer size
			static const size_t BUFFER_SIZE = 30;
			// The file path for the log file
			static const char* LOG_PATH;
			// The log instance
			static Log* log;

			// Handles all interactions with the log file
			std::ofstream fileHandle;
			// A buffer to get the date and time
			char buffer[BUFFER_SIZE];

			Log();
			~Log();

		public:
			// Returns the log instance
			static Log* getLog();
			// Deletes the log instance
			static void closeLog();

			// Logs an error to the log file
			void logError(const std::string& message);
			// Logs a warning to the log file
			void logWarning(const std::string& message);
			// Logs a regular message to the log file
			void logInfo(const std::string& message);

		};

	}
}
