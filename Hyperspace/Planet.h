#pragma once
#include <iostream>
#include <string> 

class Planet 
{
public:
  Planet();
  Planet(int);
  Planet(int , int);
  int pExist;
  void setName(std::string);
  void displayStats();
  std::string getName();
private:
  std::string nName;
  std::string nDetails;
  int nTechLevel;
  int nThreatLevel;
  int radius;
  int resourceID;
};

