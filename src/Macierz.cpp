#include "Macierz.hh"

using namespace std;

/****************************************/

MacierzKw::MacierzKw() {
  
  for(int i=0 ; i < ROZMIAR ; i++) {
    for(int j=0 ; j < ROZMIAR ; j++) {
      tab[i][j]=0;
    }
  }
}


MacierzKw::MacierzKw(const Wektor table[]) {

  for(int i=0 ; i < ROZMIAR ; i++) {
    this->tab[i] = table[i];
  }
}


MacierzKw::MacierzKw(Wektor A, Wektor B, Wektor C) {

  this->tab[1] = A;
  this->tab[2] = B;
  this->tab[3] = C;
}

/**************************************/

double MacierzKw::wyznacznik() const {

  double det=1;
  MacierzKw M;
  M=(*this);
  
  for(int i=0 ; i < ROZMIAR ; i++) {
    if(M[i][i] == 0) {
      for(int j=0 ; j < ROZMIAR ; j++) {
	if(M[j][i] != 0) {
	  swap(M[j] , M[i]);
	  det *= -1;
	  j=2;
	}
      }
      if(M[i][i] == 0) {
	cerr << "Macierz osobliwa";
	det = 0;
	return det;
      }
    }
  }
  for(int i=0 ; i < ROZMIAR ; i++) {
    for(int j=i+1 ; j < ROZMIAR ; j++) {
      for(int k=i+1 ; k < ROZMIAR ; k++) {
	M[j][k] -= M[j][i] / M[i][i] * M[i][k];
      }
    }
  }
  for(int i=0 ; i < ROZMIAR ; i++) {
    det *= M[i][i];
  }
  return det;
}
  
/**************************************/

MacierzKw MacierzKw::transponuj() const {

  MacierzKw M;
  for(int i=0 ; i < ROZMIAR ; i++) {
    for(int j=0 ; j < ROZMIAR ; j++) {
      M[j][i] = tab[i][j];
    }
  }
  return M;
    }

/**************************************/

Wektor MacierzKw::operator * (const Wektor & W2) const {

  Wektor W;
  for(int i=0 ; i < ROZMIAR ; i++) {
    W[i] = this->tab[i] * W2;
  }
  return W;
}

/*************************************/

MacierzKw  MacierzKw::operator * (MacierzKw & M2) const {

  MacierzKw MIM;
  for(int i=0 ; i < ROZMIAR ; i++) {
    for(int j=0 ; j < ROZMIAR ; j++) {
      MIM[i][j] = this->tab[i] * M2.zwrocKolumna(j);
    }
  }
  return MIM;
}


MacierzKw  MacierzKw::operator + (const MacierzKw & M2) const {

  MacierzKw MSM;
  for(int i=0 ; i < ROZMIAR ; i++) {
    MSM[i] = this->tab[i] + M2[i];
  }
  return MSM;
}


MacierzKw  MacierzKw::operator - (const MacierzKw & M2) const {

  MacierzKw MRM;
  for(int i=0 ; i < ROZMIAR ; i++) {
    MRM[i] = this->tab[i] - M2[i];
  }
  return MRM;
}

/*************************************/

MacierzKw  MacierzKw::operator * (double l) const {

  MacierzKw mIloczyn;
  for(int i=0 ; i < ROZMIAR ; i++) {
    mIloczyn[i] = this->tab[i] * l;
  }
  return mIloczyn;
}
  
MacierzKw  MacierzKw::operator / (double l) const {

  if(l != 0) {
    MacierzKw mIloraz;
    for(int i=0 ; i < ROZMIAR ; i++) {
      mIloraz[i] = this->tab[i] / l;
    }
  }
    else {
      cerr << "Achtung! Es wurde versucht, die Matrix durch Null zu tailen!"
	   << endl
	   << "(   ogolnie to nie dziel przez zero >:(   )"
	   << endl;
      exit(1);
    }
}
    

/*************************************/

const Wektor & MacierzKw::operator[] (int index) const {

  if (index < 0 || index > ROZMIAR) {
      cerr << "indeks poza zakresem" << endl;
      exit(1);
    }
    else   return tab[index];
}


Wektor & MacierzKw::operator[] (int index) {
  
  if (index < 0 || index > ROZMIAR) {
      cerr << "indeks poza zakresem" << endl;
      exit(1);
    }
    else   return tab[index];
}

/************************************/

const Wektor MacierzKw::zwrocKolumna (int index) {

  if(index < 0 || index >= ROZMIAR) {
    cerr << "Indeks jest poza zakresem ;-;" << endl;
    exit(1);
  }
  else {
    Wektor wKol;
    for(int i=0 ; i < ROZMIAR ; i++) {
      wKol[i] = tab[i][index];
    }
    return wKol;
  }
}


void MacierzKw::zmienKolumna (int index, Wektor W) {

  if(index < 0 || index >= ROZMIAR) {
    cerr << "Indeks jest poza zakresem ;-;" << endl;
    exit(1);
  }
  else {
    for(int i=0 ; i < ROZMIAR ; i++) {
      tab[i][index] = W[i];
    }
  }
}

/***********************************************/

const MacierzKw operator * (double l, const MacierzKw & M2) {

  MacierzKw mIloczyn;
  for(int i=0 ; i < ROZMIAR ; i++) {
    mIloczyn[i] = M2[i] * l;
  }
  return mIloczyn;
}

/***********************************************/

istream& operator >> (istream &Strm, MacierzKw &Mac) {

  for(int i=0 ; i < ROZMIAR ; i++) {
    cin >> Mac[i];
  }
  return Strm;
}
      

ostream& operator << (ostream &Strm, const MacierzKw &Mac) {

  for(int i=0 ; i < ROZMIAR ; i++) {
    cout << Mac[i] << endl;
  }
  return Strm;
}
      
      



  
