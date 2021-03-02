#pragma once

#include <iostream>
#include <tuple>
#include <fstream>
#include <string>
#include "Planet.h"
#include "GameWorld.h"
#include "GamePackage.h"
#include "Faction.h"

void DisplayMap(GamePackage gamePackage); //Displays GameWorld class visually
Sector JumpDrive(GamePackage gamePackage);// Transports the player to a new sector
Sector sectorSearch(int hash, GamePackage gamePackage);
std::vector<Sector> FindRoute(Sector,std::vector<Sector>);
int CalculateDistance(Sector,Sector);

