/******************************************************************************
** Program name: Project2
** Author: Kevin Hill
** Date:  04/22/2019
** Description: Implementation file for Turtle class. Sets and gets Turtles
** objects, derived from Animal. Has functions that return the age,
** number of babies, payoff, cost and the food cost.
******************************************************************************/

#include "Turtle.hpp"
#include <iostream>
#include <cstdlib>//For random numbers.
#include <iomanip>


//Default Constructor.
Turtle::Turtle(): Animal()
{
  age = -1;
  cost = 100;
  numberofBabies = 10;
  baseFoodCost = 10;
  foodCost = baseFoodCost/2;
  payoff = cost/20;
}

//getter functions.
int Turtle::getPayoff()
{
  return payoff;
}

int Turtle::getNumberBabies()
{
  return numberofBabies;
}

int Turtle::getCost()
{
  return cost;
}

int Turtle::getFoodCost()
{
  return foodCost;
}
