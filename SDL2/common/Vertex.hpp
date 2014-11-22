#ifndef MESH_HPP
#define MESH_HPP

#include <GL/gl.h>
#include <iostream>
#include <glm/glm.hpp>

using namespace std;

class Vertex
{
private:
	glm::vec3 pos;
public:
	Vertex(const glm::vec3& pos)
	{
		this->pos = pos;
	}
};


class Mesh
{
	public:
		Mesh(Vertex* vertices, unsigned int numVertices)
		{
			m_drawCount = numVertices;	
				
			glGenVertexArrays(1,&m_vertexArrayObject);
			glBindVertexArray(m_vertexArrayObject);
			
			glGenBuffers(NUM_BUFFERS,m_vertexArrayBuffers);
			glBindBuffer(GL_ARRAY_BUFFER,m_vertexArrayBuffers[POSITION_VB]);

			glBufferData(GL_ARRAY_BUFFER,
					numVertices * sizeof(vertices[0]),
					vertices,
					GL_STATIC_DRAW);
			
			glEnableVertexAttribArray(0);

			glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,0);

			glBindVertexArray(0);
		}

		~Mesh()
		{
			glDeleteVertexArray(1,&m_vertexArrayObject);	
		}

		void Draw();

private:
		Mesh(const Mesh& other);
		void operator=(const Mesh& other);

		enum
		{
			POSITION_VB,
			NUM_BUFFERS
		};

		GLuint m_vertexArrayObject;
		GLuint m_vertexArrayBuffers[NUM_BUFFERS];
		unsigned int m_drawCount;	
};

#endif //MESH_HPP
