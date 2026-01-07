#!/bin/bash

clear
clear

subtask="6"      # <==== ONLY EDIT THIS

input_folder="sub${subtask}_tests/input"
output_folder="sub${subtask}_tests/output"
settings="subtask_gen_settings/sub${subtask}_settings.txt"
solution="sub6_solution"
generator="gen"

echo "=> Compiling..."
g++ ${generator}.cpp -o ${generator}
g++ ${solution}.cpp -o ${solution}

echo "=> Generating Tests..."
./${generator} < $settings

echo "=> Solving Tests..."
i=0
for x in ${input_folder}/*.txt; do
    ((i++))
    echo "    -> Running $i"
    s_i=$i
    if (( s_i < 10 )); then
        s_i="0$i"
    fi
    ./${solution} < $x > "${output_folder}/out_${subtask}_$s_i.txt"
done

echo
echo