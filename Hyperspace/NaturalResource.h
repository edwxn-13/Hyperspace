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
  float nQuanitiy;
  int nID;
  float nScarcity;
  float nRegenRate;
  float nDangerValue;
  float nPrice;
public:
  NaturalResource(float quantity, int id, float scarcity, float regen, float dangerValue, float price);
  float getScarcity();
  float getQuantity();
  void setQuantity(float newVal);
};

