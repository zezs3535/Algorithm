# -*- coding: utf-8 -*-
"""
Created on Wed Jul 29 16:18:32 2020

@author: user
"""

import sys
input=sys.stdin.readline

def binarySearch(n, narray, key):
    l=0
    r=n-1
    mid=(l+r)//2
    while l<=r:
        if narray[mid]<key:
            l=mid+1
            mid=(l+r)//2
        elif narray[mid]>key:
            r=mid-1
            mid=(l+r)//2
        else:
            print(1)
            return
    print(0)
    return 

if __name__=="__main__":
    n=int(input())
    narray=list(map(int,(input().strip()).split()))
    narray.sort()
    m=int(input())
    marray=list(map(int,input().split()))
    for i in range(m):
        tmp=marray[i]
        binarySearch(n, narray, tmp)
