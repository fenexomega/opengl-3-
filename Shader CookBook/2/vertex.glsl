#version 400 core
uniform mat4 modelview;
uniform mat4 projection;
uniform mat4 normal;

in vec3 pos;
out vec4 vertColor;
in vec3 Color;

void main()
{
	gl_Position = vec4(pos,1.0);
	vertColor = vec4(Color,1.0);
}
