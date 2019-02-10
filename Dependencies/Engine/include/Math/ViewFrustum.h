#pragma once
#include "Plane.h"
#include "AABB.h"
#include <vector>

namespace Engine {
	namespace Math {

		enum PLANES {
			TOP = 0, BOTTOM, LEFT,
			RIGHT, NEAR, FAR
		};

		class ViewFrustum {
		private:

			// The frustum's planes
			std::vector<Plane> planes;
			// Data used for calculating the planes
			float nearPlaneWidth, nearPlaneHeight, farPlaneWidth, farPlaneHeight;

		public:
			ViewFrustum();

			void setNearFarData(float fovAngle, float ratio, float nearDistance, float farDistance);
			void generatePlanes(const Vec3& position, const Vec3& x, const Vec3& y, const Vec3& z, float nearDistance, float farDistance);

			inline const std::vector<Plane>& getPlanes() const { return planes; }
			inline const Plane& getPlane(PLANES plane) const { return planes[plane]; }

			bool pointInFrustum(const Vec3& point) const;
			bool boxInFrustum(const AABB& box) const;
			bool boxIntersectsWithFrustum(const AABB& box) const;
		};
	}
}
