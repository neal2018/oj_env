# while sh run.sh ;
# while python3 a.py > input.txt && ./main < input.txt ;
# do
#   echo $(date +"%I:%M:%S")
# done
while true; do
  python3 a.py > input.txt
  ./bf < input.txt > tmp.out
  ./main < input.txt > tmp2.out 
  if diff tmp.out tmp2.out; then
    echo AC $(date +"%I:%M:%S")
  else
    echo WA
    exit 0
  fi
done