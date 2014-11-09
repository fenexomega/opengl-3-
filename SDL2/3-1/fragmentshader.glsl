#version 150 core 
uniform vec3 triangleColor;
out vec4 outColor;

void main(){
	vec3 color = vec3(0.0,0.0,1.0);
	outColor = vec4(color, 1.0);
}
