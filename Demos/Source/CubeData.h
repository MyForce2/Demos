#pragma once

#include "pch.h"

// Atlas pixel size
static const float PIXEL_SIZE = (1.0f / 256.0f) * 0.5f;
// Atlas unit size
static const float TEXTURE_UNIT_SIZE = 1.0f / (256.0f / 16.0f);


static float cubeVerticesUV[] = {
	// Back face
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, -1.0f, 0.0f + PIXEL_SIZE, 1.0f - TEXTURE_UNIT_SIZE + PIXEL_SIZE, // Bottom-left
	 0.5f,  0.5f, -0.5f,  0.0f, 0.0f, -1.0f, TEXTURE_UNIT_SIZE - PIXEL_SIZE, 1.0f - PIXEL_SIZE, // top-right
	 0.5f, -0.5f, -0.5f,  0.0f, 0.0f, -1.0f, TEXTURE_UNIT_SIZE - PIXEL_SIZE, 1.0f - TEXTURE_UNIT_SIZE + PIXEL_SIZE, // bottom-right         
	 0.5f,  0.5f, -0.5f,  0.0f, 0.0f, -1.0f, TEXTURE_UNIT_SIZE - PIXEL_SIZE, 1.0f - PIXEL_SIZE, // top-right
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, -1.0f, 0.0f + PIXEL_SIZE, 1.0f - TEXTURE_UNIT_SIZE + PIXEL_SIZE, // Bottom-left
	-0.5f,  0.5f, -0.5f,  0.0f, 0.0f, -1.0f, 0.0f + PIXEL_SIZE, 1.0f - PIXEL_SIZE, // top-left
	// Front face
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f, 0.0f + PIXEL_SIZE, 1.0f - TEXTURE_UNIT_SIZE + PIXEL_SIZE, // Bottom-left
	 0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f, TEXTURE_UNIT_SIZE - PIXEL_SIZE, 1.0f - TEXTURE_UNIT_SIZE + PIXEL_SIZE, // bottom-right
	 0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f, TEXTURE_UNIT_SIZE - PIXEL_SIZE, 1.0f - PIXEL_SIZE, // top-right
	 0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f, TEXTURE_UNIT_SIZE - PIXEL_SIZE, 1.0f - PIXEL_SIZE, // top-right
	-0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f, 0.0f + PIXEL_SIZE, 1.0f - PIXEL_SIZE, // top-left
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f, 0.0f + PIXEL_SIZE, 1.0f - TEXTURE_UNIT_SIZE + PIXEL_SIZE, // Bottom-left
	// Left face
	-0.5f,  0.5f,  0.5f, -1.0f, 0.0f, 0.0f, TEXTURE_UNIT_SIZE - PIXEL_SIZE, 1.0f - PIXEL_SIZE, // top-right
	-0.5f,  0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f + PIXEL_SIZE, 1.0f - PIXEL_SIZE, // top-left
	-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f + PIXEL_SIZE, 1.0f - TEXTURE_UNIT_SIZE + PIXEL_SIZE, // Bottom-left
	-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f + PIXEL_SIZE, 1.0f - TEXTURE_UNIT_SIZE + PIXEL_SIZE, // Bottom-left
	-0.5f, -0.5f,  0.5f, -1.0f, 0.0f, 0.0f, TEXTURE_UNIT_SIZE - PIXEL_SIZE, 1.0f - TEXTURE_UNIT_SIZE + PIXEL_SIZE, // bottom-right
	-0.5f,  0.5f,  0.5f, -1.0f, 0.0f, 0.0f, TEXTURE_UNIT_SIZE - PIXEL_SIZE, 1.0f - PIXEL_SIZE, // top-right
	// Right face
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f, 0.0f + PIXEL_SIZE, 1.0f - PIXEL_SIZE, // top-left
	 0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f, TEXTURE_UNIT_SIZE - PIXEL_SIZE, 1.0f - TEXTURE_UNIT_SIZE + PIXEL_SIZE, // bottom-right
	 0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f, TEXTURE_UNIT_SIZE - PIXEL_SIZE, 1.0f - PIXEL_SIZE, // top-right         
	 0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f, TEXTURE_UNIT_SIZE - PIXEL_SIZE, 1.0f - TEXTURE_UNIT_SIZE + PIXEL_SIZE, // bottom-right
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f, 0.0f + PIXEL_SIZE, 1.0f - PIXEL_SIZE, // top-left
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f, 0.0f + PIXEL_SIZE, 1.0f - TEXTURE_UNIT_SIZE + PIXEL_SIZE, // Bottom-left     
	// Bottom face
	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f, 0.0f, TEXTURE_UNIT_SIZE - PIXEL_SIZE, 1.0f - PIXEL_SIZE, // top-right
	 0.5f, -0.5f, -0.5f,  0.0f, -1.0f, 0.0f, 0.0f + PIXEL_SIZE, 1.0f - PIXEL_SIZE, // top-left
	 0.5f, -0.5f,  0.5f,  0.0f, -1.0f, 0.0f, 0.0f + PIXEL_SIZE, 1.0f - TEXTURE_UNIT_SIZE + PIXEL_SIZE, // Bottom-left
	 0.5f, -0.5f,  0.5f,  0.0f, -1.0f, 0.0f, 0.0f + PIXEL_SIZE, 1.0f - TEXTURE_UNIT_SIZE + PIXEL_SIZE, // Bottom-left
	-0.5f, -0.5f,  0.5f,  0.0f, -1.0f, 0.0f, TEXTURE_UNIT_SIZE - PIXEL_SIZE, 1.0f - TEXTURE_UNIT_SIZE + PIXEL_SIZE, // bottom-right
	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f, 0.0f, TEXTURE_UNIT_SIZE - PIXEL_SIZE, 1.0f - PIXEL_SIZE, // top-right
	// Top face
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 0.0f + PIXEL_SIZE, 1.0f - PIXEL_SIZE, // top-left
	 0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f, TEXTURE_UNIT_SIZE - PIXEL_SIZE, 1.0f - TEXTURE_UNIT_SIZE + PIXEL_SIZE, // bottom-right
	 0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f, TEXTURE_UNIT_SIZE - PIXEL_SIZE, 1.0f - PIXEL_SIZE, // top-right     
	 0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f, TEXTURE_UNIT_SIZE - PIXEL_SIZE, 1.0f - TEXTURE_UNIT_SIZE + PIXEL_SIZE, // bottom-right
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 0.0f + PIXEL_SIZE, 1.0f - PIXEL_SIZE, // top-left
	-0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f + PIXEL_SIZE, 1.0f - TEXTURE_UNIT_SIZE + PIXEL_SIZE, // Bottom-left      
};

static float cubeVertices[] = {
	// Back face
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, -1.0f, // Bottom-left
	 0.5f,  0.5f, -0.5f,  0.0f, 0.0f, -1.0f, // top-right
	 0.5f, -0.5f, -0.5f,  0.0f, 0.0f, -1.0f, // bottom-right         
	 0.5f,  0.5f, -0.5f,  0.0f, 0.0f, -1.0f, // top-right
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, -1.0f, // bottom-left
	-0.5f,  0.5f, -0.5f,  0.0f, 0.0f, -1.0f, // top-left
	// Front face
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f, // bottom-left
	 0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f, // bottom-right
	 0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f, // top-right
	 0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f, // top-right
	-0.5f,  0.5f,  0.5f,  0.0f, 0.0f + PIXEL_SIZE, 1.0f - PIXEL_SIZE, // top-left
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f, // bottom-left
	// Left face
	-0.5f,  0.5f,  0.5f,  -1.0f, 0.0f, 0.0f, // top-right
	-0.5f,  0.5f, -0.5f,  -1.0f, 0.0f, 0.0f, // top-left
	-0.5f, -0.5f, -0.5f,  -1.0f, 0.0f, 0.0f, // bottom-left
	-0.5f, -0.5f, -0.5f,  -1.0f, 0.0f, 0.0f, // bottom-left
	-0.5f, -0.5f,  0.5f,  -1.0f, 0.0f, 0.0f, // bottom-right
	-0.5f,  0.5f,  0.5f,  -1.0f, 0.0f, 0.0f, // top-right
	// Right face
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f, // top-left
	 0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f, // bottom-right
	 0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f, // top-right         
	 0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f, // bottom-right
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f, // top-left
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f, // bottom-left     
	// Bottom face
	-0.5f, -0.5f, -0.5f,   0.0f, -1.0f, 0.0f, // top-right
	 0.5f, -0.5f, -0.5f,   0.0f, -1.0f, 0.0f, // top-left
	 0.5f, -0.5f,  0.5f,   0.0f, -1.0f, 0.0f, // bottom-left
	 0.5f, -0.5f,  0.5f,   0.0f, -1.0f, 0.0f, // bottom-left
	-0.5f, -0.5f,  0.5f,   0.0f, -1.0f, 0.0f, // bottom-right
	-0.5f, -0.5f, -0.5f,   0.0f, -1.0f, 0.0f, // top-right
	// Top face
	-0.5f,  0.5f, -0.5f,   0.0f, 1.0f, 0.0f, // top-left
	 0.5f,  0.5f,  0.5f,   0.0f, 1.0f, 0.0f, // bottom-right
	 0.5f,  0.5f, -0.5f,   0.0f, 1.0f, 0.0f, // top-right     
	 0.5f,  0.5f,  0.5f,   0.0f, 1.0f, 0.0f, // bottom-right
	-0.5f,  0.5f, -0.5f,   0.0f, 1.0f, 0.0f, // top-left
	-0.5f,  0.5f,  0.5f,   0.0f, 1.0f, 0.0f // bottom-left        
};
