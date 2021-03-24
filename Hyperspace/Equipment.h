#pragma once
class Equipment 
{
  int damage;
  int cost;
  bool isEquipped;
  int slot;

public:
  Equipment();
  void setSlot(int); // Stores index of equipment item
  void toggleEquip(); // Equips and unequips item from hard point 
  bool getState(); // Returns if the equipment is equipped or not
  int getPos(); // Returns stored index
  void empty(); // Emptys the equipment slot
};

