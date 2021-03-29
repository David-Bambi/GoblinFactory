#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <GLFW_C/Window.hpp>
#include <GLFW_C/GLFWObject.hpp>
#include <GF_C/GFWindow.hpp>

#include <TicTacToe/TTTBoard.hpp>


int main ()
{
  GLFW_C::InitializeGlfw();
  Window* BasicWin = new GFWindow(800,
                                  800,
                                  "TicTacToe",
                                  new GFColor(0.2f,0.2f,0.2f,1.0f),
                                  true);

  GFScene* board = new TTTBoard();
  board->Build();
  
  while(!glfwWindowShouldClose(BasicWin->Get()))
    {
      BasicWin->Draw();
      
      board->Draw();
      
      glfwSwapBuffers(BasicWin->Get());
      glfwPollEvents(); 
    }

  glfwTerminate();
    
  return 0;
}
