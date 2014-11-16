/**************************************************************************
** 		      This code is part of BasketofNano Program                  **
** This C-code is designed for determining crystal size of nanoparticles,**
** based on the well-known Scherrer equation.                            **
**************************************************************************/
#include <stdio.h>
#include <math.h>

#define lambda  0.154056
#define pi	3.1415926

int main(void)
{
		double d,theta,B;

again: 	printf("Input the Theta and B:(input 0 0 to exit)\n");
		scanf("%lf %lf", &theta,&B);
		if(theta == 0 && B == 0) goto next;	
		theta = theta*pi/180;
		B = B*pi/180;
		d=0.89*lambda/(B*cos(theta));
		printf("%lf nm\n", d);
		goto again;
		
next:	return 0;

}