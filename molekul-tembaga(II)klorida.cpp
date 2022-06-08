%%writefile molekul-tembaga.cpp

#include "iostream"
#include "cmath"
#include "iomanip"
#include "fstream"

using namespace std;

int main(){
    // deklarasi variabel
    float pi = 3.14;
    
    // deklarasi molekul tembaga(II)klorida
    float Cux, Cuy, Cuz;
    float Cl1x, Cl1y, Cl1z;
    float Cl2x, Cl2y, Cl2z;

    // masukkan nilai untuk setiap variabel CuCl2
    Cux = Cuy = Cuz = 0.0;

    Cl1x = sin(90.0*pi/180) * 180.0;
    Cl1y = 0.0;
    Cl1z = cos(90.0*pi/180) * 180.0;

    Cl2x = - Cl1x;
    Cl2y = Cl1y;
    Cl2z = Cl1z;

    // memasukkan nilai tersebut ke dalam File
    ofstream file;
    file.open("tembaga(II)klorida.hyz");
    file << "3\n" << endl;
    file << setw(3) << "Cu" << setw(3) << " " \
    << fixed << setprecision(3) << Cux << setw(3) << " "\
    << fixed << setprecision(3) << Cuy << setw(3) << " "\
    << fixed << setprecision(3) << Cuz << "\n";

    file << setw(3) << "Cl1" << setw(3) << " " \
    << fixed << setprecision(3) << Cl1x << setw(3) << " "\
    << fixed << setprecision(3) << Cl1y << setw(3) << " "\
    << fixed << setprecision(3) << Cl1z << "\n";

    file << setw(3) << "Cl2" << setw(3) << " " \
    << fixed << setprecision(3) << Cl2x << setw(3) << " "\
    << fixed << setprecision(3) << Cl2y << setw(3) << " "\
    << fixed << setprecision(3) << Cl2z << "\n";

    file.close();
    
    cout << "program selesai";

    return 0;
}





%%shell

g++ molekul-tembaga.cpp -o tembaga
./tembaga
