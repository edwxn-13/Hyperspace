#include "Faction.h"
#include <iostream>
#include <math.h>
#include "GameWorld.h"
/*
 *Initialises faction
 */
Faction::Faction() // Default constructor
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
  nStorage.push_back(1000 * rand() % 10); // Push back random amount of carbon fibre
  nStorage.push_back(200 * rand() % 10); // Push back random amount of water
  nStorage.push_back(10 * rand() % 10); // Push back random amount of xeon
  nCriticalValue = 1000; // Value at which resources are bought to stock up
  nCapital = 10000 * rand() % 10; // Random starting money 
  nType = type;
  nMineRate = 0.025 * rContainer.nResourceList[nType].getScarcity(); // Finds the speed that the faction needs to mine at to ensure they are keeping up with market demand
  nID = rand() % 20000; // Faction identifier
}

float Faction::getCapital() 
{
  return nCapital;
}
/*
* Updates the factions
* Triggers the buying and selling of goods
*/
void Faction::factionUpdate(FContainer fContainer, NaturalResource::RContainer rContainer)
{
  float supplyVar;

  for (int i = 0; i < nStorage.size(); i++)
  {
    if (i == nType)
    {
      supplyVar = mine(rContainer, i); // Sets the supply variable determiens how rare a material is in the world
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
  }

}

void Faction::market(Faction::FContainer fContainer, NaturalResource::RContainer rContainer, float supplyVal)
{
  for (int i = 0; i < nStorage.size(); i++)
  {
    if (i == nType)
    {
      // Skips the factions primary resource as it cannot buy from itself
    }
    else
    {
      float buyAmount = nControlledSectors.size() * 0.75; // factions buy based on how many sectors they posses
      float price = 7.816 * exp(0.893 * supplyVal); // Price of buying is determined by the commodity formula
      if (nCapital - price > 0) // If the faction has enough money they can buy the product with no repercussions
      {
        nCapital = nCapital - price;
        fContainer.nFactionList[i].nCapital = nCapital + price;
        nStorage[i] = nStorage[i] + buyAmount;
      }
    }
  }

  // If the faction cannot afford it they go into debt
  if (nCapital < 1000)
  {
    nCapital = nCapital + 500; // They recieve a loan
    for (int i = 0; i < rand()%10; i++)
    {
      nControlledSectors[rand() % nControlledSectors.size()].liberate(); // They also lose a random one of their controlled sectors
    }
  }
}

/*
* Factions gather natural resources 
*/
float Faction::mine(NaturalResource::RContainer rContainer, int index)
{
  srand(time(0));
  int proportion = rand() % 5; // Adds unpredictability to the world by randomizing the total amount mined
  nStorage[index] = nStorage[index] + ((nMineRate * rContainer.nResourceList[index].getQuantity()) / 5) * proportion; // Adds new resource to the factions stores depending on the mining rate
  rContainer.nResourceList[index].setQuantity(rContainer.nResourceList[index].getQuantity() - ((rContainer.nResourceList[index].getQuantity() * nMineRate) / 5) * proportion); // Total world resources are drained
  for (int i = 0; i < nStorage.size(); i++) 
  {
    // For resources apart for the main resource, minimal amounts are mined every game loop iteration
    nStorage[i] = nStorage[i] + rand() % 10;
  }

  return nMineRate * rContainer.nResourceList[index].getQuantity() / 100;
}

int Faction::sectorCount(GameWorld world) // Returns the amount of sectors belonging to the faction
{
  int count = 0;
  for(int i = 0; i < world.UniverseList.size(); i++)
  {
    if (world.UniverseList[i].nFactionID == nID) 
    {
      nControlledSectors.push_back(world.UniverseList[i]); // Adds controlled sectors to the array
      count++;
    }
  }

  return count;
}


