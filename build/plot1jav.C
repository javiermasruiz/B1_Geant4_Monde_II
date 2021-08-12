#include "TFile.h"
#include "TNtuple.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TStopwatch.h"
#include <iostream>

using namespace std;

void plot1jav()
{
	TStopwatch t;
	
	TCanvas *c1 = new TCanvas();
	// input
	TFile *finput = new TFile("monde2_out.root","read");
	TDirectory *dir=finput->GetDirectory("ntuple;1");
	dir->ls(); 

	TTree *tree = (TTree*)dir->Get("monde2_ntuple");

	int entries = tree->GetEntries();

	double PosX, PosY;

	tree->SetBranchAddress("PosX", &PosX);
	tree->SetBranchAddress("PosY", &PosY);

	cout << entries << endl;

	// output
	/*
	TFile *foutput = new TFile("plot1jav.root","recreate");
	TTree *treeout = new TTree("treeout", "treout");
	*/

	for(int i = 0; i < entries; i++)
	{
		tree->GetEntry(i);

		cout << PosX << " " << PosY << endl;
		
	}


	tree->Draw("PosX:PosY");
	
//	treeout->Write();	
//	foutput->Write();

//	finput->Close();
//	foutput->Close();
//	delete finput;		
//	delete foutput;

	t.Print();
}
