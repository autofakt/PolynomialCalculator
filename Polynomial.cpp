#include "Polynomial.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

void
Polynomial::readFile (istream & inFile)
{
  string oneLine;
  getline (inFile, oneLine);
  int pos = oneLine.find_first_of (' ');
  string coef = oneLine.substr (0, pos);
  string expo = oneLine.substr (pos + 1);
  int coefInt = stoi (coef);
  int expoInt = stoi (expo);
  addTerm (coefInt, expoInt);
}


void
Polynomial::addTerm (int coef, int expo)
{
  if (checkDuplicate (coef, expo) == false)
    {
      int tempCounter = numberOfTerms();
      poly[tempCounter].m_coefficient = coef;
      poly[tempCounter].m_exponent = expo;
      
    }
  else
    throw "duplicate term found";
}

int
Polynomial::numberOfTerms ()
{
  int numberOfTerms = 0;
  for (int i = 0; i < 10; i++)
    {
      if (poly[i].m_exponent == 0 && poly[i].m_coefficient == 0)
	    {
	    }
      else
	numberOfTerms++;
    }
  return numberOfTerms;
}

bool
Polynomial::checkDuplicate (int coef, int expo)
{
  for (int i = 0; i < numberOfTerms (); i++)
    {
      if (poly[i].m_coefficient == coef && poly[i].m_exponent == expo)
	return true;
    }
  return false;
}

void
Polynomial::showPoly ()
{
  int temp, temp2;
  for (int i = 0; i <= numberOfTerms (); i++)
    {
      for (int j = 0; j <= numberOfTerms () - i; j++)
	{
	  if (poly[j].m_exponent < poly[j + 1].m_exponent)
	    {
	      temp = poly[j].m_exponent;
	      temp2 = poly[j].m_coefficient;
	      poly[j].m_exponent = poly[j + 1].m_exponent;
	      poly[j].m_coefficient = poly[j + 1].m_coefficient;
	      poly[j + 1].m_exponent = temp;
	      poly[j + 1].m_coefficient = temp2;
	    }
	}
    }
  cout << "-------------------------------" << endl;
  for (int i = 0; i < numberOfTerms (); i++)
    cout << poly[i].m_coefficient << "x" << "^" << poly[i].m_exponent << "+";
  cout << endl;
  cout << "-------------------------------" << endl;
}

int
Polynomial::coefficient (int power)
{
  if (power < 0)
    throw "exponent cannot be a negative number when calling coefficient()";
  int coefficient = 0;
  for (int i = 0; i < 10; i++)
    {
        if (poly[i].m_exponent == power)
	    {
	  coefficient = poly[i].m_coefficient;
	  return coefficient;
	    }
    }
  return 0;
}

int
Polynomial::degree ()
{
  int degree = 0;
  for (int i = 0; i < 10; i++)
    {
      if (poly[i].m_exponent > degree)
	degree = poly[i].m_exponent;
    }
  return degree;
}

int
Polynomial::value (int x)
{
  int sum = 0;
  for (int i = 0; i < 10; i++)
    {
      sum += (poly[i].m_coefficient * pow (x, poly[i].m_exponent));
    }
  return sum;
}

void
Polynomial::showData ()
{
  cout << "Degree: " << degree () << endl;
  cout << "# of terms: " << numberOfTerms () << endl;
  for (int i = 0; i < 8; i++)
    cout << "Coeff(" << i << "): " << coefficient (i) << endl;
  for (int j = 1; j < 3; j++)
  {
    cout << "Value(" << j << "): " << value (j) << endl;
  }
}