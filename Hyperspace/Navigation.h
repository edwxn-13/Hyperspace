#pragma once

#include <iostream>
#include <tuple>
#include <fstream>
#include <string>
#include "Planet.h"
#include "GameWorld.h"
#include "GamePackage.h"
#include "RandomEncounter.h"
#include "HQueue.h"
#include "Faction.h"

void DisplayMap(GamePackage gamePackage); //Displays GameWorld class visually
Sector JumpDrive(GamePackage gamePackage);// Transports the player to a new sector
Sector sectorSearch(GamePackage gamePackage);
Player DisplayMenu(GamePackage gamePackage);
HQueue FindRoute(Sector currentNode, Sector destination , HQueue route);
int CalculateDistance(Sector, Sector);
GamePackage InitEncoutner(GamePackage gamePackage);
void ViewPlanet(GamePackage gamePackage);
void ViewInventory(GamePackage gamePacakge);
void ItemSettings(int type , Player user);
void ViewStation(GamePackage gamePackage);


