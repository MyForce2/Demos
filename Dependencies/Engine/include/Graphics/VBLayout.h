#pragma once

#include <vector>

#include "VBElement.h"

namespace Engine {
	namespace Graphics {

		/*
		A class describing the layout a vertex buffer
		*/
		class VBLayout {
		private:
			// A list of all of the elements 
			std::vector<VBElement> elements;
			// The amount of bytes per generic components in this layout
			GLsizei stride;

		public:
			VBLayout();
			// Creates this layout with the given elements
			VBLayout(size_t amount, GLenum type);
			~VBLayout();

			// Adds an element to this layout
			void addElement(size_t amount, GLenum type);

			inline const std::vector<VBElement>& getElements() const { return elements; };
			inline GLsizei getStride() const { return stride; };

		};


	}
}
