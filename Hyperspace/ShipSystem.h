#pragma once
#include <string>
/*
* Defines the Ship Subsystems responible for allowing a part of a ship to function
*/
class ShipSystem 
{
public:
  ShipSystem(std::string);
  std::string nName;
  int integrity;
};

