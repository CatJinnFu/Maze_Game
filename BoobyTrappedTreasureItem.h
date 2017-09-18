/*****************************************************************
* NAME:Dieter Schmid
* STUDENT ID:211374926
* UNIT CODE:SIT 153
* ASSIGNMENT:2
* DUE DATE:07/10/2011
*
*****************************************************************
* Plagiarism and collusion
* Plagiarism occurs when a student passes off as the student�s own
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
 * File: BoobyTrappedTreasureItem.h
 * Author:	 D. Schmid			Date Created:	2/09/2011
 * Last Modified by:				Date Modified:	
 * 
 * Comments:
 *
 * Takes away score and gives coins
 *******************************************************************
*/


#include "VirtualItem.h"
#include "TreasureItem.h"
#include "BoobyTrapItem.h"


using namespace std;


#ifndef BOOBYTRAPPEDTREASUREITEM_H
#define BOOBYTRAPPEDTREASUREITEM_H



class BoobyTrappedTreasureItem : public BoobyTrapItem, public TreasureItem {

	public :
	  BoobyTrappedTreasureItem();
	  BoobyTrappedTreasureItem(int x, int y);
	  ~BoobyTrappedTreasureItem();

	  int getScoreValue();
      int addCoins();

	  string getDetails(); 
	
};

#endif