#include "Material.h"
#include <fstream>
#include <iostream>

#include <filesystem>

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
	auto fileSize = std::filesystem::file_size(path);
	auto buf = std::make_unique<std::byte[]>(fileSize);
	std::basic_ifstream<std::byte> ifs(path, std::ios::binary);
	ifs.read(buf.get(), fileSize);

	const bgfx::Memory* mem = bgfx::copy(buf.get(), fileSize);

	bgfx::ShaderHandle handle = bgfx::createShader(mem);
	bgfx::setName(handle, path);
	return handle;
}