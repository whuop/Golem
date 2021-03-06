#pragma once
#include <bgfx/bgfx.h>

namespace bx
{
	class FileReaderI;
}

namespace Golem::Graphics
{
	class Material
	{
	public:
		Material();
		Material(const char* vertexPath, const char* fragmentPath);
		~Material();

		void Submit();
	private:
		bgfx::ShaderHandle LoadShader(const char* path);

		bgfx::ProgramHandle m_shaderProgram;
	};
}


