#pragma once
#include <bgfx/bgfx.h>

namespace Golem::Graphics
{
	class Material
	{
	public:
		Material();
		Material(const char* vertexPath, const char* fragmentPath);
		~Material();
	private:
		bgfx::ShaderHandle LoadShader(const char* path);

		bgfx::ProgramHandle m_shaderProgram;
	};
}


