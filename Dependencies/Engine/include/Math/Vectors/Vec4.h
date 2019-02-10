#pragma once

#include <iostream>
#include <functional>
#include <boost/functional/hash_fwd.hpp>


namespace Engine {
	namespace Math {

		struct Vec2;
		struct Vec3;
		struct IVec2;
		struct IVec3;
		struct IVec4;


		/*
		A glsl style vector struct used to hold and wrap four floating point values
		*/
		struct Vec4 {
			float x, y, z, w;

			// Constructors

			Vec4();
			Vec4(float value);
			Vec4(float x, float y, float z, float w);
			Vec4(const Vec2& vec);
			Vec4(const Vec3& vec);
			Vec4(const Vec4& vec);
			Vec4(const Vec2& vec, float z, float w);
			Vec4(const Vec3& vec, float w);
			Vec4(const IVec2& vec);
			Vec4(const IVec2& vec, float z, float w);
			Vec4(const IVec3& vec);
			Vec4(const IVec3& vec, float w);
			Vec4(const IVec4& vec);
			~Vec4();

			// Functions

			// Returns the length of this vector
			float length() const;
			// Normalizes this vector
			void normalize();
			// Returns a normalized version of this vector
			Vec4 normalized() const;

			// Operators

			Vec4 operator+(float value) const;
			Vec4 operator-(float value) const;
			Vec4 operator*(float value) const;
			Vec4 operator/(float value) const;

			void operator+=(float value);
			void operator-=(float value);
			void operator*=(float value);
			void operator/=(float value);

			Vec4 operator+(const Vec4& vec) const;
			Vec4 operator-(const Vec4& vec) const;
			Vec4 operator*(const Vec4& vec) const;
			Vec4 operator/(const Vec4& vec) const;

			void operator+=(const Vec4& vec);
			void operator-=(const Vec4& vec);
			void operator*=(const Vec4& vec);
			void operator/=(const Vec4& vec);

			bool operator==(const Vec4& vec) const;
			bool operator!=(const Vec4& vec) const;

		private:

			// More operators

			friend Vec4 operator*(float value, const Vec4& vec);
			friend Vec4 operator-(const Vec4& vec);

			friend std::ostream& operator<<(std::ostream& os, const Vec4& vec);
		};
	}
}

namespace std {
	/* A hash specialization for the Vec4 class
	Must include the boost hash.hpp header before
	using */
	template<> struct hash<Engine::Math::Vec4> {
		size_t operator()(const Engine::Math::Vec4& vec) const noexcept {
			size_t seed = 0;
			boost::hash_combine(seed, vec.x);
			boost::hash_combine(seed, vec.y);
			boost::hash_combine(seed, vec.z);
			boost::hash_combine(seed, vec.w);
			return seed;
		}
	};
}