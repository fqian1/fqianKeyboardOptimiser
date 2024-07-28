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
  bool isUsed;

  Finger(int id, std::pair<double, double> home_pos, double dex);

  static inline double distance(const std::pair<double, double>& p1, const std::pair<double, double>& p2);
  double press(const Key& key);
  void returnToHome();
  void moveToKey(const Key& key);
  void moveToPos(const std::pair<double, double> pos);
  double getDistanceTo(const Key& key);
  void print() const;
};
#endif