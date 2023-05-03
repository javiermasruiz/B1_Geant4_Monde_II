
#include <TFile.h>
#include <TTree.h>
#include <TH1.h>
#include <TSpectrum.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TGraph.h>
#include <iostream>
#include <fstream>
#include <TAxis.h>
#include <TH2.h>
#include "TStopwatch.h"
#include <iostream>
#include <fstream>

using namespace std;

void HistoGenerator()
{
   TStopwatch t;

   TFile *output = new TFile("HistoGenerator.root","recreate");

   TTree *tree = new TTree("tree","tree");

   TH1F *P1_hist[16];

   for (Int_t i = 1; i < 17; i++){

         TString name1 = Form("PMT%d",i);

         P1_hist[i] = new TH1F(name1, "Histogramas",1000,0,1000);

   }

Double_t val;

         fstream in;
         in.open("aN17dic.txt",ios::in);  // aqui pones el nombre del archivo a leer con 16 canales solamente

         if(in.fail()){
         cout <<" No se pudo abrir el archivo de Entrada ";
         exit(1);
         }        

            Int_t entries = 0;

            while(1){ 
                     
                     for(Int_t j = 1; j < 17; j++){

                            in >> val;

                            P1_hist[j]->Fill(val);
                     }
              
                if(in.eof()) break;
                entries++;
              }

         in.close();
   

   for(Int_t i = 1; i < 17; i++){

      //P1_hist[i]->GetXaxis()->SetRangeUser(2,1000); // aqui le das el rango de ploteo, el canal 0 tiene muchas cuentas
      P1_hist[i]->Write();

   }


   t.Print();
}
