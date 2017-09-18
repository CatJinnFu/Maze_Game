#include "HiScore.h"
#include <fstream>
#include <sstream>

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
 * File: HiScore.cpp
 * Author:	 D. Schmid			Date Created:	7/10/2011
 * Last Modified by:				Date Modified:	
 * 
 * Comments:
 *
 * This could have been my prac8, you can see the sort headaches(which is what i have now
 * trying to bang this up with a few hours left. cbf. oh well i tried.) function 
 * disabled in my beta version
 * It does however display and store and write and read scores to a file! yay
 *******************************************************************
*/



HiScore::HiScore(){

}

HiScore::HiScore(string filename){

		nameOfFile	= filename;		
		loadHiScore();
		ofd.close();
}
	
	
HiScore::~HiScore(){}


//was going sort score but ran out of time and just end up bloating out like hell
//could have gone the vector anyways - it just displays scores now
void HiScore::sortHiScore(){
		
		
	/*	//line will probably be 22
		
		char num[3];
		int * solutions;
		string * lines;

		ifstream b_file (nameOfFile);

		int size = 0;
		int i = 0;

		string line;
		string store;

		while (!b_file.eof())
		{
			//cout << "working 1" << endl;
			char test[25];
			b_file.getline(test, 25);
			size++;
			//cout << "working 2" << endl;
		}

		solutions = new int[size];
		lines = new string[size];
		
		//yeah running outta time so what you can do but code like extra fast spagetti
		ifstream c_file (nameOfFile);
		
		//cout << "working 2.1" << endl;

		while ( !c_file.eof() )
		{
			cout << "working 2.2" << endl;
			
			
			char str[25];
			c_file.getline(str,25);

			cout << "working 2.3" << endl;

		  if(str != NULL)
		  {
			cout << "working 2.4" << endl;
			  
			cout << str[0] << "wtf" <<endl;
			
			if(str[8] != 0 && str[8] != NULL){
				num[0]=str[8];
			}
			if(str[9] != 0 && str[9] == NULL){
				num[1]=str[9];
			}
			if(str[10] != 0 && str[10] == NULL){
				num[2]=str[10];
			}
			cout << "working 3" << endl;
			stringstream  score;
			score << num[0] << num[1] << num[2];
			score >> solutions[i];
			
			cout << "working 4" << endl;
			stringstream  line;
			line << * str;
			cout << "working 4.1" << * str << endl;
			lines[i] = line.str(); 
			cout << "working 5" << endl;
			i++;
		  }	
		}

		
		//cause the blank size = -2;
		bubbleSort(solutions,size-2,lines);

		cout << "working 6" << size-1 << endl;
			

		ofd.open(nameOfFile);

		if(!ofd){
			cerr << " cannot open Hi-Score file ";
		}
		else{
			//ofd << "HIGH SCORES" << endl;

			for(int i = 0; i < size-2; i++)
			{
				ofd << lines[i];
			
			}
		}

		ofd.close();
	*/
	
}

void HiScore::loadHiScore(){
	
		ofd.open(nameOfFile,ios::app);

		if(!ofd){
			cerr << " cannot open Hi-Score file ";
		}

}

void HiScore::addPlayerScore(Player * p) { 
		
		loadHiScore();
		ofd << *p <<endl;
		ofd.close();
}


void HiScore::displayHiScore()
{
	ifstream b_file(nameOfFile);
	
	string str;

	cout << "PLAYER SCORES" <<endl;

	while (!b_file.eof() )
	{
		getline(b_file,str);
		cout << str <<endl;

	}

}


//helps sort the scores not used
void HiScore::bubbleSort(int *array,int length,string *toBeSorted)//Bubble sort function 
{
    int i,j;

    for(i=0;i<10;i++)
    {
        for(j=0;j<i;j++)
        {
            if(array[i]>array[j])
            {
                cout << "working 5.1" << i << endl;
				int temp = array[i]; //swap 
				string stemp = toBeSorted[i];
                array[i] = array[j];
				toBeSorted[i] = toBeSorted[j];
                array[j] = temp;
				toBeSorted[j] = stemp;
            }

        }

    }

}