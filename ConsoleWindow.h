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
 * File: ConsoleWindow.h
 * Author:	S. Bangay	& D Schmid			Date Created:	7/10/2011
 * Last Modified by:				Date Modified:	
 * 
 * Comments:
 *
 * The Class declaration for the ConsoleWindow object.
 *******************************************************************
*/
#include <iostream>
#include <Windows.h>
#include <string>

#ifndef CONSOLEWINDOW_H
#define CONSOLEWINDOW_H

using namespace std;
/* ConsoleWindow: an interface to the console window to make life easier when drawing
 * text based graphics. */
class ConsoleWindow
{
private:
	// The handle for output related functions.
	HANDLE hStdout; 
	// The handle for input related functions.
	HANDLE hStdin;

	// The value of the last key press.
	char key;
	int oldX;
	int oldY;

public:
	ConsoleWindow(void);
	~ConsoleWindow(void);

	// Clears the window.
	void clearWindow ();

	// Puts a character at the given coordinates on the screen.
	void putChar (unsigned char c, int x, int y, WORD wColour = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE );
	void putString (string s, int x, int y, WORD wColour = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);

	// Gets the dimensions of the window.
	int getWindowRight ();
	int getWindowLeft ();
	int getWindowTop ();
	int getWindowBottom ();

	// Draws a border around the screen, using character c.
	void drawBorder (char c);

	// Returns the last key pressed, or '\0' if no key has been pressed since last check.
	char getLastKey ();

	// Checks for a key press. Use getLastKey to retrieve the result.
	void nextKey ();

	//Dont like the cursor blinking well switch it off - False or on - True
	void ConsoleWindow::switchCursor (bool On);

	
};

#endif
