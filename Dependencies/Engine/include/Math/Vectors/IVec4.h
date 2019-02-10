#pragma once

#include <functional>
#include <boost/functional/hash_fwd.hpp>

namespace Engine {
	namespace Math {

		// Forward declaration

		struct IVec2;
		struct IVec3;
		struct Vec2;
		struct Vec3;
		struct Vec4;

		/*
		A glsl style vector struct used to hold and wrap four integral values
		*/
		struct IVec4 {
			int x, y, z, w;

			// Constructors

			IVec4();
			IVec4(int value);
			IVec4(int x, int y, int z, int w);
			IVec4(const IVec2& vec);
			IVec4(const IVec2& vec, int z, int w);
			IVec4(const IVec3& vec);
			IVec4(const IVec3& vec, int w);
			IVec4(const IVec4& vec);
			IVec4(const Vec2& vec);
			IVec4(const Vec2& vec, int z, int w);
			IVec4(const Vec3& vec);
			IVec4(const Vec3& vec, int w);
			IVec4(const Vec4& vec);
			~IVec4();
		};
	}
}

namespace std {

	/* A hash specialization for the IVec4 class
	Must include the boost hash.hpp header before
	using */
	template<> struct hash<Engine::Math::IVec4> {
		size_t operator()(const Engine::Math::IVec4& vec) const noexcept {
			size_t seed = 0;
			boost::hash_combine(seed, vec.x);
			boost::hash_combine(seed, vec.y);
			boost::hash_combine(seed, vec.z);
			boost::hash_combine(seed, vec.w);
			return seed;
		}
	};
}