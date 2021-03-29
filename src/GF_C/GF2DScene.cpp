#include <GF_C/GF2DScene.hpp>

GF2DScene::GF2DScene(){};

void GF2DScene::Build()
{
  GFShader shader("shaders/shader2D.vs",
                  "shaders/shader2D.fs");
  
  this->_shaderId = shader.Id();       
  this->DrawingObjects.insert(std::pair<unsigned int,std::vector<GFDraw_I*>>
                              (shader.Id(), std::vector<GFDraw_I*>()));
}
