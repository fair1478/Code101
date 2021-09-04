#include<stdio.h>
main()
{
	double x,y;
	scanf("%lf %lf",&x,&y);
	if(x*y!=0)
	{
	x=x/y;
	y=y*x;
	x=y/x;
	}
	else if(x==0)
	{
	x=y;
	y=0;
	}
	else
	{
	y=x;
	x=0;
	}
	printf("%.16lf %.16lf",x,y);
}
