#include "Planet.h"

Planet::Planet()
{
  pExist = 1;
}

Planet::Planet(int newVal)
{
  pExist = 0; // Provides a dummy planet with no attributes to signify a station is present in the sector
}

Planet::Planet(int tech ,int threat)
{
  int iD = rand() % 590; // Generates random name ID for the planet
  std::string prefix = "P-"; // P suffix signifies it is a planet
  std::string suffix = std::to_string(iD); // Converts ID to string
  nName = prefix + suffix; // Creates full name by connecting prefix and suffix
  pExist = 1;
  radius = 10000 + rand() % 10000; // Generates a radius for the planet
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
/*
 Displays Planet Info
 */
void Planet::displayStats()
{
  std::cout << "\nRadius: " << radius << "\nTech Level: " << nTechLevel << "\nThreat Level: " << nThreatLevel << "\n\n";
}
