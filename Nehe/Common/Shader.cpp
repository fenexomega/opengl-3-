#include "Shader.h"

const string Shader::ReadContentFromFile(string filename)
{
	fstream f(filename.c_str());
	string content,aux;

	while(std::getline(f,aux) != NULL)
		content += "\n" + aux;


	return content;
}

Shader::Shader(string _filename,GLenum shaderType) : filename(_filename)
{
	this->shaderID = glCreateShader(shaderType);
	compilationErrors = NULL;
	string shaderSrc = ReadContentFromFile(filename);
	const GLchar * src = shaderSrc.c_str();
	glShaderSource(shaderID,1,&src ,0);
	glCompileShader(shaderID);
	ReadErrors();

}

void Shader::ReadErrors()
{
	GLint result;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);
	if( GL_FALSE == result)
	{
		std::cout << "Shader Compilation Failed!" << std::endl;
		GLint logLength;
		glGetShaderiv(shaderID,GL_INFO_LOG_LENGTH,&logLength);
		if( logLength > 0)
		{
			compilationErrors = new char[logLength];
			glGetShaderInfoLog(shaderID,logLength,NULL,compilationErrors);	
			std::cout << "ERRORS:\n" << compilationErrors << std::endl;
		}
		return;
	}
	std::cout << filename << " compiled!" << std::endl;
}


Shader::~Shader()
{
	glDeleteShader(shaderID);
	if(!compilationErrors)
		delete compilationErrors;
}
