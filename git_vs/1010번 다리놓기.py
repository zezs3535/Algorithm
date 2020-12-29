from math import *
fac=factorial
t=int(input())
for i in range(t):
    n,k=map(int,input().split())
    print(fac(k)//(fac(n)*fac(k-n)))