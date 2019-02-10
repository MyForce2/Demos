#pragma once

#include <GL\glew.h>

namespace Engine {
	namespace Graphics {

		/*
		A class that represent an index buffer
		*/
		class IndexBuffer {
		private:
			GLuint id;
			// The amount of indices
			GLushort count;

		public:
			IndexBuffer();
			IndexBuffer(const GLushort* data, unsigned short size);
			IndexBuffer(const GLushort* data, unsigned short size, GLenum usage);
			IndexBuffer(const IndexBuffer& ibo);
			IndexBuffer(IndexBuffer&& ibo);
			~IndexBuffer();

			// Binds this buffer
			void bind() const;
			// Unbinds this buffer
			void unBind() const;
			// Maps this buffer
			GLvoid* map(GLenum access) const;
			// Unmaps this buffer
			void unMap() const;

			inline GLuint getID() const { return id; };
			inline GLushort getCount() const { return count; };

			void operator=(IndexBuffer&& ibo);
			void operator=(const IndexBuffer& ibo);
		private:
			void copyBuffer(const IndexBuffer& ibo);
		};
	}
}
