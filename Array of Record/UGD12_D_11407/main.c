#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define tampungPeternakan 2
#define tampungPetak 8


// Alexis Divasonda Sigat Ngaing / 210711407 / D
// Bonus 1 / 2 / 

typedef char string[50];

typedef struct {
	string kodePetak;
	string namaPetugas;
	int jumlahAyam;
	int jumlahTelurAyam;
} Petak;

typedef struct {
	string namaPeternakan;
	Petak Pk[tampungPetak];
} Peternakan;

void inisialisasiPeternakan(Peternakan P[]);
Petak isiDataPetak(string kodePetak, string namaPetugas, int jumlahAyam, int jumlahTelurAyam);
Peternakan isiDataPeternakan(string namaPeternakan, Petak temp[]);
int cekEmpty(Peternakan P[]);
int cekIsi(Peternakan P[]);
int cariPeternakan(Peternakan P[], string namaPeternakan);
int cariPetak(Peternakan P[], Petak Pk[], string namaPeternakan, string kodePetak);
void tampilData(Peternakan P[], Petak Pk[], string namaPeternakan, string kodePetak);

int main(int argc, char *argv[]) {
	
	Petak temp[tampungPetak];
	Peternakan P[tampungPeternakan];
	string namaPeternakan, kodePetak, namaPetugas, Pk;
	int jumlahAyam, jumlahTelurAyam;
	int menu, submenu, i;
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
					for(i=0; i<tampungPeternakan; i++) {
						printf("\n\nNama Peternakan ke- %d	: ", (i+1)); fflush(stdin); gets(namaPeternakan);
					}
					
					P[cekEmpty(P)] = isiDataPeternakan(namaPeternakan, temp);
					printf("\n\tData berhasil ditambahkan...");
				} else {
					printf("\n[!] Anda telah melakukan set nama Peternakan");
				}
			break;
			
			case 2 :
				if(cekEmpty(P)!=-1) {
					printf("\nNama Peternakan : "); fflush(stdin); gets(namaPeternakan);
					
					printf("\n[1] Mengisi Petak");
					printf("\n[2] Edit Petak");
					printf("\n>>>> "); scanf("%d", &submenu);
					
					switch(submenu) {
						case 1 :
							printf("Kode Petak          : "); fflush(stdin); gets(kodePetak);
							printf("Nama Petugas        : "); fflush(stdin); gets(namaPetugas);
							printf("Jumlah Ayam         : "); scanf("%d", &jumlahAyam);
							printf("Jumlah Telur Ayam   : "); scanf("%d", &jumlahTelurAyam);
							
							temp[i] = isiDataPetak(kodePetak, namaPetugas, jumlahAyam, jumlahTelurAyam);
							printf("\n\n\tData Petak berhasil ditambahkan...");
						break;
						
						case 2 :
							
						break;
					}
					
					
					
				} else {
					printf("\n[!] Data Penuh");
				}
			break;
			
			case 3 :
				if(cekIsi(P)!=-1) {
					printf("\n\tNama Peternakan : "); fflush(stdin); gets(namaPeternakan);
				//	tampilData(P, Pk, namaPeternakan, kodePetak);				 				
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
	int i, j;
	
	for(i=0; i<tampungPeternakan; i++) {
		strcpy(P[i].namaPeternakan, "-");
		
		for(j=0; j<tampungPetak; j++) {
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
	for(i=0; i<tampungPetak; i++) {
		P.Pk[i] = temp[i];
	}
	return P;
}

int cekEmpty(Peternakan P[]) {
	int i;
	for(i=0; i<tampungPeternakan; i++) {
		if(strcmp(P[i].namaPeternakan, "-")==0) {
			return i;
		}
	}
	return -1;
}

int cariPeternakan(Peternakan P[], string namaPeternakan) {
	int i;
	for(i=0; i<tampungPeternakan; i++) {
		if(strcmpi(P[i].namaPeternakan, namaPeternakan)==0) {
			return i;
		}
	}
	return -1;
}

int cariPetak(Peternakan P[], Petak Pk[], string namaPeternakan, string kodePetak) {
	int i;
	int index = cariPeternakan(P, namaPeternakan);
	for(i=0; i<tampungPetak; i++) {
		if(strcmpi(P[index].Pk[i].kodePetak, kodePetak)==0) {
			return i;
		}
	}
	return -1;
}


void tampilData(Peternakan P[], Petak Pk[], string namaPeternakan, string kodePetak) {
	int i, j, n;
	int indexone = cariPeternakan(P, namaPeternakan);
	int indextwo = cariPetak(Pk, kodePetak);

	//	if(strcmp(P[index].namaPeternakan, "-")!=0) {
			printf("\nPeternakan	: %ds", P[indexone].namaPeternakan);
			for(i=0; i<tampungPetak; i++) {
	//		printf("\n[%s] ", P[indexone].Pk[indextwo].kodePetak);
			}
			printf("\n\n\tKode Petak : "); fflush(stdin); gets(kodePetak);
			for(j=0; j<tampungPetak; j++) {
				printf("\n\n[ Tampil Data Petak ]");
				printf("\n\tKode Petak        : %s", P[indexone].Pk[indextwo].kodePetak);
				printf("\n\tNama Penjaga      : %s", P[indexone].Pk[indextwo].namaPenjaga);
				printf("\n\tJumlah Ayam       : %d", P[indexone].Pk[indextwo].jumlahAyam);
				printf("\n\tJumlah Telur Ayam : %s\n\n", P[indexone].Pk[indextwo].jumlahTelurAyam);	
		//	}
		} else {
			printf("\n[!] Invalid");
		}	
		
}

