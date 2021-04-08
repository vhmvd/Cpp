#ifndef COMPLE_X_
#define COMPLE_X_

#include <cmath>
#include <iostream>
using std::ostream;
using std::istream;

class complex
{
  // private data members
private:
  double _real;
  double _imaginary;
public:
 // pubblic methods
  complex();
  complex         operator+ (const complex&);
  complex         operator- (const complex&);
  complex         operator* (const complex&);
  complex         operator/ (const complex&);
  bool            operator==(const complex&);
  friend ostream& operator<<(ostream&, const complex&);
  friend istream& operator>>(istream&, complex&);

};

#endif