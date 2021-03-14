#ifndef GFSCENE_HPP
#define GFSCENE_HPP

#include <vector>

#include <GF_C/GFDraw_I.hpp>

class GFScene : public GFDraw_I
{
private :
  std::vector<GFDraw_I*>* DrawingObjects = new std::vector<GFDraw_I*>();
public :
  GFScene();
  void Add(GFDraw_I* object);
  virtual void Draw();
};


#endif
