#include "Planet.h"

Planet::Planet()
{

}

std::string Planet::getName() 
{
  return name;
}

void Planet::setName(std::string newName) 
{
  name = newName;
}
