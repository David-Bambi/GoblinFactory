#include <GF_C/GF2DTriangle.hpp>

GF2DTriangle::GF2DTriangle()
{
  float verticesTmp [] =
    {
     -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f, 0.5f, 0.0f
    };
  
  for(int i = 0; i < 9; i++)
   this->vertices[i] = verticesTmp[i];
  
  this->usage = GL_STATIC_DRAW;
  
  this->PrepareRendering();
};

GF2DTriangle::GF2DTriangle(float vertices[],
                           unsigned int usage)
{
 for(int i = 0; i < 9; i++)
   this->vertices[i] = vertices[i];

 this->usage = usage;
 
 this->PrepareRendering();
}

void GF2DTriangle::PrepareRendering()
{
  unsigned int VBO, VAO;

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);

  glBindVertexArray(VAO);
  
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(this->vertices),
               this->vertices,
               this->usage);


  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  this->vbo = VBO;
  this->vao = VAO;
}

void GF2DTriangle::Draw()
{
  glBindVertexArray(this->vao);
  glDrawArrays(GL_TRIANGLES, 0, 3);
  glBindVertexArray(0);
}
