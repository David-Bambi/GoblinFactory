#ifndef TTTBOARD_HPP
#define TTTBOARD_HPP

#include <GF_C/GF2DScene.hpp>
#include <GF_C/GF2DRectangle.hpp>
#include <GF_C/GF2DTriangle.hpp>
#include <GF_C/GFTexture.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class TTTBoard : public GF2DScene
{
public :
  void Build();
};

#endif
