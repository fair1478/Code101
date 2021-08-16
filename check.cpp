<<<<<<< HEAD
#include<stdio.h>
char c[1000];
int main() 
{
  int a=0;
  scanf("%[^\n]",c);
  for(int i=0;c[i]!='\0';i++)
  {if(c[i]=='.')
  {
    printf("FALSE");
    a=0;
    break;
  }
  else
  a=1;
 }
 if(a)
 printf("TRUE"); 
  return 0;
}
=======
#include<stdio.h>
char c[1000];
int main() 
{
  int a=0;
  scanf("%[^\n]",c);
  for(int i=0;c[i]!='\0';i++)
  {if(c[i]=='.')
  {
    printf("FALSE");
    a=0;
    break;
  }
  else
  a=1;
 }
 if(a)
 printf("TRUE"); 
  return 0;
}
>>>>>>> d99286b34d2cb9067850ea12cb1ed69cfb15c849
