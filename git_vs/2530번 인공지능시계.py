h,m,s=map(int,input().split())
t=int(input())

s+=(t%60) #초 더하기
t//=60
m+=(t%60) #분 더하기
t//=60
h+=(t%24) #시 더하기

m+=(s//60)
s%=60
h+=(m//60)
m%=60
h%=24

print(h,m,s)