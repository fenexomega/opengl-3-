#include "Program.h"

Program::Program()
{
	this->programID = glCreateProgram();
}

void Program::AttachShader(Shader shdr)
{
	shaderList.push_back(&shdr);
	glAttachShader(programID,shdr.getShaderId());

}

void Program::Use()
{
	glUseProgram(programID);
}

void Program::Link()
{
	glLinkProgram(programID);
}

GLuint Program::getAttrib(std::string attrib)
{
	// Não esquecer de habilitar os attribs com
	// glEnableVertexAttribArray(attrib)
	return glGetAttribLocation(programID,attrib.c_str());
}

void Program::BindFragDataLocation(std::string frag,GLuint colorNumber)
{
	glBindFragDataLocation(programID,colorNumber,frag.c_str());
}

Program::~Program()
{
	for(auto i : shaderList)
		glDetachShader(programID,i->getShaderId());
	glDeleteProgram(programID);
}
