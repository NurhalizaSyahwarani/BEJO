
                            (SENYAWA TEMBAGA RUAH)  FILE 2


%%writefile senyawa-tembaga.cpp

#include "iostream"
#include "cmath"
#include "iomanip"
#include "fstream"

using namespace std;

int main (){
    // deklarasi variabel
    float pi = 3.14;
    int counter = 0;

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

    // hasil iterasi dimasukkan ke dalam file xyz
    ofstream file;
    file.open("senyawa-tembaga(II)klorida.xyz");
    int N = 125 * 3;
    file << N << "\n" << endl;

    // iterasi dalam output array
    for(int m = 0; m < 125; m++){
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

    cout << "program telah selesai";

    return 0;
}






%%shell

g++ senyawa-tembaga.cpp -o senyawa-tembaga
./senyawa-tembaga.
