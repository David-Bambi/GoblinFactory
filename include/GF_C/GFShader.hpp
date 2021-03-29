#ifndef GFSHADER_HPP
#define GFSHADER_HPP

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class GFShader
{
private :
  unsigned int _id;

  std::string ReadShaderCode(const char* filePath);
  unsigned int Compile(std::string shaderCode,
                       unsigned int shaderType);
  
public :
  // Constructor
  GFShader(const char* vertexPath,
           const char* fragmentPath);

  // Getter and Setter
  unsigned int Id();
  void Id(unsigned int id);

  // Activate the shader
  void Use();
  
  // Utility uniform functions
  void SetBool(const std::string &name, bool value) const;  
  void SetInt(const std::string &name, int value) const;   
  void SetFloat(const std::string &name, float value) const;
};

#endif
