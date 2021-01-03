l=int(input())
stick=64
cnt=0
while l:
    while stick>l:
        stick/=2
    l-=stick
    cnt+=1
print(cnt)
