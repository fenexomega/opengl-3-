#ifndef PROGRAM_H
#define PROGRAM_H

#include <GL/glew.h>
#include <vector>
#include "Shader.h"

class Program
{
private:
	GLuint programID;
	std::vector<Shader *> shaderList;	
public:
	Program();
	
	void AttachShader(Shader shdr);

	void Use();

	void Link();

	GLint getAttrib(std::string attrib);
	
	GLint EnableAttrib(std::string attrib);

	GLint DisableAttrib(std::string attrib);
	

	void BindFragDataLocation(std::string frag,GLuint colorNumber);

	const GLuint getId()
	{
		return programID; 
	}

	virtual ~Program();


};


#endif
