s = input()
s = '7' + s
s=s.replace('4', '0')
s=s.replace('7', '1')
print(int(s,2) - 1)