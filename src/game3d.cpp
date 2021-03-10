#include "game3d.h"  // my game library
#include <array>     // for array container
#include <cmath>     // for pow(), sqrt() function
#include <iomanip>   // for formatted output
#include <iostream>

/*
 * Calculates distance between two points, or the difference between two numbers in absolute value
 *
 * @param pointA: first point
 * @param pointB: second point
 *
 * @return absolute value of difference between two ints
 */
double game3d::Distance(double pointA, double pointB)
{
    double distance;

    distance = pointA - pointB;

    std::cout << "Distance between " << pointA << " and " << pointB << " = " <<
    fabs(distance) << std::endl;

    return fabs(distance);
}

/*Calculates a total walking distance between ten points
 *
 * @param &locations: reference to an array of ten integers
 */
double game3d::TotalWalkingDistance(const std::array<double, game3d::kMaxPoints> &locations)
{
    double total = 0;

    for(int i = 0; i < kMaxPoints - 1; ++i)
    {
        total = total + game3d::Distance(locations[i], locations[i + 1]);
    }

    return total;
}

/*
 * Determines whether the next point in the array is at a safe distance
 *
 * @param point1: point currently "standing" at
 * @param point2: point prospectively traveling to
 *
 * @return boolean telling whether travel is safe
 */
bool game3d::SafeToTravel(double point1, double point2)
{
    bool safe = true;

    if(game3d::Distance(point1, point2) < game3d::kSafeRadius)
    {
        safe = false;
    }

    return safe;
}

/**
 * @brief Print message if it is safe to move to another point
 *
 * @param status: true or false
 */
void game3d::SafeToTravelMessage(bool status)
{
    std::cout << "Should I move? " << std::endl;
    if (status)
    {
        std::cout << "\tYes, you are in the safe zone" << std::endl;
    }
    else
    {
        std::cout << "\tNo, stay put. You are in the danger zone" << std::endl;
    }
}

/*
 * Calculates total distance walked in safe travel, ignores unsafe travel
 *
 * @param locations: reference of an array of integers
 */
double game3d::TotalSafeWalkingDistance(const std::array<double, kMaxPoints> &locations)
{
    double total = 0;
    bool safe;

    for(int i = 0; i < kMaxPoints - 1; ++i)
    {
        if(game3d::SafeToTravel(locations[i], locations[i +1]))
        {
            total = total + locations[i +1] - locations[i];
            safe = true;
            SafeToTravelMessage(safe);
        }
        else
        {
            safe = false;
            SafeToTravelMessage(safe);
        }
    }

    return total;
}

/*
 * Calculates the distance between two points on a 3D plane
 *
 * @param: a: first point, an array of three coordinates (X, Y, Z)
 * @param: b: second point, an array of three coordinates (X, Y, Z)
 */
double game3d::Distance(std::array<double, game3d::kDimensions> a,
                        std::array<double, game3d::kDimensions> b)
{
    double distance;

    distance = sqrt(pow((b[0] - a[0]), 2) + pow((b[1] - a[1]), 2) + pow((b[2] - a[2]), 2));

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\tDistance between (" << a[0] << "," << a[1] << "," << a[2] << ") and (" << b[0]
              << "," << b[1] << "," << b[2] << ") = " << distance << std::endl;

    return distance;
}

/*
 * Calculates the total distance between an array of 3D points
 *
 * @param: locations: an array of ten arrays containing X, Y, Z coordinates of as many points
 */
double game3d::TotalWalkingDistance(
        const std::array<std::array<double, game3d::kDimensions>, game3d::kMaxPoints> &locations)
{
    float total = 0;

    for(int i = 0; i < kMaxPoints - 1; ++i)
    {
        total = total + Distance(locations[i], locations[i + 1]);
    }

    return total;
}