s = input()
t = s.split("()")
if (len(t) != 2):
  print("fix")
elif "(" in t[0] or ")" in t[0]:
  print("fix")
elif "(" in t[1] or ")" in t[1]:
  print("fix")
elif len(t[0]) != len(t[1]):
  print("fix")
else:
  print("correct")
