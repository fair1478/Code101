#include<stdio.h>
int n=0;
char c[1000];
int sum;
int main() 

{	int d;
    int r=1;
    scanf("%s",c);
    for(int i=0;c[i]<='\0';i++)
    {
          if(c[i]>='0'&&c[i]<='9')
            {
            c[i]-48;
            c[i]=c[i]*r;
            int sum=sum+c[i];
            r=r*10;
            }
          else
            printf("ERROR");
    }
    if(sum>0)
    
    int w = sum/2; d=(sum%2)+1;
    printf("Takes about %d weeks %d days",sum,d);
    return 0;
}
