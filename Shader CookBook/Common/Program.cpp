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

GLint Program::getAttrib(std::string attrib)
{
	// Não esquecer de habilitar os attribs com
	// glEnableVertexAttribArray(attrib)
	return glGetAttribLocation(programID,attrib.c_str());
}

GLint Program::EnableAttrib(std::string attrib)
{
	GLint num = getAttrib(attrib);	
	if(num == -1)
	{
		std::cerr << "Couldn't get " << attrib << " attrib" << std::endl;
		return num;
	}
	glEnableVertexAttribArray(num);
	return num;

}

GLint Program::DisableAttrib(std::string attrib)
{
	GLint num = getAttrib(attrib);	
	if(num == -1)
	{
		std::cerr << "Couldn't open " << attrib << " attrib" << std::endl;
		return num;
	}
	std::cout << attrib << " = " << num << std::endl;
	glDisableVertexAttribArray(num);
	return num;

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
