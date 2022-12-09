#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXPeternakan 2
#define MAXPetak 8

// Alexis Divasonda Sigat Ngaing / 210711407 / D

typedef char string[50];

typedef struct {
	string kodePetak;
	string namaPetugas;
	int jumlahAyam;
	int jumlahTelurAyam;
} Petak;

typedef struct {
	string namaPeternakan;
	Petak Pk[MAXPetak];
} Peternakan;

void inisialisasiPeternakan(Peternakan P[]);
Petak isiDataPetak(string kodePetak, string namaPetugas, int jumlahAyam, int jumlahTelurAyam);
Peternakan isiDataPeternakan(string namaPeternakan, Petak temp[]);
int cekEmpty(Peternakan P[]);
int cekEmptyTwo(Peternakan P[]);
int cekIsi(Peternakan P[]);
int cekPetak(Peternakan P[]);
int cariPeternakan(Peternakan P[], string namaPeternakan);
int cariPetak(Peternakan P[], string namaPeternakan, string kodePetak);
void swapData(Peternakan P[], string namaPeternakan, string kodePetak);
void tampilData(Peternakan P[], string namaPeternakan, string kodePetak);

int main(int argc, char *argv[]) {
	
	Petak temp[MAXPetak];
	Peternakan P[MAXPeternakan];
	string namaPeternakan, kodePetak, namaPetugas, Pk;
	int jumlahAyam, jumlahTelurAyam;
	int menu, submenu, i, n, j, m, petak;
	bool t = true;
	
	inisialisasiPeternakan(P);
	
	while(t) {
		system("cls");
		printf("----- PETERNAKAN -----");
		printf("\n[1] Set Nama Peternakan");
		printf("\n[2] Set Data");
		printf("\n[3] Tampil Data Petak Peternakan");
		printf("\n[0] Keluar");
		printf("\n>>>> "); scanf("%d", &menu);
		
		switch(menu) {
			case 1 :
				if(cekEmpty(P)!=-1) {
				for(j=0; j<MAXPeternakan; j++) {
					printf("\nNama Peternakan ke-%d	: ", (j+1)); fflush(stdin); gets(namaPeternakan);
					P[cekEmpty(P)] = isiDataPeternakan(namaPeternakan, temp);
				}	
					printf("\n\tData berhasil ditambahkan...");
				} else {
					printf("\n[!] Anda telah melakukan set nama Peternakan");
				}
			break;
			
			case 2 :
				if(cekIsi(P)!=-1) {
					printf("\nNama Peternakan : "); fflush(stdin); gets(namaPeternakan);
					int cari = cariPeternakan(P, namaPeternakan);
					
					if(cari!=-1) {
						printf("\n[1] Mengisi Petak");
						printf("\n[2] Edit Petak");
						printf("\n[3] Swap Petak");
						printf("\n>>>> "); scanf("%d", &submenu);
						
						switch(submenu) {
							case 1 :
							//	if(cekEmptyTwo(P)!=-1) {
									printf("\nKode Petak          : "); fflush(stdin); gets(kodePetak);
									printf("Nama Petugas        : "); fflush(stdin); gets(namaPetugas);
									printf("Jumlah Ayam         : "); scanf("%d", &jumlahAyam);
									printf("Jumlah Telur Ayam   : "); scanf("%d", &jumlahTelurAyam);
									
									temp[i] = isiDataPetak(kodePetak, namaPetugas, jumlahAyam, jumlahTelurAyam);
									i++;
									P[cari] = isiDataPeternakan(namaPeternakan, temp);
									printf("\n\tData Petak berhasil ditambahkan...");
							//	} else {
							//		printf("\n\t[!] Data Petak penuh");
							//	}
							break;
							
							case 2 :
								if(cekPetak(P)!=-1) {
									printf("\nMasukkan Kode Petak : "); fflush(stdin); gets(kodePetak);
									petak = cariPetak(P, namaPeternakan, kodePetak);
									if(petak!=-1) {
										printf("\nKode Petak          : "); fflush(stdin); gets(kodePetak);
										printf("Nama Petugas        : "); fflush(stdin); gets(namaPetugas);
										printf("Jumlah Ayam         : "); scanf("%d", &jumlahAyam);
										printf("Jumlah Telur Ayam   : "); scanf("%d", &jumlahTelurAyam);
										temp[petak] = isiDataPetak(kodePetak, namaPetugas, jumlahAyam, jumlahTelurAyam);
										P[petak] = isiDataPeternakan(namaPeternakan, temp);
										printf("\n\tData Petak berhasil diubah...");
									} else {
										printf("\n\t[!] Data Petak invalid / tidak ada");
									}
								} else {
									printf("\n\t[!] Data Petak kosong");
								}
							break;
								
							case 3 :
								for(m=0; m<2; m++) {
								//	printf("\nKode Petak"); fflush(stdin); gets(kodePetak);
								//	tukar = cariPetak(P);
								}
							//	swap(P, namaPeternakan, kodePetak);
							break;
							
							default :
								printf("\n[!] Menu invalid");
							break;
						} getch();
					} else {
						printf("\n\t\t[!] Peternakan invalid");
					}
				} else {
					printf("\n[!] Data Penuh");
				}
			break;
			
			case 3 :
				if(cekIsi(P)!=-1) {
					printf("\nNama Peternakan : "); fflush(stdin); gets(namaPeternakan);
					int cari = cariPeternakan(P, namaPeternakan);
					int petak = cekPetak(P);
					if(cari==-1) {
						printf("\n\t\t[!] Peternakan tidak ditemukan");
					} else if(petak==-1) {
						printf("\n[!] Data Petak kosong");
					} else {
						tampilData(P, namaPeternakan, kodePetak);
					}				 				
				} else {
					printf("\n[!] Data kosong");
				} 
			break;
			
			case 0 :
				printf("\nALEXIS DIVASONDA SIGAT NGAING / 210711407 / D");
				printf("\nKeluar...");
				t=false;
			break;
			
			default:
				printf("\n[!] Menu invalid");  
			break;
		} getch();
	}
	return 0;
}

void inisialisasiPeternakan(Peternakan P[]) {
	int i, j, n;
	
	for(i=0; i<MAXPeternakan; i++) {
		strcpy(P[i].namaPeternakan, "-");
		
		for(j=0; j<MAXPetak; j++) {
			strcpy(P[i].Pk[j].kodePetak, "-");
			strcpy(P[i].Pk[j].namaPetugas, "-");
			P[i].Pk[j].jumlahAyam = 0;
			P[i].Pk[j].jumlahTelurAyam = 0;	
		}
	}
}

Petak isiDataPetak(string kodePetak, string namaPetugas, int jumlahAyam, int jumlahTelurAyam) {
	Petak Pk;
	
	strcpy(Pk.kodePetak, kodePetak);
	strcpy(Pk.namaPetugas, namaPetugas);
	Pk.jumlahAyam = jumlahAyam;
	Pk.jumlahTelurAyam = jumlahTelurAyam;
	
	return Pk;
}

Peternakan isiDataPeternakan(string namaPeternakan, Petak temp[]) {
	Peternakan P;
	int i;

	strcpy(P.namaPeternakan, namaPeternakan);
	for(i=0; i<MAXPetak; i++) {
		P.Pk[i] = temp[i];
	}
	return P;
}

int cekEmpty(Peternakan P[]) {
	int i;
	for(i=0; i<MAXPeternakan; i++) {
		if(strcmp(P[i].namaPeternakan, "-")==0) {
			return i;
		}
	}
	return -1;
}

int cekEmptyTwo(Peternakan P[]) {
	int i;
	int index = cekEmpty(P);
	for(i=0; i<MAXPetak; i++) {
		if(strcmp(P[index].Pk[i].kodePetak, "-")==0) {
			return i;
		}
	}
	return -1;
}

int cekIsi(Peternakan P[]) {
	int i;
	for(i=0; i<MAXPeternakan; i++) {
		if(strcmp(P[i].namaPeternakan, "-")!=0) {
			return i;
		}
	}
	return -1;
}

int cekPetak(Peternakan P[]) {
	int i;
	int index = cekIsi(P);
	for(i=0; i<MAXPetak; i++) {
		if(strcmp(P[index].Pk[i].kodePetak, "-")!=0) {
			return i;
		}
	}
	return -1;
}

int cariPeternakan(Peternakan P[], string namaPeternakan) {
	int i;
	for(i=0; i<2; i++) {
		if(strcmpi(P[i].namaPeternakan, namaPeternakan)==0) {
			return i;
		}
	}
	return -1;
}

int cariPetak(Peternakan P[], string namaPeternakan, string kodePetak) {
	int i;
	int index = cariPeternakan(P, namaPeternakan);
	for(i=0; i<8; i++) {
		if(strcmpi(P[index].Pk[i].kodePetak, kodePetak)==0) {
			return i;
		}
	}
	return -1;
}

void swapData(Peternakan P[], string namaPeternakan, string kodePetak) {
//	P.Pk[]
}

void tampilData(Peternakan P[], string namaPeternakan, string kodePetak) {
	int i, j, n;
	int indexone = cariPeternakan(P, namaPeternakan);

	if(strcmp(P[indexone].namaPeternakan, "-")!=0) {
		for(i=0; i<4; i++) {
		printf("[%s] ", P[indexone].Pk[i].kodePetak);
		}
		printf("\n");
		for(n=4; n<MAXPetak; n++) {
		printf("[%s] ", P[indexone].Pk[n].kodePetak);
		}
		printf("\n\nKode Petak : "); fflush(stdin); gets(kodePetak);
		int indextwo = cariPetak(P, namaPeternakan, kodePetak);                          
			printf("\n[ Tampil Data Petak ]");
			printf("\nKode Petak        : %s", P[indexone].Pk[indextwo].kodePetak);
			printf("\nNama Petugas      : %s", P[indexone].Pk[indextwo].namaPetugas);
			printf("\nJumlah Ayam       : %d", P[indexone].Pk[indextwo].jumlahAyam);
			printf("\nJumlah Telur Ayam : %d\n\n", P[indexone].Pk[indextwo].jumlahTelurAyam);	
	} else {
		printf("\n[!] Invalid");
	}	
}
