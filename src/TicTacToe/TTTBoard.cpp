#include <TicTacToe/TTTBoard.hpp>

void TTTBoard::Build()
{
  GF2DScene::Build();
  
  GFTexture tex = GFTexture("textures/wall.jpg");

  // First row from right to left
  GF2DRectangle* rec1 = new GF2DRectangle(this->_shaderId,
                                          Color::Blue,
                                          tex.Id());

  GF2DRectangle* rec2 = new GF2DRectangle(this->_shaderId,
                                           Color::Blue,
                                           tex.Id());

  GF2DRectangle* rec3 = new GF2DRectangle(this->_shaderId,
                                           Color::Blue,
                                           tex.Id());
  
  rec1->T = glm::translate(rec1->T, glm::vec3(-0.5f, 0.5f, 0.0f));
  rec1->T = glm::scale(rec1->T, glm::vec3(0.2, 0.2, 0.2));

  rec2->T = glm::translate(rec2->T, glm::vec3(0.0f, 0.5f, 0.0f));
  rec2->T = glm::scale(rec2->T, glm::vec3(0.2, 0.2, 0.2));

  rec3->T = glm::translate(rec3->T, glm::vec3(0.5f, 0.5f, 0.0f));
  rec3->T = glm::scale(rec3->T, glm::vec3(0.2, 0.2, 0.2));
  
  // First row from right to left
  GF2DRectangle* rec4 = new GF2DRectangle(this->_shaderId,
                                          Color::Blue,
                                          tex.Id());

  GF2DRectangle* rec5 = new GF2DRectangle(this->_shaderId,
                                          Color::Blue,
                                          tex.Id());

  GF2DRectangle* rec6 = new GF2DRectangle(this->_shaderId,
                                          Color::Blue,
                                          tex.Id());

  rec4->T = glm::translate(rec4->T, glm::vec3(-0.5f, 0.0f, 0.0f));
  rec4->T = glm::scale(rec4->T, glm::vec3(0.2, 0.2, 0.2));

  rec5->T = glm::translate(rec5->T, glm::vec3(0.0f, 0.0f, 0.0f));
  rec5->T = glm::scale(rec5->T, glm::vec3(0.2, 0.2, 0.2));

  rec6->T = glm::translate(rec6->T, glm::vec3(0.5f, 0.0f, 0.0f));
  rec6->T = glm::scale(rec6->T, glm::vec3(0.2, 0.2, 0.2));
  
  // First row from right to left
  GF2DRectangle* rec7 = new GF2DRectangle(this->_shaderId,
                                          Color::Blue,
                                          tex.Id());
  
  GF2DRectangle* rec8 = new GF2DRectangle(this->_shaderId,
                                          Color::Blue,
                                          tex.Id());
  
  GF2DRectangle* rec9 = new GF2DRectangle(this->_shaderId,
                                          Color::Blue,
                                          tex.Id());
  
  rec7->T = glm::translate(rec7->T, glm::vec3(-0.5f, -0.5f, 0.0f));
  rec7->T = glm::scale(rec7->T, glm::vec3(0.2, 0.2, 0.2));

  rec8->T = glm::translate(rec8->T, glm::vec3(0.0f, -0.5f, 0.0f));
  rec8->T = glm::scale(rec8->T, glm::vec3(0.2, 0.2, 0.2));

  rec9->T = glm::translate(rec9->T, glm::vec3(0.5f, -0.5f, 0.0f));
  rec9->T = glm::scale(rec9->T, glm::vec3(0.2, 0.2, 0.2));
  
  this->DrawingObjects[this->_shaderId].push_back(rec1);
  this->DrawingObjects[this->_shaderId].push_back(rec2);
  this->DrawingObjects[this->_shaderId].push_back(rec3);
  this->DrawingObjects[this->_shaderId].push_back(rec4);
  this->DrawingObjects[this->_shaderId].push_back(rec5);
  this->DrawingObjects[this->_shaderId].push_back(rec6);
  this->DrawingObjects[this->_shaderId].push_back(rec7);
  this->DrawingObjects[this->_shaderId].push_back(rec8);
  this->DrawingObjects[this->_shaderId].push_back(rec9);

}
