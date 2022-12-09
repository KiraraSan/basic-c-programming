#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// Alexis Divasonda Sigat Ngaing / 210711407 / D

typedef char string[50];

void tampilMenu();
void setJumlahTebak(int *jumlahTebak, int inputan);
void setRange(int *maxRange, int *minRange, int inputMax, int inputMin);
void setNilaiRandom(int *nilaiTebakan, int maxRange, int minRange);
void tebakAngka(int nilaiTebakan, int *tebakanSebelum, bool sudahMain, bool menang);
void tampilInformasiPermainan(int jumlahTebak, int maxRange, int minRange);

int main() {
	
	srand(time(NULL));
	
	int menu;
	int temp=1;
	int nilaiTebakan;
	int jumlah;
	int max;
	int min;
	int inpMax=10;
	int inpMin=0;
	int tebak;
	int sdhmain;
	int tebakSebelum;
	int win;
	int selisih=0;

	bool sudahSetTebakan =  false;
	bool sudahRange = false;
	bool sudahMain = false;
	bool menang = false;
	
	bool sudahInputN = false;
	int inputan;
	int n;
	string jawab;
	
	do {
		tampilMenu();
		printf("\n===> "); scanf("%d", &menu);
		
		switch(menu) {
			case 1 :
				printf("\n\t\t\t=== Tampil Selisih ===");
				printf("\n\t\tTampilkan selisih jarak? [ya / tidak] : "); fflush(stdin); gets(jawab);	
					if(strcmpi(jawab, "ya")==0) {
						printf("\n\t\t\t\tMenampilkan selisih jarak...");	
						selisih=1;
					} 
					else {
						printf("\n\t\t\t\tTidak menampilkan selisih jarak...");
						selisih=0;
					}
			break;
				
			case 2 :
				printf("\n\t\t=== Status Permainan ===");
				printf("\n\tJumlah Tebakan		: %d", temp);
				printf("\n\tMax Range		: %d", inpMax);
				printf("\n\tMin Range		: %d", inpMin);
				printf("\n\t----------------------------\n\n");
			break;
			
			case 3 :
				if(!sudahMain) {
					printf("\n\t\t[!] Belum pernah bermain");
				} 
				else {
					printf("\n\t\t=== Laporan Permainan ===");
					printf("\n\tStatus Permainan Terakhir	: %s");
					printf("\n\tMax Range Permainan		: %d", inpMax);
					printf("\n\tMin Range Permainan		: %d", inpMin);
					printf("\n\tNilai Tebakan			: %d", nilaiTebakan);
				}
			break;
			
			case 4 :
				printf("\n\t\t--- Set Jumlah Tebakan ---");
				do {
					printf("\n\tInput Jumlah Tebakan : "); scanf("%d", &temp);
					if(temp < 0) {
						printf("\t\t\t[!] Jumlah Tebakan Tidak Boleh <= 0\n");
					} 
					else if(temp > inpMax) {
						printf("\t\t\t[!] Jumlah tebakan tidak boleh lebih dari rentang permainan\n");
					}
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
						printf("\n\tInput Rentang Max : "); scanf("%d", &inpMax);
						printf("\tInput Rentang Min : "); scanf("%d", &inpMin);
						if(inpMin < temp && inpMax < temp) {
							printf("\t\t\t[!] Rentang tidak boleh kurang dari Jumlah tebakan\n");
						} 
						else if(inpMin >= inpMax) {
							printf("\t\t\t[!] Rentang invalid\n");
						}
						else {
							break;
						}
					} while(true);
					
					setRange(&max, &min, inpMax, inpMin);
	
					printf("\n\t\t[*] Rentang Permainan Berhasil Diupdate");
						
					sudahRange = true;
			break;
			
			case 6 :
				if(!sudahSetTebakan) {
					printf("\n\t\t[!] Set jumlah tebakan terlebih dahulu");
				} 
				else if(!sudahRange) {
					printf("\n\t\t[!] Set range tebakan terlebih dahulu");
				}
				else {
					printf("\n\t\t--- Game On! ---");
					printf("\n\tJumlah Tebakan		: %d", temp);
					printf("\n\tMax Range		: %d", inpMax);
					printf("\n\tMin Range		: %d", inpMin);
					printf("\n\t----------------------------\n\n");
				
				setNilaiRandom(&nilaiTebakan, inpMax, inpMin);
				
				tebakAngka(tebak, &tebakSebelum, sdhmain, win);

				sudahMain = true;
				}		
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

void setNilaiRandom(int *nilaiTebakan, int maxRange, int minRange) {
	*nilaiTebakan = (rand() % (maxRange - minRange + 1) + minRange);
}

void tebakAngka(int nilaiTebakan, int *tebakanSebelum, bool sudahMain, bool menang) {
	int n;
	int temp;
	int tebakan;
	int menu;
	
		for(n=0; n<temp; n++) {
			printf("\n\tTebak angka : "); scanf("%d", &tebakan);
				if(tebakan=nilaiTebakan) {
					printf("\nTebakan Anda benar");
					printf("\nSelamat Anda menang");
					printf("\ndi tebakan ke-%d\n", n);
					menang = true;
					break;
				} 
				else if(n>temp) {
					printf("\nAnda kalah awokawokawoka\n");
					printf("Semoga beruntung lain kali");
					break;
				} 
				else;
		} 	
}


