#pragma once

#include <iostream>
#include <vector>
#include "Planet.h"
#include "Encounters.h"

using namespace std;

struct Coords {int x;};
struct Map { vector<Planet> map;};
Map InitGalaxy();
void DisplayMap(Map mapVal);
Coords Navigation();
Planet JumpDrive(Coords val, Map mapVal);


