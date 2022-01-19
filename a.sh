# while sh run.sh ;
while python a.py > input.txt && ./main.exe < input.txt ;
do
  echo $(date +"%I:%M:%S")
done