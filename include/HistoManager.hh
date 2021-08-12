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
/// \file analysis/AnaEx01/include/HistoManager.hh
/// \brief Definition of the HistoManager class
//
//
// $Id: HistoManager.hh 99607 2016-09-28 13:33:42Z gcosmo $
// 
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo...... 

#ifndef HistoManager_h
#define HistoManager_h 1

#include "globals.hh"

#include "g4root.hh"
//#include "g4csv.hh"
//#include "g4xml.hh"
#include <iostream>
#include <fstream>

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class HistoManager
{
  public:
    HistoManager();
   ~HistoManager();
   std::ofstream out; //********************* declaramos la variable de tipo ofstream

    void Book();
    void Save();
    
    //void FillHisto(G4int id, G4double e, G4double weight = 1.0);
    void Normalize(G4int id, G4double fac); 

    void FillNtuple( G4double posX, G4double posY,
                      G4int sumPMT1, G4int sumPMT2, G4int sumPMT3, G4int sumPMT4,
                      G4int sumPMT5, G4int sumPMT6, G4int sumPMT7, G4int sumPMT8,
                      G4int sumPMT9, G4int sumPMT10, G4int sumPMT11, G4int sumPMT12,
                      G4int sumPMT13, G4int sumPMT14, G4int sumPMT15, G4int sumPMT16 );

  /* void FillNtuple1( G4int sumPMT1, G4int sumPMT2, G4int sumPMT3, G4int sumPMT4,
                      G4int sumPMT5, G4int sumPMT6, G4int sumPMT7, G4int sumPMT8,
                      G4int sumPMT9, G4int sumPMT10, G4int sumPMT11, G4int sumPMT12,
                      G4int sumPMT13, G4int sumPMT14, G4int sumPMT15, G4int sumPMT16 );
  */
    /*
    void FillNtuple2( G4double posX, G4double posY );
    */

    //void PrintStatistic();        
    
  private:
    G4bool fFactoryOn;    
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

