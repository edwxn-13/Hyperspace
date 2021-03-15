#pragma once
#include <iostream>

class Planet 
{
private:
  std::string nName;
  std::string nDetails;
  int nTechLevel;
  int nThreatLevel;
public:
  int pExist;
  void setName(std::string);
  std::string getName();
  Planet();
};

