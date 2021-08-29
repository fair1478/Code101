#include<stdio.h>
int P[200][150];
int S[200][150];
main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	int y=m;
	for(int t=0;t<m*2;t++)
		{
		for(int r=0;r<n;r++)
			scanf("%d",&P[t][r]);
	}
		
	for(int t=0;t<m;t++,y++)
	{
		for(int r=0;r<n;r++)
			S[t][r]=P[t][r]+P[y][r];
}
	for(int t=0;t<m;t++)
		{
		for(int r=0;r<n;r++)
			printf("%d ",S[t][r]);
			printf("\n");
	}
	
	return 0;
		}
	
