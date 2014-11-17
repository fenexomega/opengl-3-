#ifndef SHADER_HPP
#define SHADER_HPP
#include <iostream>
#include <GL/gl.h>
#include <fstream>
//#include <GL/glew.h>

using namespace std;

class Shader
{
private:
	char * errors;
	GLuint shaderID;
	
	const char*  LoadFileIntoString( string filename)
	{
		ifstream file(filename.c_str(),ios::in);

		if(!file.is_open())
		{
			cerr << "Couldn't open file " << filename << endl;
			exit(EXIT_FAILURE);
		}

		string *text = new string;
		string line;
		do
		{
			getline(file,line);
				*text += line + "\n"; 			
		}while(!file.eof());
		
		file.close();
		return text->c_str();
	}

public:
	Shader(string filename,GLenum shaderType)
	{
		
		shaderID = glCreateShader(shaderType);	
		char const *text = LoadFileIntoString(filename);
		glShaderSource(shaderID,1,&text,NULL);
		glCompileShader(shaderID);
		GetShaderErrors();

	}

	const char * GetShaderErrors()
	{
		errors = NULL;
		GLint isCompiled = 0;
		glGetShaderiv(shaderID, GL_COMPILE_STATUS,&isCompiled);
		if(!isCompiled)
		{
			GLint lenght;
			glGetShaderiv(shaderID,GL_INFO_LOG_LENGTH,&lenght);
			errors = new GLchar[lenght];
			glGetShaderInfoLog(shaderID,lenght,&lenght,errors);
			cerr << "Compile error!:\n" << errors << endl;
		}
		return errors;
	}

	const GLuint getShaderID()
	{
		return shaderID;
	}
};

#endif
