#include<stdio.h>
int main() 
{
  int a,b,p,s=0;
  scanf("%d %d",&a,&b);
  if(a>b)
  {
  p=a;
  a=b;
  b=p;
  }
  if(a==b)
  printf("%d",a);
  if(a<b)
  {
printf("%d",(((b-a)+1)*(a+b))/2);
  }

}
