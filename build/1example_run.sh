#!/bin/bash  

start_time=$(date +%s)
echo " Run monde Simulation"

./exampleB1 run3jav.mac -> run3jav.out

echo " --Finished--"
finish_time=$(date +%s)
echo "Time Calculation: $((finish_time - start_time)) seg."




