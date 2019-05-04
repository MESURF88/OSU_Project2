/******************************************************************************
** Program name: Project2
** Author: Kevin Hill
** Date:  04/22/2019
** Description: Main method file for Zoo, Animal and its inherited classes.
** user prompted for input file name. The menu is displayed after
** completion of program until user quits. Outputs are printed to the console.
******************************************************************************/


#include <iostream>
#include <fstream>
#include <string>
#include "menu.hpp"
#include "Zoo.hpp"


int main()
{
	int option_picked = 0;

	option_picked = menu();//Call initial function

  //Loop Zoo until user quits the menu.
	while (option_picked == 1)
	{
		Zoo place;
		option_picked = menu();
  }


	return 0;
}
