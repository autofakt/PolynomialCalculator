/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include "Polynomial.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int
main ()
{
  try
  {
    cout << "Welcome to Mike's polynomial calculator" << endl;

    ifstream inFile;
    inFile.open ("input.txt");
    if (!inFile)
      {
	cout << "Unable to open file datafile.txt";
	exit (1);
      }
    Polynomial polynomial;


    while (!inFile.eof ())
      {
	polynomial.readFile (inFile);
      }

    polynomial.showPoly ();
    polynomial.showData ();

    inFile.close ();

    inFile.open ("input2.txt");
    if (!inFile)
      {
	cout << "Unable to open file datafile.txt";
	exit (1);
      }
    Polynomial polynomial2;


    while (!inFile.eof ())
      {
	polynomial2.readFile (inFile);
      }

    polynomial2.showPoly ();
    polynomial2.showData ();
    inFile.close ();
  }
  catch (const char *msg)
  {
    cout << msg << endl;
  }
  return 0;
}
