/******************************************************************************
** Program name: Project2
** Author: Kevin Hill
** Date:  04/22/2019
** Description: Implementation file for Penguin class. Sets and gets Penguin
** objects, derived from Animal. Has functions that return the age,
** number of babies, payoff, cost and the food cost.
******************************************************************************/

#include "Penguin.hpp"
#include <iostream>
#include <cstdlib>//For random numbers.
#include <iomanip>


//Default Constructor.
Penguin::Penguin(): Animal()
{
  age = -1;
  cost = 1000;
  numberofBabies = 5;
  baseFoodCost = 10;
  foodCost = baseFoodCost;
  payoff = cost/10;
}

//getter functions.
int Penguin::getPayoff()
{
  return payoff;
}

int Penguin::getNumberBabies()
{
  return numberofBabies;
}

int Penguin::getCost()
{
  return cost;
}

int Penguin::getFoodCost()
{
  return foodCost;
}
