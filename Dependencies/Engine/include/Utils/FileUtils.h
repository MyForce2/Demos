#pragma once


#include <string>

namespace Engine {
	namespace Utils {

		// Reads a file and returns the content of it
		std::string readFile(const std::string& path);
		// Reads a file and adds the content to the data string
		void readFile(const std::string& path, std::string& data);

	}
}