from collections import deque

if __name__=="__main__":
    n,w,l=map(int,input().split())
    truck=[*map(int,input().split())]
    bridge=deque()
    truckSum=0
    time=0
    for i in range(n):
        while(True):
            if(len(bridge)==w):
                truckSum-=bridge[0]
                bridge.popleft()
            if(truckSum+truck[i]>l):
                bridge.append(0)
                time+=1
            else:
                bridge.append(truck[i])
                truckSum+=truck[i]
                time+=1
                break
    time+=w
    print(time)
