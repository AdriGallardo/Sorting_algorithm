import random

N=10
def particion(arr,l,h):
    pivot=arr[h]
    i=l-1
    for j in range(l,h):
        if arr[j]<=pivot:
            i=i+1
            aux=arr[i]
            arr[i]=arr[j]
            arr[j]=aux
    aux1=arr[i+1]
    arr[i+1]=arr[h]
    arr[h]=aux1
    return i+1;

def quickSort(arr,l,h):
    if l<h:
        p=particion(arr,l,h)
        quickSort(arr,l,p-1)
        quickSort(arr,p+1,h);

arr=[]
for i in range(N):
    v=random.randint(0,N)
    arr.append(v)
print(arr)
quickSort(arr,0,N-1)
print(arr)
