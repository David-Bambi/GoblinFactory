#ifndef GFCOLOR_HPP
#define GFCOLOR_HPP

class GFColor
{
private:
  float _red = 0;
  float _green = 0;
  float _blue = 0;
  float _opacity = 1;
public:
  GFColor();
  GFColor(float red, float green, float blue, float opacity);
  float Red();
  float Green();
  float Blue();
  float Opacity();
};

#endif
