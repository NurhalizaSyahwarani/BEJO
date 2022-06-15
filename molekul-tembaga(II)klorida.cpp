                                        MOLEKUL TEMBAGA(II) KLORIDA (FILE KE 1)
                                            
                                            

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

    Cl1x = sin(54.75*pi/180) * 109.5;
    Cl1y = 0.0;
    Cl1z = cos(54.75*pi/180) * 109.5;

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




proges selanjutnya :
1.Akses ke komputer kemudian melakukan registrasi pada laman 
https://chemcompute.org/register/. Pengguna perlu mengisi data username(osyellah), email(osyellah@gmail.com), 
dan password kemudian klik tombol SIGN ME UP. Email konfirmasi akan otomatis 
dikirim pada alamat email yang kita masukkan. Input perhitungan komputasi dapat 
dibuat secara manual melalui software Avogadro (https://avogadro.cc/)

DIPEROLEH
!   File created by the GAMESS Input Deck Generator Plugin for Avogadro
 $BASIS GBASIS=STO NGAUSS=3 $END
 $CONTRL SCFTYP=ROHF RUNTYP=ENERGY MULT=2 $END

 $DATA 
Title
C1
Cu    29.0    -0.47232     0.26856     0.00000
Cl    17.0     1.39718     1.56220    -0.00000
Cl    17.0    -2.31511     1.59997    -0.00000
 $END
 
 
 KEMUDIAN SETELAH INPUT CODE DIATAS DIPEROLEH CODE DIBAWAH DAN TERBENTUK MOLEKULNYA
 ----- GAMESS execution script 'rungms' -----
This job is running on host chemcompute-node-0.novalocal
under operating system Linux at Wed Jun 15 14:18:16 UTC 2022
SLURM has assigned the following compute nodes to this run:
chemcompute-node-0
Available scratch disk space (Kbyte units) at beginning of the job is
Filesystem     1K-blocks     Used Available Use% Mounted on
/dev/sda1       62903276 16791632  46111644  27% /
GAMESS temporary binary files will be written to /scratch/385486
GAMESS supplementary output files will be written to /data/slurm/434600
Copying input file 434600.inp to your run's scratch directory...
The generated host list is
chemcompute-node-0.novalocal

 Distributed Data Interface kickoff program.
 Initiating 1 compute processes on 1 nodes to run the following command:
 /data/gamess-2019R1-ddi/gamess.00.x 434600 

          

 


atau secara 
otomatis laman https://chemcompute.org/gamess/submit
DIPEROLEH STRUKTUR MOLEKUL CuCl2


