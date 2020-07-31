#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <string>
using namespace std;

struct Term
{
  int m_coefficient;
  int m_exponent;
};

class Polynomial
{
public:
Term poly[10] = { };
void addTerm (int coef, int expo);
int degree ();
int coefficient (int power);
int numberOfTerms ();
int value (int x);
void readFile (istream & inFile);
bool checkDuplicate (int coef, int expo);
void showPoly ();
void showData ();
};

#endif