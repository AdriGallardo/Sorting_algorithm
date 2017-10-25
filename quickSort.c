#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define N 10

int particion(int arr[],int l,int h)
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
        }
    }
    aux1=arr[i+1];
    arr[i+1]=arr[h];
    arr[h]=aux1;
    return i+1;
}

void quickSort(int arr[],int l, int h)
{   int p;
    if(l<h)
    {   p=particion(arr,l,h);
        quickSort(arr,l,p-1);
        quickSort(arr,p+1,h);   
    }
}
int main()
{
    int arr[N]={0};
    int i=0;
    int v=0;
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
    quickSort(arr,0,N-1);
    for(i=0;i<N;i++)
    {   printf("%i ",arr[i]);
    }
}
