#include<stdio.h> 
int* fibo(int n,int *f) 
{
  f[0] = 0; 
  f[1] = 1; 
  for (int i = 2; i <= n; i++) 
      f[i] = f[i-1] + f[i-2];  
  return f[n]; 
} 
  
int main () 
{ 
  int n;
  printf("no. of terms: ");
  scanf("%d",&n);
  int f[n+2];
  fibo(n,f);
    for(int i=0;i<n;i++)
        printf(" %d ",f[i]);
  return 0; 
} 