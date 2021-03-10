# CHALLENGE: 3D GAME LIBRARY


## Purpose

The purpose of this assignment is to help you practice and implement the use of `functions` and `namespaces` in `C++`.  

## Skills and Knowledge

This activity will help you practice the following skills that essential to know for basic programming in `C++`:

- Define libraries
- Call functions with return values
- Define namespaces
- Use of C++ array collections
- Use of function overload

This lab will also help you to become familiar with the following important content knowledge in CS:

- Working in your development environment.
- Review basic programming concepts.
- Use basic unit testing to validate your code: `catch2`.

### Files to work on

You will be working the following files:

- All the functions you write, will be part of the library `game3d`. The library consist of these two files:
  - `src/game3d.cpp`
  - `src/game3d.h`.
- Our "driver" will be `src/main.cpp`.

Please **DO NOT MODIFY** any other files. Modifying other files may result 
in the unit tests not passing.

---

## Part 1: Game Distance in 1D

In this task you are commissioned to create a game library to calculate the distance between points. First, you are going to define a set of function to work on a `1D` world, then we will modify the functions to work in a `3D` world.

### Part 1.1: 1D Distance Function

As a good C++ practice, we will define our function libraries inside a new `namespace` called `game3d`. Your first function should be one to calculate the distance between two 1D points. Your function should take either one or two input parameters. Your first parameter is required while your second parameter is optional. The function should return the absolute value of the distance between the two points.

```cpp
// game3d.h

namespace game3d
{
// namespace constants

// Part 1
// Default input parameters are only defined in the header file.
double Distance(double point_a, double point_b = 0);
}
```

As you can see from the function signature, required parameters are listed first, in this case `point_a` while the optional parameters are listed at the end, `point_b`.
Optional parameters require a `default value`, in this case we will use `0` as a representation of the origin. Also, required parameters are set ONLY in the header file.

Your implementation function should calculate the absolute value between point b and point a, then display a formatted message with the information. The required format for your floating point numbers should be `fixed` 2 decimal `precision`.

Hint: Use fabs() function to calculate the absolute value of float points

```cpp
// game3d.cpp
#include <iostream>
#include <cmath>     // for fabs(), pow() function
#include <iomanip>   // for formatted output
#include "game3d.h"  // my game library

double game3d::Distance(double point_a, double point_b)
{
    double distance = 0;

    // Calculate difference and save it in the distance variable

    // Set fixed precision of 2 decimal places

    // Output message
    std::cout << "Distance between " << point_a << " and " << point_b << " = " << distance << std::endl;

    return distance;
}
```

You could test your code in `main()` with something similar to this:

```cpp
    //////////////// Part 1 //////////////////////////
    double p1 = 5.9, p2 = 4.5;
    std::cout << "\n********Part 1********"<< std::endl;
    game3d::Distance(p1, p2); // compare two points
    game3d::Distance(p1);  // compare vs origin
```

Once again, we will NOT use the `namespace std` in this file.

#### Compile Part 1.1

[How to compile and run the code with cmake.](../faqs.md#how-to-compile-and-run-the-code-with-cmake)

#### Sample Output Part 1.1

```bash
********Part 1********
Distance between 5.90 and 4.50 = 1.40
Distance between 5.90 and 0.00 = 5.90
```

### Part 1.2: Total Walking Distance Function for 1D points

Next, create a function to calculate the total walking distance for a collection of points. The collection of points comes in the form of a C++ array.  To control the size of the array, define a `constant variable` inside the `game3d` namespace called `kMaxPoints` and set it to the integer `10`.
Your function should take a `constant reference` to an `array` as input parameter. Remember that constant references prevents you from modifying the values the reference points to by accident. In other words, it is a read only parameter.
Then, your function should iterate over all the elements of the array and calculate the distance between each point.
For example, if your array has values `3, 7, 2, 9, 4, etc`, you calculate the distance between `3 and 7`, then between `7 and 2`, and so on using your `Distance()` function from [Part 1.1](#task-12-total-walking-distance-function-for-1d-points).

```cpp
//game3d.h
namespace game3d
{
// namespace constants
const int kMaxPoints = 10;

// Part 1
double Distance(double a, double b = 0);
double TotalWalkingDistance(const std::array<double, kMaxPoints> &locations);
```

Now define our function in your implementation file

```cpp
double game3d::TotalWalkingDistance(const std::array<double, kMaxPoints> &locations)
{
    double total = 0;
    // loop over all elements
        // call Distance function and save it in total variable

    return total;
}
```

Test your code in `main()`

```cpp
    // Array of 1D points
    std::cout << "Now calculate for " << game3d::kMaxPoints << " points" << std::endl;
    std::array<double, game3d::kMaxPoints> locations_1d = {11, 22, 37, 41, 53, 66, 79, 80, 95, 101};
    double total_distance = game3d::TotalWalkingDistance(locations_1d);
    std::cout << "Total traveled distance between " << " = " << total_distance << std::endl;
```

#### Compile Part 1.2

[How to compile and run the code with cmake.](../faqs.md#how-to-compile-and-run-the-code-with-cmake)

#### Sample Output Part 1.2

```bash
# ...  output from Part1.1
Now calculate for 10 points
Distance between 11.00 and 22.00 = 11.00
Distance between 22.00 and 37.00 = 15.00
Distance between 37.00 and 41.00 = 4.00
Distance between 41.00 and 53.00 = 12.00
Distance between 53.00 and 66.00 = 13.00
Distance between 66.00 and 79.00 = 13.00
Distance between 79.00 and 80.00 = 1.00
Distance between 80.00 and 95.00 = 15.00
Distance between 95.00 and 101.00 = 6.00
Total traveled distance between  = 90.00
```

## Part 2: Help Functions for Game Distance in 1D

Your next task consist on creating a set of functions to help your distance game.

### Part 2.1: 1D Safe to Move Function

The first function you need to write checks if you are within a safe distance to move from one point to another. Once again, to avoid the use of `magic numbers` you need to define the safe distance variable (`kSafeRadius = 12.0`) using a constant inside your namespace.

Your function should take one `require` parameter and one `optional` with a default value of `0` and the function should return a `boolean` value.
To determine this, calculate the distance between the two input points using your `Distance()` function and compare the result to the `kSafeRadius` variable.
If the distance is `greater or equal` to the `kSafeRadius` value, then return `true`, otherwise return `false`.

```cpp
// game3d.h
namespace game3d
{
// namespace constants
const int kMaxPoints = 10;
const double kSafeRadius = 12.0;

// Part 1
// ...

// Part 2:
// Default input parameters are only defined in the header file.
bool SafeToTravel(double point1, double point2 = 0);
void SafeToTravelMessage(bool status);
```

To help you better document if the result from your `SafeToTravel()` function, I provided a `SafeToTravelMessage()` function. This second function takes a boolean value and it prints the informational message.

```cpp
// game3d.cpp
bool game3d::SafeToTravel(double point1, double point2)
{
   bool safe = true;
    // Calculate Distance

    // Determine if it is safe to travel

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
```

Test your code in `main()`

```cpp
    // Part 1 testing code

    //////////////// Part 2 //////////////////////////
    std::cout << "\n********Part 2********\n";
    // Test if safe to travel between two points
    p1 = 8.5, p2 = 26.9;
    game3d::SafeToTravelMessage(game3d::SafeToTravel(p1, p2));

    p1 = 8.5, p2 = 10.9;
    game3d::SafeToTravelMessage(game3d::SafeToTravel(p1, p2));

    p1 = 10.5;
    game3d::SafeToTravelMessage(game3d::SafeToTravel(p1)); // test vs origin
```

#### Compile Part 2.1

[How to compile and run the code with cmake.](../faqs.md#how-to-compile-and-run-the-code-with-cmake)

#### Sample Output Part 2.1

```bash
# ... Part 2 output
********Part 2********
Distance between 8.50 and 26.90 = 18.40
Should I move?
        Yes, you are in the safe zone
Distance between 8.50 and 10.90 = 2.40
Should I move?
        No, stay put. You are in the danger zone
Distance between 10.50 and 0.00 = 10.50
Should I move?
        No, stay put. You are in the danger zone
```

### Part 2.2: Total Safe Walking Distance Function for 1D points

Your next function should calculate the total walking distance, but only if it is safe. In other words, you need to create a function that follws the rules from [Part 1.2](#task-12-total-walking-distance-function-for-1d-points) and [Part 2-1](#task-21-1d-safe-to-move-function).

```cpp
// game3d.h
// ...
double TotalSafeWalkingDistance(const std::array<double, kMaxPoints> &locations);
```

```cpp
// game3d.cpp
double game3d::TotalSafeWalkingDistance(const std::array<double, kMaxPoints> &locations)
{
    double total = 0;
    // loop over all elements
    //for loop
    //{
        // Check if it safe to travel

        // If it is safe, calculate the distance and add it to total variable

    // }

    return total;
}
```

Test your code in `main()`

```cpp
    std::cout << "\nCalculating safe traveled distance for " << game3d::kMaxPoints << " points "
              << std::endl;
    total_distance = game3d::TotalSafeWalkingDistance(locations_1d);
    std::cout << "\nTotal safe traveled distance =" << total_distance << std::endl;
```

#### Compile Part 2.2

[How to compile and run the code with cmake.](../faqs.md#how-to-compile-and-run-the-code-with-cmake)

#### Sample Output Part 2.2

```bash
Calculating safe traveled distance for 10 points
Distance between 11.00 and 22.00 = 11.00
Should I move?
        No, stay put. You are in the danger zone
Distance between 22.00 and 37.00 = 15.00
Should I move?
        Yes, you are in the safe zone
Distance between 22.00 and 37.00 = 15.00
Distance between 37.00 and 41.00 = 4.00
Should I move?
        No, stay put. You are in the danger zone
Distance between 41.00 and 53.00 = 12.00
# ...
# ...

Total safe traveled distance =68.00

```

Note: Your output may vary depending on the logic of the algorithm. This function will be graded based on the `return value`, not on the output to the screen.

## Part 3: Game Distance in 3D

Your final consist in defining two more functions that support a 3D coordinate point instead of just a 1D point.

### Part 3.1: 3D Distance Function

Following the logic from [Part 1.1](#task-11-1d-distance-function) define another function with the same name but different input parameter types. In this case, we will use an array 3 of doubles. Remember we need to store the values for the `X, Y, and Z` coordinates. Once again, the second parameter into the function will be optional with the default value to the origin, in this case (0, 0, 0)

Note: There would be no name class between the two functions thanks to the C++ property called `function overload`. Function overloading is a feature where two or more functions can have the same name but different parameters.

```cpp
// game3d.h

// Part 3: Overload functions
// Default input parameters are only defined in the header file.
double Distance(std::array<double, kDimensions> a, std::array<double, kDimensions> b = {0, 0, 0});
```

In your implementation function you could use the square root function `sqrt()` and the to the power `pow()` function from the `<cmath>` library

```cpp
// game3d.cpp
#include <cmath>     // for pow(), sqrt() function

double game3d::Distance(std::array<double, game3d::kDimensions> a,
                        std::array<double, game3d::kDimensions> b)
{
     // Formula to calculate the distance between two 3D points:
    // distance = square root of ( (x2-x1)^2 + (y2-y1)^2 + (z2-z1)^2 )

    // square root function: std::sqrt(expression)
    // power function: std::pow(x, 2) == x^2
    double distance = 0;
     // Calcuate distance here

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\tDistance between (" << a[0] << "," << a[1] << "," << a[2] << ") and (" << b[0]
              << "," << b[1] << "," << b[2] << ") = " << distance << std::endl;

    return distance;
}
```

Test your code in `main()`

```cpp
    std::cout << "\n********Part 3********\n";
    std::array<double, 3> enemy1_location = {2, 6, 1};
    std::array<double, 3> enemy2_location = {3, 4, 0};

    double enemy_distance = game3d::Distance(enemy1_location, enemy2_location);
    std::cout << "Distance between 2 3D points: " << enemy_distance << std::endl;
    enemy_distance = game3d::Distance(enemy1_location);
    std::cout << "Distance between 1 3D point and origin: " << enemy_distance << std::endl;
```

#### Compile Part 3.1

[How to compile and run the code with cmake.](../faqs.md#how-to-compile-and-run-the-code-with-cmake)

#### Sample Output Part 3.1

```bash
# .. Part 1 and Part 2 output

********Part 3********
        Distance between (2.00,6.00,1.00) and (3.00,4.00,0.00) = 2.45
Distance between 2 3D points: 2.45
        Distance between (2.00,6.00,1.00) and (0.00,0.00,0.00) = 6.40
Distance between 1 3D point and origin: 6.40

```

### Part 3.2: Total Walking Distance Function for 3D points

The last function once again will follow the logic from [Part 1.2](#task-12-total-walking-distance-function-for-1d-points) but for 3D point. In this case, the input parameter should be an  `array of 3D points`. To define a `3D` point, just as in the previous task, use an  `array` of three elements. In other words, the input parameter for this function is an `array of arrays`.

Define one more constant to hold the number of dimensions inside your namespace.

```cpp
// game3d.h
const int kDimensions = 3;
// ...
double TotalWalkingDistance(const std::array<std::array<double, kDimensions>, kMaxPoints> &locations);
```

And just as before, in your implementation, you need to call the `Distance()` function. Your compiler is smart enough to call the correct function based on the input parameters.

```cpp
// game3d.cpp
double game3d::TotalWalkingDistance(
    const std::array<std::array<double, game3d::kDimensions>, game3d::kMaxPoints> &locations)
{
    float total = 0;
    // loop over all elements

    return total;
}
```

Test your code in `main()`

```cpp
    std::cout << "Calculating 3D distance for " << game3d::kMaxPoints << " 3D points " <<
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

```

#### Compile Part 3.2

[How to compile and run the code with cmake.](../faqs.md#how-to-compile-and-run-the-code-with-cmake)

#### Sample Output Part 3.2

```bash
# ...
Calculating 3D distance for 10 3D points
        Distance between (2.00,6.00,1.00) and (3.00,6.00,7.00) = 6.08
        Distance between (3.00,6.00,7.00) and (2.00,3.00,3.00) = 5.10
        Distance between (2.00,3.00,3.00) and (5.00,3.00,5.00) = 3.61
        Distance between (5.00,3.00,5.00) and (8.00,3.00,0.00) = 5.83
        Distance between (8.00,3.00,0.00) and (8.00,8.00,2.00) = 5.39
        Distance between (8.00,8.00,2.00) and (2.00,1.00,2.00) = 9.22
        Distance between (2.00,1.00,2.00) and (6.00,3.00,1.00) = 4.58
        Distance between (6.00,3.00,1.00) and (5.00,2.00,0.00) = 1.73
        Distance between (5.00,2.00,0.00) and (3.00,4.00,0.00) = 2.83
Total traveled distance between 10 3D points  = 44.37
```

## Validate your code

Once you are satisfied with your work, run the unit test file:

From the dropdown select main_test and run.

Sample output:

Tests passed: 12 of 12 tests

---

## Submit your code

Zip your src folder and submit in Canvas.
