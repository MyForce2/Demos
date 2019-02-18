#include "pch.h"

using namespace Engine;
using namespace Graphics;
using namespace Math;

std::vector<Vec3> getColors() {
	std::random_device rd;
	std::default_random_engine random(rd());
	std::uniform_real_distribution<float> dis;
	std::vector<Vec3> colors;
	for (int i = 0; i < 36; i++) 
		colors.push_back(Vec3(dis(random), dis(random), dis(random)));
	return colors;
}

int main() {
	Window window("Demo", 720, 1080, GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (glewInit() != GLEW_OK)
		return EXIT_FAILURE;
	auto colors = getColors();
	VertexBuffer vb1(cubeVertices, sizeof(cubeVertices)), vb2(colors.data(), sizeof(Vec3) * colors.size());
	VertexArray vao;
	VBLayout l1, l2;
	l1.addElement(3, GL_FLOAT);
	l1.addElement(3, GL_FLOAT);
	l2.addElement(3, GL_FLOAT);
	vao.addBuffer(vb1, l1);
	vao.addBuffer(vb2, l2);
	Camera c(window, 0.1f, 100.0f);
	c.setPosition(Math::Vec3(0.0f));
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	Utils::Clock timer;
	BasicRenderer r;
	std::string k = "Source//Resources//Shaders//Vertex.shader";
	std::string b = "Source//Resources//Shaders//Fragment.shader";
	Mat4 vp = c.getProjectionMatrix() * c.getViewMatrix();
	Shader shader(k, b);
	shader.bind();
	shader.setUniformMatrix4fv("u_VP", vp);
	while (window.isKeyReleased(GLFW_KEY_ESCAPE) && !window.isClosed()) {
		shader.setUniformMatrix4fv("u_Model", Mat4(1.0f));
		r.renderArrays(vao, shader, 0, 36);
		shader.setUniformMatrix4fv("u_Model", Mat4::translation(Vec3(2.0, 0.0, 2.0)));
		r.renderArrays(vao, shader, 0, 36);
		c.update(window, timer.getTimePassed());
		timer.reset();
		vp = c.getProjectionMatrix() * c.getViewMatrix();
		shader.setUniformMatrix4fv("u_VP", vp);
		window.update();
	}
}