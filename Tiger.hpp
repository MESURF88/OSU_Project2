
/******************************************************************************
** Program name: Project2
** Author: Kevin Hill
** Date:  04/22/2019
** Description: Class Specification file for Tiger. Derived from Animal.
**    Declares functions, constructors and variables.
******************************************************************************/

#ifndef TIGER_HPP
#define TIGER_HPP
#include "Animal.hpp"

//Defines the interface of the Tiger Class.
class Tiger: public Animal{
private:
  //Declare private variables for Tiger
  int age;
  int cost;
  int numberofBabies;
  int baseFoodCost;
  int foodCost;
  int payoff;

public:
  //Constructors.
  Tiger();
  //Member functions.
  int getPayoff();
  int getNumberBabies();
  int getCost();
  int getFoodCost();
};
#endif
