#version 150
in vec3 color;
out vec4 Color;
in vec2 pos;

void main()
{
	Color = vec4(color,1.0);
	gl_Position = vec4(pos,0,1.0);
}
