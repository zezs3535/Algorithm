n,m=map(int,input().split())
dict={}
for i in range(n):
    url=input().split()
    dict.update({url[0]:url[1]})
    
for i in range(m):
    url=input()
    print(dict[url])
