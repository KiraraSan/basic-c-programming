#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// Alexis Divasonda Sigat Ngaing / 210711407 / D

typedef char string[50];

void tampilMenu();
void setBilangan(int *bilanganAsli, int inputan);
void tampilOperasi(string operasi, int angka1, int angka2, int hasil);

void prosedurPenjumlahan(int *hasil, int input1, int input2);
void prosedurPengurangan(int *hasil, int input1, int input2);
void laporanOperasi(bool sudahJumlah, bool sudahKurang, int hasilJumlah, int hasilKurang);

void inputBilanganN(int *temp);
void tebakAngka(int *inputan);

int main() {
	
	srand(time(NULL));
	
	int menu;
	int temp;
	int i;
	
	bool sudahInputBilangan = false;
	bool sudahPenjumlahan = false;
	bool sudahPengurangan = false;
	
	int bilangan1;
	int bilangan2;
	int hasilPenjumlahan;
	int hasilPengurangan;
	
	bool sudahInputN = false;
	int inputan;
	int n;
	
	do {
		tampilMenu();
		printf("\n>>> "); scanf("%d", &menu);
		
		switch(menu) {
			case 1 :
				printf("\n\t\t--- Input Bilangan ---");
				
				do {
					printf("\n\tInput Bilangan Pertama : "); scanf("%d", &temp);
					if(temp < 0) {
						printf("\t\t\t[!] Inputan Tidak Boleh < 0\n");
					} else {
						break;
					}
				} while(true);
				
				setBilangan(&bilangan1, temp);
				
				do {
					printf("\n\tInput Bilangan Kedua :" ); scanf("%d", &temp);
					
					if(temp < 0) {
						printf("\t\t\t[!] Inputan Tidak Boleh < 0\n");
					} else {
						break;
					}
				} while(true);
				
				setBilangan(&bilangan2, temp);
				sudahInputBilangan = true;
				printf("\n\t\t[*] Berhasil Menginput Bilangan");
			break;
			
			case 2 :
				if(!sudahInputBilangan) {
					printf("\n\t\t[!] Belum Input Bilangan");
				} else {
					printf("\n\t\t---- Penjumlahan ---");
					
					prosedurPenjumlahan(&hasilPenjumlahan, bilangan1, bilangan2);
					tampilOperasi("Penjumlahan", bilangan1, bilangan2, hasilPenjumlahan);
					
					sudahPenjumlahan = true;
				}
			break;
			
			case 3 :
				if(!sudahInputBilangan) {
					printf("\n\t\t[!] Belum Input Bilangan");
				} else {
					printf("\n\t\t---- Pengurangan ----");
				
					prosedurPengurangan(&hasilPengurangan, bilangan1, bilangan2);
					tampilOperasi("Pengurangan", bilangan1, bilangan2, hasilPengurangan);
					
					sudahPengurangan = true;
				}
			break;
			
			case 4 :
				if(!sudahInputBilangan) {
					printf("\n\t\t[!] Belum Input Bilangan");
				} else {
					printf("\n\t\t--- Laporan ---\n");
					laporanOperasi(sudahPenjumlahan, sudahPengurangan, hasilPenjumlahan, hasilPengurangan);
				}	
			break;
			
			case 5 :
				inputBilanganN(&n);
				
				sudahInputN = true;
			break;
			
			case 6 :
				if(!sudahInputN) {
					printf("\n\t\t[!] Belum Menginput N");
				} else {
					for(i=0; i<n; i++) {
						tebakAngka(&inputan);
						printf("\tKamu Menginputkan : %d\n", inputan);
					}
				}
			break;
			
			case 0 :
				printf("\n\t[*] Program Keluar");
				printf("\n\tAlexis Divasonda Sigat Ngaing - 210711407");
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
	
	printf("\n\t--- Guided ---");
	printf("\n[1] Input Bilangan");
	printf("\n[2] Penjumlahan   ");
	printf("\n[3] Pengurangan   ");
	printf("\n[4] Laporan       ");
	printf("\n------------------");
	printf("\n[5] Input N               ");
	printf("\n[6] Input Sebanyak N Kali ");
	printf("\n[0] Keluar Program        ");
}

void setBilangan(int *bilanganAsli, int inputan) {
	*bilanganAsli = inputan;
}

void prosedurPenjumlahan(int *hasil, int input1, int input2) {
	*hasil = input1 + input2;
}

void prosedurPengurangan(int *hasil, int input1, int input2) {
	*hasil = input1 - input2;
}

void tampilOperasi(string operasi, int angka1, int angka2, int hasil) {
	printf("\n\t%s %d dan %d", operasi, angka1, angka2);
	printf("\n\tMenghasilkan : %d", hasil);
}

void laporanOperasi(bool sudahJumlah, bool sudahKurang, int hasilJumlah, int hasilKurang) {
	
	printf("\n\tHasil Penjumlahan Terakhir : ");
	if(sudahJumlah) {
		printf("%d", hasilJumlah);
	} else {
		printf("<Belum Ada>");
	}
	
	printf("\n\tHasil Pengurangan Terakhir : ");
	if(sudahKurang) {
		printf("%d", hasilKurang);
	} else {
		printf("<Belum Ada>");
	}
}

void inputBilanganN(int *temp) {
	
	int menu;
	
	system("cls");
	printf("\n\t--- Input N ---");
	printf("\n[1] Dari User    ");
	printf("\n[2] Random [1-10]");
	printf("\n>>> "); scanf("%d", &menu);
	
	switch(menu) {
		case 1 :
			do {
				printf("\n\tInput N : "); scanf("%d", temp);
				if(*temp < 0) {
					printf("\t\t[!] Tidak Boleh Negatif\n");
				} else {
					break;
				}
			} while(true);
			
			printf("\n\t\t[*] Berhasil Input N");	
		break;
			
		case 2 :
			*temp = (rand() % (10-1+1) +1);
			printf("\n\t\t[*] Berhasil Input N");
			printf("\n\t\t    Nilai N : %d", *temp);	
		break;
	}
}

void tebakAngka(int *inputan) {
	
	int temp;
	printf("\n\tTebak Bilangan : "); scanf("%d", &temp);
	*inputan = temp;
}















