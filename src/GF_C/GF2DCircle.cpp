#include <GF_C/GF2DCircle.hpp>

GF2DCircle::GF2DCircle( GFColor color,
                        float smoothing,
                        unsigned int usage
                        )
{
  this->vertices.push_back(Vec3_f{0.0f, 0.0f, 0.0f}); // Center of the circle
  this->vertices.push_back(Vec3_f{color.Red(), color.Green(), color.Blue()});          // Color

  unsigned int index = 1;
  for(float ange = 0.0f; ange <= 360.0f ; ange+=(1 * smoothing))
    {
      float rad = (ange * M_PI) / 180;
    
      this->vertices.push_back(Vec3_f{sinf(rad), cosf(rad), 0});   // Position
      this->vertices.push_back(Vec3_f{color.Red(), color.Green(), color.Blue()});          // Color

      if(index > 1)
        this->indices.push_back(Vec3_ui{0, index - 1 , index});    // Index

      ++index;
    }
  
  this->color = color;  
  this->usage = GL_STATIC_DRAW;
  this->PrepareRendering();

}

void GF2DCircle::PrepareRendering()
{
  unsigned int VBO, VAO, EBO;

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);

  float vertices_in_array[this->vertices.size()*3];
  unsigned int index_in_array[this->indices.size()*3];

  int j = 0;
  for (int i = 0; i<this->vertices.size(); i++)
    {
      vertices_in_array[j] = this->vertices[i].x;
      //      std::cout << vertices_in_array[j] << " ,";
      j++;
      vertices_in_array[j] = this->vertices[i].y;
      //std::cout << vertices_in_array[j] << " ,";

      j++;
      vertices_in_array[j] = this->vertices[i].z;
      //std::cout << vertices_in_array[j] << std::endl;

      j++;
    }

  j = 0;
  for (int i = 0; i<this->indices.size(); i++)
    {
      index_in_array[j] = this->indices[i].x;
      //std::cout << index_in_array[j] << " ,";
            
      j++;
      index_in_array[j] = this->indices[i].y;
      //    std::cout << index_in_array[j] << " ,";

      j++;
      index_in_array[j] = this->indices[i].z;
      //  std::cout << index_in_array[j] << std::endl;

      j++;
    }
 
  
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(vertices_in_array),
               vertices_in_array,
               GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,
               sizeof(index_in_array),
               index_in_array,
               this->usage); 
  
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
  glEnableVertexAttribArray(1);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  this->vbo = VBO;
  this->vao = VAO;
  this->ebo = EBO;
}

void GF2DCircle::Draw()
{
  glBindVertexArray(this->vao);
  glDrawElements(GL_TRIANGLES, (this->indices.size())*3, GL_UNSIGNED_INT, 0);
  glBindVertexArray(0);
}

GFColor GF2DCircle::Color()
{
  return this->color;
}
void GF2DCircle::Color(GFColor color)
{
  this->color = color;
}

unsigned int  GF2DCircle::ShaderType()
{
  return this->_shaderType;
}
