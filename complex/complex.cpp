#include "complex.h"

//default initialisor
complex::complex():_real(0.0), _imaginary(0.0){}

complex complex::operator+(const complex& rhs){
  complex temp = *this;
  temp._imaginary += rhs._imaginary;
  temp._real += rhs._real;
  std::cout << "Result: " << temp;
  return temp;
}

complex complex::operator-(const complex& rhs){
  complex temp = *this;
  temp._imaginary -= rhs._imaginary;
  temp._real -= rhs._real;
  std::cout << "Result: " << temp;
  return temp;
}

complex complex::operator*(const complex& rhs){
  complex temp = *this;
  temp._real = (temp._real*rhs._real - temp._imaginary*rhs._imaginary);
  temp._imaginary = (temp._real*rhs._imaginary + temp._imaginary*rhs._real);
  std::cout << "Result: " << temp;
  return temp;
}

complex complex::operator/(const complex& rhs){
  complex temp = *this;
  temp._real = (temp._real*rhs._real + temp._imaginary*rhs._imaginary) / (rhs._real*rhs._real + rhs._imaginary*rhs._imaginary);
  temp._imaginary = (temp._imaginary*rhs._real - temp._real*rhs._imaginary) / (rhs._real*rhs._real + rhs._imaginary*rhs._imaginary);
  std::cout << "Result: " << temp;
  return temp;
}

bool complex::operator==(const complex& rhs){
  complex temp = *this;
  if(fabs(temp._imaginary - rhs._imaginary) < 1e-15 && fabs(temp._real - rhs._real) < 1e-15)
  {
    return true;
  }
  return false;
}

ostream& operator<<(ostream& out, const complex& a)
{
  out << a._real << "," << a._imaginary << std::endl;
  return out;
}

istream& operator>>(istream& in, complex& a)
{
  std::cout << "Enter a complex number problem: ";
  in >> a._real;
  in.ignore();
  in >> a._imaginary;
  char op;
  in >> op;
  if(op == ' ')
  {
    in >> op;
    in.ignore();
  }
  complex temp;
  in >> temp._real;
  in.ignore();
  in >> temp._imaginary;
  if(op == '-')
  {
    a - temp;
  }
  else if(op == '+')
  {
    a + temp;
  }
  else if(op == '/')
  {
    a / temp;
  }
  else if(op == '*')
  {
    a * temp;
  }
  else
  {
    std::cout << "Inavlid fields\n\n";
  }
  return in;
}