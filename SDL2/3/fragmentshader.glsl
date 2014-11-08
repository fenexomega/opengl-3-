#version 150 core 
uniform vec3 triangleColor;
out vec4 outColor;

void main(){
	float gray = (triangleColor.r + triangleColor.g + triangleColor.b)/3.0;
	vec3 grayShade = vec3(gray,gray,gray);	
	outColor = vec4(grayShade, 1.0);
}
