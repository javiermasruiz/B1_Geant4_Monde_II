#include "TFile.h"
#include "TTree.h"
#include "TStopwatch.h"

#include <iostream>
#include <fstream>

using namespace std;

void plotjav()
{
	TStopwatch t;

	fstream in;
	in.open("monde2_out.txt");

	double x, y;
	double pmt1, pmt2, pmt3, pmt4, pmt5, pmt6;
	double pmt7, pmt8, pmt9, pmt10, pmt11, pmt12;
	double pmt13, pmt14, pmt15, pmt16;

	TFile *output = new TFile("plotjav.root","recreate");

	TTree *tree = new TTree("tree","tree");

	tree->Branch("x", &x, "x/D");
	tree->Branch("y", &y, "y/D");

	while(1)
	{ 
		in >> x >> y >> pmt1 >> pmt2 >> pmt3 >> pmt4
			 >> pmt5 >> pmt6 >> pmt7 >> pmt8 >> pmt9
			>> pmt10 >> pmt11 >> pmt12 >>pmt13>>pmt14
			>> pmt15 >> pmt16;

		if(in.eof()) break;

		cout << x << " " << y << endl;	

		tree->Fill();
		
	}
	
	tree->Draw("x:y");
	tree->Write();

	output->Write();

	output->Close();

	in.close();

	t.Print();
}
