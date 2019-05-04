
/******************************************************************************
** Program name: Project2
** Author: Kevin Hill
** Date:  04/22/2019
** Description: Class Specification file for Zoo. Declares functions,
**    constructors and variables.
******************************************************************************/

#ifndef ZOO_HPP
#define ZOO_HPP
#include "Animal.hpp"//Include Animal class to maintain link with its functions
#include "Tiger.hpp"//Include Tiger class to maintain link with its functions
#include "Penguin.hpp"//Include Penguin class to maintain link with its functions
#include "Turtle.hpp"//Include Turtle class to maintain link with its functions

//Defines the interface of the Zoo Class.
class Zoo
{
private:
  //Declare private variables for Zoo
  int game_in_session;
  int exit_game;
  int Days;
  int randEvent;
  int rand_animal;
  int zooFunds;
  int totalFoodCost;
  int totalAnimalPay;
  //Animal specific variables
  int tiger_num;
  int penguin_num;
  int turtle_num;
  int tiger_option;
  int penguin_option;
  int turtle_option;
  int tigerIndex;
  int penguinIndex;
  int turtleIndex;
  //Array sizing variables
  int SIZEMAX;
  int expFactorTig;
  int expFactorPen;
  int expFactorTur;
  int flagBaby[3];
  int flagAdult[3];
  //Declare array of animal objects
  Tiger *zooTigers;
  Penguin *zooPenguins;
  Turtle *zooTurtles;
  //temporary array of animal objects
  Tiger *tempTigers;
  Penguin *tempPenguins;
  Turtle *tempTurtles;
  //Member functions
  void requestInitialInput();
  void endDayRequest();
  void setupZoo();
  void startZoo();
  void foodPay();
  void randomEvent();
  void animalAge_Revenue();
  void addAnimals(int);
  void checkArrLen();
  //Mutators
public:
  //Constructors.
  Zoo();
  //Destructor
  ~Zoo();
  //Member functions.
  void printDetails();
};
#endif
