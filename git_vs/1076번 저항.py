col=['black','brown','red','orange','yellow','green','blue','violet','grey','white']
col_index=[i for i in range(10)]
num=[0]
color=input()
if color!='black':
    num.append(col.index(color))
    color=input()
    num.append(col.index(color))
else:
    color=input()
    if color!='black':
        num.append(col.index(color))
a=''.join(list(map(str,num)))
a=int(a)
color=input()
print(a*(10**(col.index(color))))