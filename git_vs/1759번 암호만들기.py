from itertools import combinations

mo=['a','e','i','o','u']

if __name__=="__main__":
    l,c=map(int,input().split())
    li=list(input().split())
    li.sort()
    pwd=list(combinations(li,l))
    answer=[]
    for i in pwd: #acis
        
        tmp=''.join(i)
        jcnt=0
        mcnt=0
        
        for j in tmp:
            if j in mo:
                mcnt+=1
            else:
                jcnt+=1
            if jcnt>1 and mcnt>0:
                answer.append(tmp)
                break
    for i in answer:
        print(i)
        
