#include "Encounters.h"



Encounter::Encounter()
{

}

Encounter::Encounter(int threat , Player user) 
{
  pThreat = threat;
  srand(time(0));
  pFleetSize = rand() % 4;
  for (int i = 0; i < pFleetSize+1; i++) 
  {
    Fleet.push_back(Enemy(pThreat));
  }
  Combat(user);
}
void Encounter::DisplayTargets() 
{
  std::cout << "< <Target Computer> >";

  for (int i = 0; i < pFleetSize; i++) 
  {
    std::cout << Fleet[i].getShip().mShipName << "\n";
  }
}

void Encounter::DisplayEquipment(Player user) 
{

}

void Encounter::Combat(Player user) 
{

  while (!Fleet.empty())
  {
    //User choses target
    DisplayTargets();
    int enenmyTarget;
    std::cin >> enenmyTarget;

    //User makes attack

    DisplayEquipment(user);
    int equip;
    std::cin >> equip;
    switch (equip) {
      case 0:
        
        break;
        
      default:
        break;
    }

    //Effective>?

    //Enemy's turn
  }
}
