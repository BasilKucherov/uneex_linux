#!/bin/bash

delay=${1:-0.1}

rows=()
cols=()
syms=()

cur_col=0
cur_row=0

art=$(cat)
for ((i = 0; i < ${#art}; i++)); do
  cur_sym="${art:$i:1}"

  if [ "$cur_sym" = $'\n' ]; then 
    cur_row=$((cur_row + 1))
    cur_col=0
    continue
  fi

  if [ "$cur_sym" != " " ] && [ "$cur_sym" != $'\n' ]; then
    rows+=($cur_row)
    cols+=($cur_col)
    syms+=($cur_sym)
  fi

  cur_col=$((cur_col + 1))
done

permutation=$(shuf -i 0-$((${#rows[@]} - 1)))
tput clear

for i in $permutation; do
  tput cup ${rows[i]} ${cols[i]}
  echo -n ${syms[i]}
  sleep $delay
done

tput cup $(tput lines) 0
