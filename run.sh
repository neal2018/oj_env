## build and run file once
# g++.exe --std=c++17 -g roundc/A.cpp -o main.exe && ./main.exe < input.txt > output.txt

## local interact test
# python croupier.py ./main "python gen.py"

## single file stress test
# i=0
# while python gen.py >input.txt && ./main <input.txt; do
#   i=$(expr $i + 1)
#   echo $(date +"%I:%M:%S.%3N") AC ON TEST $i
# done

# two files stress test
i=0
while true; do
  i=$(expr $i + 1)
  python gen.py >input.txt
  if ! ./bf <input.txt >tmp_bf.out; then
    echo $(date +"%I:%M:%S.%3N"): RE ON TEST $i \(BF\)
    exit 0
  fi

  if ! ./main <input.txt >tmp_sol.out; then
    echo $(date +"%I:%M:%S.%3N"): RE ON TEST $i \(SOL\)
    exit 0
  fi

  if diff tmp_bf.out tmp_sol.out; then
    echo $(date +"%I:%M:%S.%3N"): AC ON TEST $i
  else
    echo $(date +"%I:%M:%S.%3N"): WA ON TEST $i
    exit 0
  fi
done
