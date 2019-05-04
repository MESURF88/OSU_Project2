
/******************************************************************************
** Program name: Project2
** Author: Kevin Hill
** Date:  04/22/2019
** Description: Class Specification file for Animal. Declares functions,
**    constructors and variables.
******************************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

//Defines the interface of the Animal Class.
class Animal
{
private:
  //Declare private variables for Animal
  int age;
  int cost;
  int numberofBabies;
  int baseFoodCost;
  int payoff;
  int foodCost;

public:
  //Constructors.
  Animal();
  //Member functions.
  //Accessors/Mutators
  void setAge(int);
  int getAge();
  int getPayoff();
  int getNumberBabies();
  int getCost();
  int getFoodCost();
};
#endif
