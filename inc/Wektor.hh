#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>



class Wektor {

  double tab[ROZMIAR];
  
public:

  Wektor(); //done
  Wektor(double x, double y, double z); //done
  Wektor(double table[]); //done
  
  double dlugosc() const;
  double operator * (const Wektor & W2) const; // skalarnie
  
  /* Wektor & operator += (const Wektor & W2);     // W1 += W2  , W1 += W3 += W4 */

  
  Wektor operator + (const Wektor & W2) const; // W1 + W2
  Wektor operator - (const Wektor & W2) const; // W1 - W2  
  Wektor operator * (double l) const; // W1 * liczba
  Wektor operator / (double l) const; // W1 / liczba
  
  bool operator == (const Wektor & W2) const;
  bool operator != (const Wektor & W2) const;

  const double & operator[] (int index) const;  //done
  double & operator[] (int index); //done
      
};



Wektor operator * (double l, Wektor W2); // liczba * W2



std::istream& operator >> (std::istream &Strm, Wektor &Wek);



std::ostream& operator << (std::ostream &Strm, const Wektor &Wek);



#endif
