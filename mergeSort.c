#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define N 100

void printA(int *arr, int n)
{
    int i=0;
    for(i=0;i<n;i++)
        printf("[%i], ",arr[i]);
    printf("\n");
}

void merge(int arr1[],int arr2[],int arr3[], int len1,int len2,int operaciones[0])
{   
    int i=0,j=0;
    int k;
//    printf("len1 %i len2: %i\n",len1,len2);
//    printA(arr1,len1);
//    printA(arr2,len2);
   
    k=0;
    while(i<len1 || j<len2)
    {   operaciones[0]=operaciones[0]+1;
        if(i>=len1)
        {   arr3[k]=arr2[j];
            j=j+1;
        }
        else
        {   if(j>=len2)
            {   arr3[k]=arr1[i];
                i=i+1;
            }
            else
            {   if(arr1[i]<arr2[j])
                {   arr3[k]=arr1[i];
                    i=i+1;
                }
                else
                {   arr3[k]=arr2[j];
                    j=j+1;
                }
            }
        }
        k=k+1;
    }
}

int *mergeSort(int *arr, int len,int iteraciones[1],int operaciones[1])
{   iteraciones[0]=iteraciones[0]+1;
    int i;    
    int y;
//    printf("Len: %d\n", len);
    int *a=malloc(sizeof(int)*len);
    if(len == 1)
    {   
//        printf("Base case reached\n");
        a=arr;
        return a;
    }
    int *arr1=malloc(sizeof(int)*len/2);
    int *arr2=malloc(sizeof(int)*(len-(len/2)));
    int *arr3=malloc(sizeof(int)*len);
    int j=0;
    for(i=0;i<len;i++)
    {
        if(i<len/2)
            arr1[i]=arr[i];
        else
        {    arr2[j]=arr[i];
             j++;
        }
    }
    arr1=mergeSort(arr1,len/2,iteraciones,operaciones);
    arr2=mergeSort(arr2,len-(len/2),iteraciones,operaciones);
/*    printf("Merging...\n");
    printf("arr1\n");
    printA(arr1,len/2);
    printf("arr2\n");
    printA(arr2,len-len/2);
*/
    merge(arr1,arr2,arr3,len/2,len-(len/2),operaciones);
    a=arr3;
    return a;     
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
    {
        printf("%i ", arr[i]);   
    }

    int *a=mergeSort(arr,N,iteraciones,operaciones);   
    printf("\n");
    for(i=0;i<N;i++)
        printf("%i ",a[i]);
    printf("\nIteraciones: %i",iteraciones[0]);
    printf("\nOperaciones: %i",operaciones[0]);
}
