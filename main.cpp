/*****************************************************************
* NAME:Dieter Schmid
* STUDENT ID:211374926
* UNIT CODE:SIT 153
* ASSIGNMENT:1
* DUE DATE:07/10/2011
*
*****************************************************************
* Plagiarism and collusion
* Plagiarism occurs when a student passes off as the student’s own
* work, or copies without acknowledgment as to its authorship, the
* work of any other person.
* Collusion occurs when a student obtains the agreement of another
* person for a fraudulent purpose with the intent of obtaining an
* advantage in submitting an assignment or other work
*
* Declaration
* I certify that the attached work is entirely my own (or where
* submitted to meet the requirements of an approved group
* assignment is the work of the group), except where work quoted
* or paraphrased is acknowledged in the text. I also certify that
* it has not been submitted for assessment in any other unit or course.
*
* I agree that Deakin University may make and retain copies of this
* work for the purposes of marking and review, and may submit
* this work to an external plagiarism-detection service who may
* retain a copy for future plagiarism detection but will not release
* it or use it for any other purpose.
*
* DATE: 07/10/2011
*
* An assignment will not be accepted for assessment if the declaration
* appearing above has not been duly completed by the author.
 * File: main.cpp
 * Author:	 D. Schmid			Date Created:	7/11/2011
 * Last Modified by:				Date Modified:	
 * 
 * Comments:
 *
 * Yes this is the game loop from below hell or the 7th layer of it.
 * I wish i had to make this quality but it is as it is. 
 *******************************************************************
*/


#include "ConsoleWindow.h"
#include "Maze.h"
#include "DFSMaze.h"
#include "Player.h"
#include "BoobyTrappedTreasureItem.h"
#include "BoobyTrapItem.h"
#include "TreasureItem.h"
#include "VirtualItem.h"
#include "HiScore.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>


void displayMenu();
int menuChoice(int mc);

int main ()
{
	//char * fileName = "outfile.dat";
	//ofstream ofd(fileName);

	string input[50];//big buffer
	
	
	int MenuChoice;
	
	bool MenuLoop = true;
	bool option1 = false;
	bool newGame = true;

	HiScore hi("scores.dat");
	string name;
	Player * player1; 
	
	//handy i, and j variables just in case
	//int i = 0;
	//int j = 0;
	
	cout << "WELCOME TO THE MAZE OF CHOAS !" << "\n\n";
	while(newGame)
	{

	do{
		displayMenu();
	    cin >> MenuChoice;
		

		    if (!cin.fail())
		    {
				MenuChoice = menuChoice(MenuChoice);
				MenuLoop = false;

			} else {cout << "ERROR: You did not enter an integer value?! Please try again!\n" << endl;
			
				MenuLoop = true;

			}
		  

			 string junk;		
			 cin.clear();		
			 getline(cin,junk);	// read a line of text (up until the newline) 
				
			 //do what needs to be done with the menu options
			if(MenuChoice == 3) return 0;

			if(MenuChoice == 1) {
				MenuLoop = false;
				option1 = true; //lets play ! aiiiight
				cout << "Your Name Please ?" << endl;
				
				cin >> name;
				player1 = new Player(name,223);
			}
			if(MenuChoice == 2){MenuLoop = true;}
			if(MenuChoice == 4){
			
				hi.displayHiScore();
				MenuLoop = true;
			}

		}while (MenuLoop);

	//option 1

	while(option1)
	{
		//Was going to add some customisation


		//variables to trigger maze generation algorithm
		bool Mazed = true;
		bool newLevel = true;
		
		ConsoleWindow window;

		try{
			//set up teh screen for the game
		    window.clearWindow ();
			window.drawBorder (' ');
			window.switchCursor(false); //switch off the cursor
		
		} catch(char *str){
			cout << "windows setup error" << str << endl;
		}

		//DFS Maze with back tracking
		DFSMaze MehMaze(78,22);//to stay in the window.
		//Or Prims Maze
		//PrimMaze MehMaze(78,22); //to stay in the window. The cursor looks better for some reason at full size

		//create random items a starting point for the player	
		srand((unsigned int) time(0));
	
		int ran1 = 0;
		int ran2 = 0;

		try{
		
			do{
			 ran1 = rand() % MehMaze.max_row()-1;
			 ran2 = rand() % MehMaze.max_col()-1;
	
			}while(player1->setStartPos(ran1,ran2, MehMaze));
		
		}catch(...){cout << "setup error" <<endl;
				
		}
		
		//store all teh items for easy access in a vector
		vector<VirtualItem *> v;
		vector<VirtualItem *>::iterator current;

		ran1 = rand() % (MehMaze.max_row()-1)+1;
		ran2 = rand() % (MehMaze.max_col()-1)+1;
		BoobyTrappedTreasureItem btti1(ran1,ran2);

		v.push_back(&btti1);

		ran1 = rand() % (MehMaze.max_row()-1)+1;
		ran2 = rand() % (MehMaze.max_col()-1)+1;
		BoobyTrapItem bti1(ran1,ran2);

		v.push_back(&bti1);

		ran1 = rand() % (MehMaze.max_row()-1)+1;
		ran2 = rand() % (MehMaze.max_col()-1)+1;
		TreasureItem ti1(ran1, ran2);

		v.push_back(&ti1);


	

	    while (newLevel)
		{	
		 try //do some error checking for the maze generation
		  {
			//maze generator loop (random level maker)
			while(Mazed)
			{

			//DRAWS THE MAZE NOT QUITE THE WAY I PLANNED IT BUT ITS RANDOMLY GENERATED
			//WHICH IS WHAT I WANTED

				int endx = 0; 
				int endy = 0; 

				//Get a location for the end. Currently same point not randomly generated
				MehMaze.getEnd(endx,endy);
				

				for(int row = 0; row < MehMaze.max_row(); row++)
				{ 
					
					for(int col = 0; col < MehMaze.max_col(); col++)
					{
							
						if(row%2 == 1 && col%2 == 1){
							if(MehMaze.getIn(row/2+1,col/2+1)) {
								window.putChar(178, row+1,col+1); 
							}
							else window.putChar(219, row+1,col+1); 

						}
						else if(row%2 == 0 && col%2 == 0){ window.putChar(219, row+1,col+1);}
						else if(row%2 == 0 && col%2 == 1)
						{
							 if(MehMaze.getLeft(row/2+1,col/2+1)) window.putChar(219, row+1,col+1);
								else { window.putChar(178, row+1,col+1);}

							}else if(row%2 == 1 && col%2 == 0){
                                
								if(MehMaze.getUp(row/2+1,col/2+1)) window.putChar(219, row+1,col+1);
								else{window.putChar(178, row+1,col+1); }
						 }
			        }
					//give it a slight animation effect
				  Sleep(20)	;
        		}

				//set up things to start 
				//print all the items, the GUI and exit on teh screen
				
				VirtualItem * v1;
				
				for (current = v.begin(); current != v.end(); ++current){
					
					v1 = *current;
					window.putChar('T', v1->getPosX()+1,v1->getPosY()+1, FOREGROUND_GREEN);
				}
	
				window.putChar('E', endx+1,endy+1,  BACKGROUND_BLUE | FOREGROUND_GREEN);
				stringstream s;
				s  << *player1;
				window.putString(s.str(), 0,23,  BACKGROUND_BLUE | FOREGROUND_GREEN);
				//s << "\tCoins :  " << player1->getCoins();
				//window.putString(s.str(), 0,23, BACKGROUND_BLUE | FOREGROUND_GREEN);
				window.putString("Press R to re-start - cause The Algorthimn is Buggy OR Q to quit", 0,24,  FOREGROUND_GREEN);
			
				Mazed = false;
			}
		  
				
		    }	catch (char *str) {  
				//any problems in putting things on screen this will say why
			 cout << "Error in generating the maze " << str << endl;
			//Mazed = false;
		  
		    }
		 
		//game loop
		//Sleep(50);

		// Check to see if a key has been pressed
		window.nextKey ();

		//setup key input handling
		HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);	
		INPUT_RECORD key;
		DWORD numRead;

		//set up th eplayers position
		int pX = 0;
		int pY = 0;

		player1->getPos(pX, pY);
		//put the player on screen
		window.putChar(177, pX+1,pY+1,FOREGROUND_RED );

		PeekConsoleInput (hIn, &key, 1, &numRead);
		
		if (numRead > 0)
		{
			ReadConsoleInput (hIn, &key, 1, &numRead);
			//this is teh event handling for the players movement
			if ((key.EventType == KEY_EVENT) && (key.Event.KeyEvent.bKeyDown) && (key.Event.KeyEvent.uChar.AsciiChar == 's'))
			{
					//move player down
				if(player1->moveDown(MehMaze,v)) {
						
					window.putChar(176, pX+1 ,pY+1  );
						window.putChar(177, pX+1 ,pY+2 );
						player1->setPos(pX,pY+1);
						stringstream s;
				s  << *player1;
				window.putString(s.str(), 0,23,  BACKGROUND_BLUE | FOREGROUND_GREEN);
			

				} else {
					//block by a wall is it the exit ?
					if(MehMaze.Completed()){cout << "FINISHED MAZE !" << endl;
					//amazed ? heheh
					Mazed = true;
					newLevel = false;
					player1->addScore(1);
					}
					//cout << "BLOCKED DOWN" << endl;
				}
			}
			if ((key.EventType == KEY_EVENT) && (key.Event.KeyEvent.bKeyDown) && (key.Event.KeyEvent.uChar.AsciiChar == 'w'))
			{
				//move player up
				if(player1->moveUp(MehMaze,v)) {
							window.putChar(176, pX+1 ,pY+1 );
					    window.putChar(177, pX+1 ,pY);
						player1->setPos(pX,pY-1);
						stringstream s;
				s  << *player1;
				window.putString(s.str(), 0,23,  BACKGROUND_BLUE | FOREGROUND_GREEN);
				
				} else {
					if(MehMaze.Completed()){cout << "FINISHED MAZE !" << endl;
					Mazed = true;
					newLevel = false;
					player1->addScore(1);
						window.clearWindow ();
					}
				}
			}
			if ((key.EventType == KEY_EVENT) && (key.Event.KeyEvent.bKeyDown) && (key.Event.KeyEvent.uChar.AsciiChar == 'a'))
			{
				//move player left
				if(player1->moveLeft(MehMaze,v)) {
					window.putChar(176, pX+1 ,pY+1 );
					window.putChar(177, pX ,pY+1);
					player1->setPos(pX-1,pY);
					stringstream s;
				s  << *player1;
				window.putString(s.str(), 0,23,  BACKGROUND_BLUE | FOREGROUND_GREEN);
	
				} else {
					if(MehMaze.Completed()){cout << "FINISHED MAZE !" << endl;
					Mazed = true;
					newLevel = false;
					player1->addScore(1);
						window.clearWindow ();
					}
					
				}
			}
			if ((key.EventType == KEY_EVENT) && (key.Event.KeyEvent.bKeyDown) && (key.Event.KeyEvent.uChar.AsciiChar == 'd'))
			{
				//move player right
				if(player1->moveRight(MehMaze,v)) {
						window.putChar(176, pX+1 ,pY+1 );
					window.putChar(178, pX+2 ,pY+1);
					player1->setPos(pX+1,pY);
					stringstream s;
				s  << *player1;
				window.putString(s.str(), 0,23,  BACKGROUND_BLUE | FOREGROUND_GREEN);
				
				} else {
					if(MehMaze.Completed()){cout << "FINISHED MAZE !" << endl;
					Mazed = true;
					newLevel = false;
					player1->addScore(1);
						window.clearWindow ();
					}
					
				}
			}
			if ((key.EventType == KEY_EVENT) && (key.Event.KeyEvent.bKeyDown) && (key.Event.KeyEvent.uChar.AsciiChar == 'r'))
			{
				//trigger a redraw of the maze and a new level
					Mazed = true;
					newLevel = false;
					
					cout << "restart" <<endl; 
					window.clearWindow ();
					
				
			}
			if ((key.EventType == KEY_EVENT) && (key.Event.KeyEvent.bKeyDown) && (key.Event.KeyEvent.uChar.AsciiChar == 'q'))
			{
				
				//end game record the score
				hi.addPlayerScore(player1);
				//ran out of time on this function
				//hi.sortHiScore();
				window.clearWindow();
				window.putChar ('*', 0, 0, FOREGROUND_RED  );
				hi.displayHiScore();
				
				//uncomment to loop so as the program jumps back to the menu - i dont like this
				//Mazed = false;
				//newLevel = false;
				//option1 =false;
				
				return 0;
				
			}
		}
	 }
  	
  }
 }
}




void displayMenu()
{
		 cout << "Please select from one of the following options:" << endl
		 << "\t1: Play"   << endl
		 << "\t2: Help"   << endl
		 << "\t3: Quit"   << endl
		 << "\t4: High Scores"   << endl
		 << "Enter (1,2, or 3 only):" << endl;
}


int menuChoice(int mc){

 switch (mc){
			case 1 : {
				cout << "PLAY Option Selected!" << endl;
				return 1;
			 }
			case 2 : {
				cout << "HELP Option Selected!" << endl;
				cout << "w - moves UP" << endl;
				cout << "s - moves DOWN" << endl;
				cout << "a - moves LEFT" << endl;
				cout << "d - moves RIGHT" << endl;
				cout << "ARE YOU READY TO PLAY NOW ?" << endl;
					return 2;
			}
			case 3 :{
				cout << "QUIT Option Selected!" << endl;
				return 3;
			}
			case 4 :{
			
				return 4;
			}
			default : {
				cout << "ERROR: Invalid option selected! Please selected from 1,2,or 3 \n" << endl;
			    return 0;}
		   }
}