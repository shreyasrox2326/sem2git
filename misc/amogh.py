x=input("Enter string of numbers:\n")
y='['
for i in x:
    if i==' ':
        y+=','
    else:
        y+=i
y+=']'
z=eval(y)
flag=0
for i in range(len(z)):
    if z[i]==z[len(z)-1-i]:
        flag=0
    else:
        flag=1
if flag:
    print("string is not a palindrome.")
else:
    print("string is a palindrome")