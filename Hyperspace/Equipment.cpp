#include "Equipment.h"

Equipment::Equipment()
{
  isEquipped = false;
}

void Equipment::setSlot(int slotVal)
{
  slot = slotVal;
}

void Equipment::toggleEquip()
{
  isEquipped = !isEquipped;
}

bool Equipment::getState()
{
  return isEquipped;
}

int Equipment::getPos()
{
  return slot;
}

void Equipment::empty()
{

}
