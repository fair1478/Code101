<<<<<<< HEAD
#include<stdio.h>
#include<string.h>
int main()
{
    char n[257];
    char m[257];
    int sum1=0,sum2=0;
    scanf("%s %s", n,m);

    int r=1;
    for(int i = strlen(n)-1;i>=0;i--)
    {
        if(n[i]>='0'&&n[i]<='9')
        {
            sum1+=(n[i]-'0')*r;
        }
        else
        {
            sum1+=(n[i]-'A'+10)*r;
        }
        r*=16;
    }
    
    {
    int t=1;
    for(int i = strlen(n)-1;i>=0;i--)
    {
        if(n[i]>='0'&&n[i]<='9')
        {
            sum2+=(n[i]-'0')*t;
        }
        else
        {
            sum2+=(n[i]-'A'+10)*t;
        }
        t*=16;
    }printf("%d",sum1+sum2);

    return 0;
}
}
=======
#include<stdio.h>
#include<string.h>
int main()
{
    char n[257];
    char m[257];
    int sum1=0,sum2=0;
    scanf("%s %s", n,m);

    int r=1;
    for(int i = strlen(n)-1;i>=0;i--)
    {
        if(n[i]>='0'&&n[i]<='9')
        {
            sum1+=(n[i]-'0')*r;
        }
        else
        {
            sum1+=(n[i]-'A'+10)*r;
        }
        r*=16;
    }
    
    {
    int t=1;
    for(int i = strlen(n)-1;i>=0;i--)
    {
        if(n[i]>='0'&&n[i]<='9')
        {
            sum2+=(n[i]-'0')*t;
        }
        else
        {
            sum2+=(n[i]-'A'+10)*t;
        }
        t*=16;
    }printf("%d",sum1+sum2);

    return 0;
}
}
>>>>>>> d99286b34d2cb9067850ea12cb1ed69cfb15c849
