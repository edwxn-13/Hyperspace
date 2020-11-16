#pragma once
#include <iostream>

class Planet 
{
private:
  std::string name;
  std::string details;
  int techLevel;
  int threatLevel;
public:
  void setName(std::string);
  std::string getName();
  Planet();
};

