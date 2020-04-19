#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"



using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{
  UkladRownanL UklRown;   // To tylko przykladowe definicje zmiennej
  MacierzKw A;

  
  cout << endl << " Start programu " << endl << endl;

  fstream plik;
  plik.open("dane.txt" , ios::in);
  if(plik.good()!=true) {
    cout << "Nie znaleziono pliku :<"<<endl;
    return 0;
  }
  cin >> UklRown;
  plik.close();

  cout << "Macierz A^T:" << endl;

  cout << UklRown.zwroc_macierz() << endl;

  cout << "Wektor wyrazow wolnych b:" << endl;

  cout << UklRown.zwroc_wektor() << endl;

  cout << "Rozwiazanie x=(x1,x2,x3):" << endl;
  cout << UklRown.oblicz();



  return 0;
}
  
