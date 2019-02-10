#pragma once


#include "Font.h"

namespace Engine {
	namespace Graphics {

		/*
			A basic font manager for all currently loaded fonts, all fonts should be created through this
			class and used with this class
		*/
		class FontManager {
		private:
			// All the currently loaded fonts
			std::vector<Font*> fonts;
			// The singleton instance
			static FontManager* instance;

			FontManager() {}
			~FontManager();

		public:
			// Returns the font manager instance
			static FontManager* getFontManager();
			// Call only at the end of the program, deletes all of the fonts and this manager
			static void deleteManager();

			// Return if the given font is loaded
			bool hasFont(const std::string& fontName, size_t pointSize) const;
			// Returns the given font or nullptr if it isn't
			Font* get(const std::string& fontName, size_t pointSize) const;
			// Adds the given font if it isn't already loaded
			void add(const std::string& name, size_t pointSize);

		};
	}
}