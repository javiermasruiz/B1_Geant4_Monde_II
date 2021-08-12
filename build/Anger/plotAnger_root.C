#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TAttPad.h"

#include "TStopwatch.h"

#include <iostream>
#include <fstream>

using namespace std;

void plotAnger_root()
{
	TStopwatch t;

	fstream in;
	in.open("anger_out.txt");

	Double_t x, y, x0, y0, dx, dy;
	Int_t pmt1, pmt2, pmt3, pmt4, pmt5, pmt6;
	Int_t pmt7, pmt8, pmt9, pmt10, pmt11, pmt12;
	Int_t pmt13, pmt14, pmt15, pmt16;
	Int_t pmt_sum;

	TFile *output = new TFile("plotAnger.root","recreate");

	TTree *tree = new TTree("tree","tree");

	tree->Branch("x", &x, "x/D");
	tree->Branch("y", &y, "y/D");
	tree->Branch("x0", &x0, "x0/D");
	tree->Branch("y0", &y0, "y0/D");
	tree->Branch("dx", &dx, "dx/D");
	tree->Branch("dy", &dy, "dy/D");

	Int_t entries = 0;
	while(1)
	{ 
		in >> x >> y >> x0 >> y0 >> dx >> dy
		 >> pmt1 >> pmt2 >> pmt3 >> pmt4
		 >> pmt5 >> pmt6 >> pmt7 >> pmt8 >> pmt9
		 >> pmt10 >> pmt11 >> pmt12 >> pmt13 >> pmt14
		 >> pmt15 >> pmt16 >> pmt_sum;

		if(in.eof()) break;

		cout << x << " " << y << endl;	

		tree->Fill();

		entries++;
		
	}
	
	cout << "We read --> "<< entries << " <-- lines" << endl;



   
    gStyle->SetPalette(1,0);
    gStyle->SetNumberContours(100);
	gErrorIgnoreLevel = kError;

	TCanvas *c1 = new TCanvas("c1", "Position & Errors",800,700);
	gStyle->SetOptStat(0);
//	gStyle->SetPadLeftMargin(0.05);
// 	gStyle->SetPadRightMargin(0.15);

	c1->Divide(2,2,0.01,0.01);

	c1->cd(1);
	//gPad->SetTickx(2);
	tree->Draw("dx:dy","","colz");

	c1->cd(2);
	//gPad->SetTickx(2);
	tree->Draw("dx:dy","","surf3z");

	c1->cd(3);
	tree->Draw("x:y","","colz");

	c1->cd(4);
	tree->Draw("x0:y0","","colz");

	tree->Write();

	output->Write();

	output->Close();

	in.close();

	t.Print();
}


