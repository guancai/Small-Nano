/**************************************************************************
** 		      This code is part of BasketofNano Program                  **
** This C-code is designed for unit conversion between wavelength and eV.**                      
**************************************************************************/
#include <stdio.h>

int main(void)
{
	double lambda,E;
	int process;
	
next:	printf("Input the unit you want to converse: 1-wave2eV,2-eV2wave,3-quit\n");
		scanf("%d",&process);
		if(process == 3) 
			return 0;
		
	switch (process) {
		case 1:
		 	printf("Input the wavelenght: \n");
			scanf("%lf", &lambda);
			E = 2.99792e8*4.135667e-15;
			E = E/(lambda*1e-9);
			printf("%lf eV\n", E);
			goto next;	
		case 2:
			printf("Input the energy (eV): \n");
			scanf("%lf", &E);
			lambda = 2.99792e8*4.135667e-15;
			lambda = lambda*1e9/E;
			printf("%lf nm\n", lambda);
			goto next;
		default:
			printf("The number you input is incorrect!");
			break;
	}
	return 0;
}