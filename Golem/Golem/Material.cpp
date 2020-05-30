#include "Material.h"
#include <fstream>
#include <iostream>

using namespace Golem::Graphics;

Material::Material()
{
}

Material::Material(const char* vertexPath, const char* fragmentPath)
{
	bgfx::ShaderHandle vert = LoadShader(vertexPath);
	bgfx::ShaderHandle frag = LoadShader(fragmentPath);

	m_shaderProgram = bgfx::createProgram(vert, frag, true);
}

Material::~Material()
{
	bgfx::destroy(m_shaderProgram);
}

bgfx::ShaderHandle Golem::Graphics::Material::LoadShader(const char* path)
{
	char* data = new char[2048];
	std::ifstream file;
	size_t fileSize = 0;
	file.open(path);
	if (file.is_open())
	{
		file.seekg(0, std::ios::end);
		fileSize = file.tellg();
		file.seekg(0, std::ios::beg);
		file.read(data, fileSize);
		file.close();
	}
	else
	{
		std::cout << "Could not load shader at path: " << path << std::endl;
	}

	const bgfx::Memory* mem = bgfx::copy(data, fileSize + 1);
	mem->data[mem->size - 1] = '\0';
	bgfx::ShaderHandle handle = bgfx::createShader(mem);
	bgfx::setName(handle, path);
	return handle;
}