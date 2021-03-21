#include "RandomEncounter.h"
RandomEncounter::RandomEncounter(int threatVal) 
{
  threat = threatVal;
}

GamePackage RandomEncounter::CombatInit(GamePackage gamePackage) 
{
  nEnemyContainer.push_back(Enemy(threat));
  
  while (nEnemyContainer.size() != 0) 
  {
    gamePackage = Combat(gamePackage);
  }

  return gamePackage;
}

GamePackage RandomEncounter::Combat(GamePackage gamePackage)
{
  bool encounterStatus = true;
  Ship eTarget = nEnemyContainer[0].getShip();

  while (encounterStatus) 
  {
    DisplayTargets();
    gamePackage.nUser.displayStats();

    int pWeaponChoice;
    std::cout << "\n<<Select Weapon>>\n";
    std::cin >> pWeaponChoice;

    int pSystemChoice;
    std::cout << "\n<<Select System To Target>>\n";
    std::cin >> pSystemChoice;

    Weapon chosenWeapon = gamePackage.nUser.getInventroy(pWeaponChoice - 1);
    if (pSystemChoice > 3) {eTarget.damageShip(chosenWeapon.useEquipment());}
    else { eTarget.damageSystem(chosenWeapon.useEquipment(), pSystemChoice); }

    nEnemyContainer[0].setShip(eTarget);
    if (eTarget.getArmour() < 1) 
    {
      std::cout << "\n\n<<Enemy " << eTarget.getName() << " has been destroyed>>\n";
      nEnemyContainer[0].~Enemy();
      nEnemyContainer.erase(nEnemyContainer.begin());
      return gamePackage;
    }
    else 
    {
      if (nEnemyContainer[0].retreat())
      {
        nEnemyContainer[0].~Enemy();
        nEnemyContainer.erase(nEnemyContainer.begin());
        return gamePackage;
      }
    }
    gamePackage.nUser = nEnemyContainer[0].attack(gamePackage);
  }

  return gamePackage;

}

void RandomEncounter::DisplayTargets()
{
  for (int i = 0; i < nEnemyContainer.size(); i++) 
  {
    nEnemyContainer[i].displayStats();
  }
}

