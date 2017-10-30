import random

n=10

def insertSort(arr,iteraciones,operaciones):
    arr2=[]
    arr2.append(arr[0])
    for i in range(1,len(arr)):  
        k=0
        iteraciones[0]=iteraciones[0]+1
        for j in range(0,i):
            if arr[i] < arr2[j]:
                arr2.insert(j,arr[i])
                k=1
                operaciones[0]=operaciones[0]+1
                break
        if k==0:
       #     print len(arr2)
            arr2.insert(len(arr2),arr[i])
    print arr2



arr=[]
iteraciones=[0]
operaciones=[0]
for i in range(n):
    v=random.randint(0,n)
    arr.append(v)
print(arr)
insertSort(arr,iteraciones,operaciones)
print "Iteraciones: ",iteraciones[0]
print "Operaciones: ",operaciones[0]
