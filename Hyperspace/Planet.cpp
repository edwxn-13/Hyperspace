#include "Planet.h"

Planet::Planet()
{

}

std::string Planet::getName() 
{
  return nName;
}

void Planet::setName(std::string newName) 
{
  nName = newName;
}
