#!/bin/bash

MIN_VALUE=-2147483648
MAX_VALUE=2147483647

generateRandomNumbers() {
    local n=$1
    local nums=()
    for ((i=0; i<n; i++)); do
        random_num=$(( (RANDOM % (MIN_VALUE - MAX_VALUE + 1)) + MIN_VALUE ))
        for j in "${nums[@]}"; do
            if [[ $j == $random_num ]]; then
                ((i--))
                break
            fi
        done
        if [[ $j != $random_num ]]; then
            nums+=($random_num)
        fi
    done
    echo "${nums[@]}"
}

printList() {
    local nums=($1)
    local num
    for num in "${nums[@]}"; do
        echo $num
    done
}

checkDuplicates() {
    local nums=($1)
    local num
    for num in "${nums[@]}"; do
        count=0
        for check_num in "${nums[@]}"; do
            if [[ $num == $check_num ]]; then
                ((count++))
            fi
        done
        if [[ $count -gt 1 ]]; then
            echo "Duplicate found: $num"
            return 1
        fi
    done
    echo "No duplicates found"
    return 0
}

checkProgramValidity() {
    local program=$1
    if ! [ -x "$(command -v $program)" ]; then
         echo -e "\033[31mUsage: \"$program\" is not a valid program." >&2
        exit 1
    fi
}

checkProgramName() {
    local program=$1
    if [[ "$program" != "push_swap" ]]; then
        echo -e "\033[31mError: \"$program\" is not a valid program name. It should be 'push_swap'.\033[0m" >&2
        exit 1
    fi
}



if [[ $# -lt 2 ]]; then
     echo -e "\033[31mUsage: $0 <program> <number of tests> <number of random numbers>\033[0m" >&2
    exit 1
fi

clear
program=$1
num_tests=$2
num_randoms=$3
checkProgramValidity $program
checkProgramName $program

    for ((i=0; i<num_tests; i++)); do
        nums=$(generateRandomNumbers $num_randoms)
        export ARG="$nums"
        echo "=  =   =   =   =   =   ="
        printList "$nums"
        echo "=  =   =   =   =   =   ="
        checkDuplicates "$nums"
        output=$($program $ARG | wc -l)
        lines=$(echo "$output")
        total_lines=$((total_lines + lines))
        echo "nombre d'operation effectue : $output";
        output=$($program $ARG | ./checker_linux $ARG)
        echo "le programme a bien trie les nombre ? $output";
        echo "-  -   -   -   -   -   -"
        sleep 2
    done

average_lines=$(($total_lines / $num_tests))
echo "la moyenne des resultat genere pour $num_tests est egale a : $average_lines"