#pragma once

#include <GL\glew.h>
#include "Buffers/VertexBuffer.h"
#include "VBLayout.h"

namespace Engine {
	namespace Graphics {
		/*
		A class used to represent a vertex array
		*/
		class VertexArray {
		private:
			GLuint id;
			// The amount of enabled attributes
			unsigned int amountOfAttributes;

			static const unsigned int MATRIX_AMOUNT_OF_ATTRIBUTES = 4U;

		public:
			VertexArray();
			~VertexArray();

			void bind() const;
			void unBind() const;

			// Binds the content of the given vbo to this vao according to the vbo layout
			void addBuffer(const VertexBuffer& vbo, const VBLayout& layout);
			// Binds the content vbo to this vao for mat4 attributes (Takes 4 attribute spots)
			// e.g if the attribute location is 0 then location 1, 2, 3 can't be used
			void addMatrixBuffer(const VertexBuffer& vbo);

			// Binds the content of the given vbo to this vao according to the vbo layout
			// Adds the call for glVertexAttribDivisor so the correct data is passed for each instance
			void addInstancedBuffer(const VertexBuffer& vbo, const VBLayout& layout);
			// Binds the content vbo to this vao for mat4 attributes (Takes 4 attribute spots)
			// e.g if the attribute location is 0 then location 1, 2, 3 can't be used
			// Adds the call for glVertexAttribDivisor so the correct data is passed for each instance
			void addInstancedMatrixBuffer(const VertexBuffer& vbo);
		};
	}
}