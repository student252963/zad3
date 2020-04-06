#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include <iostream>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class MacierzKW {

  Wektor tab[ROZMIAR];

public:

  MacierzKw();
  MacierzKw(const Wektor & tab[]);
  MacierzKw(Wektor A, Wektor B, Wektor C);

  double wyznacznik();// rozwiniecje laplace'a, gaussa, sarrusa
  // double wyznacznikGauss(); double wyznacznik(metoda met = Gauss) <- enum

  int rzad();

  const MacierzKw & transponuj() const;
  void transponuj();

  const MacierzKw & odwroc() const;
  void odwroc();
  
  const MacierzKw & operator*(const MacierzKw & M2);
  const MacierzKw & operator+(const MacierzKw & M2);
  const MacierzKw & operator-(const MacierzKw & M2);
  const MacierzKw & operator*(double l);
  const Wektor & operator*(const Wektor & W2);
  const MacierzKw & operator*(double l, const MacierzKw & M2);

  const Wektor & operator[] (ind index) const;
  Wektor & operator[] (ind index); // M[2][0] - zerowy element, drugiego wektora
  
};



/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &Strm, Macierz &Mac);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);


#endif
