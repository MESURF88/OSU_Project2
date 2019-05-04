/******************************************************************************
** Program name: Project2
** Author: Kevin Hill
** Date:  04/22/2019
** Description: Implementation file for Tiger class. Sets and gets Tiger
** objects, derived from Animal. Has functions that return the age,
** number of babies, payoff, cost and the food cost.
******************************************************************************/

#include "Tiger.hpp"
#include <iostream>
#include <cstdlib>//For random numbers.
#include <iomanip>


//Default Constructor.
Tiger::Tiger(): Animal()
{
  age = -1;
  cost = 10000;
  numberofBabies = 1;
  baseFoodCost = 10;
  foodCost = 5*baseFoodCost;
  payoff = cost/5;
}

//getter functions.
int Tiger::getPayoff()
{
  return payoff;
}

int Tiger::getNumberBabies()
{
  return numberofBabies;
}

int Tiger::getCost()
{
  return cost;
}

int Tiger::getFoodCost()
{
  return foodCost;
}
