#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Wektor {

  Wektor tab[ROZMIAR]
  
  public:

  Wektor();
  Wektor(double x, double y, double z);
  
  double dlugosc() const; // modul
  
  Wektor & operator += (const Wektor & W2); // W1 += W2  , W1 += W3 += W4
  const Wektor & operator + (const Wektor & W2) const; // W1 + W2
  const Wektor & operator - (const Wektor & W2) const; // W1 - W2
  double operator * (const Wektor & W2) const; // skalarnie
  
  const Wektor & operator * (double l) const; // W1 * 2
  const Wektor & operator / (double l) const; // W1 / 2
  Wektor operator *(double l, Wektor W2); // 3 * W2
  
  bool operator == (const Wektor & W2) const;
  bool operator != (const Wektor & W2) const;

  const double & operator[] (ind index) const;
  double & operator[] (ind index) {
    if (index < 0 || index > ROZMIAR) {
      cerr << "indeks poza zakresem" << endl;
      exit(1);
    }    
  }
      
};




/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &Strm, Wektor &Wek);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << (std::ostream &Strm, const Wektor &Wek);

#endif
