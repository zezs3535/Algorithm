from itertools import permutations

if __name__=="__main__":
    n,key=map(int,input().split())
    li=list(map(int,input().split()))
    li.sort()

    per=list(permutations(li,key))
    for i in per:
        print(*i)
