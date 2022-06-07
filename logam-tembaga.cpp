
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
    
          
          
    
