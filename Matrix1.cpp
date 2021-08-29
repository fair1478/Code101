#include<stdio.h>
int A[1000][1000],B[1000][1000];
int main()
{
    int a,b,i,j;
    scanf("%d %d",&a,&b);
    
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            scanf("%d",&B[i][j]);
        }
    }
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            printf("%d ",A[i][j]+B[i][j]);
        }
        printf("\n");
    }
    return 0;
}
