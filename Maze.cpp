#include "Maze.h"

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
 * File: Maze.cpp
 * Author:	 D. Schmid			Date Created:	7/10/2011
 * Last Modified by:				Date Modified:	
 * 
 * Comments:
 *
 * The less said the better - works but!... does a lot of cool stuff
 * even overloaded the << so it can be written to a file easily
 * never did however. Maybe I should make my maze printable ...hmm
 *******************************************************************
*/

Maze::Maze()
{
  _max_row = 7;
  _max_col = 7;
   complete =false;


        //Initialize the maze!
        for(int x=0;x<_max_row;x++){
                for(int y=0;y<_max_col ;y++){
                        //The maze cells on the edges of the maze are "in" to provide padding. Otherwise, all maze cells are not in.
                        _map[x][y].in   = (x==0||x==_max_row-1||y==0||y==_max_col -1)?1:0;
                        //All maze cells have all walls existing by default, except the perimeter cells.
                        _map[x][y].up   = (x==0||x==_max_row-1||y==0)?0:1;
                        _map[x][y].left = (x==0||y==0||y==_max_col-1)?0:1;
						_map[x][y].asciiValue = pTile;
                }
        }
}


Maze::Maze(int rows, int cols)
{
  //if (rows > MAX_MAZE_DIM || cols > MAX_MAZE_DIM)
   // throw "Attempted to create overly large Maze";

  _max_row = rows;
  _max_col = cols;
  complete =false;
  
  //Initialize the maze!
        for(int x=0;x<_max_row;x++){
                for(int y=0;y<_max_col ;y++){
                        //The maze cells on the edges of the maze are "in" to provide padding. Otherwise, all maze cells are not in.
                        _map[x][y].in   = (x==0||x==_max_row-1||y==0||y==_max_col -1)?1:0;
                        //All maze cells have all walls existing by default, except the perimeter cells.
                        _map[x][y].up   = (x==0||x==_max_row-1||y==0)?0:1;
                        _map[x][y].left = (x==0||y==0||y==_max_col-1)?0:1;
						_map[x][y].asciiValue = pTile;
                }
        }
}

Maze::~Maze(){}

int Maze::max_row() const { return _max_row; }

int Maze::max_col() const { return _max_col; }

char Maze::getAscii(int row, int col) { return _map[row][col].asciiValue;}

bool Maze::getIn(int row, int col){return _map[row][col].in;};
bool Maze::getUp(int row, int col){return _map[row][col].up;};
bool Maze::getLeft(int row, int col){return _map[row][col].left;};

//mark as a area the player can traverse
void Maze::mark(int row, int col)
{
  _map[row][col].asciiValue = 178;
  
}




//mark the exit
bool Maze::setEnd(int x, int y){
		
	if(getIn(x,y)){
		e.x = x;
	    e.y = y;
		return true;
	}else return false;

}


bool Maze::getEnd(int & x, int & y){
		
	if(getIn(x,y)){
		x = e.x;
	    y = e.y;
		return true;
	}else return false;

}

void Maze::flagComplete(){
		
	complete = true;

}

bool Maze::Completed(){
		
	if(complete) return true;
	else return false;
	
}

//return false if your trying to move into a wall 
bool Maze::collisionDetection(int upX, int upY)
{
		if(upX%2 == 1 && upY%2 == 1)
		{
						
			if(getIn(upX/2+1,upY/2+1)) {
								return true; 
			}
							else return false;  

		}
		else if(upX%2 == 0 && upY%2 == 0){
                 return false; 
		}
		else if(upX%2 == 0 && upY%2 == 1)
		{
                                
			if(getLeft(upX/2+1,upY/2+1)) return false; 
								else { return true; }
		}
		else if(upX%2 == 1 && upY%2 == 0)
		{
                                if(getUp(upX/2+1,upY/2+1))  return false; 
								else{
									return true; 
								}
		}else return true;
}

ostream& operator<<(ostream& stream, Maze & m)
{ 
  //not so simple cause we need to have some sort of a wall.
  
  for(int row = 0; row <= m.max_row(); row++)
   { 
		for(int col = 0; col <= m.max_col(); col++)
		{
			if(row%2 == 1 && col%2 == 1)//we do sumthin differnet if odd. 
			{	
                  if(m._map[row/2+1][col/2+1].in) stream.put(m.marker); 
				  else stream.put(m.pTile);
            }else if(row%2 == 0 && col%2 == 0){
                                stream.put(m.pTile);
            }else if(row%2 == 0 && col%2 == 1){
                                if(m._map[row/2+1][col/2+1].left) stream.put(m.pTile);
								else stream.put(m.marker); 
            }else if(row%2 == 1 && col%2 == 0){
                                if(m._map[row/2+1][col/2+1].up) stream.put(m.pTile);
								else stream.put(m.marker); 
            }
            
	    }

		stream << endl;	
	}
  
  
  stream << flush;
  return stream;
}


istream& operator>>(istream& stream, Maze& m)
{ 
	char ch;

  for(int row = 1; row <= m._max_row; row++)
    { 
      for(int col = 1; col <= m._max_col; col++)
	{ 
	  stream.get(ch);
	  if (ch == '.' || ch == ' ')
	    m._map[row][col].asciiValue = m.pTile;
	  else
	    m._map[row][col].asciiValue = '*';
	}
      stream.ignore(50,'\n');
    }
  return stream;
}

