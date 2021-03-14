#include <GF_C/GF2DRectangle.hpp>

GF2DRectangle::GF2DRectangle()
{
  float verticesTmp [] =
    {
     0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left 
    };

  for(int i = 0; i < 12; i++)
   this->vertices[i] = verticesTmp[i];

  this->usage = GL_STATIC_DRAW;
  
  this->PrepareRendering();
};

GF2DRectangle::GF2DRectangle(float vertices[],
                             unsigned int usage)
{
 for(int i = 0; i < 12; i++)
   this->vertices[i] = vertices[i];

 this->usage = usage;
 
 this->PrepareRendering();
}

GF2DRectangle::GF2DRectangle(Point2D pt1, // top left
                             Point2D pt2, // top right
                             Point2D pt3, // bottom left
                             Point2D pt4, // bottom right
                             unsigned int usage)
{
  // Point 1 
  this->vertices[0] = pt1.x;
  this->vertices[1] = pt1.y;
  this->vertices[2] = 0.0f;

  // Point 2
  this->vertices[3] = pt2.x;
  this->vertices[4] = pt2.y;
  this->vertices[5] = 0.0f;

  // Point 3
  this->vertices[6] = pt3.x;
  this->vertices[7] = pt3.y;
  this->vertices[8] = 0.0f;

  // Point 4
  this->vertices[9] = pt4.x;
  this->vertices[10] = pt4.y;
  this->vertices[11] = 0.0f;

 for(int i = 0; i < 12; i++)
   this->vertices[i] = vertices[i];

 this->usage = usage;
 
 this->PrepareRendering();
}

void GF2DRectangle::PrepareRendering()
{
  unsigned int VBO, VAO, EBO;

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);
  
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(this->vertices),
               this->vertices,
               GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,
               sizeof(this->indices),
               this->indices,
               this->usage); 
  
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  this->vbo = VBO;
  this->vao = VAO;
  this->ebo = EBO;
}

void GF2DRectangle::Draw()
{
  glBindVertexArray(this->vao);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  glBindVertexArray(0);
}
