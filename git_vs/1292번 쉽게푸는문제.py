in1,in2=map(int,input().split())
a=[]
s=0
for i in range(1,47):
    for j in range(i):
        a.append(i)
        if len(a)==1000:
            break
    if len(a)==1000:
        break
print(sum(a[in1-1:in2]))
