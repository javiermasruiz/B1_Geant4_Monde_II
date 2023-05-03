#include "TFile.h"
#include "TNtuple.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TStopwatch.h"
#include <iostream>
#include <fstream>

using namespace std;

void readroot()
{
	TStopwatch t;
	
	TCanvas *c1 = new TCanvas();
	// input
	TFile *finput = new TFile("monde2_out.root","read");
	TDirectory *dir=finput->GetDirectory("ntuple;1");
	dir->ls(); 

	TTree *tree = (TTree*)dir->Get("monde2_ntuple");

	int entries = tree->GetEntries();

	Double_t PosX, PosY;
	Int_t sumPMT1, sumPMT2, sumPMT3, sumPMT4, sumPMT5, sumPMT6;
	Int_t sumPMT7, sumPMT8, sumPMT9, sumPMT10, sumPMT11;
	Int_t sumPMT12, sumPMT13, sumPMT14, sumPMT15, sumPMT16;

	tree->SetBranchAddress("PosX", &PosX);
	tree->SetBranchAddress("PosY", &PosY);
	tree->SetBranchAddress("sumPMT1", &sumPMT1);
	tree->SetBranchAddress("sumPMT2", &sumPMT2);
	tree->SetBranchAddress("sumPMT3", &sumPMT3);
	tree->SetBranchAddress("sumPMT4", &sumPMT4);
	tree->SetBranchAddress("sumPMT5", &sumPMT5);
	tree->SetBranchAddress("sumPMT6", &sumPMT6);
	tree->SetBranchAddress("sumPMT7", &sumPMT7);
	tree->SetBranchAddress("sumPMT8", &sumPMT8);
	tree->SetBranchAddress("sumPMT9", &sumPMT9);
	tree->SetBranchAddress("sumPMT10", &sumPMT10);
	tree->SetBranchAddress("sumPMT11", &sumPMT11);
	tree->SetBranchAddress("sumPMT12", &sumPMT12);
	tree->SetBranchAddress("sumPMT13", &sumPMT13);
	tree->SetBranchAddress("sumPMT14", &sumPMT14);
	tree->SetBranchAddress("sumPMT15", &sumPMT15);
	tree->SetBranchAddress("sumPMT16", &sumPMT16);
	
	// output
	/*
	TFile *foutput = new TFile("plot1jav.root","recreate");
	TTree *treeout = new TTree("treeout", "treout");
	*/

	ofstream out;
	out.open("anger_in.txt",ios::out);

	if(out.fail()){
	  cout <<" No se pudo abrir el archivo de Salida ";
	  exit(1);
	}

	for(int i = 0; i < entries; i++)
	{
		tree->GetEntry(i);

		cout <<fixed<<showpoint<<setprecision(2)<< PosX << " " << PosY;
		cout << " " << sumPMT1 << " " << sumPMT2 << " " << sumPMT3 << " " << sumPMT4; 
		cout << " " << sumPMT5 << " " << sumPMT6 << " " << sumPMT7 << " " << sumPMT8;
		cout << " " << sumPMT9 << " " << sumPMT10 << " " << sumPMT11 << " " << sumPMT12;
		cout << " " << sumPMT13 << " " << sumPMT14 << " " << sumPMT15 << " " << sumPMT16 << endl;

		out <<fixed<<showpoint<<setprecision(2)<< PosX << " " << PosY;
		out << " " << sumPMT1 << " " << sumPMT2 << " " << sumPMT3 << " " << sumPMT4; 
		out << " " << sumPMT5 << " " << sumPMT6 << " " << sumPMT7 << " " << sumPMT8;
		out << " " << sumPMT9 << " " << sumPMT10 << " " << sumPMT11 << " " << sumPMT12;
		out << " " << sumPMT13 << " " << sumPMT14 << " " << sumPMT15 << " " << sumPMT16 << endl;
	}

	out.close();

		cout <<" We read --> " << entries << " <-- lines" << endl;

	tree->Draw("PosX:PosY");
	
//	treeout->Write();	
//	foutput->Write();

//	finput->Close();
//	foutput->Close();
//	delete finput;		
//	delete foutput;

	t.Print();
}
