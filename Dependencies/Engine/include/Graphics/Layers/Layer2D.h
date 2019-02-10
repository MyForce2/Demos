#pragma once

#include "Math/Mat4.h"
#include "Graphics/Shader.h"
#include "Graphics/Rendering/BatchRenderer.h"

namespace Engine {
	namespace Graphics {

		class Layer2D {
		private:
			Math::Mat4 projection;
			Math::Mat4 view;
			BatchRenderer renderer;
			Shader shader;

			// Projection matrix (Orthographic matrix) top value (Bottom = 0.f)
			static const float PROJECTION_TOP;
			// Projection matrix (Orthographic matrix) left value (Right = 0.f)
			static const float PROJECTION_LEFT;
			// The amount of texture units allocated for the shader (Batch renderer units)
			static const int MAX_TEXTURE_UNITS;
			
		public:
			Layer2D(float top, float right, const std::string& vertex, const std::string& fragment);
			Layer2D(const std::string& vertex, const std::string& fragment);
			Layer2D(const Math::Mat4& projection, const std::string& vertex, const std::string& fragment);

			void add(Label& label);
			void add(const Renderable2DTexture& renderable);

			void setProjection(const Math::Mat4& projection);
			void setView(const Math::Mat4& view);

			void startFrame();
			void render();

		private:
			void initShader();
		};
	}
}