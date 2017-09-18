/*****************************************************************
* NAME:Dieter Schmid
* STUDENT ID:211374926
* UNIT CODE:SIT 153
* ASSIGNMENT:2
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
 *******************************************************************
 * File: DFSMaze.cpp
 * Author:	 D. Schmid			Date Created:	7/10/2011
 * Last Modified by:				Date Modified:	
 * 
 * Comments:
 *
 * Ummm http://en.wikipedia.org/wiki/User:Purpy_Pupple/Maze based on this code
 * but heavily modded to suit this game...didnt really work as well 
 * as it looks on wikki - still trying to kill off bugs :(
 * also the code below is Prim's Algorithm not DFS - minor changes make it DFS.
 * was going to split classes but not enough time - DFS is even less playable.
 *******************************************************************
*/

#include "DFSMaze.h"
#include "Maze.h"
#include <iostream>
#include <Windows.h>

DFSMaze::DFSMaze(){};

DFSMaze::DFSMaze(int rows, int cols): Maze(rows,cols) {

	srand((unsigned int) time(0));

	int ran3 = 0;
	int ran4 = 0;
	
	do{
		ran3 = rand() % rows;
		ran4 = rand() % cols;
	}
	while(!setEnd(ran3,ran4));

	int  ran1= rand() % rows;
	int ran2= rand() % cols;

	setEnd(0,1);
   
 	try{
		//Mark the current cell as visited, and get a list of its neighbors. For each neighbor, starting with a randomly selected neighbor:
		//mark(ran1, ran2);

		generate(ran1,ran2,1);
	
	}
	catch( char *str ) {cout << "Caught an exception : " << str << "\n"; }	

};

DFSMaze::~DFSMaze(){ }

void DFSMaze::generate(int & x, int & y, long numin)
{
	
		_map[x][y].in = 1;
		//long numin=1;     //Number of cells in the _map.
        int whichway;
        bool success;
		
		//cout << "pt1" <<endl;
		do{
		    
			if( _map[x][y-1].in&&_map[x][y+1].in&&
                           _map[x-1][y].in&&_map[x+1][y].in )
		    {
                                   //If at a dead end, randomly destroy a wall to make it not a dead end!
               do{
                        success=0;
                        whichway=rand()%4;
                        
						switch(whichway){
                        
								case UP:
                                        if(_map[x][y].up&&y!=1){
                                                success=1;
                                                _map[x][y].up=0;
												_map[x][y].asciiValue = 178;
                                        }
                                        break;
                                case DOWN:
                                        if(_map[x][y+1].up&&y!=y-2){
                                                success=1;
                                                _map[x][y+1].up=0;
												_map[x][y+1].asciiValue = 178;
                                        }
                                        break;
                                case LEFT:
                                        if(_map[x][y].left&&x!=1){
                                                success=1;
                                                _map[x][y].left=0;
												_map[x][y].asciiValue = 178;
                                        }
                                        break;
                                case RIGHT:
                                        if(_map[x+1][y].left&&x!=x-2){
                                                success=1;
                                                _map[x+1][y].left=0;
												_map[x+1][y].asciiValue = 178;
                                        }
                                        break;
                                }
                        }while(!success);
                }

		        /*while( _map[x][y-1].in&&_map[x][y+1].in&& _map[x-1][y].in&&_map[x+1][y].in )
				{
                    //If all the neighbourhood cells are in, backtrack.
                    int x2 = _map[x][y].prevx;
                    y = _map[x][y].prevy;
                    x = x2;
                }*/
				
				do{
                        //randomly find a cell that's in the maze
                        x=rand()%(max_row()-1)+1;
                        y=rand()%(max_col()-1)+1;
                }while(!_map[x][y].in ||
                        _map[x][y-1].in&&_map[x][y+1].in&&
                        _map[x-1][y].in&&_map[x+1][y].in);
			
				do{
                     //Randomly grow the _map if possible.
                     success=0;
                     whichway=rand()%4;
                     
					 switch(whichway) {

                        case UP:
                                if(!_map[x][y-1].in){
                                        success=1;
                                        _map[x][y].up=0;
										_map[x][y].asciiValue = 178;
                                        _map[x][y-1].prevx=x;
                                        _map[x][y-1].prevy=y;
                                        y--;

                                }
                                break;
                        case DOWN:
                                if(!_map[x][y+1].in){
                                        success=1;
                                        _map[x][y+1].up=0;
										_map[x][y+1].asciiValue = 178;
                                        _map[x][y+1].prevx=x;
                                        _map[x][y+1].prevy=y;
                                        y++;
                                }
                                break;
                        case LEFT:
                                if(!_map[x-1][y].in){
                                        success=1;
                                        _map[x][y].left=0;
										_map[x][y-1].asciiValue = 178;
                                        _map[x-1][y].prevx=x;
                                        _map[x-1][y].prevy=y;
                                        x--;
                                }
                                break;
                        case RIGHT:
                                if(!_map[x+1][y].in){
                                        success=1;
                                        _map[x+1][y].left=0;
										_map[x+1][y].asciiValue = 178;
                                        _map[x+1][y].prevx=x;
                                        _map[x+1][y].prevy=y;
                                        x++;
                                }
                                break;
					 }

                } while(!success);
                
						
				_map[x][y].in=1;
                
				numin++; //Every iteration of this loop, one _map cell is added to the _map.
		
		}while(numin<(max_row()-2)*(max_col()-2));
	
	
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	



