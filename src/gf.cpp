#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <vector>
#include <GLFW_C/Window.hpp>
#include <GLFW_C/GLFWObject.hpp>
#include <GF_C/GFWindow.hpp>

#include <GF_C/GFScene.hpp>
#include <GF_C/GF2DScene.hpp>

int main()
{
  GLFW_C::InitializeGlfw();
  Window* BasicWin = new GFWindow(800,
                                  800,
                                  "Goblin Factory",
                                  new GFColor(0.2f,0.2f,0.2f,1.0f));

  GFScene* scene = new GF2DScene();
  scene->Build();

  while(!glfwWindowShouldClose(BasicWin->Get()))
    {
      BasicWin->Draw();
      scene->Draw();
      
      glfwSwapBuffers(BasicWin->Get());
      glfwPollEvents(); 
    }

  glfwTerminate();
    
  return 0;
}

