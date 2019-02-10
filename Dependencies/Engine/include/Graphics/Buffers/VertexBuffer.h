#pragma once

#include <GL\glew.h>

namespace Engine {
	namespace Graphics {
		 
		/*
		A class that represent a simple VertexBuffer and handles its creation and deletion
		*/
		class VertexBuffer {
		private:
			GLuint id;
			
		public:
			VertexBuffer(GLsizeiptr size);
			VertexBuffer(GLsizeiptr size, GLenum usage);
			VertexBuffer(const VertexBuffer& vbo);
			VertexBuffer(VertexBuffer&& vbo);

			// Size in bytes
			VertexBuffer(const GLvoid* data, GLsizeiptr size);
			VertexBuffer(const GLvoid* data, GLsizeiptr size, GLenum usage);

			

			~VertexBuffer();


			// Binds this buffer
			void bind() const;
			// Unbinds this buffer
			void unBind() const;
			// Maps this buffer
			GLvoid* map(GLenum access) const;
			// Unmaps this buffer
			void unMap() const ;

			inline GLuint getID() const { return id; }
		
			void operator=(VertexBuffer&& vbo);
			void operator=(const VertexBuffer& vbo);

		private:
			void copyBuffer(const VertexBuffer& vbo);
		};
	}
}