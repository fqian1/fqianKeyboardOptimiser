#pragma once

class Finger {
public:
  int id;
  double score;
  double dexterity;
  std::pair<int, int> home_position;
  std::pair<int, int> current_position;

  Finger(int id, std::pair<int, int> home_pos, double dex);

  void press(const Key& key);
  void returnToHome();
  void move(const Key& key);
};