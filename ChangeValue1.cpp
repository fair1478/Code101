#include<stdio.h>
main()
{
	double x,y;
	scanf("%lf %lf",&x,&y);
	x=y-x;
	y=y-x;
	x=y+x;
	printf("%.16lf %.16lf",x,y);
}
