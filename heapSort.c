#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define N 10

void heap(int arr[],int n, int i,int operaciones[1])
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
        operaciones[0]=operaciones[0]+1;
        heap(arr,n,l,operaciones);
    }
}

void heapSort(int arr[],int n,int iteraciones[1],int operaciones[1])
{   int i,aux;
    for(i=n/2-1;i>=0;i--)
    {   heap(arr,n,i,operaciones);
    }
    for(i=n-1;i>=0;i--)
    {   aux=arr[i];
        arr[i]=arr[0];
        arr[0]=aux;
        iteraciones[0]=iteraciones[0]+1;
        heap(arr,i,0,operaciones);
    }
}

int main()
{   int iteraciones[1]={0};
    int operaciones[1]={0}; 
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
    heapSort(arr,N,iteraciones,operaciones);
    for(i=0;i<N;i++)
    {   printf("%i ", arr[i]);
    }
    printf("\nIteraciones: %i", iteraciones[0]);
    printf("\nOperaciones: %i", operaciones[0]);
    return 0;
}

