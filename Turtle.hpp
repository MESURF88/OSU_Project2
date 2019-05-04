
/******************************************************************************
** Program name: Project2
** Author: Kevin Hill
** Date:  04/22/2019
** Description: Class Specification file for Turtle. Derived from Animal.
**    Declares functions, constructors and variables.
******************************************************************************/

#ifndef TURTLE_HPP
#define TURTLE_HPP
#include "Animal.hpp"

//Defines the interface of the Turtle Class.
class Turtle: public Animal{
private:
  //Declare private variables for Turtle
  int age;
  int cost;
  int numberofBabies;
  int baseFoodCost;
  int foodCost;
  int payoff;

public:
  //Constructors.
  Turtle();
  //Member functions
  int getPayoff();
  int getNumberBabies();
  int getCost();
  int getFoodCost();
};
#endif
