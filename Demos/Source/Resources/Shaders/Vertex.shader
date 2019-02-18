#version 400 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec4 color;


uniform mat4 u_Model;
uniform mat4 u_VP;

out vec4 v_Color;

void main() {
	mat4 mvp = u_VP * u_Model;
	gl_Position = mvp * position;
	v_Color = color;
}