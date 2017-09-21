#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10000

void bubbleSort(int a[N])
{   int i=0;
    int j=0;
    int a1;
    int a2;
    for(j=0;j<N;j++)
    {
        for(i=0;i< N-j-1;i++)
        {   if(a[i]> a[i+1])
            {   a1=a[i];
                a2=a[i+1];
                a[i]=a2;
                a[i+1]=a1;     
            }                     
        }
    }
}

int main()
{    int arr[N]={0};
     int i=0;
     int v=0;

     srand(time(NULL));
     for(i=0;i<N;i++)
     {    v=rand()%N;
          arr[i]=v;
  //        printf("%d ",arr[i]);
     }
//     printf("\n");
     bubbleSort(arr);
/*     for(i=0;i<N;i++)
     {  printf("%d ",arr[i]);
     }
     printf("\n"); */
     return 0;

}
