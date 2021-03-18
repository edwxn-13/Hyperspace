#pragma once

#include <iostream>
#include <tuple>
#include <fstream>
#include <string>
#include "Planet.h"
#include "GameWorld.h"
#include "GamePackage.h"
#include "RandomEncounter.h"

#include "Faction.h"

void DisplayMap(GamePackage gamePackage); //Displays GameWorld class visually
Sector JumpDrive(GamePackage gamePackage);// Transports the player to a new sector
Sector sectorSearch(int hash, GamePackage gamePackage);
void DisplayMenu(GamePackage gamePackage);
std::vector<Sector> FindRoute(Sector currentNode, std::vector<Sector> route);
int CalculateDistance(Sector, Sector);
GamePackage InitEncoutner(GamePackage gamePackage);


