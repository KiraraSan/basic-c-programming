#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>

// Alexis Divasonda Sigat Ngaing / 210711407 / D

#define phi 3.14
typedef char string[20];

float volumeTabung(float jari, float tinggi);
float luasPermukaanTabung(float jari, float tinggi);
float bilanganKuadrat(float bilangan);

int main(int argc, char *argv[]) {
	
	int menu;
	float jari, tinggi;
	string ans;
	
	printf("\n\n\n\t\tApakah Kamu Manusia [Y/N] ?"); fflush(stdin); gets(ans);
	
	if(strcmpi(ans, "Y")==0) {
		
		system("color 20");
		printf("\n\n\n\t\tYeay Anda Manusia :)\n\n");
		printf("\n\n\t\tTekan apapun untuk melanjutkan Guided :D Semangat!!!"); 
		getch();
		
		do {
			system("color 60");
			system("cls");
			printf("\n\t====== GUIDED FUNGSI ======\n\n");
			printf("\n\t[1] Input Data Tabung");
			printf("\n\t[2] Hitung Volume Tabung");
			printf("\n\t[3] Hitung Luas Permukaan Tabung");
			printf("\n\t[0] EXIT");
			printf("\n\tMasukkan Pilihan >>> "); scanf("%d", &menu);
			
			switch(menu) {
				case 1:
					printf("\n\n\tInput Data Tabung");
					printf("\n\n\tMasukkan Jari-jari	: "); scanf("%f", &jari);
					printf("\n\tMasukkan Tinggi		: "); scanf("%f", &tinggi);
					printf("\n\n\tInput Data Berhasil");
				break;
				
				case 2:
					printf("\n\n\tMenghitung Volume Tabung");
					printf("\n\t====================================");
					printf("\n\n\tVolume Tabung adalah %.2f", volumeTabung(jari, tinggi));
				break;
				
				case 3:
					printf("\n\n\tMenghitung Luas Permukaan Tabung");
					printf("\n\t====================================");
					printf("\n\n\tLuas Permukaan Tabung adalah %.2f", luasPermukaanTabung(jari, tinggi));
				break;
			}
			printf("\n\n\n\t\tTekan Apapun Untuk Melanjutkan\n\n");
			getch();
		} 
		while(menu != 0);
	} 
	else if(strcmpi(ans, "N")==0) {
		system("color 40");
		printf("\n\n\n\t\tSystem Out!\n\n");
	}
	printf("\n\n\n\t\tSampai Jumpa di UGD\n\n");
	
	return 0;
}

float volumeTabung(float jari, float tinggi) {
	return phi * bilanganKuadrat(jari) * tinggi;
}

float luasPermukaanTabung(float jari, float tinggi) {
	return (2 * phi * bilanganKuadrat(jari)) + (2 * phi * jari * tinggi);
}

float bilanganKuadrat(float bilangan) {
	return bilangan * bilangan;
}
