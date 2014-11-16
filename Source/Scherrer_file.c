/**************************************************************************
** 		      This code is part of BasketofNano Program                  **
** This C-code is designed for determining crystal size of nanoparticles,**
** based on the well-known Scherrer equation.                            **
** The input and the output are files from this code.                    **
**************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define lambda  0.154056
#define pi	3.1415926
#define linenum 1000

int main(void)
{
	FILE *data, *out;
	double xrd[linenum][3],temp1,temp2;
	char c;
	int i;
	
	data = fopen("xrd.txt","rt");
	out  = fopen("xrd_result.txt","wt");
	if(data == NULL){
		printf("xrd.txt does not exit! Please check your file name.");
		return 1;
	}
	
	fprintf(out,"Sample\t 2Theta\t FWHM\t Crystal-Size\n");
	for (i=0;i<linenum;i++){
		fscanf(data,"%lf %lf", &xrd[i][0],&xrd[i][1]);
		temp1 = xrd[i][0];
		temp2 = xrd[i][1];
		temp1 = temp1*pi/180;
		temp2 = temp2*pi/180;
		xrd[i][2] = 0.89*lambda/(temp2*cos(temp1));
		fprintf(out,"%d\t%g\t%g\t%g nm\n",i+1,xrd[i][0],xrd[i][1],xrd[i][2]);
		if((c=fgetc(data)) == EOF)
			break;
	}
	fclose(data);
	fclose(out);
	return 0;
}