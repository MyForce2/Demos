#pragma once

#include <string>
#include <vector>
#include "Math\Vectors\Vec2.h"
#include "Math\Vectors\Vec3.h"
#include "Font.h"

namespace Engine {
	namespace Graphics {

		/*
		A class that holds the data for a 2d text label
		*/

		struct LabelVertex {
			Math::Vec2 position;
			Math::Vec2 uv;
			Math::Vec3 color;

			LabelVertex(const Math::Vec2& position, const Math::Vec2& uv, const Math::Vec3& color) :
				position(position), uv(uv), color(color) {

			}
		};

		class Label {
		private:
			std::string text;
			Math::Vec2 startPosition;
			Math::Vec3 labelColor;
			std::vector<LabelVertex> vertices;
			const Font* font;


		public:
			Label(const std::string& text, const Font* font);
			Label(const std::string& text, const Math::Vec2& startPosition, const Font* font);
			Label(const std::string& text, const Math::Vec2& startPosition, const Math::Vec3& labelColor, const Font* font);
			Label();

			~Label();

			inline const std::string& getText() const { return text; }
			inline const Math::Vec2& getStartPosition() const { return startPosition; }
			inline const Math::Vec3& getLabelColor() const { return labelColor; }
			inline const std::vector<LabelVertex>& getData() const { return vertices; }
			inline const Font* getFont() const { return font; }

			void setText(const std::string& text);
			void setStartPosition(const Math::Vec2& startPosition);
			void setLabelColor(const Math::Vec3& labelColor);

			// Generates the actual data for this label (Faster for batch renderer usage)
			void generateVerticesData();
		};
	}
}
