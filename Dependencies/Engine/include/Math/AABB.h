#pragma once
#include "Vectors/Vec3.h"
#include <array>


namespace Engine {
	namespace Math {

		/*
		An Axis Aligned Bounding Box (AABB), used to check if objects are in a certain fov
		*/
		class AABB {
		private:

			static const unsigned int AMOUNT_OF_VERTICES = 8U;
			std::array<Vec3, AMOUNT_OF_VERTICES> vertices;

		public:
			AABB(const std::array<Vec3, AMOUNT_OF_VERTICES>& data);

			inline const std::array<Vec3, AMOUNT_OF_VERTICES>& getVertices() const { return vertices; }
		};

	}
}