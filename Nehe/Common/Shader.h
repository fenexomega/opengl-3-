#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <iostream>
#include <memory>

#include <fstream>


using std::fstream;
using std::string;

class Shader
{
private:
	string filename;
	GLchar * compilationErrors;
	unsigned int shaderID;

	void ReadErrors();
	const string ReadContentFromFile(string filename);
		
public:
	Shader(string filename,GLenum shaderType);
	
	const int getShaderId()
	{
		return shaderID;
	}

	const string getCompilationErrors()
	{
		return compilationErrors;
	}

	~Shader();
};


#endif
