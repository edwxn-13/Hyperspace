#include "Planet.h"

Planet::Planet()
{
  pExist = 1;
}

std::string Planet::getName() 
{
  return nName;
}

void Planet::setName(std::string newName) 
{
  nName = newName;
}
