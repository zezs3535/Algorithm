n=int(input())
exp={}
for i in range(n):
    s=input().split('.')
    if s[1] in exp:
        cnt=exp[s[1]]
        exp[s[1]]=cnt+1
    else:
        exp[s[1]]=1

tmp=sorted(exp.items())
for i in tmp:
    print(i[0],i[1])