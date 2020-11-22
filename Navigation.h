#pragma once

#include <iostream>
#include <tuple>
#include <fstream>
#include <string>

#include "Planet.h"
#include "Encounters.h"
#include "GameWorld.h"
#include "GamePackage.h"

void DisplayMap(GamePackage gamePackage); //Displays GameWorld class visually
Sector JumpDrive(GamePackage gamePackage);// Transports the player to a new sector

