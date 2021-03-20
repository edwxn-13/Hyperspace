#include "RandomEncounter.h"
RandomEncounter::RandomEncounter(int threatVal) 
{
  threat = threatVal;
}

GamePackage RandomEncounter::CombatInit(GamePackage gamePackage) 
{
  for (int i = 0; i < rand() % 5; i++)
  {
    nEnemyContainer.push_back(Enemy(threat));
  }

  while (nEnemyContainer.size() != 0) 
  {
    gamePackage = Combat(gamePackage);
  }

  return gamePackage;
}

GamePackage RandomEncounter::Combat(GamePackage gamePackage)
{
  bool encounterStatus = true;
  while (encounterStatus) 
  {
    DisplayTargets();
    int pTargetChoice;
    std::cout << "\n<<Select Enemy Target>>\n";
    std::cin >> pTargetChoice;

    Enemy eTarget = nEnemyContainer[pTargetChoice - 1];

    int pWeaponChoice;
    std::cout << "\n<<Select Weapon>>\n";
    std::cin >> pWeaponChoice;

    int pSystemChoice;
    std::cout << "\n<<Select System To Target>>\n";
    std::cin >> pSystemChoice;

    Weapon chosenWeapon = gamePackage.nUser.getInventroy(pWeaponChoice - 1);
    if (!eTarget.getShip().hasShields()) {
      if (pSystemChoice < 5 && pSystemChoice < 0)
      {
        int damage = chosenWeapon.useEquipment();
        eTarget.getShip().nSystems[pSystemChoice - 1].integrity = eTarget.getShip().nSystems[pSystemChoice - 1].integrity - damage;
        std::cout << "\n<<"<< damage <<" Damge Delt To Enemy>>\n";
      }
      else 
      {
        for (int i = 0; i < eTarget.getShip().nSystems.size(); i++) 
        {
          int damage = chosenWeapon.useEquipment();
          eTarget.getShip().nSystems[i].integrity = eTarget.getShip().nSystems[i].integrity - (damage/10);
          std::cout << "\n<<" << damage << " Damge Delt To Enemy>>\n";
        }

        eTarget.getShip().setArmour(chosenWeapon.useEquipment());
      }
    }
    else 
    {
      eTarget.getShip().setShields(chosenWeapon.useEquipment());
    }

    nEnemyContainer[pTargetChoice - 1] = eTarget;

    if (eTarget.getShip().getArmour() < 1) 
    {
      std::cout << "<<Enemy " << eTarget.getShip().getName() << " has been destroyed>>";
      eTarget.~Enemy();
      nEnemyContainer[pTargetChoice - 1].~Enemy();
      nEnemyContainer.erase(nEnemyContainer.begin() + pTargetChoice - 1);
      return gamePackage;
    }
    else 
    {
      if (eTarget.retreat()) 
      {
        return gamePackage;
      }
      eTarget.attack(gamePackage);
    }
    
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

