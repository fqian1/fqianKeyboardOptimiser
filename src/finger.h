#pragma once

#include <cmath>

class Finger {
public:
  int id;
  bool hand;
  double distanceTravelled;
  bool isPressed;
  double dexterity;
  double currentX, currentY;
  double homeX, homeY;

  Finger(int id, bool hand, double homeX, double homeY, double dexterity);

  void press(const Key& key, bool prevHand);
  void release();
};