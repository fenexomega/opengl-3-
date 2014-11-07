#include <iostream>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


/*
 * Tirado do código parte de minha engine. Ela foi feita pensando em networking,
 * em que os dados chegam em um pacotes,então todos os dados (posção, rotação,
 * etc) são alocados fora da engine. O pepel da engine é ler os dados e mostrar
 * passar pro opengl.
 */

/*
 * Essa classe guarda atributos do modelo, assim como sprites tem pixels,
 * modelos tem vários atributos estáticos. Imagina essa classe como uma
 * abstração para o vetor de dados que sai da função de precache de mídia de um
 * jogo.
 */
class Model
{
private:

	GLfloat*	_vertices;
	GLfloat* 	_colors;
	GLint*		_indices;
	GLint		_numIndices;
	int			_type;


public:

	Model(	GLfloat*	vertices,
			GLfloat*	colors,
			GLint*		indices,
			GLint		numIndices,
			int			type):
		_vertices	(vertices),
		_colors		(colors),
		_indices	(indices),
		_numIndices	(numIndices),
		_type		(type){}
	~Model(){}

	void draw()
	{
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3,GL_FLOAT,0,_vertices);

		glEnableClientState(GL_COLOR_ARRAY);
		glColorPointer(3,GL_FLOAT,0,_colors);

		glDrawElements(_type,_numIndices,GL_UNSIGNED_INT,_indices);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
	}


};

/*
 * Classe com propriedades e métodos para desenhar no cenário, possui um
 * ponteiro para uma classe de modelo. Assim, essa classe pode ficar 'trocando
 * de roupa' quando quiser, só mudar o ponteiro do modelo.
 */
class Object
{
private:

	GLfloat* _pos;
	GLfloat* _rotation;
	GLfloat* _scale;

	Model* _model;


public:


	Model* model(){ return _model; }


	Object(	GLfloat*	defPos,
			GLfloat*	defRotation,
			GLfloat*	defScale,
			Model*		defModel):
		_pos		(defPos),
		_rotation   (defRotation),
		_scale		(defScale),
		_model		(defModel){}
	~Object(){}


	void rotate()
	{
		glRotatef(_rotation[0],1,0,0);
		glRotatef(_rotation[1],0,1,0);
		glRotatef(_rotation[2],0,0,1);
	}
	void translate()
	{
		glTranslatef(	_pos[0],
						_pos[1],
                    	_pos[2]);
	}
	void scale()
	{
		glScalef(	_scale[0],
					_scale[1],
					_scale[2]);
	}
};

/*
 * Uma classe rápida que criei agora pra simplificar uma outra classe que lida
 * com o cenário. Ela é bem imples, mas olha lá no loop infinito, a chamada de
 * rotate & translate está propositalmente com ordem contrária ao do modelo.
 */
class Camera
{

private:

	GLfloat* _pos;
	GLfloat* _rotation;

public:

	Camera(	GLfloat* defPos,
			GLfloat* defRotation):
		_pos		(defPos),
		_rotation	(defRotation){}
	~Camera(){}
	
	void rotate()
	{
		glRotatef(_rotation[0],1,0,0);
		glRotatef(_rotation[1],0,1,0);
		glRotatef(_rotation[2],0,0,1);
	}
	void translate()
	{
		glTranslatef(	-_pos[0],
						-_pos[1],
                        -_pos[2]);
	}

};

int main(int argc,char* argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800,600);

	glutCreateWindow("demo");

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0,0,800,600);
	gluPerspective(80,((800*1.0f)/(600*1.0f)),1.0f,10000.0f);

	glClearColor(0.0,0.0,0.0,0.0);
	glClearDepth(1.0f);

	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);


	GLfloat camPos[] =
	{
		-3.0f,3.0f,3.0f,
	};
	GLfloat camRotation[] =
	{
		30.0f,30.0f,0.0f,
	};
	Camera camera(camPos,camRotation);


	// os pontos do modelo, que vamos traçar as linhas imaginarias que vão
	// compor os triangulos
	GLfloat vertices[] =
	{
			//		front				back
		 	 1.0f, 1.0f, 1.0f,	-1.0f, 1.0f, 1.0f,	
	/* x */  1.0f,-1.0f, 1.0f,	-1.0f,-1.0f, 1.0f,  
		 	 1.0f, 1.0f,-1.0f,	-1.0f, 1.0f,-1.0f,  
		 	 1.0f,-1.0f,-1.0f,	-1.0f,-1.0f,-1.0f,  
		                                        	
		 	 1.0f, 1.0f, 1.0f,	 1.0f, 1.0f,-1.0f,	
	/* y */	-1.0f, 1.0f, 1.0f,	-1.0f, 1.0f,-1.0f,  
		 	 1.0f,-1.0f, 1.0f,	 1.0f,-1.0f,-1.0f,  
			-1.0f,-1.0f, 1.0f,	-1.0f,-1.0f,-1.0f,  
                                                	
		 	 1.0f, 1.0f, 1.0f,	 1.0f,-1.0f, 1.0f,	
	/* z */	 1.0f, 1.0f,-1.0f,	 1.0f,-1.0f,-1.0f,  
			-1.0f, 1.0f, 1.0f,	-1.0f,-1.0f, 1.0f,  
			-1.0f, 1.0f,-1.0f,	-1.0f,-1.0f,-1.0f
	};
	// as cores de cada ponto. Modifique esses valores pra ver os resultados
	GLfloat colors[] =
	{
		1.0f,0.0f,0.0f,
		1.0f,0.0f,0.0f,
		1.0f,0.0f,0.0f,
		1.0f,0.0f,0.0f,
		1.0f,0.0f,0.0f,
		1.0f,0.0f,0.0f,
		1.0f,0.0f,0.0f,
		1.0f,0.0f,0.0f,
		1.0f,0.0f,0.0f,
		1.0f,0.0f,0.0f,
		1.0f,0.0f,0.0f,
		1.0f,0.0f,0.0f,
		1.0f,0.0f,0.0f,
		1.0f,0.0f,0.0f,
		1.0f,0.0f,0.0f,
		1.0f,0.0f,0.0f,
		1.0f,0.0f,0.0f,
		1.0f,0.0f,0.0f,
		1.0f,0.0f,0.0f,
		1.0f,0.0f,0.0f,
		1.0f,0.0f,0.0f,
		1.0f,0.0f,0.0f,
		1.0f,0.0f,0.0f,
		1.0f,0.0f,0.0f,
	};
	// Ordem dos pontos que vamos seguir para desenhar o cubo, cada indice
	// representa um ponto definido lá no vetor de vertices
	GLint indices[] =
	{
		0, 1, 2, 1, 2, 3,
		4, 5, 6, 5, 6, 7,
		8, 9,10, 9,10,11,
		12,13,14,13,14,15,
		16,17,18,17,18,19,
		20,21,22,21,22,23
	};
	GLint numIndices = 36;
	// diz que deve-se interpretar os indices que demos como um desenho de
	// triangulos imagina um desenhista, desce o lapis no ponto 1, arrasta pro
	// ponto 2, pro 3 daí solta. agora desce o lapis no ponto 4 ....
	int type = GL_TRIANGLES;
	Model model(vertices,colors,indices,numIndices,type);


	GLfloat objPos[] =
	{
		0.0f,0.0f,0.0f,
	};
	GLfloat objRotation[] =
	{
		0.0f,0.0f,0.0f,
	};
	GLfloat objScale[] =
	{
		1.0f,1.0f,1.0f
	};
	Object obj(objPos,objRotation,objScale,&model);

	while(true)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glPushMatrix();
			camera.rotate();
			camera.translate();

			glPushMatrix();
				// aqui poderia-se botar um loop para varios objetos em um
				// array, pra desenha-los de um por um
				obj.translate();
				obj.rotate();
				obj.scale();
				obj.model()->draw();
			glPopMatrix();

		glPopMatrix();

		glutSwapBuffers();

		++objRotation[1];
	}


	return 0;
}
