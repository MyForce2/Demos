#pragma once

#include "Renderable2D.h"
#include "Textures/Texture.h"


namespace Engine {
	namespace Graphics {

		class Renderable2DTexture : public Renderable2D {
		private:
			const Texture* texture;

		public:
			Renderable2DTexture(const GLvoid* data, GLsizeiptr size, const std::string& texturePath);
			Renderable2DTexture(const GLvoid* data, GLsizeiptr size, const std::string& texturePath, const Math::Mat4& modelMatrix);
			Renderable2DTexture(const GLvoid* data, GLsizeiptr size, const Texture* texture);
			~Renderable2DTexture();

			inline const Texture& getTexture() const { return *texture; }
		};

	}
}