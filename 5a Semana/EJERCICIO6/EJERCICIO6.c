//Programa que calcula el porcentage de caráctetes que se utilizan en un fichero de texto.

#include <stdio.h>
#include <stdlib.h>


int main (){
	FILE *fp;
	int estadistica[256];
	int i;
	float total=0;
	long num=0;
	for(i=0;i<256;i++){
		estadistica[i]=0;
	}
	int a, media=0;
	fp = fopen ("fichero.txt", "r");
	while((a=fgetc(fp))!=EOF){
		estadistica[a]++;
		num++;
	}
	
	for (i=0; i<256; i++){
		if(estadistica[i]!=0){
			printf("\nEl numero de veces que aparece el caracter %3c en el fichero es %3d y su porcentaje es %5.3f  \n\n",(char)i,estadistica[i],(((float)estadistica[i])/num)*100);
			total+=(((float)estadistica[i])/num)*100;
		}
	}
	fclose(fp);
	printf("La suma del porcentaje total es %5.3f\n",total);
	return 0;
}