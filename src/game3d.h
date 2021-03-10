#ifndef GAME_3D_H
#define GAME_3D_H

#include <array>

namespace game3d {
// namespace constants
const int kMaxPoints = 10;
const int kDimensions = 3;
const double kSafeRadius = 12.0;

// Task 1
double Distance(double point_a, double point_b = 0);
double TotalWalkingDistance(const std::array<double, kMaxPoints> &locations);

// Task 2:
void SafeToTravelMessage(bool status);
bool SafeToTravel(double point1, double point2 = 0);
double TotalSafeWalkingDistance(const std::array<double, kMaxPoints> &locations);


// Task 3: Overload functions
double Distance(std::array<double, kDimensions> a, std::array<double, kDimensions> b = {0, 0, 0});
double TotalWalkingDistance(const std::array<std::array<double, kDimensions>, kMaxPoints> &locations);

}  // namespace game3d
#endif
