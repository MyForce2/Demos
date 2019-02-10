#pragma once

#include <iostream>
#include <functional>
#include <boost/functional/hash_fwd.hpp>


namespace Engine {
	namespace Math {

		struct Vec3;
		struct Vec4;
		struct IVec2;
		struct IVec3;
		struct IVec4;

		/*
		A glsl style vector struct used to hold and wrap two floating point values
		*/
		struct Vec2 {
		public:
			float x, y;

			// Constructors

			Vec2();
			Vec2(float value);
			Vec2(float x, float y);
			Vec2(const Vec3& vec);
			Vec2(const Vec4& vec);
			Vec2(const Vec2& vec);
			Vec2(const IVec2& vec);
			Vec2(const IVec3& vec);
			Vec2(const IVec4& vec);
			~Vec2();

			// Returns the length of this vector
			float length() const;
			// Normalizes this vector
			void normalize();
			// Returns a normalized version of this vector
			Vec2 normalized() const;
			// Returns the dot product of this vector and the given vector
			float dot(const Vec2& vec) const;
			// Returns the distance between this vector and the given vector
			float distance(const Vec2& vec) const;


			// Operators

			Vec2 operator+(float value) const;
			Vec2 operator-(float value) const;
			Vec2 operator*(float value) const;
			Vec2 operator/(float value) const;

			void operator+=(float value);
			void operator-=(float value);
			void operator*=(float value);
			void operator/=(float value);

			Vec2 operator+(const Vec2& vec) const;
			Vec2 operator-(const Vec2& vec) const;
			Vec2 operator*(const Vec2& vec) const;
			Vec2 operator/(const Vec2& vec) const;

			void operator+=(const Vec2& vec);
			void operator-=(const Vec2& vec);
			void operator*=(const Vec2& vec);
			void operator/=(const Vec2& vec);

			bool operator==(const Vec2& vec) const;
			bool operator!=(const Vec2& vec) const;

		private:

			// More operators

			friend Vec2 operator*(float value, const Vec2& vec);
			friend Vec2 operator-(const Vec2& vec);

			friend std::ostream& operator<<(std::ostream& os, const Vec2& vec);
		};
	}
}

namespace std {
	/* A hash specialization for the Vec2 class
	Must include the boost hash.hpp header before
	using */
	template<> struct hash<Engine::Math::Vec2> {
		size_t operator()(const Engine::Math::Vec2& vec) const noexcept {
			size_t seed = 0;
			boost::hash_combine(seed, vec.x);
			boost::hash_combine(seed, vec.y);
			return seed;
		}
	};
}
