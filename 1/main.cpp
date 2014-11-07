/*	Tutorial do 	
 *	
 *	www.open.gl
 *
 *	Agora utlizando o OpenGL moderno!
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>

#define GLEW_STATIC
#include <GL/glew.h>

GLuint vertexBuffer;
GLuint vertexArrayID;

using namespace std;

float vertices[] = {
	0.0f,0.5f,0.0f,
	0.5f,-0.5f, 0.0f,
	-0.5f,-0.5f, 0.0f
};

void DrawGL()
{
	glClear(GL_COLOR_BUFFER_BIT);

	

	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER,vertexBuffer);

	glVertexAttribPointer(
			0,
			3,
			GL_FLOAT,
			GL_FALSE,
			0,
			0
			);

	glDrawArrays(GL_TRIANGLES,0,3);
	
	glDisableVertexAttribArray(0);

	glutSwapBuffers();
}

void InitGL()
{
	//Chamar antes de criar o contexto para criar
	//usar o novo opengl
	/**     *******           **/
	glewExperimental = GL_TRUE;
	glewInit();

	glGenVertexArrays(1,&vertexArrayID);
	glBindVertexArray(vertexArrayID);


	glGenBuffers(1,&vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER,vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
	cout << vertexBuffer << endl;

}

void ReshapeWindow(int w, int h)
{
	if(h == 0) h = 1 ;
	
	GLfloat ratio = (float) w/h;

	glViewport(0,0,w,h);
/*
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluPerspective(45.0f,ratio,0.1f,100.0f);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

*/
}

int main (int argc, char** argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA );
	glutInitWindowSize(1024,768);
	glutCreateWindow("GLUT com novo OpenGL!");
	InitGL();



	glutDisplayFunc(DrawGL);
	glutIdleFunc(DrawGL);
	glutReshapeFunc(ReshapeWindow);
	glutMainLoop();

	return 0;
}
