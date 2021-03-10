#include <iostream>
#include "game3d.h"

int main()
{
    /*
     * Part 1 handles all one-dimensional distance calculating functions
     */
    //////////////// Part 1 //////////////////////////
    double p1 = 9.8, p2 = 49;
    std::cout << "********Part 1********" << std:: endl;

    //Begin with simple output and proof of calculation
    game3d::Distance(p1, p2);
    game3d::Distance(p1);

    //Next we accept an array, and tally the distance between each pair of points, followed
    //by a sum-total
    std::cout << "Now calculate for " << game3d::kMaxPoints << " points" << std::endl;
    std::array<double, game3d::kMaxPoints> locations_1d =
            {11, 22, 37, 41, 53,
             66, 79, 80, 95, 101};
    double total_distance = game3d::TotalWalkingDistance(locations_1d);
    std::cout << "Total traveled distance between " << " = " << total_distance << std::endl;

    /*
     * Part two makes sure you stay safe out on the road
     */
    //////////////// Part 2 //////////////////////////
    std::cout << "\n********Part 2********\n";
    // Test if safe to travel between two points
    p1 = 8.5, p2 = 26.9;
    game3d::SafeToTravelMessage(game3d::SafeToTravel(p1, p2));

    p1 = 8.5, p2 = 10.9;
    game3d::SafeToTravelMessage(game3d::SafeToTravel(p1, p2));

    p1 = 10.5;
    game3d::SafeToTravelMessage(game3d::SafeToTravel(p1)); // test vs origin

    //Here we use the same logic as Part one, compounded with the logic used directly above
    //An array of points is assessed, determining which pairs are safe to travel
    //And then a sum-total of "safe travel" distance is returned
    std::cout << "\nCalculating safe traveled distance for " << game3d::kMaxPoints << " points "
              << std::endl;
    total_distance = game3d::TotalSafeWalkingDistance(locations_1d);
    std::cout << "\nTotal safe traveled distance =" << total_distance << std::endl;

    /*
     * Part 3 handles all three-dimensional distance calculating functions
     */
    //////////////// Part 3 //////////////////////////
    std::cout << "\n********Part 3********\n";
    std::array<double, 3> enemy1_location = {2, 6, 1};
    std::array<double, 3> enemy2_location = {3, 4, 0};

    double enemy_distance = game3d::Distance(enemy1_location, enemy2_location);
    std::cout << "Distance between 2 3D points: " << enemy_distance << std::endl;
    enemy_distance = game3d::Distance(enemy1_location);
    std::cout << "Distance between 1 3D point and origin: " << enemy_distance << std::endl;

    std::cout << "\nCalculating 3D distance for " << game3d::kMaxPoints << " 3D points " <<
              std::endl;
    std::array<std::array<double, game3d::kDimensions>, game3d::kMaxPoints>
            locations_3d{
            enemy1_location,   // point 1, index [0]
            {3, 6, 7},         // point 2, index [1]
            {2, 3, 3},         // point 3, index [2]
            {5, 3, 5},         // point 4, index [3]]
            {8, 3, 0},         // point 5, index [4]
            {8, 8, 2},         // point 6, index [5]
            {2, 1, 2},         // point 7, index [6]
            {6, 3, 1},         // point 8, index [7]
            {5, 2, 0},         // point 9, index [8]
            enemy2_location};  // point 10, index [9]

    total_distance = game3d::TotalWalkingDistance(locations_3d);
    std::cout << "Total traveled distance between " << game3d::kMaxPoints << " 3D points "
              << " = " << total_distance << std::endl;

    return 0;
}