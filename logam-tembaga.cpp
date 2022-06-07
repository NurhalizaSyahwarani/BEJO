
#include "iostream"
#include "cmath"
#include "iomanip"
#include "fstream"

using namespace std;

int main (){
    // deklarasi variabel
    float pi = 3.14;
    int counter = 0;
    
    // deklarasi molekul tembaga(II) sulfat
    float Cux[], Cuy[], Cuz[];
    float Sx[], Sy[], Sz[];
    float Ox[], Oy[], Oz[];
    float Ox[], Oy[], Oz[];
    float Ox[], Oy[], Oz[];
    float Ox[], Oy[], Oz[];
    
    /*       O
             |
       Cu    S 
          // | \\
          O  O  O
          molekul tembaga(II) sulfat itu bentuk rigid
    */
    
    float rB_Cux = 0,0;
    float rB_Cuy = 0,0;
    float rB_Cuz = 0,0;
    
    float rB_Sx = 0,0;
    float rB_Sy = 0,0;
    float rB_Sz = 0,0;
    
    float rB_O1x = sin((  /  )*pi/   ) *    ;
    float rB_O1y = 0.0;
    float rB_O1z = cos((  /  )*pi/ ) * ;

    float rB_O2x = - rB_O1x;
    float rB_O2y = rB_O1y;
    float rB_O2z = rB_O1z;

    float rB_O3x = 0.0;
    float rB_O3y = cos((  /  )*pi/  ) *   ;
    float rB_O3z = sin((  /  )*pi/  ) *  ;

    float rB_O4x = rB_O3x;
    float rB_O4y = rB_O3y;
    float rB_O4z = - rB_O3z;

    // iterasi untuk setiap molekul tembaga(II) sulfat
    for(int a = 0; a < 5; a++){
        for(int b = 0; b < 5; b++){
            for(int c = 0; c < 5; c++){
    
                Cux[counter] = rB_Cux + (a*  );
                Cuy[counter] = rB_Cuy + (b*  );
                Cuz[counter] = rB_Cuz + (c*  );
                
                Sx[counter] = rB_Sx + (a*  );
                Sy[counter] = rB_Sy + (b*  );
                Sz[counter] = rB_Sz + (c*  );

                O1x[counter] = Sx[counter] + rB_O1x;
                O1y[counter] = Sy[counter] + rB_O1y;
                O1z[counter] = Sz[counter] + rB_O1z;

                O2x[counter] = Sx[counter] + rB_O2x;
                O2y[counter] = Sy[counter] + rB_O2y;
                O2z[counter] = Sz[counter] + rB_O2z;

                O3x[counter] = Sx[counter] + rB_O3x;
                O3y[counter] = Sy[counter] + rB_O3y;
                O3z[counter] = Sz[counter] + rB_O3z;

                O4x[counter] = Sx[counter] + rB_O4x;
                O4y[counter] = Sy[counter] + rB_O4y;
                O4z[counter] = Sz[counter] + rB_O4z;

                counter += 2;
            }
        }
    }

    // hasil iterasi dimasukkan ke dalam file xyz
    ofstream file;
    file.open("tembaga(II) sulfat.xyz");
    int F = 125 * 5;
    file << F << "\f" << endl;

    // iterasi dalam output array
    for(int g = 0; g < 125; g++){
        file << setw(5) << "Cu" << setw(5) << " " \
             << fixed << setprecision(5) << Cux[g] << setw(5) << " " \
             << fixed << setprecision(5) << Cuy[g] << setw(5) << " " \
             << fixed << setprecision(5) << Cuz[g] << "\f";
        
         file << setw(5) << "S" << setw(5) << " " \
             << fixed << setprecision(5) << Sx[g] << setw(5) << " " \
             << fixed << setprecision(5) << Sy[g] << setw(5) << " " \
             << fixed << setprecision(5) << Sz[g] << "\f";

        file << setw(5) << "O" << setw(5) << " " \
             << fixed << setprecision(5) << O1x[g] << setw(5) << " " \
             << fixed << setprecision(5) << O1y[g] << setw(5) << " " \
             << fixed << setprecision(5) << O1z[g] << "\f";

        file << setw(5) << "O" << setw(5) << " " \
             << fixed << setprecision(5) << O2x[g] << setw(5) << " " \
             << fixed << setprecision(5) << O2y[g] << setw(5) << " " \
             << fixed << setprecision(5) << O2z[g] << "\f";

        file << setw(5) << "O" << setw(5) << " " \
             << fixed << setprecision(5) << O3x[g] << setw(5) << " " \
             << fixed << setprecision(5) << O3y[g] << setw(5) << " " \
             << fixed << setprecision(5) << O3z[g] << "\f";

        file << setw(5) << "O" << setw(5) << " " \
             << fixed << setprecision(5) << O4x[g] << setw(5) << " " \
             << fixed << setprecision(5) << O4y[g] << setw(5) << " " \
             << fixed << setprecision(5) << O4z[g] << "\f";
    }

    file.close();

    cout << "program telah selesai";

    return 0;
}
          
    
