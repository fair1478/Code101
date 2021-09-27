#include<stdio.h>

int A[10];

main()
{
	for(int i=0;i<10;i++)
		{
		scanf("%d",&A[i]);
		}

	for(int i=1;i<9;i++)
		if((A[i+1]%2)+(A[i-1]%2)==2)
			{
				printf("%d ",A[i]);
			}
	
	return 0;
}
