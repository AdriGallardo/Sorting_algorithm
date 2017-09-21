
n=10000

def bubbleSort(arr):
    operaciones=0
    iteraciones=0
    ban=0
    for j in range(0,n):
        if j>=1 and ban==0:
            break
        ban=0
        for i in range(0,n-j-1):
            iteraciones=iteraciones+1
            if(arr[i] > arr[i+1]):
                a=arr[i]
                arr[i]=arr[i+1]
                arr[i+1]=a
                operaciones=operaciones+1
                ban=ban+1
    print operaciones
    print iteraciones


archivo= open("random_words.txt","r")
contenido= archivo.read()

#print contenido
arr=contenido.split('\n')
arr.pop(n)
#print arr

bubbleSort(arr)
#print arr
