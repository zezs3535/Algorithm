from collections import deque
if __name__=="__main__":
    test=int(input())
    for i in range(test):
        ins=input()
        strlength=int(input())
        a=deque()
        flag=True
        if strlength==0:
            if 'D' in ins:
                q=input()
                flag=False
            if 'R' in ins:
                q=input()
        else:
            tmp=input()
            tmp=tmp[1:-1]
            a=deque(map(int,tmp.split(',')))
        idx=0
        for j in ins:
            if j=='R':
                idx^=1
            if j=='D':
                if a==deque():
                    print('error')
                    flag=False
                    break
                if idx==0:
                    a.popleft()
                elif idx==1:
                    a.pop()
        if flag==True:
            if idx==1:
                a.reverse()
            a=str(list(a))
            print(a.replace(' ',''))