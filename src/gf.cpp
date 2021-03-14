#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <GLFW_C/Window.hpp>
#include <GLFW_C/GLFWObject.hpp>

#include <GF_C/GFWindow.hpp>
#include <GF_C/GFScene.hpp>
#include <GF_C/GFColor.hpp>
#include <GF_C/GF2DTriangle.hpp>
#include <GF_C/GF2DRectangle.hpp>
#include <GF_C/GFData.hpp>

const char* vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

const char* fragmentShaderSource = "#version 330 core\n"
  "out vec4 FragColor;\n"
  "void main()\n"
  "{\n"
  "FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
  "}\0"; 


int main()
{
  GLFW_C::InitializeGlfw();
  Window* BasicWin = new GFWindow(800,
                                  600,
                                  "Goblin Factory",
                                  new GFColor(0.2f,0.2f,0.2f,1.0f));
  
  // SHADER
  unsigned int vertexShader;
  vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);

  int  success;
  char infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if(!success)
    {
      glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
      std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

  unsigned int fragmentShader;
  fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);

  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if(!success)
    {
      glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
      std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

  // PROGRAM
  unsigned int shaderProgram;
  shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);

  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if(!success)
    {
      glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
      std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

  glUseProgram(shaderProgram);
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);  
  

   GFScene* scene = new GFScene();
   scene->Add(new GF2DRectangle(Point2D{-0.5f, 0.5f},
                                Point2D{0.5f, 0.5f},
                                Point2D{-0.5f, -0.5f},
                                Point2D{0.5f, -0.5f}));
   
  while(!glfwWindowShouldClose(BasicWin->Get()))
     {
       BasicWin->Draw();
       glUseProgram(shaderProgram);

       scene->Draw();
       glfwSwapBuffers(BasicWin->Get());
       glfwPollEvents(); 
     }

  glfwTerminate();
    
  return 0;
}

