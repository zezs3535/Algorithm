from itertools import *
import time

if __name__=="__main__":
    n,k=map(int,input().split())
    alpha=[]
    words=[]
    answer=0
    for i in range(n):
        word=input()
        words.append(set(list(word)))
        for j in word:
            if j not in alpha:
                alpha.append(j)

    li=list(combinations(alpha,k))
    print(len(li))
    for alphabet in li: #배울 수 있는 알파벳 조합
        for word in words: #단어
            cnt=0
            for i in word: #알파벳
                if i in alphabet:
                    cnt+=1
                else:
                    break
                if cnt==len(word):
                    answer+=1        

    print(answer)