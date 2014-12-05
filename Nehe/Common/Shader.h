#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <iostream>

#include <fstream>


using std::fstream;
using std::string;

class Shader
{
private:
	string filename;
	char * compilationErrors;
	unsigned int shaderID;

	void ReadErrors();
	const string ReadContentFromFile(string filename);
		
public:
	Shader(string filename,GLenum shaderType);
	
	const int getShaderId()
	{
		return shaderID;
	}

	const char * getCompilationErrors()
	{
		return compilationErrors;
	}

	~Shader();
};


#endif
