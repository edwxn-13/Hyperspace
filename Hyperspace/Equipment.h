#pragma once
class Equipment 
{
  int damage;
  int cost;
  bool isEquipped;
  int slot;

public:
  Equipment();
  void setSlot(int);
  void toggleEquip();
  bool getState();
  int getPos();
  void empty();
};

