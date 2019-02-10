#pragma once

#include "Math\Mat4.h"
#include "Math\Vectors\Vec3.h"
#include "Graphics/Window.h"
#include "Math/ViewFrustum.h"


namespace Engine {
	namespace Graphics {

		/*
		A class that used to simulate a FPS 3D camera
		*/
		class Camera {
		private:
			// The camera's position in space (Player position)
			Math::Vec3 position;
			// The direction the camera is looking at
			Math::Vec3 viewingDirection;
			// The up direction in world space (Default is (0, 1, 0))
			Math::Vec3 upDirection;
			// The view matrix
			Math::Mat4 view;
			// The projection matrix
			Math::Mat4 projection;
			// Euler angle, depicts how much the camera is looking up or down
			float pitch;
			// Euler angle, depicte how much the camera is looking right or left 
			float yaw;
			// Window size
			Math::Vec2 windowSize;
			// Projection matrix data
			float near, far;
			// A cap for the pitch value
			static const float MAX_PITCH_ANGLE;
			// The mouse sensitivity (How much does the camera move for a certain mouse movement)
			static const float SENSITIVITY;
			// The fov (Field of view) angle for the perspective matrix
			static const float FIELD_OF_VIEW;
			// Movement speed for WASD movement
			static const float MOVEMENT_SPEED;
			// Speed boost for movement 
			static const float SPEED_BOOST;

		public:
			Camera(const Window& window, float near, float far);
			~Camera();

			// Sets the camera position in world space
			void setPosition(const Math::Vec3& position);
			// Sets the viewing direction in world space
			void setViewingDirection(const Math::Vec3& direction);

			inline const Math::Vec3& getPosition() const { return position; }
			inline const Math::Vec3& getViewingDirection() const { return viewingDirection; }
			inline const Math::Mat4& getViewMatrix() const { return view; }
			inline const Math::Mat4& getProjectionMatrix() const { return projection; }

			// Updates the view matrix, the view direction, and the camera position according to input
			void update(const Window& window, float time);

		private:
			// Generates the view matrix, according to the position and viewDirection
			Math::Mat4 generateViewMatrix();
			// Generates the viewing direction vector, (recalculates it according to mouse movement)
			Math::Vec3 generateViewDirection(const Window& window);
		};
	}
}
