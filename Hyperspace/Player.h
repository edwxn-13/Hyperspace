#pragma once

#include <iostream>
#include "Ship.h"
#include "Planet.h"
#include "GameWorld.h"
#include "Equipment.h"
#include "Weapon.h"
/*
 Defines Player, the users controlled entity
 */
class Player
{
public:
  bool alive; // Is the player alive?
  Sector CurrentSector; // Players current location
private:
  std::string mName; // The name the user wishes to be identified as
  int nBankAccount; // Players Credit Balance.
  int nPlayerLevel, XP;
  Ship nPlayerShip; // The player's ship
  std::vector<Weapon> nInventory; // Contains all of the users equipment.
public:
  Player(); // Default player constructor, sets initial values.
  std::string getName(); // Returns players name.
  void setName(std::string); // Sets a new name for the player.
  Weapon getInventroy(int);
  std::vector<Weapon> getInventroy();
  Weapon getCargo(int index);
  int getBalance(); // Returns the players credit balance
  void setBalance(int); // Sets new balance.
  void setSector(Sector);
  void displayStats();
  void displayStats(int);
  void purchase(Ship);
  void sell(int);
  void toggleEquip(int);
  void discard(int);
  void purchase(Weapon);

  Ship getShip();
  void setShip(Ship);
  void Equip(int); // Equips a new item from the inventory.
  void LevelUp(); // Increases players level.
  void XPCheck(); // Checks if player can increace in level.
  void useEquipment(int); // Uses currently equipped equipment.

};

