#include <GF_C/GFScene.hpp>

GFScene::GFScene()
{}

void GFScene::Draw()
{
  for (auto i = this->DrawingObjects->begin();
       i != this->DrawingObjects->end(); ++i) 
    (*i)->Draw();
}

void GFScene::Add(GFDraw_I* drawing_object)
{
  this->DrawingObjects->push_back(drawing_object);
}
