#ifndef GF2DTRIANGLE_HPP
#define GF2DTRIANGLE_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <GF_C/GFDraw_I.hpp>

class GF2DTriangle : public GFDraw_I
{
private :
  float vertices [9];
  unsigned int vao;
  unsigned int vbo;
  unsigned int usage;
  void PrepareRendering();

public :
  GF2DTriangle();
  GF2DTriangle(float vertices[],
               unsigned int usage);

  virtual void Draw();
};


#endif 
