
#include "Navigation.h"
/*
 Contains scripts used for navigating from
 planet to planet and system to system.
 
 Also triggers encounter logic.
 */


void DisplayMap(GamePackage gamePackage)
{

}


Sector sectorSearch(int hash , GamePackage gamePackage)
{
  Sector destination;
  return destination;
}

Sector JumpDrive(GamePackage gamePackage)
{
  std::cout << "<<Select Your Destination >>\n";
  int x,y;
  std::cout << "<<X>> :";
  std::cin >> x;
  std::cout << "<<Y>> :";
  std::cin >> y;
  
  int destHash = x*y;
  Sector destination = sectorSearch(destHash , gamePackage);
  return destination;
}
