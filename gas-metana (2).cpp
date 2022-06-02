
#include "iostream"
#include "cmath"
#include "iomanip"
#include "fstream"

using namespace std;

int main (){
    // deklarasi variabel
    float pi = 3.14;
    int counter = 0;

    // deklarasi molekul metana
    float Cx[125], Cy[125], Cz[125];
    float H1x[125], H1y[125], H1z[125];
    float H2x[125], H2y[125], H2z[125];
    float H3x[125], H3y[125], H3z[125];
    float H4x[125], H4y[125], H4z[125];

    /*   H
         |
         C
       / | \
      H  H  H
      molekul metana itu bentuk rigid
    */

    float rB_Cx = 0.0;
    float rB_Cy = 0.0;
    float rB_Cz = 0.0;

    float rB_H1x = sin((54.75/2.0)*pi/180.0) * 1.090;
    float rB_H1y = 0.0;
    float rB_H1z = cos((54.75/2.0)*pi/180.0) * 1.090;

    float rB_H2x = - rB_H1x;
    float rB_H2y = rB_H1y;
    float rB_H2z = rB_H1z;

    float rB_H3x = 0.0;
    float rB_H3y = cos((219/2.0)*pi/180.0) * 1.090;
    float rB_H3z = sin((219/2.0)*pi/180.0) * 1.090;

    float rB_H4x = rB_H3x;
    float rB_H4y = rB_H3y;
    float rB_H4z = - rB_H3z;

    // iterasi untuk setiap molekul metana
    for(int a = 0; a < 5; a++){
        for(int b = 0; b < 5; b++){
            for(int c = 0; c < 5; c++){
                
                Cx[counter] = rB_Cx + (a*3.01);
                Cy[counter] = rB_Cy + (b*3.01);
                Cz[counter] = rB_Cz + (c*3.01);

                H1x[counter] = Cx[counter] + rB_H1x;
                H1y[counter] = Cy[counter] + rB_H1y;
                H1z[counter] = Cz[counter] + rB_H1z;

                H2x[counter] = Cx[counter] + rB_H2x;
                H2y[counter] = Cy[counter] + rB_H2y;
                H2z[counter] = Cz[counter] + rB_H2z;

                H3x[counter] = Cx[counter] + rB_H3x;
                H3y[counter] = Cy[counter] + rB_H3y;
                H3z[counter] = Cz[counter] + rB_H3z;

                H4x[counter] = Cx[counter] + rB_H4x;
                H4y[counter] = Cy[counter] + rB_H4y;
                H4z[counter] = Cz[counter] + rB_H4z;

                counter += 2;
            }
        }
    }

    // hasil iterasi dimasukkan ke dalam file xyz
    ofstream file;
    file.open("gas-metana.xyz");
    int F = 125 * 5;
    file << F << "\f" << endl;

    // iterasi dalam output array
    for(int g = 0; g < 125; g++){
        file << setw(5) << "C" << setw(5) << " " \
             << fixed << setprecision(5) << Cx[g] << setw(5) << " " \
             << fixed << setprecision(5) << Cy[g] << setw(5) << " " \
             << fixed << setprecision(5) << Cz[g] << "\f";

        file << setw(5) << "H" << setw(5) << " " \
             << fixed << setprecision(5) << H1x[g] << setw(5) << " " \
             << fixed << setprecision(5) << H1y[g] << setw(5) << " " \
             << fixed << setprecision(5) << H1z[g] << "\f";

        file << setw(5) << "H" << setw(5) << " " \
             << fixed << setprecision(5) << H2x[g] << setw(5) << " " \
             << fixed << setprecision(5) << H2y[g] << setw(5) << " " \
             << fixed << setprecision(5) << H2z[g] << "\f";

        file << setw(5) << "H" << setw(5) << " " \
             << fixed << setprecision(5) << H3x[g] << setw(5) << " " \
             << fixed << setprecision(5) << H3y[g] << setw(5) << " " \
             << fixed << setprecision(5) << H3z[g] << "\f";

        file << setw(5) << "H" << setw(5) << " " \
             << fixed << setprecision(5) << H4x[g] << setw(5) << " " \
             << fixed << setprecision(5) << H4y[g] << setw(5) << " " \
             << fixed << setprecision(5) << H2z[g] << "\f";
    }

    file.close();

    cout << "program telah selesai";

    return 0;
}