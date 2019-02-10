#pragma once

#include <GL\glew.h>

namespace Engine {
	namespace Graphics {

		struct VBElement {
			// The amount of components of this element
			size_t amount;
			// The OpenGL type of this element
			GLenum type;

			// Gets the size (in bytes) of an OpenGL type
			inline static constexpr GLuint getSizeOfElement(GLenum type) {
				switch (type) {
				case GL_FLOAT:
					return 4;
				case GL_DOUBLE:
					return 8;
				case GL_UNSIGNED_BYTE:
					return 1;
				case GL_BYTE:
					return 1;
				case GL_SHORT:
					return 2;
				case GL_UNSIGNED_SHORT:
					return 2;
				case GL_UNSIGNED_INT:
					return 4;
				case GL_INT:
					return 4;
				default:
					return 0;
				}
			}

			inline static constexpr bool isInteger(GLenum type) {
				switch (type) {
				case GL_BYTE:
					return true;
				case GL_UNSIGNED_BYTE:
					return true;
				case GL_SHORT:
					return true;
				case GL_UNSIGNED_SHORT:
					return true;
				case GL_INT:
					return true;
				case GL_UNSIGNED_INT:
					return true;
				default:
					return false;
				}
			}

			inline static constexpr bool isDouble(GLenum type) {
				return type == GL_DOUBLE;
			}
		};
	}
}
