#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 4

void bubbleSort(char s[N][256])
{   int i,k,j;
    char a[256]={0};
    int iteraciones=0;
    int operaciones=0;
    for(j=0;j<N;j++)
    {     if(j>=1 && operaciones==0)
          { break;
          }
        for(i=0;i<N-j-1;i++)
        {   
            iteraciones=iteraciones+1;
   //         printf("%i\n",i);
            if(strcmp(s[i],s[i+1])>0)
            {  
                strcpy(a,s[i]);
                strcpy(s[i],s[i+1]);
                strcpy(s[i+1],a);
                operaciones=operaciones+1;
            }
        }
    }
    printf("Operaciones: %d",operaciones);
    printf("Iteraciones: %d",iteraciones);
}

int main()
{   int v=0;
    int i=0;
    char arr[N][256]={0};
    char str[256];
 
    FILE *f=fopen("texto.txt","r");
    if (!f)
    {  perror("Error al abrir el archivo");
    }
    //Read File
    i=0;
    while(fgets(str,256,f))
    {
      strcpy(arr[i],str);
//      printf("%s",arr[i]);
      i++;
    }
    fclose(f);
    
    bubbleSort(arr);
/*
    for(i=0;i<N;i++)
    { printf("%s",arr[i]);
    }

*/ 
    return 0;
}
