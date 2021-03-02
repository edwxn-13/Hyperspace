#include "NaturalResource.h"
NaturalResource::NaturalResource(float quantity, int id, float scarcity, float regen, float dangerValue,float price) 
{
  nQuanitiy = quantity;
  nID = id;
  nScarcity = scarcity;
  nRegenRate = regen;
  nDangerValue = dangerValue;
  nPrice = price;
}

float NaturalResource::getScarcity() 
{
  return nScarcity;
}

float NaturalResource::getQuantity() 
{
  return nQuanitiy;
}

void NaturalResource::setQuantity(float newVal) 
{
  nQuanitiy = newVal;
}