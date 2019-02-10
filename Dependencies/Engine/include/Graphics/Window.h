#pragma once

#include <string>
#include <GLFW\glfw3.h>

#include "Math\Vectors\Vec2.h"

namespace Engine {
	namespace Graphics {
		 
		class Window {
		private:
			int height, width;
			std::string title;
			GLFWwindow* windowHandle;
			GLbitfield clearMask;

			static const int NO_MONITOR_OFFSET = 100;
			static const int REFRESH_RATE = 60;

		public:
			Window(const std::string& title, int height, int width, GLbitfield clearMask);
			~Window();

			bool isClosed() const;
			bool isKeyPressed(int key) const;
			bool isKeyReleased(int key) const;

			bool isMouseButtonPressed(int button) const;
			bool isMouseButtonReleased(int button) const;
			bool isCapsLockOn() const;

			void setSize(const Math::Vec2& v);
			void setFullScreen(bool fullScreen);
			

			void update();

			Math::Vec2 getMousePosition() const;
			void setMousePosition(const Math::Vec2& pos) const;
			inline const Math::Vec2 getSize() const { return Math::Vec2(float(width), float(height)); }
			
		};
	}
}