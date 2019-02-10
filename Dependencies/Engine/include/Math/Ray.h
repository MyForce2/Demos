#pragma once

#include "Vectors/Vec3.h"
#include "Plane.h"

namespace Engine {
	namespace Math {

		/*
		A class that represents a ray (A line)
		*/
		class Ray {
		private:
			// The starting position
			Vec3 start;
			// The end position
			Vec3 end;

		public:
			Ray(const Vec3& start, const Vec3& end);
			~Ray();

			float rayLength() const;
			bool intersectsWith(const Plane& plane) const;
			bool intersectsWith(const Plane& plane, float maxDistance) const;

		};
	}
}