## build and run file once
# g++.exe --std=c++17 -g roundc/A.cpp -o main.exe && ./main.exe < input.txt > output.txt

## local interact test
# python croupier.py ./main "python gen.py"

## single file stress test
# while python gen.py > input.txt && ./main < input.txt ;
# do
#   echo $(date +"%I:%M:%S")
# done

# two files stress test
while true; do
  python gen.py > input.txt
  ./bf < input.txt > tmp.out
  ./main < input.txt > tmp2.out 
  if diff tmp.out tmp2.out; then
    echo AC $(date +"%I:%M:%S")
  else
    echo WA
    exit 0
  fi
done
