#!/bin/bash  

start_time=$(date +%s)
echo " Run monde Simulation"
cmake -D_Geant4_DIR=/home/javier/software/geant4/share/Geant4-10.3.3 /home/javier/Desktop/geant4_work/B1 && make -j2 
./exampleB1
echo " --Finished--"
finish_time=$(date +%s)
echo "Time Calculation: $((finish_time - start_time)) seg."




