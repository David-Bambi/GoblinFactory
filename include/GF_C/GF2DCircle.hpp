#ifndef GF2DCIRCLE_HPP
#define GF2DCIRCLE_HPP

#include <vector>
#include <iostream>
#include <cmath>
#include <limits>

#include <glad/glad.h>
#include <GF_C/GFDraw_I.hpp>
#include <GF_C/GFColor.hpp>
#include <GF_C/GFData.hpp>

class GF2DCircle : public GFDraw_I
{
private :
  std::vector<Vec3_f>  vertices;
  std::vector<Vec3_ui> indices;

  unsigned int vao;
  unsigned int vbo;
  unsigned int ebo;
  unsigned int usage;
  GFColor color;
  unsigned int _shaderType;
  void PrepareRendering();

public :
  GF2DCircle(GFColor color = Color::Black,
             float smoothing = 1.0f,
             unsigned int usage = GL_STATIC_DRAW
             );
  virtual void Draw();
  virtual unsigned int ShaderType();
  GFColor Color();
  void Color(GFColor color);
};


#endif 
