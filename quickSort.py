import random

N=10
def particion(arr,l,h,operaciones):
    pivot=arr[h]
    i=l-1
    for j in range(l,h):
        if arr[j]<=pivot:
            i=i+1
            aux=arr[i]
            arr[i]=arr[j]
            arr[j]=aux
            operaciones[0]=operaciones[0]+1
        
    aux1=arr[i+1]
    arr[i+1]=arr[h]
    arr[h]=aux1
    operaciones[0]=operaciones[0]+1
    return i+1;

def quickSort(arr,l,h,iteraciones,operaciones):
    iteraciones[0]=iteraciones[0]+1
    if l<h:
        p=particion(arr,l,h,operaciones)
        quickSort(arr,l,p-1,iteraciones,operaciones)
        quickSort(arr,p+1,h,iteraciones,operaciones);

iteraciones=[0]
operaciones=[0]
arr=[]
for i in range(N):
    v=random.randint(0,N)
    arr.append(v)
print(arr)
quickSort(arr,0,N-1,iteraciones,operaciones)
print(arr)
print "Iteraciones: ",iteraciones[0]
print "Operaciones: ",operaciones[0]
