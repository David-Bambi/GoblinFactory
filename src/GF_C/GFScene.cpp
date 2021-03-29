#include <GF_C/GFScene.hpp>

void GFScene::Draw()
{

  for (std::map<unsigned int, std::vector<GFDraw_I*>>::iterator it = DrawingObjects.begin();
       it != DrawingObjects.end(); ++it)
    {        
      glUseProgram(it->first);
      std::vector<GFDraw_I*> objToRender = it->second;
      
      for (std::vector<GFDraw_I*>::iterator it = objToRender.begin();
       it != objToRender.end(); ++it)
         {
           (*it)->Draw();
         }
    }
}
