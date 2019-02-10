#pragma once

#include <GL/glew.h>
#include "Math/Vectors/Vec2.h"

namespace Engine {
	namespace Graphics {

		/*
		A Framebuffer class, can be used to render object offscreen
		*/
		class FrameBuffer {
		private:
			// The Framebuffer itself, openGL id
			GLuint bufferID;
			// The texture used for rendering, openGL id
			GLuint textureID;
			// A Renderbuffer object, openGL id, used to keep the depth and stencil value of each pixel
			GLuint rboID;
			// The window size, used for the texture creation
			Math::Vec2 windowSize;

		public:
			FrameBuffer(float width, float height);
			~FrameBuffer();

			FrameBuffer(const FrameBuffer&) = delete;
			FrameBuffer(FrameBuffer&&) = delete;

			// Binds this frame buffer
			void bind() const;
			// Unbinds this frame buffer
			void unBind() const;
			// Binds the texture
			void bindTexture() const;
			// Unbinds the texture
			void unBindTexture() const;
			// Binds the render buffer
			void bindRenderBuffer() const;
			// Unbinds the render buffer
			void unBindRenderBuffer() const;
			
			// Sets the size of this window, recreates render buffer & texture
			void setSize(const Math::Vec2& size);

			// Clears the content of the currently bound frame buffer, according to the given mask
			static void clearBuffer(GLbitfield mask);
			
		
		private:
			// Handles the creation of the render buffer & texture
			void handleCreation();
		};
	}
}
