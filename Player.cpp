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
 * File: Player.cpp
 * Author:	 D. Schmid			Date Created:	7/10/2011
 * Last Modified by:				Date Modified:	
 * 
 * Comments:
 *
 * All the player code - function self explanatory. B
 * The code for movement and collosion works really well (cause its mine)
 * but the crap maze algorithmns I used from wikki make it look rather bloated
 * and hacked up - next time - mental note maze gen code from scratch
 *******************************************************************
*/



#include "Player.h"
#include <ctime> 
#include <cstdlib>
#include <windows.h>


 
Player::Player(){
	
	name = "Player1";
	Tile = 223;
	score =0;
	coins =0;

}


void Player::addCoins(int amount){
	coins = coins + amount;
}


void Player::addScore(int amount){
	score = score + amount ;
}


Player::Player(string n, unsigned char t){	

	name = n;
	Tile = t;
	score =0;
	coins =0;
	
}

Player::~Player(){}

bool Player::setStartPos(int row, int col, Maze & m){

	x = row;
	y = col;
	
	//cout << "Ascii Code : " << m.getAscii(row, col) << endl;

	if(m.getAscii(row, col) == 178) return true;
	else return false;
}


void Player::setPos(int row, int col){
	 x = row;
	 y = col;
}

void Player::getPos(int & row, int & col){
	 
	row = x;
	col = y;
}

int Player::getCoins(){
return coins;
}

int Player::getScore(){
return score;
}

//Moves up in the maze
bool Player::moveUp(Maze & m,vector<VirtualItem *> & v){
	
	int upX = x;
	int upY = y-1;
	int endX = 0;
	int endY = 0;

	m.getEnd(endX,endY);	
	checkItem(upX, upY,v);

	if(upX == endX && upY == endY) {m.flagComplete();}

	return m.collisionDetection(upX,upY);



}

//Moves down in the maze
bool Player::moveDown(Maze & m,vector<VirtualItem *>  &v){
        
	//for(int i = 0; i < 71; i++)
		//for(int j = 0;  j < 21; j++)
			//cout << " Down Value \d" << m.getAscii(x,y+1) << " x value " <<x << " y value " << y << endl;
	//cout << " DOWN Value " << m.getAscii(x,y+1) << "**" << endl;

		 int upX = x;
		int upY = y+1;

	 	int endX = 0;
		int endY = 0;
		
		m.getEnd(endX,endY);
		checkItem(upX, upY,v);
		
		if(upX == endX && upY == endY) {m.flagComplete();}


    return m.collisionDetection(upX,upY);


}

//moves left in the maze
bool Player::moveLeft(Maze & m,vector<VirtualItem *> & v){
			
		//cout << " LEFT Value " << m.getAscii(x-1,y) << " in " << "**" << endl;	
		
		int upX = x-1;
		int upY = y;

		int endX = 0;
		int endY = 0;
		

		m.getEnd(endX,endY);
		checkItem(upX, upY,v);
		
		if(upX == endX && upY == endY) {m.flagComplete();}

		return m.collisionDetection(upX,upY);

						
	
}

string Player::getName(){ return name;}

//moves right in the maze
bool Player::moveRight(Maze & m,vector<VirtualItem *> & v){
	
	    int upX = x+1;
		int upY = y;
		
		int endX = 0;
		int endY = 0;
		
		m.getEnd(endX,endY);
		
		checkItem(upX, upY,v);

		if(upX == endX && upY == endY) {m.flagComplete();}

		return m.collisionDetection(upX,upY);

			
}

//print player details to an ostream
ostream & operator << (ostream & stream, Player & p){

	stream << p.getName() << "\t Score : " << p.getScore() << "\t Coins : "  << p.getCoins();
	//stream << endl;
	stream << flush;
	return stream;
}


// a function to check if the player has landed on an item in the maze
//it also removes that item so the player cannot end up on it again
bool Player::checkItem(int x, int y,vector<VirtualItem *> & v)
{
		vector<VirtualItem *>::iterator current;
		VirtualItem * v1;

		for (current = v.begin(); current != v.end(); ++current){
			
				v1 = *current;
		
				if(x == v1->getPosX() && y == v1->getPosY())
				{
						
						coins = coins + v1->addCoins();
						score = score + v1->getScoreValue();
						cout << v1->getDetails();
						v.erase(current);//
						return true;
						
				}
		}

		return false;

}