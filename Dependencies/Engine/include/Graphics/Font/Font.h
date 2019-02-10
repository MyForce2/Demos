#pragma once

#include <Typo/Typo.h>
#include "Graphics/Textures/Texture.h"

namespace Engine {
	namespace Graphics {

		/*
			A font class, shouldn't and can't be used without the font manager		
		*/
		class Font {
		private:
			// The font filename
			const std::string fileName;
			// The font size, Point size
			const unsigned int fontSize;
			// An OpenGL texture object containing an image with font symbols
			const Texture* fontAtlas;
			// Tg lib font model for symbol data
			Tg::FontModel font;

			// Ascii value for the start of the glyph set
			static const wchar_t GLYPH_SET_START = wchar_t(31);
			// Ascii value for the end of the glyph set
			static const wchar_t GLYPH_SET_END = wchar_t(126);
			// A pixel border between font symbols, ideal for common font sizes
			// Might not be the most ideal setting for really large fonts / really small font
			static const unsigned int FONT_BORDER = 3U;

			// Private ctor and dtor to prevent creation outside of the FontManager class

			Font(const std::string& fileName, unsigned int fontSize);
			~Font();

			friend class FontManager;

		public:

			inline const std::string& getFileName() const { return fileName; }
			inline const Texture& getFontAtlas() const { return *fontAtlas; }
			inline const Tg::FontModel& getFont() const { return font; }
			inline unsigned int getFontSize() const { return fontSize; }

		private:
			// Inits all of the members and data
			void init();
			// Takes the source font atlas image data (Grayscale), and converts it to a RGBA formatted image
			static void convertToRGBA(const std::vector<unsigned char>& sourceData, std::vector<unsigned char>& outData);
		};
	}
}
