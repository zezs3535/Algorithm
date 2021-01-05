t=int(input())
dp=[0]*10002
dp[1]=1
for i in range(2,10001):
    dp[i]=dp[i-1]+dp[i-2]

for i in range(t):
    p,q=map(int,input().split())
    print("Case #",end="")
    print(i+1,end="")
    print(":",dp[p]%q)