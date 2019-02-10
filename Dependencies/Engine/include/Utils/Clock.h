#pragma once

#include <chrono>

namespace Engine {
	namespace Utils {

		class Clock {
		private:
			std::chrono::time_point<std::chrono::steady_clock> start;

		public:
			Clock();
			~Clock();

			// Sets the start point for the clock
			void reset();
			// Gets the time passed since the start point (in seconds)
			float getTimePassed() const;
		};
	}
}