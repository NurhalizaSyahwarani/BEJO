
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
    cout <<  (eg. 5): ";
    cin >> numb_lat;
    N = (pow(numb_lat,3)) * 3;
    volum = (float)N / numb_mol;

    // 
    lx = pow(volum,(1.0/3.0));
    ly = lx;
    lz = lx;
    if(lx < (2*rcut)){
        cout << ";
        exit(0);
    } else{
        cout << ": " << lx << endl;
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

    float rB_Cux = 0.0;
    float rB_Cuy = 0.0;
    float rB_Cuz = 0.0;

    float rB_Cl1x = sin((180.0/2.0)*pi/180.0) * 180.0;
    float rB_Cl1y = 0.0;
    float rB_Cl1z = cos((180.0/2.0)*pi/180.0) * 180.0;

    float rB_Cl2x = - rB_Cl1x;
    float rB_Cl2y = rB_Cl1y;
    float rB_Cl2z = rB_Cl1z;

    // iterasi untuk setiap senyawa tembaga
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                
                Cux[counter] = rB_Cux + (i*3.01);
                Cuy[counter] = rB_Cuy + (j*3.01);
                Cuz[counter] = rB_Cuz + (k*3.01);

                Cl1x[counter] = Cux[counter] + rB_Cl1x;
                Cl1y[counter] = Cuy[counter] + rB_Cl1y;
                Cl1z[counter] = Cuz[counter] + rB_Cl1z;

                Cl2x[counter] = Cux[counter] + rB_Cl2x;
                Cl2y[counter] = Cuy[counter] + rB_Cl2y;
                Cl2z[counter] = Cuz[counter] + rB_Cl2z;

                counter += 1;
            }
        }
    }

    //
    A12 = 4.0 * epsilon * pow(sigma,12);
    B6 = 4.0 * epsilon * pow(sigma, 6);

    Ep = 0.0;
    for(int a = 0; a < (N-1); a++){
        for(int b = (0+1); b < N; b++){
            
            dx = Cux[a] - Cux[b];
            dy = Cuy[a] - Cuy[b];
            dz = Cuz[a] - Cuz[b];

            dx = dx - round(dx/lx) * lx;
            dy = dy - round(dy/ly) * ly;
            dz = dz - round(dz/lz) * lz;
rij = pow(dx,2) + pow(dy,2) + pow(dz,2);
            if(rij < rcut2){
                rij6 = pow(rij,3);
                rij12 = pow(rij6,2);
                Ep = (A12/rij12) - (B6/rij6);
                Ep_LJ = (A12/rij12) - (B6/rij6);
                Ep += Ep_LJ;
            }
        }
    }

    cout << ": " \
         << Ep/(float)N << "kJ/mol";

    // 
    ofstream file;
    file.open("_ep.xyz");
    file << N << "\n" << endl;

    int Nw = N/5;

    // iterasi dalam output array
    for(int m = 0; m < Nw; m++){
     file << setw(3) << "Cu" << setw(3) << " " \
             << fixed << setprecision(3) << Cux[m] << setw(3) << " " \
             << fixed << setprecision(3) << Cuy[m] << setw(3) << " " \
             << fixed << setprecision(3) << Cuz[m] << "\n";

        file << setw(3) << "Cl" << setw(3) << " " \
             << fixed << setprecision(3) << Cl1x[m] << setw(3) << " " \
             << fixed << setprecision(3) << Cl1y[m] << setw(3) << " " \
             << fixed << setprecision(3) << Cl1z[m] << "\n";

        file << setw(3) << "Cl" << setw(3) << " " \
             << fixed << setprecision(3) << Cl2x[m] << setw(3) << " " \
             << fixed << setprecision(3) << Cl2y[m] << setw(3) << " " \
             << fixed << setprecision(3) << Cl2z[m] << "\n";
    }


    file.close();

    return 0;
}
