#!/bin/bash

time_base36=$(date +%Y%m%d%H%M%S | python3 -c "import base36; print(base36.dumps(int(input())).upper())")
random_value=$(cat /dev/urandom | tr -dc 'A-Z0-9' | fold -w 23 | head -n 1)

for i in $(seq 0 8); do
  echo -n "${time_base36:$i:1}${random_value:$i:1}"
done
for i in $(seq 9 22); do
  echo -n "${random_value:$i:1}"
done
echo