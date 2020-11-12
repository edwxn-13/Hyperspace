#pragma once

#include <iostream>
#include <vector>
#include "Planet.h"
#include "Encounters.h"
#include "GameWorld.h"
using namespace std;

struct Coords {int x, y;};
struct Map { vector<Planet> map;};
Map InitGalaxy();
void DisplayMap(std::vector< std::vector<Sector>> mapVal);
Coords Navigation();
Sector JumpDrive(Coords val, std::vector< std::vector<Sector>> mapVal);


