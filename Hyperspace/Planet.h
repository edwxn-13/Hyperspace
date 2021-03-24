#pragma once
#include <iostream>
#include <string> 

class Planet 
{
public:
  Planet();
  Planet(int);
  Planet(int , int);
  int pExist; // If the planet exists 
  void setName(std::string);
  void displayStats(); // Displays attributes such as name and planet radius and any other details
  std::string getName();
private:
  std::string nName;
  std::string nDetails;
  int nTechLevel;
  int nThreatLevel;
  int radius;
  int resourceID; // What natural resource the planet contains
};

