#ifndef GF2DRECTANGLE_HPP
#define GF2DRECTANGLE_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <GF_C/GFDraw_I.hpp>
#include <GF_C/GFData.hpp>

class GF2DRectangle : public GFDraw_I
{
private :
  float vertices [12];
  unsigned int indices[6] = {0, 1, 3,   // first triangle
                             0, 3, 2};  // second triangle
    
  unsigned int vao;
  unsigned int vbo;
  unsigned int ebo;
  unsigned int usage;
  void PrepareRendering();

public :
  GF2DRectangle();
  GF2DRectangle(float vertices[],
                unsigned int usage = GL_STATIC_DRAW);
  GF2DRectangle(Point2D pt1,
                Point2D pt2,
                Point2D pt3,
                Point2D pt4,
                unsigned int usage = GL_STATIC_DRAW);

  virtual void Draw();
};


#endif 
