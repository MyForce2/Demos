#pragma once

#include "Texture.h"

#include <array>
#include "Math\Vectors\Vec2.h"

namespace Engine {
	namespace Graphics {

		struct UVCoords {
			Math::Vec2 topRight;
			Math::Vec2 bottomLeft;
		};


		class TextureAtlas {
		private:
			Texture atlas;
			unsigned int atlasSize;
			float textureSize;

		public:
			TextureAtlas(const std::string& path, unsigned int atlasSize, unsigned int textureSize);
			~TextureAtlas();

			inline const Texture& getTexture() const { return atlas; }
			
			UVCoords getUVCoordinates(unsigned int textureOffset) const;
		};
	}
}