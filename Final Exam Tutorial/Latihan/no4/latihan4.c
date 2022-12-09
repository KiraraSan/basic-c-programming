#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXDosen 5
#define MAXJournal 5

typedef char string[50];

typedef struct {
	string judul;
	string pengarang;
	int halaman;
	int tahunTerbit;
} Journal;

typedef struct {
	int noUrut;
	int tahun;
	Journal J[MAXJournal];
} Dosen;

void inisialisasiDosen(Dosen P[]);
Journal inputJournal(string judul, string pengarang, int halaman, int tahunTerbit);
Dosen inputDosen(int noUrut, int tahun, Journal temp[]);
int cekEmpty(Dosen D[]);
int hitungTahun(Dosen D[]);
void cetak(Dosen D[], string judul, int tahunTerbit);

int main(int argc, char *argv[]) {
	
	Journal temp[MAXJournal];
	Dosen D[MAXDosen];
 	
 	int i;
 //	int ;
 	bool t = true;
 	
 	while(t) {
	 
 		system("cls");
		printf("----- PETERNAKAN -----");
		printf("\n[1] Input Dosen");
		printf("\n[2] Input Journal");
		printf("\n[3] Tampil Data Petak Peternakan");
		printf("\n[0] Keluar");
		printf("\n>>>> "); scanf("%d", &menu);
 	
 		switch(menu) {
 			case 1 :
 				printf("\nINPUT DATA DOSEN\n\n");
				printf("Nomor Urut			: "); scanf("%d", &noUrut);
				printf("Tahun Masuk UAJY	: "); fflush(stdin); gets(tahun);
				D[cekEmpty(D)] = inputDosen(noUrut, tahun, temp);
 			break;
 			
 			case 2 :
 				printf("\n\tINPUT JOURNAL");
				printf("\tJudul			: "); fflush(stdin); gets(judul);
				printf("\tPengarang		: "); fflush(stdin); gets(pengarang);
				printf("\tHalaman		: "); scanf("%d", &halaman);
				printf("\tTahun Terbit	: "); scanf("%d", &tahunTerbit);
						
				temp[i] = inputJournal(judul, pengarang, halaman, tahunTerbit);
				i++;
				printf("\n\tData berhasil ditambahkan...");
 			break;
 			
 			case 3 :
 				cetak(D, noUrut);
 			break;
 			
 			case 0 :
 				t = false;
 			break;
		 } getch();	
	}
	return 0;
}

void inisialisasiDosen(Dosen P[]) {
	int i, j, n;
	
	for(i=0; i<MAXDosen; i++) {
		D[i].noUrut = 0;
		D[i].tahun = 0;
		
		for(j=0; j<MAXJournal; j++) {
			strcpy(D[i].J[j].judul, "-");
			strcpy(D[i].J[j].pengarang, "-");
			D[i].J[j].halaman = 0;
			D[i].J[j].tahun = 0;	
		}
	}
}

Dosen inputDosen(int noUrut, int tahun, Journal temp[]) {
	Journal J;
	
	strcpy(J.judul, judul);
	strcpy(J.pengarang, pengarang);
	J.halaman = halaman;
	J.tahunTerbit = tahunTerbit;
	
	return J;
}

Dosen inputDosen(int noUrut, int tahun, Journal temp[]) {
	Dosen D;
	int i;

	strcpy(D.noUrut = noUrut);
	for(i=0; i<MAXJournal; i++) {
		D.J[i] = temp[i];
	}
	return D;
}

int cekEmpty(Dosen D[]) {
	int i;
	for(i=0; i<MAXDosen; i++) {
		if(D[i].noUrut = 0) {
			return i;
		}
	}
	return -1;
}

int cariDosen(Dosen D[], int noUrut) {
	int i;
	for(i=0; i<MAXDosen; i++) {
		if(noUrut == D[n].noUrut) {
			return i;
		}
	}
	return -1;
}

int hitungTahun(Dosen D[], int noUrut){
    int n;
    int index = cariDosen(D, noUrut);

    if(D[index].J[0].tahunTerbit != 0) {
        return D[index].tahun - D[index].J[0].tahunTerbit;
    }
    return -1;
}

void cetak(Dosen D[], int noUrut) {
    int n;
    int index = cariDosen(D, noUrut);

    for(n=0; n<MAXJournal; n++){
        if(strcmpi(D[index].J[n].judul, "-")!=0) {
        printf("\nJudul        : %s",D[index].J[n].judul);
        printf("\nTahun        : %d",D[index].J[n].tahunTerbit);
        }
    }
}
