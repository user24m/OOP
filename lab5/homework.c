#include<stdlib.h>
#include "sort.h"
#define max(a,b) (a>b)?(a):(b)
#define min(a,b) (a<b)?(a):(b)
void minim_maxim(int* a,int k,int p, int* m,int* M)
{
    if(k==p)
      *m=*M=a[k];
    else
      if(k<p)
      {
        int mini1,maxi1,mini2,maxi2;
        minim_maxim(a,k,(k+p)/2,&mini1,&maxi1);
        minim_maxim(a,(k+p)/2+1,p,&mini2,&maxi2);
        *m=min(mini1,mini2);
        *M=max(maxi1,maxi2);

      }
}
void solve_problem_3(int* a ,int n)
{
    quick_sort(a,0,n-1);
    int temp[n];
    int i=0,j=n-1;
    int k=-1;
    while(i<j)
       {
           temp[++k]=a[i++];
           temp[++k]=a[j--];
       }
    for(int i=0;i<n;i++)
        a[i]=temp[i];

}
