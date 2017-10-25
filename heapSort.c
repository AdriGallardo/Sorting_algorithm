#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define N 10

void heap(int arr[],int n, int i)
{   int l=i;
    int izq=2*i+1;
    int der=2*i+2;
    int aux;
//comparar hijos con el padre
    if(izq < n && arr[l]<arr[izq])
    {   l=izq;
    }
    if(der < n && arr[l] <arr[der])
    {   l=der;
    }
//cambiar la raiz
    if(l != i)
    {   aux=arr[i];
        arr[i]=arr[l];
        arr[l]=aux;
        heap(arr,n,l);
    }
}

void heapSort(int arr[],int n)
{   int i,aux;
    for(i=n/2-1;i>=0;i--)
    {   heap(arr,n,i);
    }
    for(i=n-1;i>=0;i--)
    {   aux=arr[i];
        arr[i]=arr[0];
        arr[0]=aux;
        heap(arr,i,0);
    }
}

int main()
{   
    int arr[N]={0};
    int i=0;
    int v=0;
    srand(time(NULL));
    for(i=0;i<N;i++)
    {   v=rand()%N;
        arr[i]=v;
    }
    for(i=0;i<N;i++)
    {   printf("%i ",arr[i]);
    }
    printf("\n");
    heapSort(arr,N);
    for(i=0;i<N;i++)
    {   printf("%i ", arr[i]);
    }
    return 0;
}

