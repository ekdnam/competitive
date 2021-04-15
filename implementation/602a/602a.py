nx=input()
bx=input()
d_nx=input()
d_nx=d_nx.split()
ny=input()
by=input()
d_ny=input()
d_ny=d_ny.split()
d_nx=d_nx.reverse()
d_ny=d_ny.reverse()
x=0
ite=0
for val in d_nx:
    x += val*(10**ite)
    ite += 1
y=0
ite=0
for val in d_ny:
    y += val*(10**ite)
    ite+=1
if x > y:
    print('>')
elif x < y:
    print('<')
else:
    print('+')
