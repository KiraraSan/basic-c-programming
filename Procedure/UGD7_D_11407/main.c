#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

void setJumlahTebak(int *jumlahTebak, int inputan);
void setRange(int *maxRange, int *minRange, int inputMax, int inputMin);
void setNilaiRandom(int *nilaiTebakan, int maxRange, int minRange);
void tebakAngka(int nilaiTebakan, int *tebakanSebelum, bool *sudahMain, bool *menang);
void tampilInformasiPermainan(int jumlahTebak, int maxRange, int minRange);

int main() {
	
	srand(time(NULL));
	
	int menu;
	int temp;
	int nilaiTebakan;
	int jumlah;
	int max=0;
	int min=0;
	int inpMax=0;
	int inpMin=0;
	int tebak;
	int tebakSebelum;
	int main;
	int win;
	
	bool sudahSetTebakan =  false;
	bool sudahRange = false;
	
	bool sudahInputN = false;
	int inputan;
	int n;
	
	do {
		tampilMenu();
		printf("\n===> "); scanf("%d", &menu);
		
		switch(menu) {
			case 1 :
				printf("Program masih dalam tahap pengembangan");
			break;
				
			case 2 :
				printf("Program masih dalam tahap pengembangan");
			break;
			
			case 3 :
				printf("Program masih dalam tahap pengembangan");
			break;
			
			case 4 :
				printf("\n\t\t--- Set Jumlah Tebakan ---");
				
				do {
					printf("\n\tInput Jumlah Tebakan : "); scanf("%d", &temp);
					if(temp < 0) {
						printf("\t\t\t[!] Jumlah Tebakan Tidak Boleh <= 0\n");
					} 
					
				/*	else if(temp > max) {
						printf("\t\t\t[!] Jumlah Tebakan tidak boleh lebih dari Rentang Permainan\n");
					} */
					
					else {
						break;
					}
				} while(true);
				
				setJumlahTebak(&jumlah, temp);

				printf("\n\t\t[*] Jumlah Tebakan Berhasil Diupdate");
				
				sudahSetTebakan = true;
			break;
			
			case 5 :
				printf("\n\t\t--- Set Rentang Permainan ---");
				
				do {
					printf("\n\tInput Rentang Max : "); scanf("%d", &max);
					printf("\n\tInput Rentang Min : "); scanf("%d", &min);
					if(min && max < temp) {
						printf("\t\t\t[!] Rentang tidak boleh < Jumlah tebakan\n");
					} else {
						break;
					}
				} while(true);
				
				setRange(&max, &min, inpMax, inpMin);

				printf("\n\t\t[*] Jumlah Rentang Permainan Berhasil Diupdate");
					
				sudahRange = true;
				
			break;
			
			case 6 :
				tebakAngka(tebak, &tebakSebelum, &main, &win);
				nilaiTebakan = (rand() % (max-1+1) +1);
				
			break;
			
			default:
				printf("\n\t[!] Menu Tidak Tersedia");
			break;
		}
		getch();
	} while(menu !=0);
	
	return 0;
}

void tampilMenu() {
	
	system("cls");
	
	printf("\n\t--- Tugas/Bonus Prosedur ---");
	printf("\n[1] Tampil Selisih Jarak");
	printf("\n[2] Status Permainan");
	printf("\n[3] History Permainan");
	printf("\n\n\t--- UGD Prosedur ---");
	printf("\n[4] Set Jumlah Tebakan");
	printf("\n[5] Set Rentang Permainan");
	printf("\n[6] Mulai Permainan");
}

void setJumlahTebak(int *jumlahTebak, int inputan) {
	*jumlahTebak = inputan;
}

void setRange(int *maxRange, int *minRange, int inputMax, int inputMin) {
	*maxRange = inputMax;
	*minRange = inputMin;
}

void tebakAngka(int nilaiTebakan, int *tebakanSebelum, bool *sudahMain, bool *menang) {
	
	system("cls");
	
	int temp;
	int max;
	int min;
	int tebak;
	int n=0;
	
	printf("\n\t\t--- Game On! ---");
	printf("\n\t\Jumlah Tebakan		: %d", temp);
	printf("\n\t\Max Range		: %d", max);
	printf("\n\t\Min Range		: %d", min);
	printf("\n\t\----------------------------");
	printf("\n\tTebak Angka : "); scanf("%d", &tebak);
	
	while(n<temp) {
		printf("Tebak Angka : "); scanf("%d", &tebak);
		n++;	
	} 
	

}
