
import random 

n=10000
def bubbleSort(arr):
    for j in range(0,n):
        for i in range(0,n-j-1):
            if arr[i] > arr[i+1]:
                a1=arr[i]
                a2=arr[i+1]
                arr[i]=a2
                arr[i+1]=a1

arr=[]
for i in range(n):
    v=random.randint(0,n)
    arr.append(v)
#print(arr)
bubbleSort(arr)
#print(arr)    
