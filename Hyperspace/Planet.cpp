#include "Planet.h"

Planet::Planet()
{
  pExist = 1;
}

Planet::Planet(int tech ,int threat)
{
  int iD = rand() % 590;
  std::string prefix = "P-";
  std::string suffix = std::to_string(iD);
  nName = prefix + suffix;
  pExist = 1;
  radius = 10000 + rand() % 10000;
  nTechLevel = tech;
  nThreatLevel = threat;
}

std::string Planet::getName() 
{
  return nName;
}

void Planet::setName(std::string newName) 
{
  nName = newName;
}

void Planet::displayStats()
{
  std::cout << "\nRadius: " << radius << "\nTech Level: " << nTechLevel << "\nThreat Level: " << nThreatLevel << "\n\n";
}
