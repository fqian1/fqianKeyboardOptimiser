#ifndef FINGER_H
#define FINGER_H

#include "key.h"

class Finger {
public:
  int id;
  double score;
  double dexterity;
  std::pair<double, double> home_position;
  std::pair<double, double> current_position;

  Finger(int id, std::pair<double, double> home_pos, double dex);

  void press(const Key& key);
  void returnToHome();
  void move(const Key& key);
  double getDistanceTo(const Key& key);
};
#endif