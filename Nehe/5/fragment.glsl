#version 400 core
in vec4 Color;
out vec4 outColor;
in vec2 TexPos;
uniform sampler2D tex;
void main()
{
	outColor = texture(tex,TexPos) * Color;
	
}
