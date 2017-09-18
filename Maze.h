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
 * File: Maze.h
 * Author:	 D. Schmid			Date Created:	7/10/2011
 * Last Modified by:				Date Modified:	
 * 
 * Comments:
 *
 * Look at all the stuff this does, there is just stuff here that not needed
 * manage to get some out of it.
 *******************************************************************
*/


#include <iostream>
#include <string>

#ifndef MAZE_H
#define MAZE_H

#define UP 0     //-y
#define DOWN 1   //+y
#define LEFT 2   //-x
#define RIGHT 3  //+x

using namespace std;

class Maze
{
	

		friend ostream & operator << (ostream & out, Maze & m);
		friend istream & operator >> (istream & in, Maze & m);

		struct cell{
			  bool in;  //Is this cell in the maze?
			  bool up;  //Does the wall above this cell exist?
			  bool left;//Does the wall to the left of this cell exist?
			  bool right;  //Does the wall above this cell exist?
			  bool down;//Does the wall to the left of this cell exist?
			  int prevx, prevy; //The coordinates of the previous cell, used for backtracking.
			  unsigned char asciiValue;
	    };

	    struct start{
		      int x;
		      int y;
	    };

	    struct end{
		     int x;
		     int y;
	    };


        public :
				Maze();
				Maze(int rows, int cols);
				~Maze();

				//methods
				int max_row() const;
				int max_col() const;
	
				char getAscii(int row, int col);
				bool getIn(int row, int col);
				bool getUp(int row, int col);
				bool getLeft(int row, int col);

				//old functions I made that are redundant.
				//bool is_passible(int i, int j) const;
				void mark(int row, int col);
			
				bool setEnd(int x, int y);
				bool getEnd(int & x, int & y);

				bool Completed();
				void flagComplete();
			

				bool collisionDetection(int upX, int upY);

		protected :
				//static const int MAX_MAZE_DIM = 30;
				static const unsigned char pTile = 219;
				static const unsigned char marker = 178;
				int _max_row;
				int _max_col;
				int e_row;
				int e_col;
				start s;
				end e;
				cell _map[100][100];
				bool complete;

};

#endif