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
// $Id: B1SteppingAction.cc 74483 2013-10-09 13:37:06Z gcosmo $
//
/// \file B1SteppingAction.cc
/// \brief Implementation of the B1SteppingAction class

#include "B1SteppingAction.hh"
#include "B1EventAction.hh"
#include "B1DetectorConstruction.hh"

#include "G4Step.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"

//
// * mod
//
#include "G4StepPoint.hh"
#include "G4VTouchable.hh"
#include "G4VPhysicalVolume.hh"
#include "G4ParticleDefinition.hh"
#include "G4Track.hh"
#include "G4ParticleTypes.hh"
#include "G4ProcessManager.hh"
#include "G4VProcess.hh"

//
// * end mod
//

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1SteppingAction::B1SteppingAction(B1EventAction* eventAction)
: G4UserSteppingAction(),
  fEventAction(eventAction)
  //fScoringVolume(0)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1SteppingAction::~B1SteppingAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B1SteppingAction::UserSteppingAction(const G4Step* step)
{
  /*
  if (!fScoringVolume) { 
    const B1DetectorConstruction* detectorConstruction
      = static_cast<const B1DetectorConstruction*>
        (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
    fScoringVolume = detectorConstruction->GetScoringVolume();   

  }
  */

  //
  // * mod
  //
  
  G4StepPoint* point1 = step->GetPreStepPoint();
  G4StepPoint* point2 = step->GetPostStepPoint();

  G4ThreeVector pos1 = point1->GetPosition();
  G4ThreeVector pos2 = point2->GetPosition();

  //const G4VTouchable* touch1 = point1->GetTouchable();
  const G4VTouchable* touch2 = point2->GetTouchable();

  G4VPhysicalVolume* volume1 = point1->GetPhysicalVolume();  
  G4VPhysicalVolume* volume2 = point2->GetPhysicalVolume();   
 
  //const G4String name1 = volume1->GetName();
  //const G4String name2 = volume2->GetName();  
  
  G4ParticleDefinition* particleType = step->GetTrack()->GetDefinition();

  if( volume1->GetName() == "Shape3P" && volume2->GetName() == "divided_tube_phys" &&
   particleType == G4OpticalPhoton::OpticalPhotonDefinition()){
    G4int copyNo = touch2->GetCopyNumber(0);
    G4cout << "Numero de Copia: "<< copyNo << G4endl;

    fEventAction->AddCountPMT(copyNo); 
  }
/*
  if(particleType == G4OpticalPhoton::OpticalPhotonDefinition() && volume1->GetName() == "Shape3P"){

  }
*/
  //
  // * end mod
  //

//     ---------------------------------------------
  G4Track* theTrack = step->GetTrack();
/*
  G4ProcessManager* pm = step->GetTrack()->GetDefinition()->GetProcessManager();
    G4int nprocesses = pm->GetProcessListLength();
    G4ProcessVector* pv = pm->GetProcessList();
    G4int i;
    for( i=0;i<nprocesses;i++){
      if((*pv)[i]->GetProcessName()=="hadElastic" && theTrack->GetParentID() == 0){
        G4cout << "Bello" << G4endl;
        //G4cout << "->Position : "<< theTrack->GetPosition() << G4endl;
      }
    }
*/
//2da via
       G4String procName = point2->GetProcessDefinedStep()->GetProcessName();
     if(theTrack->GetParentID() == 0 && procName == "hadElastic"){
      //G4cout << "Bello" << G4endl;
          G4cout << "->Position PostStep : "<< point2->GetPosition() << G4endl; 
          G4cout << "->Position theTrack : "<< theTrack->GetPosition() << G4endl; 
     }

//theTrack->GetCreatorProcess()->GetProcessName() == "hadElastic"

//     G4cout << "->Position : "<< posHad << G4endl;
//     G4double  hadX = posHad->getX();
//     G4double  hadY = posHad->getY();
//     G4double  hadZ = posHad->getZ();
// ------------------------------------------------------

  // get volume of the current step
 /* G4LogicalVolume* volume 
    = step->GetPreStepPoint()->GetTouchableHandle()
      ->GetVolume()->GetLogicalVolume();
      
  // check if we are in scoring volume
  if (volume != fScoringVolume) return;

  // collect energy deposited in this step
  G4double edepStep = step->GetTotalEnergyDeposit();
  fEventAction->AddEdep(edepStep);  
  */
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

