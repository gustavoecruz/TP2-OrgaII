#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void readRGB(char *img, unsigned char *buffer, long cant) {
	FILE *imgRead = fopen(img, "rb");
	fread(buffer, cant, 1, imgRead);
	fclose(imgRead);
}

void writeRGB(char *img, unsigned char *buffer, long cant) {
	FILE *imgWrite = imgWrite = fopen(img, "wb");
	fwrite(buffer, cant, 1, imgWrite);
	fclose(imgWrite);
}

void enmascarar_c(unsigned char *a, unsigned char *b, unsigned char *mask, long cant) {
	int i=0;
	for (i; i<cant; i++) {
		if (mask[i] != 0) { 
			a[i] = b[i];
		}
	}
}

extern void enmascarar_asm(unsigned char *a, unsigned char *b, unsigned char *mask, int cant);

int main(int argc, char *argv[]) {

	char *nombreSalidaC= "salida_c.rgb";
	char *nombreSalidaAsm = "salida_asm.rgb";

	//Si me pasa menos de 6 parametro no hago nada	
	if(argc < 6) {
		printf("Faltan parametros");
		return 0;
	}
	else {
		//creo y asigno las variables que voy a necesitar
		char *img1 = argv[1];
		char *img2 = argv[2];
		char *mask = argv[3];
		int ancho = atoi(argv[4]);
		int alto = atoi(argv[5]);
		long cant = ancho * alto * 3;
		unsigned char *bufferImg1 = malloc(cant);
		unsigned char *bufferImg2 = malloc(cant);
		unsigned char *bufferMask = malloc(cant);
		double tiempoC;
		double tiempoAsm;
		printf ("%d x %d \n", ancho, alto);

		//leo los archivos
		readRGB(img1, bufferImg1, cant);
		readRGB(img2, bufferImg2, cant);
		readRGB(mask, bufferMask, cant);

		//inicio el timer para tomar el tiempo de enmascarar_c
		clock_t inicio = clock();
		enmascarar_c(bufferImg1, bufferImg2, bufferMask, cant);
		tiempoC = (double)(clock() - inicio) / CLOCKS_PER_SEC;
		printf ("La funcion enmascarar_c tardo:  %f segundos. \n", tiempoC);

		//escribo el archivo de salida con la info guardada en el bufferImg1
		writeRGB(nombreSalidaC, bufferImg1, cant);

		//vuelvo a leer los archivos
		readRGB(img1, bufferImg1, cant);
		readRGB(img2, bufferImg2, cant);
		readRGB(mask, bufferMask, cant);

		//vuelvo a inicializar el timer para tomar el tiempo de enmascarar_asm
		inicio = clock();
		enmascarar_asm(bufferImg1, bufferImg2, bufferMask, cant);
		tiempoAsm = (double)(clock() - inicio) / CLOCKS_PER_SEC;
		printf ("La funcion enmascarar_asm tardo:  %f segundos. \n", tiempoAsm);

		//escribo el archivo de salida con la info del bufferImg1 escrito por enmascarar_asm
		writeRGB(nombreSalidaAsm, bufferImg1, cant);
		
		//libero la memoria asignada
		free(bufferImg1);
		free(bufferImg2);
		free(bufferMask);

		return 0;				
	}	
	
}