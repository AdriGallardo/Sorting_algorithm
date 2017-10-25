import random

N=10

def heap(arr,n,i):
    l=i
    izq=2*i+1
    der=2*i+2
#comparar hijos con padre
    if izq < n and arr[i]<arr[izq]:
        l=izq
    if der < n and arr[l]<arr[der]:
        l=der
#cambiar raiz
    if l != i:
        aux=arr[i]
        arr[i]=arr[l]
        arr[l]= aux
        heap(arr,n,l) 
        
def heapSort(arr):
    n=len(arr)
    for i in range(n,-1,-1):
        heap(arr,n,i)
    for i in range(n-1,0,-1):
        aux=arr[i]
        arr[i]=arr[0]
        arr[0]=aux
        heap(arr,i,0)

arr=[]
for i in range(N):
    v=random.randint(0,N)
    arr.append(v)

print arr
heapSort(arr)
print arr
