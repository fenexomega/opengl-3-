#version 150
in vec3 color;
out vec4 Color;
in vec3 pos;
uniform mat4 model;
uniform mat4 proj;
uniform mat4 view;

void main()
{
	Color = vec4(color,1.0);
	gl_Position = proj * view * model * vec4(pos,1.0);
}
