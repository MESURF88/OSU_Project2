/******************************************************************************
** Program name: Project2
** Author: Kevin Hill
** Date:  04/22/2019
** Description: Implementation file for Animal class. Sets and gets Animal
** objects. Has functions that return the age, number of babies, payoff, cost
** and the food cost.
******************************************************************************/

#include "Animal.hpp"
#include "Tiger.hpp"
#include <iostream>
#include <cstdlib>//For random numbers.
#include <iomanip>


//Default Constructor.
Animal::Animal()
{
  age = -1;
  baseFoodCost = 10;
  cost = 0;
  numberofBabies = 0;
  baseFoodCost = 0;
  payoff = 0;
  foodCost = 0;
}

//setter function.
void Animal::setAge(int age_num)
{
  age = age_num;
}

//getter functions.
int Animal::getAge()
{
  return age;
}

int Animal::getPayoff()
{
  return payoff;
}

int Animal::getNumberBabies()
{
  return numberofBabies;
}

int Animal::getCost()
{
  return cost;
}

int Animal::getFoodCost()
{
  return foodCost;
}
