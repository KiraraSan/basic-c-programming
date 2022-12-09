#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

float ratusan(float n);
float ratusan2(float m, int b);

int main(int argc, char *argv[]) {
	float n, m, b;
	int menu;
	bool boolean;
	
	do {
		system("cls");
		printf("\n[1] Ratusan");
		printf("\n[2] Ratusan 2");
		printf("\n[0] Exit");
		printf("\n>>>> "); scanf("%d", &menu);
		
		switch(menu) { 
			case 1 :
				printf("Masukkan angka : "); scanf("%f", &n);
				int balik = ratusan(n);
				printf("Hasil return : %.0f", balik);
			break;
			
			case 2 :
				printf("Masukkan angka : "); scanf("%f", &n);
				printf("Masukkan boolean (0/1) : "); scanf("%d", &b);
				float bolak = ratusan2(m, b);
				printf("Hasil return : %.0f", bolak);
			break;
			
			case 0 :
				
			break;
			
			default :
				printf("Invalid");
			break;
		} getch();
	} while(menu!=0);
	return 0;
}

float ratusan(float n) {
	int a;
	
	if(n<0) {
		return 0;	
	} else {
		n = ceil(n);
		return n;
	} 	
}

float ratusan2(float m, int b) {
	if(b=1) {
		m = ceil(m);
		return m;
	} else {
		return 0;
	} 
}

