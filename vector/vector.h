#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

using namespace std;
template<typename T> // Assume Vector only takes in int or double for T
class Vector {
private:
  int sz = -1; 	// the number of elements in this Vector
  T* buf = nullptr; 	// the base of the array of Ts, you must allocate it
public:
  Vector(int n) // Vector v1(10); -- create a 10 element Vector
  {
    sz  = 1;
    buf = new T(n);
  }
  Vector(initializer_list<T> L) // Vector v1{T1, T2, T3};
  {
    int counter = 0;
    sz  = L.size();
    buf = new T[sz];
    for(auto itr: L)
    {
      buf[counter] = itr;
      counter += 1;
    }
  }
  ~Vector() /* destructor called automatically when a Vector dies */
  {
    if(sz == 1)
      delete buf;
    else
      delete[] buf;
  }
/*Destructor should free memory used. your program should have no leak/lost/still-reachable/errors(suppressed or not), besides 72704 bytes in one still-reachable block (a g++/valgrind bug on some versions). */
  Vector(const Vector & v) // Vector v2(v1); deep-copy
  {
    if(sz == 1)
      delete buf;
    else
      delete[] buf;
    buf = nullptr;
    sz  = v.size();
    buf = new T[sz];
    for(int i=0; i<sz; i++)
    {
      buf[i] = v[i];
    }
  }
  int size() const // v1.size() returns 10 for v1 example above
  {
    return sz;
  }
  T & operator [] (const int i) const /* T x = V[i]; */
  {
    if(i > sz)
    {
      throw std::out_of_range("Out of bounds");
    }
    else
      return buf[i];
  }
/*Access out-of-bound index should throw an error to be caught in outside scope */
  T operator * (const Vector & v) const
  {
    int result = 0;
    if(this->sz == v.size())
    {
      for(int i=0; i<sz; i++)
      {
        result = result + (this->buf[i] * v[i]);
      }
    }
    else if (this->sz > v.size())
    {
      for(int i=0; i<v.size(); i++)
      {
        result = result + (this->buf[i] * v[i]);
      }
    }
    else
    {
      for(int i=0; i<this->sz; i++)
      {
        result = result + (this->buf[i] * v[i]);
      }
    }
    return result;
  }
// T x = V1 * V2; dot product
// e.g. [1, 2] * [3, 4, 5] = 1 * 3 + 2 * 4 + 0 = 11
// Assume an empty Vector will cause the product to be 0.
  Vector operator + (const Vector & v) const 
// V3 = V1 + V2; [1, 2, 3] + [4, 5, 6, 7] = [5, 7, 9, 7]
  {
    if(this->sz == v.size())
    {
      Vector copy = v;
      for(int i=0; i<sz; i++)
      {
        copy[i] = (this->buf[i] + v[i]);
      }
    }
    else if (this->sz > v.size())
    {
      Vector copy = *this;
      for(int i=0; i<v.size(); i++)
      {
        copy[i] = (this->buf[i] + v[i]);
      }
    }
    else
    {
      Vector copy = v;
      for(int i=0; i<this->sz; i++)
      {
        copy[i] = (this->buf[i] + v[i]);
      }
    }
    return copy;
  }
  const Vector & operator = (const Vector & v) // V1 = V2;
  {
    if(sz == 1)
      delete buf;
    else
      delete[] buf;
    buf = nullptr;
    sz  = v.size();
    buf = new T[sz];
    for(int i=0; i<sz; i++)
    {
      buf[i] = v[i];
    }
    return *this;
  }

  bool operator == (const Vector & v) const // if (V1 == V2)...
  {
    if(this->sz == v.size())
    {
      for(int i=0; i<v.size(); i++)
      {
        if(buf[i] == v[i])
          return false;
      }
    }
    else
    {
      return false;
    }
  }

  bool operator != (const Vector & v) const // if (V1 != V2)...
  {
    if(this->sz == v.size())
    {
      for(int i=0; i<v.size(); i++)
      {
        if(buf[i] != v[i])
          return true;
      }
    }
    else
    {
      return true;
    }
  }
  friend Vector operator * (const int n, const Vector & v)
  // V1 = 20 * V2; -- each element of V1 is element of V2 * 20
  {
    Vector copy = v;
    for(int i=0; i<v.size();i++)
    {
      copy[i] = n * v[i];
    }
    return copy;
  }
  friend Vector operator + (const int n, const Vector & v)
  // V1 = 20 + V2; -- each element of V1 is element of V2 + 20
  {
    Vector copy = v;
    for(int i=0; i<v.size();i++)
    {
      copy[i] = n + v[i];
    }
    return copy;
  }
  friend ostream& operator << (ostream & o, const Vector & v)
  // cout << V2; -- prints the vector in this format 
  // (v0, v1, v2, ... vn-1);
  {
    o << "(";
    for(int i=0; i<v.size(); i++)
    {
      if(i == v.size()-1)
      {
        o << v[i];
        break;
      }
      o << v[i] << ", ";
    }
    o << ")";
    return o;
  }
};

#endif