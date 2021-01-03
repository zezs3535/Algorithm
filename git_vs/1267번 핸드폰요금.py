test=int(input())
Y=[]
M=[]
n=[]
st=input().split(' ')
for i in st:
    n.append(int(i))
j=0
for i in range(test):
    q=0
    while True:
        if (q*30)<=n[j] and ((q+1)*30>n[j]):
            Y.append(10+(10*q))
            M.append(15+(15*(q//2)))
            break
        q+=1
    j+=1
if sum(Y)>sum(M):
    print('M',sum(M))
elif sum(Y)<sum(M):
    print('Y',sum(Y))
else:
    print('Y M',sum(Y))
