
/******************************************************************************
** Program name: Project2
** Author: Kevin Hill
** Date:  04/22/2019
** Description: Class Specification file for Penguin. Derived from Animal.
**    Declares functions, constructors and variables.
******************************************************************************/

#ifndef PENGUIN_HPP
#define PENGUIN_HPP
#include "Animal.hpp"

//Defines the interface of the Die Class.
class Penguin: public Animal{
private:
  //Declare private variables for Game
  int age;
  int cost;
  int numberofBabies;
  int baseFoodCost;
  int foodCost;
  int payoff;

public:
  //Constructors.
  Penguin();
  //Member functions.
  int getPayoff();
  int getNumberBabies();
  int getCost();
  int getFoodCost();
};
#endif
