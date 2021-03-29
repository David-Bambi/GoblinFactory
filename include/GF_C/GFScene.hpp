#ifndef GFSCENE_HPP
#define GFSCENE_HPP

#include <vector>
#include <map>

// GF library 
#include <GF_C/GFDraw_I.hpp>
#include <GF_C/GFShader.hpp>
#include <GF_C/GFShaderList.hpp>

class GFScene
{
protected :
  std::map<unsigned int, std::vector<GFDraw_I*>> DrawingObjects;
  
public :
  void Draw();
  virtual void Build() = 0;
};


#endif
