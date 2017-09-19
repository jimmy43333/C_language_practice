#include <stdlib.h>     
#include <string.h>     
#include <stdio.h>     
#include <math.h>     
#define TRUE 1
#define FALSE 0

int main(int argc,char *argv[])
{   
	FILE *fp;
	int i,j,k,num,nrows,ncols, npixel;
	float xlen,ylen,sizex,sizey;
	unsigned char ** image, c, noprint=FALSE  /* texmode=FALSE */  ;
	
	//read input
	if (argc<=6) {
		fprintf(stderr,"\nlaser lenna 512 512 4.5 6.0 3.5 3.5 [+T]>lenna.ps\n");
		exit(-1); };
	fp=fopen(argv[1],"r");
	sscanf(argv[2],"%d",&nrows);
	sscanf(argv[3],"%d",&ncols);
	sscanf(argv[4],"%f",&xlen);
	sscanf(argv[5],"%f",&ylen);
	sscanf(argv[6],"%f",&sizex);
	sscanf(argv[7],"%f",&sizey);

	if (argc>8)
		for(i=0;i<strlen(argv[8]);i++) { 
			c= *(argv[8]+i); 
			switch(c) {
				case '+': noprint=TRUE; break;
						  /*  case 'T': texmode=TRUE; break;  */
				default: fprintf(stderr,"\ninvalid option: %c",c);
			};
		}
	
	//read the images
	npixel = nrows*ncols;
	image=(unsigned char **) malloc(nrows*sizeof(unsigned char *));
	if (image==NULL) return(NULL); 
	for (i=0; i<nrows; i++) {
		image[i]=(unsigned char *) malloc(ncols*sizeof(unsigned char));
		if (image[i]==NULL) return(NULL); 
	}

	for(i=0; i<nrows; i++) {
		for(j=0; j<ncols; j++) {
			fscanf(fp,"%c",&c);
			image[i][j]=c;
			if (feof(fp))
			{fprintf(stderr,"\nError: too small picture array\n"); exit(-1); };
		}
	}  
	fprintf(stdout,"%%! Raw to PostScript by Chaur-Chin Chen on 2/21/2002\n");
	fprintf(stdout,"gsave\n"); 
	/*if (!texmode)*/   fprintf(stdout,"initmatrix\n");
	fprintf(stdout,"/picstr %d string def\n",ncols);
	fprintf(stdout,"%d %d translate",(int)(72.0*xlen),(int)(72.0*ylen));
	fprintf(stdout,"\n%d %d scale",(int)(72.0*sizex),(int)(72.0*sizey));
	fprintf(stdout,"\n%d %d 8 [%d 0 0 -%d 0 %d]",ncols,nrows,ncols,nrows,nrows);
	fprintf(stdout," {currentfile picstr readhexstring pop} image\n");

	num=0;
	for(i=0; i<nrows; i++) {
		for(j=0; j<ncols; j++) {
			k=(int) image[i][j];
			if (k<16)
				fprintf(stdout,"0%x",k);
			else
				fprintf(stdout,"%2x",k);
			num++; if (num==40) {num=0; fprintf(stdout,"\n");}
		}
	}
	fprintf(stdout,"\ngrestore");
	if  /*(!texmode)&&*/ (!noprint)  fprintf(stdout,"\nshowpage\n");
	else fprintf(stdout,"\n");  exit(0);

	
	for(i = 0;i<nrows;i++){
		free(image[i]);	
	}
	free(image);
}	
