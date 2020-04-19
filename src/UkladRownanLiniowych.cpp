#include "UkladRownanLiniowych.hh"
#include <iostream>

using namespace std;

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy UkladRownanLiniowych, ktore zawieraja 
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */


Wektor UkladRownanL::oblicz() {

  UkladRownanL Oblicz = (*this);
  MacierzKw a = Oblicz.zwroc_macierz();
  Wektor b = Oblicz.zwroc_wektor();
  Wektor Wynik;
  double det = a.wyznacznik();

  if(det==0) {
    cerr << "Uklad nie ma rozwiazan lub zawiera nieskonczona ilosc rozwiazan" << endl;
  }
  else {
    for(int i=0 ; i < ROZMIAR ; i++) {

      A = Oblicz.zwroc_macierz();
      A[i] = b;
      double det_w = a.wyznacznik();
      Wynik[i] = det_w / det;
    }
  }
  return Wynik;
}

/************************************************/

istream& operator >> (istream &Strm, UkladRownanL &UklRown) {

  MacierzKw a;
  Wektor b;
  cin >> a >> b;
  UklRown.zmien_macierz(a.transponuj());
  UklRown.zmien_wektor(b);
  return Strm;
}


ostream& operator << (ostream &Strm, const UkladRownanL &UklRown) {

  cout << UklRown.zwroc_macierz() << UklRown.zwroc_wektor() << endl;
  return Strm;
}
  
