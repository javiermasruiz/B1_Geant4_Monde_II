#!/bin/bash  

start_time=$(date +%s)
echo " Run monde Simulation"

./exampleB1 run3jav.mac -> z.out

echo " --Finished--"
finish_time=$(date +%s)
echo "Time Calculation: $((finish_time - start_time)) seg."




