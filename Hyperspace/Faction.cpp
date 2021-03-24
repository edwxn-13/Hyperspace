#include "Faction.h"
#include <iostream>
#include <math.h>
#include "GameWorld.h"
/*
 *Initialises faction
 */
Faction::Faction()
{
  nStorage.push_back(10000);
  nStorage.push_back(2000);
  nStorage.push_back(100);
  nCriticalValue = 1000;
  nCapital = 100000;
}

Faction::Faction(std::string name , NaturalResource::RContainer rContainer , int type)
{
  srand(time(0));
  nName = name;
  nStorage.push_back(1000 * rand() % 10);
  nStorage.push_back(200 * rand() % 10);
  nStorage.push_back(10 * rand() % 10);
  nCriticalValue = 1000;
  nCapital = 10000 * rand() % 10;
  nType = type;
  nMineRate = 0.025 * rContainer.nResourceList[nType].getScarcity();
  nID = rand() % 20000;
}

float Faction::getCapital() 
{
  return nCapital;
}

void Faction::factionUpdate(FContainer fContainer, NaturalResource::RContainer rContainer)
{
  float supplyVar;

  for (int i = 0; i < nStorage.size(); i++)
  {
    if (i == nType)
    {
      supplyVar = mine(rContainer, i);
    }
  }

  market(fContainer, rContainer, supplyVar);
}

void Faction::dailySpening(NaturalResource::RContainer rContainer)
{
  nCapital = nCapital - pow(nControlledSectors.size(), 2);

  for (int i = 0; i < nStorage.size(); i++)
  {
    nStorage[i] = nStorage[i] - nControlledSectors.size() * rContainer.nResourceList[i].getScarcity() / 1;
    if (nStorage[i] < 0) { nStorage[i] = 0; nControlledSectors[rand() % nControlledSectors.size()].liberate();}

    if (nControlledSectors.size() < 1) {}
    else {}
  }

}

void Faction::market(Faction::FContainer fContainer, NaturalResource::RContainer rContainer, float supplyVal)
{
  for (int i = 0; i < nStorage.size(); i++)
  {
    if (i == nType)
    {
    }
    else
    {
      float buyAmount = nControlledSectors.size() * 0.75;
      float price = 7.816 * exp(0.893 * supplyVal);
      if (nCapital - price > 0)
      {
        nCapital = nCapital - price;
        fContainer.nFactionList[i].nCapital = nCapital + price;
        nStorage[i] = nStorage[i] + buyAmount;
      }
    }
  }

  if (nCapital < 1000)
  {
    nCapital = nCapital + 500;
    for (int i = 0; i < rand()%10; i++)
    {
      nControlledSectors[rand() % nControlledSectors.size()].liberate();
    }
  }
}

float Faction::mine(NaturalResource::RContainer rContainer, int index)
{
  srand(time(0));
  int proportion = rand() % 5;
  nStorage[index] = nStorage[index] + ((nMineRate * rContainer.nResourceList[index].getQuantity()) / 5) * proportion;
  rContainer.nResourceList[index].setQuantity(rContainer.nResourceList[index].getQuantity() - ((rContainer.nResourceList[index].getQuantity() * nMineRate) / 5) * proportion);
  for (int i = 0; i < nStorage.size(); i++) 
  {
    nStorage[i] = nStorage[i] + rand() % 10;
  }

  return nMineRate * rContainer.nResourceList[index].getQuantity() / 100;
}

int Faction::sectorCount(GameWorld world)
{
  int count = 0;
  for(int i = 0; i < world.UniverseList.size(); i++)
  {
    if (world.UniverseList[i].nFactionID == nID) 
    {
      count++;
    }
  }

  return count;
}


