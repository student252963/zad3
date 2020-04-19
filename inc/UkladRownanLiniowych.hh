#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Macierz.hh"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class UkladRownanL {
  MacierzKw A;
  Wektor B;
public:
  UkladRownanL() {MacierzKw A; Wektor B;}
  UkladRownanL(MacierzKw AA, Wektor BB) {this->A=AA; this->B=BB;}

  const MacierzKw zwroc_macierz() const {return A;}
  void zmien_macierz(const MacierzKw & AA) {this->A=AA;}

  const Wektor zwroc_wektor() const {return B;}
  void zmien_wektor(const Wektor & BB){this->B=BB;}

  Wektor oblicz();
};


std::istream& operator >> (std::istream &Strm, UkladRownanL &UklRown);


std::ostream& operator << (std::ostream &Strm, const UkladRownanL &UklRown);


#endif
