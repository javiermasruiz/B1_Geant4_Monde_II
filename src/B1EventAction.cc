//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: B1EventAction.cc 93886 2015-11-03 08:28:26Z gcosmo $
//
/// \file B1EventAction.cc
/// \brief Implementation of the B1EventAction class

#include "B1EventAction.hh"
#include "B1RunAction.hh"
#include "B1PrimaryGeneratorAction.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include <iostream>
#include <fstream>
#include <iomanip>
#include "HistoManager.hh"
#include "G4Cons.hh"
#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1EventAction::B1EventAction(B1RunAction* runAction, B1PrimaryGeneratorAction* primaryAction, HistoManager* histo)
: G4UserEventAction(),
  fRunAction(runAction),fprimaryAction(primaryAction),
  fHistoManager(histo),
  fEdep(0.)
 {}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1EventAction::~B1EventAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B1EventAction::BeginOfEventAction(const G4Event*)
{    

  for (G4int i=0; i<16; i++){
          sumPMT[i] = 0; 
          }

  fEdep = 0.;
  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B1EventAction::EndOfEventAction(const G4Event*)
{   

  PosX = fprimaryAction->GetPosX();
  PosY = fprimaryAction->GetPosY();
  fHistoManager->out<< std::setprecision(3) << PosX/cm <<"\t" << std::setprecision(3) << PosY/cm << "\t";


	for (G4int i=0; i<16; i++){
	        fHistoManager->out << sumPMT[i] << "\t"; 
	        }
	fHistoManager->out << std::endl;
  // accumulate statistics in run action
  fRunAction->AddEdep(fEdep);

  //
  fHistoManager->FillNtuple(  PosX/cm, PosY/cm, 
                              sumPMT[0],  sumPMT[1],  sumPMT[2],  sumPMT[3],
                              sumPMT[4],  sumPMT[5],  sumPMT[6],  sumPMT[7],
                              sumPMT[8],  sumPMT[9],  sumPMT[10],  sumPMT[11],
                              sumPMT[12],  sumPMT[13],  sumPMT[14],  sumPMT[15] );



}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
