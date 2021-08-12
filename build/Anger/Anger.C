#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <iomanip>

using namespace std;

// Global variables
ofstream out;
ifstream in;
double x, y, X, Y, X0, Y0, dX, dY;
long pmt_sum, threshold = 50, fail_pmt, good_PMT;
long pmt1, pmt2, pmt3, pmt4, pmt5, pmt6, pmt7, pmt8, pmt9, pmt10, pmt11, pmt12, pmt13, pmt14, pmt15, pmt16;
long PMT1, PMT2, PMT3, PMT4, PMT5, PMT6, PMT7, PMT8, PMT9, PMT10, PMT11, PMT12, PMT13, PMT14, PMT15, PMT16;
double x1pos = 30.895, x2pos = 26.191, x3pos = 17.500, x4pos = 6.145, x5pos = -6.145;
double x6pos = -17.500, x7pos = -26.191, x8pos = -30.891, x9pos = -30.895, x10pos = -26.191;
double x11pos = -17.500, x12pos = -6.145, x13pos = 6.145, x14pos = 17.500, x15pos = 26.191, x16pos = 30.895;

double y1pos = 6.145, y2pos = 17.500, y3pos = 26.191, y4pos = 30.895, y5pos = 30.895;
double y6pos = 26.191, y7pos = 17.500, y8pos = 6.145, y9pos = -6.145, y10pos = -17.500;
double y11pos = -26.191, y12pos = -30.895, y13pos = -30.895, y14pos = -26.191, y15pos = -17.500, y16pos = -6.145;


//void AngerXY(float&, float&, float&);

int main(){

	in.open("anger_in.txt", ios::in);
	out.open("anger_out.txt", ios::out);

	if(in.fail()){
	  cout <<" No se pudo abrir el archivo de Entrada ";
	  exit(1);
	}

	if(out.fail()){
	  cout <<" No se pudo abrir el archivo de Salida";
	  exit(1);
	}
/*
	       out << " X " << " Y " << " X0 " << " Y0 " << " dX " << " dY ";
		   out << " PMT1 " << " PMT2 " << " PMT3 " <<  " PMT4 " <<  " PMT5 " << " PMT6 " << " PMT7 "; 
		   out << " PMT8 " << "PMT9 " << " PMT10 " << " PMT11 " << " PMT12 " << " PMT13 " << " PMT14 ";
		   out << " PMT15 " << " PMT16 " << " pmt_sum " << endl;
*/
 int entries = 0;
 while (in.good()) 
   {  
        in >> x >> y >> pmt1 >> pmt2 >> pmt3 >> pmt4 >> pmt5
		   >> pmt6 >> pmt7 >> pmt8 >> pmt9 >> pmt10
		   >> pmt11 >> pmt12 >> pmt13 >> pmt14 >> pmt15 >> pmt16;

		X = x;
		Y = y;
		PMT1 = pmt1;
		PMT2 = pmt2;
		PMT3 = pmt3;
		PMT4 = pmt4;
		PMT5 = pmt5;
		PMT6 = pmt6;
		PMT7 = pmt7;
		PMT8 = pmt8;
		PMT9 = pmt9;
		PMT10 = pmt10;
		PMT11 = pmt11;
		PMT12 = pmt12;
		PMT13 = pmt13;
		PMT14 = pmt14;
		PMT15 = pmt15;
		PMT16 = pmt16;

		fail_pmt = 0;

		if( PMT1 < threshold ){
		 PMT1 = 0 ;
		 fail_pmt += 1 ; 
		}
	    if( PMT2 < threshold ){
	     PMT2 = 0 ;
	     fail_pmt += 1 ; 
	 	}
		if( PMT3 < threshold ){
		 PMT3 = 0 ;
		 fail_pmt += 1 ; 
		}
		if( PMT4 < threshold ){
		 PMT4 = 0 ;
		 fail_pmt += 1 ; 
		}
		if( PMT5 < threshold ){
		 PMT5 = 0 ;
		 fail_pmt += 1 ; 
		}
		if( PMT6 < threshold ){
		 PMT6 = 0 ;
		 fail_pmt += 1 ; 
		}
		if( PMT7 < threshold ){
		 PMT7 = 0 ;
		 fail_pmt += 1 ; 
		}
		if( PMT8 < threshold ){
		 PMT8 = 0 ;
		 fail_pmt += 1 ; 
		}
		if( PMT9 < threshold ){
		 PMT9 = 0 ;
		 fail_pmt += 1 ; 
		}
		if( PMT10 < threshold ){
		 PMT10 = 0 ;
		 fail_pmt += 1 ; 
		}
		if( PMT11 < threshold ){
		 PMT11 = 0 ;
		 fail_pmt += 1 ; 
		}
		if( PMT12 < threshold ){
		 PMT12 = 0 ;
		 fail_pmt += 1 ; 
		}
		if( PMT13 < threshold ){
		 PMT13 = 0 ;
		 fail_pmt += 1 ; 
		}
		if( PMT14 < threshold ){
		 PMT14 = 0 ;
		 fail_pmt += 1 ; 
		}
		if( PMT15 < threshold ){
		 PMT15 = 0 ;
		 fail_pmt += 1 ; 
		}
		if( PMT16 < threshold ){
		 PMT16 = 0 ;
		 fail_pmt += 1 ; 
		} 

		good_PMT = 16 - fail_pmt;

		pmt_sum = PMT1+PMT2+PMT3+PMT4+PMT5+PMT6+PMT7+PMT8+PMT9 + PMT10 + PMT11 + PMT12 + PMT13 + PMT14 + PMT15 + PMT16;
		if(pmt_sum == 0) continue;

		if(good_PMT >= 4){

		  X0 = (x1pos*PMT1 + x2pos*PMT2 + x3pos*PMT3 + x4pos*PMT4 + x5pos*PMT5 + x6pos*PMT6
				 + x7pos*PMT7 + x8pos*PMT8 + x9pos*PMT9 + x10pos*PMT10 + x11pos*PMT11 
				 + x12pos*PMT12 + x13pos*PMT13 + x14pos*PMT14 + x15pos*PMT15 + x16pos*PMT16)/(pmt_sum*1.0);

		  Y0 = (y1pos*PMT1 + y2pos*PMT2 + y3pos*PMT3 + y4pos*PMT4 + y5pos*PMT5 + y6pos*PMT6
				 + y7pos*PMT7 + y8pos*PMT8 + y9pos*PMT9 + y10pos*PMT10 + y11pos*PMT11 
				 + y12pos*PMT12 + y13pos*PMT13 + y14pos*PMT14 + y15pos*PMT15 + y16pos*PMT16)/(pmt_sum*1.0);
	    
	      dX = fabs(X-X0);
	      dY = fabs(Y-Y0);
	    }

	      if(in.good()){
       	/*
       	   cout <<fixed<<showpoint<<setprecision(2)<< X << " " << Y << " " << X0 << " " << Y0 << " " <<  dX  << " " <<  dY;
		   cout << " " << PMT1 << " " << PMT2 << " " << PMT3 << " " << PMT4 << " " << PMT5 << " " << PMT6 << " " << PMT7; 
		   cout << " " << PMT8 << " " << PMT9 << " " << PMT10 << " " << PMT11 << " " << PMT12 << " " << PMT13 << " " << PMT14;
		   cout << " " << PMT15 << " " << PMT16 << "  " << pmt_sum << endl;
	    */
	   	   out <<fixed<<showpoint<<setprecision(2)<< X << " " << Y << " " << X0 << " " << Y0 << " " <<  dX  << " " <<  dY;
		   out << " " << PMT1 << " " << PMT2 << " " << PMT3 << " " << PMT4 << " " << PMT5 << " " << PMT6 << " " << PMT7; 
		   out << " " << PMT8 << " " << PMT9 << " " << PMT10 << " " << PMT11 << " " << PMT12 << " " << PMT13 << " " << PMT14;
		   out << " " << PMT15 << " " << PMT16 << "  " << pmt_sum << endl;

      	  entries++;
      	  cout << entries << " -- " << good_PMT  << endl;
        }


    }
    cout << "We read -> " << entries << " <- lines." << endl;

	in.close();
	out.close();

return 0;
}

	