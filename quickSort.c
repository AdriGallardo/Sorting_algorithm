#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define N 10

int particion(int arr[],int l,int h,int operaciones[1])
{   int pivot=arr[h];
    int i= l-1;
    int j,aux,aux1;

    for(j=l;j<=h-1;j++)
    {   if(arr[j]<=pivot)
        {
            i++;
            aux=arr[i];
            arr[i]=arr[j];
            arr[j]=aux;
            operaciones[0]=operaciones[0]+1;
        }
    }
    aux1=arr[i+1];
    arr[i+1]=arr[h];
    arr[h]=aux1;
    operaciones[0]=operaciones[0]+1;
    return i+1;
}

void quickSort(int arr[],int l, int h,int iteraciones[1],int operaciones[1])
{   int p;
    iteraciones[0]=iteraciones[0]+1;
    if(l<h)
    {   p=particion(arr,l,h,operaciones);
        quickSort(arr,l,p-1,iteraciones,operaciones);
        quickSort(arr,p+1,h,iteraciones,operaciones);   
    }
}
int main()
{   
    int arr[N]={0};
    int i=0;
    int v=0;
    int iteraciones[1]={0};
    int operaciones[1]={0};
    srand(time(NULL));
    for(i=0;i<N;i++)
    {
        v=rand()%N;
        arr[i]=v;
    }
    for(i=0;i<N;i++)
    {   printf("%i ",arr[i]);
    }
    printf("\n");
    quickSort(arr,0,N-1,iteraciones,operaciones);
    for(i=0;i<N;i++)
    {   printf("%i ",arr[i]);
    }
    printf("\nIteraciones: %i",iteraciones[0]);
    printf("\nOperaciones: %i",operaciones[0]);
}
