#pragma once

#include <functional>
#include <boost/functional/hash_fwd.hpp>

namespace Engine {
	namespace Math {

		// Forward declaration

		struct IVec2;
		struct IVec4;
		struct Vec2;
		struct Vec3;
		struct Vec4;

		/*
		A glsl style vector struct used to hold and wrap three integral values
		*/
		struct IVec3 {
			int x, y, z;

			// Constructors

			IVec3();
			IVec3(int value);
			IVec3(int x, int y, int z);
			IVec3(const IVec2& vec);
			IVec3(const IVec2& vec, int z);
			IVec3(const IVec3& vec);
			IVec3(const IVec4& vec);
			IVec3(const Vec2& vec);
			IVec3(const Vec2& vec, int z);
			IVec3(const Vec3& vec);
			IVec3(const Vec4& vec);
			~IVec3();
		};
		
	}
}

namespace std {

	/* A hash specialization for the IVec3 class
	Must include the boost hash.hpp header before
	using */
	template<> struct hash<Engine::Math::IVec3> {
		size_t operator()(const Engine::Math::IVec3& vec) const noexcept {
			size_t seed = 0;
			boost::hash_combine(seed, vec.x);
			boost::hash_combine(seed, vec.y);
			boost::hash_combine(seed, vec.z);
			return seed;
		}
	};
}