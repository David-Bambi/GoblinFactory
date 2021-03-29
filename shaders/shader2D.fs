#version 330 core

out vec4 FragColor;

in vec3 vertexcolor;
in vec2 vertexcoord;

uniform sampler2D texture;
uniform int hasTex;

void main()
{
  if(hasTex > 0)
    FragColor = texture(texture, vertexcoord) * vec4(vertexcolor, 1.0);
  else
    FragColor = vec4(vertexcolor, 1.0);
}
