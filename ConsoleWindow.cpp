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
 * File: ConsoleWindow.cpp
 * Author:	S. Bangay	& D. Schmid			Date Created:	2/09/2011
 * Last Modified by:				Date Modified:	
 * 
 * Comments:
 *
 * The Class method definitions for the ConsoleWindow object. Modified
 * for the Choas Maze Game
 *******************************************************************
*/

#include "ConsoleWindow.h"

using namespace std;

ConsoleWindow::ConsoleWindow(void)
{
	hStdout = GetStdHandle( STD_OUTPUT_HANDLE); // Get the Screen handle
	hStdin = GetStdHandle(STD_INPUT_HANDLE);	// Get Input handle.

	key = '\0';
}


ConsoleWindow::~ConsoleWindow(void)
{
}

void ConsoleWindow::clearWindow ()

{
	COORD coordScreen = { 0, 0 };    /* here's where we'll home the cursor */ 
	BOOL bSuccess;
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */ 
	DWORD dwConSize;                 /* number of character cells in the current buffer */ 

	/* get the number of character cells in the current buffer */ 
	bSuccess = GetConsoleScreenBufferInfo( hStdout, &csbi );
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

	/* fill the entire screen with blanks */ 
	bSuccess = FillConsoleOutputCharacter( hStdout, (TCHAR) ' ', 
		dwConSize, coordScreen, &cCharsWritten );
}

int ConsoleWindow::getWindowRight ()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */ 
	GetConsoleScreenBufferInfo (hStdout, &csbi);
	return csbi.srWindow.Right;
}

int ConsoleWindow::getWindowLeft ()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */ 
	GetConsoleScreenBufferInfo (hStdout, &csbi);
	return csbi.srWindow.Left;
}

int ConsoleWindow::getWindowTop ()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */ 
	GetConsoleScreenBufferInfo (hStdout, &csbi);
	return csbi.srWindow.Top;
}

int ConsoleWindow::getWindowBottom ()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */ 
	GetConsoleScreenBufferInfo (hStdout, &csbi);
	return csbi.srWindow.Bottom - 1; // avoid the last row - can be problematic.
}

void ConsoleWindow::putChar (unsigned char c, int x, int y, WORD	wColour)
{
	
	
	COORD coordScreen;
	coordScreen.X = oldX;
	coordScreen.Y = oldY;
	SetConsoleCursorPosition( hStdout, coordScreen );
	//cout << ' ';
	
	
	coordScreen.X = x;
	coordScreen.Y = y;
	SetConsoleCursorPosition( hStdout, coordScreen );
	SetConsoleTextAttribute(hStdout, wColour);
	cout << c;

	oldX = x;
	oldY = y;

}

void ConsoleWindow::putString (string s, int x, int y, WORD	wColour)
{
	
	
	COORD coordScreen;
	coordScreen.X = oldX;
	coordScreen.Y = oldY;
	SetConsoleCursorPosition( hStdout, coordScreen );
	//cout << ' ';
	
	
	coordScreen.X = x;
	coordScreen.Y = y;
	SetConsoleCursorPosition( hStdout, coordScreen );
	SetConsoleTextAttribute(hStdout, wColour);
	cout << s;

	oldX = x;
	oldY = y;

}


void ConsoleWindow::drawBorder (char c)

{
	for (int i = getWindowLeft (); i <= getWindowRight (); i++)
	{
		putChar (c, i, getWindowBottom ());
		putChar (c, i, getWindowTop ());
	}
	for (int i = getWindowTop (); i <= getWindowBottom (); i++)
	{
		putChar (c, getWindowLeft (), i);
		putChar (c, getWindowRight (), i);
	}
}

char ConsoleWindow::getLastKey ()

{
	return key;
}

void ConsoleWindow::nextKey ()

{
  key = '\0';

  INPUT_RECORD keystroke;
  DWORD numRead;
  PeekConsoleInput (hStdin, &keystroke, 1, &numRead);
  if (numRead > 0)
	{
    	ReadConsoleInput (hStdin, &keystroke, 1, &numRead);
		if ((keystroke.EventType == KEY_EVENT) && (keystroke.Event.KeyEvent.bKeyDown))
			{
				key = keystroke.Event.KeyEvent.uChar.AsciiChar;
			}
	}
}

void ConsoleWindow::switchCursor (bool On)
{
	
	CONSOLE_CURSOR_INFO concurinfo;

	if(On){ 
		concurinfo.dwSize = 100;
		concurinfo.bVisible = true;
	}
	else { 
		concurinfo.dwSize = 100;
		concurinfo.bVisible = false;
	}
	
	SetConsoleCursorInfo(hStdout, &concurinfo);


}