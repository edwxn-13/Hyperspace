#pragma once
#include <string>
#include <vector>
class NaturalResource
{
public:
  struct RContainer 
  {
    std::vector<NaturalResource> nResourceList;
  };
private:
  std::string name;
  float nQuanitiy; // Total amount of resource in the world
  int nID; // Identification number
  float nScarcity; // How rare it is to find, determines mining success
  float nRegenRate; // How fast the resource regenerates in world
  float nDangerValue; // The amount at which more resource is spawned to avoid negative values
  float nPrice; // base price of resource
public:
  NaturalResource(float quantity, int id, float scarcity, float regen, float dangerValue, float price);
  float getScarcity(); // returns scarcity
  float getQuantity(); // returns quantity
  void setQuantity(float newVal);
};

