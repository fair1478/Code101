#include<stdio.h>
main(){
	int a,i=1;
	scanf("%d",&a);
	int A=(a*2)-1;
	int B;
	for(;i<=(a*2)-1;i++)
	{
		
		if(i<a)
			{
			for(int j=1;j<=i;j++)
			printf("* ");
			for(int j=1;j<=A-(i*2);j++)
			printf("  ");
			for(int j=1;j<=i;j++)
			printf("* ");
		printf("\n");
			}
		else if(i==a)
			{
			for(int j=1;j<=A;j++)
			printf("* ");
			printf("\n");
			}
			
		else
			{
			for(int j=1;j<=a-(i-a);j++)
			printf("* ");
			for(int j=1;j<=((i-a)*2)-1;j++)
			printf("  ");
			for(int j=1;j<=a-(i-a);j++)
			printf("* ");
			printf("\n");
			}	
	}
}
