#version 400 core
in vec3 color;
out vec4 Color;
in vec3 pos;
in vec2 texPos;
out vec2 TexPos;
//uniform mat4 model;
uniform mat4 proj;
uniform mat4 view;

void main()
{
	Color = vec4(color,1.0);
	//Linha para deixar a textura na cor padrão
	Color = vec4(1.0,1.0,1.0,1.0);
	TexPos = texPos;
	gl_Position = proj * view * model * vec4(pos,1.0);
}
