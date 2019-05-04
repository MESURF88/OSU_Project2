/******************************************************************************
** Program name: Project2
** Author: Kevin Hill
** Date:  04/22/2019
** Description: Implementation file for Zoo class. Sets and gets Zoo
** objects.
******************************************************************************/

#include "Zoo.hpp"
#include "Animal.hpp"
#include "inputValidateMenu.hpp"
#include <iostream>
#include <cstdlib>//For random numbers.
#include <iomanip>


//Default Constructor.
Zoo::Zoo()
{
  //set game in session to one initially.
  game_in_session = 1;
  //Set days to 1
  Days = 1;
    //Set money and other cost values.
  zooFunds = 100000;//start with 100,000 dollars in funds.
  totalFoodCost = 0;
  totalAnimalPay = 0;
  randEvent = 1;
  rand_animal = 0;
  //set animal specific values
  tiger_num = 0;
  penguin_num = 0;
  turtle_num = 0;
  tiger_option = 0;
  penguin_option = 0;
  turtle_option = 0;
  tigerIndex = 0;
  penguinIndex = 0;
  turtleIndex = 0;
  //Set array size constant
  SIZEMAX = 10;
  //set expansion factor for Tigers to 1 until array is doubled, tripled etc..
  expFactorTig = 1;
  //set expansion factor for Penguins to 1 until array is doubled, tripled etc..
  expFactorPen = 1;
  //set expansion factor for Turtles to 1 until array is doubled, tripled etc..
  expFactorTur = 1;
  //flag variable for adding multiple animals
  flagBaby[0] = 0;//Tiger
  flagBaby[1] = 0;//Penguin
  flagBaby[2] = 0;//Turtle
  //flag variable for finding adult animal
  flagAdult[0] = 0;//Tiger
  flagAdult[1] = 0;//Penguin
  flagAdult[2] = 0;//Turtle
  //Call for user inputs in order to build array
  requestInitialInput();
  //Initialize dynamically allocated array for each Animal class
  zooTigers = new Tiger[SIZEMAX];
  zooPenguins = new Penguin[SIZEMAX];
  zooTurtles = new Turtle[SIZEMAX];
  //Begin zoo tycoon game.
  setupZoo();
  startZoo();
}

//Destructor, deallocates arrays
Zoo::~Zoo()
{
	delete[] zooTigers;
  delete[] zooPenguins;
  delete[] zooTurtles;
}


/************************************************
*             requestInitialInput               *
*This function asks the user to initialize the  *
*parameters of the class. These include, initial*
*number of tigers, penguins and turtles. Also   *
*validates input so nothing is out of bounds.   *
************************************************/
void Zoo::requestInitialInput()
{
  //Request information for number of animals at start.
  std::cout<<"\n"<<std::endl;
  std::cout<<"How many tigers would you like to buy (minumum 1, maximum 2):"<<std::endl;
  tiger_num = inputValidateMenu(1,2);
  std::cout<<"How many penguins would you like to buy (minumum 1, maximum 2):"<<std::endl;
  penguin_num = inputValidateMenu(1,2);
  std::cout<<"How many turtles would you like to buy (minumum 1, maximum 2):"<<std::endl;
  turtle_num = inputValidateMenu(1,2);
  //seed the random  number generator
  srand(time(0));
}

/************************************************
*             endDayRequest                     *
*This function asks the user first if they want *
*to continue playing. Then if they want to buy  *
*another one of the animals from the options.   *
*validates input and if not enough funds, shows *
*error message to user.                         *
************************************************/
void Zoo::endDayRequest()
{
  //set number of animals bought and buy animal option to zero.
  tiger_num = 0;
  penguin_num = 0;
  turtle_num = 0;
  tiger_option = 0;
  penguin_option = 0;
  turtle_option = 0;
  //Reset baby flags
  flagBaby[0] = 0;//Tiger
  flagBaby[1] = 0;//Penguin
  flagBaby[2] = 0;//Turtle
  //Ask if user would like to continue
  std::cout<<"\n"<<std::endl;
  std::cout<<"Would you like to keep playing?:"<<std::endl;
  std::cout<<"1. Yes."<<"\n"<<std::endl;
  std::cout<<"2. No."<<"\n"<<std::endl;
  exit_game = inputValidateMenu(1,2);
  if (exit_game == 2)
  {
    game_in_session = 0;
  }
  else{
    //If continuing ask user if wants to buy more adult animals.
    std::cout<<"\n"<<std::endl;
    std::cout<<"Available Funds: "<<zooFunds<<std::endl;
    std::cout<<"Would you like to buy an adult Tiger?:"<<std::endl;
    std::cout<<"\n"<<std::endl;
    std::cout<<"1. Yes, buy a Tiger."<<"\n"<<std::endl;
    std::cout<<"2. No, don't buy a Tiger."<<"\n"<<std::endl;
    std::cout<<"Enter the following number to continue with the chosen option: "<<std::endl;
    tiger_option = inputValidateMenu(1,2);
    //check if enough funds.
    if (zooFunds>=10000 && tiger_option == 1)
    {
      //set penguin/turtle numbers to zero
      penguin_num = 0;
      turtle_num = 0;
      //Calculate changed funds
      zooFunds = zooFunds - zooTigers[0].getCost();
      tiger_num = 1;
      addAnimals(3);
    }
    else if (zooFunds<10000 && tiger_option == 1)
    {
      std::cout<<"Sorry not enough funds for a Tiger."<<std::endl;
    }
    std::cout<<"\n"<<std::endl;
    std::cout<<"Available Funds: "<<zooFunds<<std::endl;
    std::cout<<"Would you like to buy an adult Penguin?:"<<std::endl;
    std::cout<<"\n"<<std::endl;
    std::cout<<"1. Yes, buy a Penguin."<<"\n"<<std::endl;
    std::cout<<"2. No, don't buy a Penguin."<<"\n"<<std::endl;
    std::cout<<"Enter the following number to continue with the chosen option: "<<std::endl;
    penguin_option = inputValidateMenu(1,2);
    //check if enough funds.
    if (zooFunds>=1000 && penguin_option == 1)
    {
      //set tiger/turtle numbers to zero
      tiger_num = 0;
      turtle_num = 0;
      //Calculate changed funds
      zooFunds = zooFunds - zooPenguins[0].getCost();
      penguin_num = 1;
      addAnimals(3);
    }
    else if (zooFunds<1000 && penguin_option == 1)
    {
      std::cout<<"Sorry not enough funds for a Penguin."<<std::endl;
    }
    std::cout<<"\n"<<std::endl;
    std::cout<<"Available Funds: "<<zooFunds<<std::endl;
    std::cout<<"Would you like to buy an adult Turtle?:"<<std::endl;
    std::cout<<"\n"<<std::endl;
    std::cout<<"1. Yes, buy a Turtle."<<"\n"<<std::endl;
    std::cout<<"2. No, don't buy a Turtle."<<"\n"<<std::endl;
    std::cout<<"Enter the following number to continue with the chosen option: "<<std::endl;
    turtle_option = inputValidateMenu(1,2);
    //check if enough funds.
    if (zooFunds>=100 && turtle_option == 1)
    {
      //set tiger/penguin numbers to zero
      tiger_num = 0;
      penguin_num = 0;
      //Calculate changed funds
      zooFunds = zooFunds - zooTurtles[0].getCost();
      turtle_num = 1;
      addAnimals(3);
    }
    else if (zooFunds<100 && turtle_option == 1)
    {
      std::cout<<"Sorry not enough funds for a Turtle."<<std::endl;
    }
  }
}

/************************************************
*             setupZoo                          *
*Makes a zoo full of animals of aged one day.   *
*The animals are added based on how many the    *
*user requests (1,2).                           *
************************************************/
void Zoo::setupZoo()
{
  for (int i=0; i<tiger_num; i++)
  {
    zooTigers[i].setAge(1);
    zooFunds = zooFunds - zooTigers[i].getCost();
    //increment index by one
    tigerIndex++;
  }
  for (int i=0; i<penguin_num; i++)
  {
    zooPenguins[i].setAge(1);
    zooFunds = zooFunds - zooPenguins[i].getCost();
    //increment index by one
    penguinIndex++;
  }
  for (int i=0; i<turtle_num; i++)
  {
    zooTurtles[i].setAge(1);
    zooFunds = zooFunds - zooTurtles[i].getCost();
    //increment index by one
    turtleIndex++;
  }
}

/************************************************
*             addAnimals                        *
*Adds an animal to the zoo with an input of an  *
*age integer. It also verifies if array length  *
*can hold the amount of animals that will be    *
*added. Increments animal index after addition  *
************************************************/
void Zoo::addAnimals(int age)
{
  if (tiger_num == 1)
  {
    checkArrLen();
    zooTigers[tigerIndex].setAge(age);
    //increment index by one
    tigerIndex++;
  }
  if (penguin_num == 1)
  {
    checkArrLen();
    zooPenguins[penguinIndex].setAge(age);
    //increment index by one
    penguinIndex++;
  }
  if (turtle_num == 1)
  {
    checkArrLen();
    zooTurtles[turtleIndex].setAge(age);
    //increment index by one
    turtleIndex++;
  }
  //Reset animal number
  tiger_num = 0;
  penguin_num = 0;
  turtle_num = 0;
}

/************************************************
*             foodPay                           *
*Adds the specific food cost for every animal   *
*based on how many animals are in the array.    *
************************************************/
void Zoo::foodPay()
{
  for (int i=0; i<SIZEMAX*expFactorTig; i++)
  {
    if (zooTigers[i].getAge()!=-1)
    {
      totalFoodCost += zooTigers[i].getFoodCost();
    }
  }
  for (int i=0; i<SIZEMAX*expFactorPen; i++)
  {
    if (zooPenguins[i].getAge()!=-1)
    {
      totalFoodCost += zooPenguins[i].getFoodCost();
    }
  }
  for (int i=0; i<SIZEMAX*expFactorTur; i++)
  {
    if (zooTurtles[i].getAge()!=-1)
    {
      totalFoodCost += zooTurtles[i].getFoodCost();
    }
  }
  std::cout<<"foodcost: "<<totalFoodCost<<std::endl;
  zooFunds = zooFunds - totalFoodCost;
}

/************************************************
*             animalAge_Revenue                 *
*Adds the specific animal revenue for each      *
*animal based on every animal in the array. The *
*function also increments age of animal by one. *
************************************************/
void Zoo::animalAge_Revenue()
{
  for (int i=0; i<SIZEMAX*expFactorTig; i++)
  {
    if (zooTigers[i].getAge()!=-1)
    {
      totalAnimalPay += zooTigers[i].getPayoff();
      //Age animal one day
      zooTigers[i].setAge(zooTigers[i].getAge()+1);
    }
  }
  for (int i=0; i<SIZEMAX*expFactorPen; i++)
  {
    if (zooPenguins[i].getAge()!=-1)
    {
      totalAnimalPay += zooPenguins[i].getPayoff();
      //Age animal one day
      zooPenguins[i].setAge(zooPenguins[i].getAge()+1);
    }
  }
  for (int i=0; i<SIZEMAX*expFactorTur; i++)
  {
    if (zooTurtles[i].getAge()!=-1)
    {
      totalAnimalPay += zooTurtles[i].getPayoff();
      //Age animal one day
      zooTurtles[i].setAge(zooTurtles[i].getAge()+1);
    }
  }
  std::cout<<"AnimalPay: "<<totalAnimalPay<<std::endl;
  zooFunds = zooFunds + totalAnimalPay;
}

/************************************************
*             checkArrLen                       *
*Verifies if there is room for another animal.  *
*Checks to see if baby flag is on then the array*
*size is doubled. Resets baby flags after.      *
************************************************/
void Zoo::checkArrLen()
{
  if (tigerIndex == SIZEMAX*expFactorTig || flagBaby[0] == 1)
  {
    //double array size expansion factor
    expFactorTig *= 2;
    //expand array to twice the size
    tempTigers = new Tiger[SIZEMAX*expFactorTig];
    //Initialize array values
    for (int i=0; i<SIZEMAX*expFactorTig; i++)
    {
      tempTigers[i].setAge(-1);
    }
    //for length of old array copy values over to new array
    for (int i=0; i<(SIZEMAX*expFactorTig)/2; i++)
    {
      tempTigers[i].setAge(zooTigers[i].getAge());
    }
    //delete old array transfer pointer to new array
    delete[] zooTigers;
    zooTigers = tempTigers;
  }
  if (penguinIndex == SIZEMAX*expFactorPen || flagBaby[1] == 1)
  {
    //double array size expansion factor
    expFactorPen *= 2;
    //expand array
    tempPenguins = new Penguin[SIZEMAX*expFactorPen];
    //Initialize array values
    for (int i=0; i<SIZEMAX*expFactorPen; i++)
    {
      tempPenguins[i].setAge(-1);
    }
    //for length of old array copy values over to new array
    for (int i=0; i<(SIZEMAX*expFactorPen)/2; i++)
    {
      tempPenguins[i].setAge(zooPenguins[i].getAge());
    }
    //delete old array transfer pointer to new array
    delete[] zooPenguins;
    zooPenguins = tempPenguins;
  }
  if (turtleIndex == SIZEMAX*expFactorTur || flagBaby[2] == 1)
  {
    //double array size expansion factor
    expFactorTur *= 2;
    //expand array
    tempTurtles = new Turtle[SIZEMAX*expFactorTur];
    //Initialize array values
    for (int i=0; i<SIZEMAX*expFactorTur; i++)
    {
      tempTurtles[i].setAge(-1);
    }
    //for length of old array copy values over to new array
    for (int i=0; i<(SIZEMAX*expFactorTur)/2; i++)
    {
      tempTurtles[i].setAge(zooTurtles[i].getAge());
    }
    //delete old array transfer pointer to new array
    delete[] zooTurtles;
    zooTurtles = tempTurtles;
  }
  //Reset baby flags
  flagBaby[0] = 0;//Tiger
  flagBaby[1] = 0;//Penguin
  flagBaby[2] = 0;//Turtle
}

/************************************************
*             randomEvent                       *
*Picks randomly from four options of events.    *
*prints out which event occured and what animal *
*it affected if applicable.                     *
************************************************/
void Zoo::randomEvent()
{
  //Generate random event during the day out of four options.
  randEvent = (rand()%4)+1;
  if (randEvent == 1) {
    //generate random number to remove random animal
    rand_animal = (rand()%3)+1;
    if (rand_animal == 1)
    {
      //check to see if there are any tigers left, if not avoid sickness
      if (tigerIndex == 0)
      {
        randEvent = 3;
      }
      else{
        std::cout<<"Tiger is sick."<<std::endl;
        //delete last index of tiger
        zooTigers[tigerIndex-1].setAge(-1);
        //decrement index by one
        tigerIndex--;
      }
    }
    else if (rand_animal == 2)
    {
      //check to see if there are any penguins left, if not avoid sickness
      if (penguinIndex == 0)
      {
        randEvent = 3;
      }
      else{
        std::cout<<"Penguin is sick."<<std::endl;
        //delete last index of tiger
        zooPenguins[penguinIndex-1].setAge(-1);
        //decrement index by one
        penguinIndex--;
      }
    }
    else if (rand_animal == 3)
    {
      //check to see if there are any turtles left, if not avoid sickness
      if (turtleIndex == 0)
      {
        randEvent = 3;
      }
      else{
        std::cout<<"Turtle is sick."<<std::endl;
        //delete last index of tiger
        zooTurtles[turtleIndex-1].setAge(-1);
        //decrement index by one
        turtleIndex--;
      }
    }
  }
  else if (randEvent == 2)
  {
    std::cout<<"Boom in tiger viewing."<<std::endl;
    for (int i=0; i<tigerIndex; i++)
    {
      zooFunds += (rand()%(250+1))+250;
    }

  }
  else if (randEvent == 3)
  {
    //check for adults
    for (int i=0; i<tigerIndex;i++)
    {
      if (zooTigers[i].getAge() >= 3)
      {
        flagAdult[0] = 1;
      }
    }
    for (int i=0; i<penguinIndex;i++)
    {
      if (zooPenguins[i].getAge() >= 3)
      {
        flagAdult[1] = 1;
      }
    }
    for (int i=0; i<turtleIndex;i++)
    {
      if (zooTurtles[i].getAge() >= 3)
      {
        flagAdult[2] = 1;
      }
    }
    if (flagAdult[0] == 0 && flagAdult[1] == 0 && flagAdult[2] == 0)
    {
      //if no adults then nothing happens
      randEvent = 3;
    }
    else{
      //generate random number to remove random animal that has adult
      do{
          rand_animal = (rand()%3);
        }while (flagAdult[rand_animal] != 1);
        //Tiger babies
        if (rand_animal == 0)
        {
          if (tigerIndex == SIZEMAX*expFactorTig)
          {
            flagBaby[0] = 1;
          }
          std::cout<<"Tiger was born."<<std::endl;
          tiger_num = 1;
          addAnimals(0);
        }
        //Penguin babies
        else if (rand_animal == 1)
        {
          if (SIZEMAX*expFactorPen - penguinIndex < (zooPenguins[0].getNumberBabies()-1))
          {
            flagBaby[1] = 1;
          }
          for (int i=0; i<zooPenguins[0].getNumberBabies(); i++)
          {
            penguin_num = 1;
            std::cout<<"Penguins were born."<<std::endl;
            addAnimals(0);
          }
        }
        //Turtle babies
        else if (rand_animal == 2)
        {
          if (SIZEMAX*expFactorTur - turtleIndex < (zooTurtles[0].getNumberBabies()-1))
          {
            flagBaby[2] = 1;
          }
          for (int i=0; i<zooTurtles[0].getNumberBabies(); i++)
          {
            turtle_num = 1;
            std::cout<<"Turtles were born."<<std::endl;
            addAnimals(0);
          }
        }
    }
  }
  else if (randEvent == 4)
  {
    std::cout<<"Nothing happened today."<<std::endl;
  }
  //Reset adult flags
  flagAdult[0] = 0;
  flagAdult[1] = 0;
  flagAdult[2] = 0;
}

/************************************************
*             printDetails                      *
*This function prints the day's details.        *
************************************************/
void Zoo::printDetails()
{
  /*
  std::cout<<"Tigers"<<"   "<<"Penguins"<<"  "<<"Turtles"<<std::endl;
 for (int i=0; i<10; i++)
 {
   std::cout<<"\n"<<std::endl;
   std::cout<<zooTigers[i].getAge()<<"         "<<zooPenguins[i].getAge()<<"         "<<zooTurtles[i].getAge()<<std::endl;
   std::cout<<"\n"<<std::endl;
 }
 */
 //Print out day and Zoo funds.
  std::cout<<"\n"<<std::endl;
  std::cout<<"Day: "<<Days<<std::endl;//remove
  std::cout<<"Zoo funds: "<<zooFunds<<std::endl;//remove


}

/************************************************
*             startZoo                          *
*This function loops the Zoo function while     *
*the user wants to continue the game or until   *
*funds run out. Calls end of day details as well*
************************************************/
void Zoo::startZoo()
{
  //Print first day's details.
  printDetails();
  //Loop days until user quits or runs out of funds
  while (game_in_session == 1){
    totalFoodCost = 0;//Re-initialize food costs for all animals day
    totalAnimalPay = 0;//Re-initialize animal payoff for all animals each day
    foodPay();
    animalAge_Revenue();
    randomEvent();
    //increment Days
    Days++;
    //check to see if funds have run out, if so, end game
    if (zooFunds <= 0)
    {
      game_in_session = 0;
    }
    //request user for information if they want more adult animals
    endDayRequest();
    printDetails();
  }

}
