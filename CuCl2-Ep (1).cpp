
#include "iostream"
#include "cmath"
#include "iomanip"
#include "fstream"

using namespace std;

float densitas;         /*densitas ini memiliki satuan g cm^-3
                          dan ini harus diinput dari user */
// converter dari nilai cm^-3 ke A^3
float cm3_to_A3 = 1.0E-24;
float numb_mol;
float Na = 6.022E23;            // bilangan avogadro
float Mr_tembaga= 134,5;         // massa relatif dari tembaga
int numb_lat;                   // panjang sel simulasi
int N;                          // jumlah molekul
float volum;                    // volume dari molekul tembaga
float lx, ly, lz;               // panjang sel simulasi terhitung 
float lat;                      // jarak antar molekul tembaga

// variabel perhitungan energi potensial
float sigma = 2.725;            // satuan (A)
float epsilon = 3.725;          // satuan (kj/mol)
float rij, rcut, rcut2;
float Ep, Ep_LJ, A12, B6;
float rij6, rij12;
float dx, dy, dz;

int main(){
    
    rcut = 3 * sigma;
    rcut2 = pow(rcut,2);
    
    cout << "program menghitung energi potensial dari tembaga" << endl;
    cout << "Masukkan nilai densitas dari tembaga (eg. 1.0): ";
    cin >> densitas;

    numb_mol = densitas * (Na / Mr_tembaga) * cm3_to_A3;
    cout << "Masukkan panjang sel simulasi (eg. 5): ";
    cin >> numb_lat;
    N = (pow(numb_lat,3)) * 3;
    volum = (float)N / numb_mol;

    // panjang sel simulasi secara perhitungan
    lx = pow(volum,(1.0/3.0));
    ly = lx;
    lz = lx;
    if(lx < (2*rcut)){
        cout << "sorry mazeh, sel simulasi kamu besar";
        exit(0);
    } else{
        cout << "panjang sek simulasi baru: " << lx << endl;
    }
    lat = lx / (float)numb_lat;

    // deklarasi variabel
    float pi = 3.14;
    
    // deklarasi senyawa tembaga
    float Cux[125], Cuy[125], Cuz[125];
    float Cl1x[125], Cl1y[125], Cl1z[125];
    float Cl2x[125], Cl2y[125], Cl2z[125];

    /* Cl-Cu-Cl
      senyawa tembaga itu bentuk rigid
    */