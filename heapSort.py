import random

N=10

def heap(arr,n,i,operaciones):
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
        operaciones[0]=operaciones[0]+1
        heap(arr,n,l,operaciones) 
        
def heapSort(arr,iteraciones,operaciones):
    n=len(arr)
    for i in range(n,-1,-1):
        heap(arr,n,i,operaciones)
    for i in range(n-1,0,-1):
        aux=arr[i]
        arr[i]=arr[0]
        arr[0]=aux
        iteraciones[0]=iteraciones[0]+1
        heap(arr,i,0,operaciones)

iteraciones=[0]
operaciones=[0]
arr=[]
for i in range(N):
    v=random.randint(0,N)
    arr.append(v)

print arr
heapSort(arr,iteraciones,operaciones)
print arr
print "Iteraciones: ",iteraciones[0]
print "Operaciones: ",operaciones[0]
