#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define N 10

void insertSort(int arr[N])
{   int i,k,j,t;
    int arr2[N];
    for(i=0;i<N;i++)
    {   arr2[i]=arr[i];
    }

    for(i=1;i<N;i++)
    {   k=0;
        for(j=0;j<i;j++)
        {   if(arr[i]<arr2[j])
            {  //insertar arr[i] en posicion j de arr2
                for(t=i;t>=j;t--)
                {   arr2[t]=arr2[t-1];
                    if(t==j)
                        arr2[j]=arr[i];
                }

                k=1;
                break;
            }
        }
        if(k==0)
        {    //inserta arr[i] al final de arr2 
             arr2[N-1]=arr[i];
        }
    }
    //imprime arreglo ordenado
    for(i=0;i<N;i++) 
        printf("%d ",arr2[i]);  
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
    
//imprime arreglo
    for(i=0;i<N;i++)
    {
        printf("%i ",arr[i]);
    }
    printf("\n");
    insertSort(arr);

}
