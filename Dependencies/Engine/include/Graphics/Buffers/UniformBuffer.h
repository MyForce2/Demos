#pragma once

#include "GL\glew.h"

namespace Engine {
	namespace Graphics {

		/*
		A class that represent a Uniform Buffer Object and handles its creation and deletion 
		and manages its data
		*/
		class UniformBuffer {
		private:
			GLuint id;

		public:
			UniformBuffer();
			// size in bytes
			UniformBuffer(GLvoid* data, GLsizeiptr size);
			UniformBuffer(GLvoid* data, GLsizeiptr size, GLenum usage);
			UniformBuffer(const UniformBuffer& ubo);
			UniformBuffer(UniformBuffer&& ubo);
			~UniformBuffer();

			// Binds this buffer
			void bind() const;
			// Unbinds this buffer
			void unBind() const;
			// Maps this buffer
			GLvoid* map(GLenum access) const;
			// Unmaps this buffer
			void unMap() const;
				

			inline GLuint getID() const { return id; }

			void operator=(UniformBuffer&& ubo);
			void operator=(const UniformBuffer& ubo);
		private:
			void copyBuffer(const UniformBuffer& ubo);
			
		};
	}
}
