import random

n=10

def merge(arr1,arr2,operaciones):
    arr3=[]
    i=0
    j=0
    while i < len(arr1) or j<len(arr2):
        operaciones[0]=operaciones[0]+1
        if i>=len(arr1):
            arr3.append(arr2[j])
            j=j+1
        else:
            if j>= len(arr2):
                arr3.append(arr1[i])
                i=i+1
            else:
                if arr1[i]< arr2[j]:
                    arr3.append(arr1[i])
                    i=i+1
                else:
                    arr3.append(arr2[j])
                    j=j+1
    return arr3
      
def mergeSort(arr,iteraciones,operaciones):
    iteraciones[0]=iteraciones[0]+1
    if len(arr)==1: 
        return arr
    arr1=mergeSort(arr[:(len(arr)/2)],iteraciones,operaciones)
    arr2=mergeSort(arr[(len(arr)/2):],iteraciones,operaciones)
    
    return merge(arr1,arr2,operaciones)

iteraciones=[0]
operaciones=[0]
arr=[]
for i in range(n):
    v=random.randint(0,n)
    arr.append(v)

print arr
a=mergeSort(arr,iteraciones,operaciones)

print a
print "Iteraciones: ",iteraciones[0]
print "Operaciones: ",operaciones[0]
