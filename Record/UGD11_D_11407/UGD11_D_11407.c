#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Alexis Divasonda Sigat Ngaing / 210711407 / D
// Bonus 1
// Bonus 2
// Bonus 3

typedef char string[50];

typedef struct {
	string nama;
	string kelas;
} Kamar;

typedef struct {
	string nama;
	string induk;
} Dokter;

typedef struct {
	string nama;
	string penyakit;
	int obat;
	string namaObat[10]; 
	Kamar kamar;
	Dokter dokter;
} Pasien;

void initPasien(Pasien *P);
void inputPasien(Pasien *P, int ubah);
void inputDokter(Dokter *D);
void inputKamar(Kamar *K);
int isPasienEmpty(Pasien P);
int isdokterEmpty(Dokter D);
int iskamarEmpty(Kamar K);
void tampilPasien(Pasien P);

void main() {
	Pasien P;
	int menu, ubah=0;
	initPasien(&P);
	
	do {
		system("cls");
		printf("--- ATMA HOSPITALS ---");
		printf("\n[1] Input Data");
		printf("\n[2] Tampilkan Data");
		printf("\n[3] Ubah Data");
		printf("\n[4] Hapus Data");
		printf("\n[0] Keluar");
		printf("\n>>> "); scanf("%d", &menu);
		
		switch(menu) {
			case 1 :
				if(isPasienEmpty(P)) {
					printf("\n\t--- Pasien ---\n");
					inputPasien(&P, ubah);
					printf("\n\t--- Dokter ---\n");
					inputDokter(&P.dokter);
					
					string confirm;
					printf("\n\tInput data kamar? [Y/N]: "); fflush(stdin); gets(confirm);
					if(strcmpi(confirm, "Y")==0) {
						inputKamar(&P.kamar);
						printf("\n\tData berhasil disimpan");
					} else {
						printf("\n\tData berhasil disimpan");
					}
				} else {
					printf("\n\t[!] Data Mahasiswa sudah diisi");
				}
			break;
			
			case 2 :
				printf("\n\t--- Tampil Semua ---");
				if(!isPasienEmpty(P)) {
					tampilPasien(P);
				} else {
					printf("\n\t[!] Data Pasien belum diisi");
				}
			break;
			
			case 3 :
				if(!isPasienEmpty(P)) {
					int submenu;
					printf("\n\t--- Ubah Data ---");
					printf("\n\t[1] Ubah data Pasien");
					printf("\n\t[2] Ubah data Dokter");
					printf("\n\t[3] Ubah data Kamar");
					printf("\n\t>>> "); scanf("%d", &submenu);
					
					switch(submenu) {
						case 1 :
							printf("\n\t--- Ubah Data Pasien ---\n");
							ubah=1;
							inputPasien(&P, ubah);
							printf("\n\tBerhasil mengubah data Pasien");
						break;
						
						case 2 :
							printf("\n\t--- Ubah Data Dokter ---\n");
							inputDokter(&P.dokter);
							printf("\n\tBerhasil mengubah data Dokter");
						break;
							
						case 3 :
							printf("\n\t--- Ubah Data Kamar ---\n");
							inputKamar(&P.kamar);
							printf("\n\tBerhasil mengubah data Kamar");
						break;
						
						default :
							printf("\n\t[!] Menu invalid");
						break;
					}
				} else {
					printf("\n\t[!] Data Pasien belum diisi");
				}
			break;
			
			case 4 :
				if(!isPasienEmpty(P)) {
					string confirm;
					printf("\n\tApakah Anda yakin ingin menghapus data? [Y/N]: "); fflush(stdin); gets(confirm);
					if(strcmpi(confirm, "Y")==0) {
						initPasien(&P);
						printf("\n\tBerhasil menghapus data");
					} else {
						printf("\n\t[!] Batal menghapus data");
					}
				} else {
					printf("\n\t[!] Data Pasien belum diisi");
				}
			break;
			
			case 0 :
				printf("\n\tTerima kasih...");
				printf("\n\tAlexis Divasonda Sigat Ngaing - 210711407 - Praktikum Dasar Pemrograman D");
			break;
			
			default :
				printf("\n\t[!] Menu tidak tersedia");
			break;
		}
		getch();
	} while(menu!=0);
}

void initPasien(Pasien *P) {
	strcpy((*P).nama, "");
	strcpy((*P).penyakit, "");
	(*P).obat = 0;
	
	strcpy((*P).dokter.nama, "");
	strcpy((*P).dokter.induk, "");
	strcpy((*P).kamar.nama, "");
	strcpy((*P).kamar.kelas, "");
}

void inputPasien(Pasien *P, int ubah) {
	Pasien input = (*P);
	
	int i;
	
	if(ubah==1) {
		while(true) {
			printf("\tNama Pasien  : "); fflush(stdin); gets(input.nama);
			if(strlen(input.nama)==0) {
				printf("\t[!] Nama Pasien tidak boleh kosong\n");
			} else {
				break;
			}
		}
		while(true) {
			printf("\tPenyakit   : "); fflush(stdin); gets(input.penyakit);
			if(strlen(input.penyakit)==0) {
				printf("\t[!] Penyakit tidak boleh kosong\n");
			} else {
				break;
			}
		}
	} else {
		while(true) {
			printf("\tNama Pasien  : "); fflush(stdin); gets(input.nama);
			if(strlen(input.nama)==0) {
				printf("\t[!] Nama Pasien tidak boleh kosong\n");
			} else {
				break;
			}
		}
		while(true) {
			printf("\tPenyakit     : "); fflush(stdin); gets(input.penyakit);
			if(strlen(input.penyakit)==0) {
				printf("\t[!] Penyakit tidak boleh kosong\n");
			} else {
				break;
			}
		}
		while(true) {
			printf("\tJumlah obat  : "); scanf("%d", &input.obat);
			if(input.obat<1 && input.obat>10) {
				printf("\t[!] Jumlah obat tidak boleh < 1 & >10\n");
			} else {
				break;
			}
		}
		for(i=0; i<input.obat; i++) {	
			while(true) {
				printf("\t\tObat ke-%d  : ", i); fflush(stdin); gets(input.namaObat[i]);
				if(strlen(input.namaObat[i])==0) {
					printf("\t[!] Nama obat tidak boleh kosong\n");
				} 
			//	else if(strlen(input.namaObat[i]) == strlen(input.namaObat[i])) {
			//		printf("\t[!] Nama obat tidak sama\n");
			//	} 
				else {
					break;	
				}
			}
		}
	}
		(*P) = input;
}

void inputDokter(Dokter *D) {
	Dokter input = (*D);
	
	while(true) {
		printf("\tNama Dokter  : "); fflush(stdin); gets(input.nama);
		if(strlen(input.nama)==0) {
			printf("\t[!] Nama Dokter tidak boleh kosong\n");
		} else {
			break;
		}
	}
	while(true) {
		printf("\tNo. Pegawai  : "); fflush(stdin); gets(input.induk);
		if(strlen(input.induk)!=9) {
			printf("\t[!] Nomor pegawai harus 9 digit\n");
		} else {
			break;
		}
	}
	
	(*D) = input;
}

void inputKamar(Kamar *K) {
	Kamar input = (*K);
	
	while(true) {
		printf("\tNama Kamar  : "); fflush(stdin); gets(input.nama);
		if(strlen(input.nama)==0) {
			printf("\t[!] Kamar tidak boleh kosong\n");
		} else {
			break;
		}
	}
	while(true) {
		printf("\tKelas Kamar  : "); fflush(stdin); gets(input.kelas);
		if(strcmpi(input.kelas, "I")!=0 && strcmpi(input.kelas, "II")!=0 && strcmpi(input.kelas, "III")!=0 && strcmpi(input.kelas, "VIP")!=0 && strcmpi(input.kelas, "VVIP")!=0) {
			printf("\t[!] Kelas Kamar invalid (nb: I, II, III, VIP, VVIP)\n");
		} else {
			break;
		}
	}
	
	(*K) = input;
}

int isPasienEmpty(Pasien P) {
	return (strcmp(P.nama, "")==0);
}

int isdokterEmpty(Dokter D) {
	return (strcmp(D.nama, "")==0);
}

int iskamarEmpty(Kamar K) {
	return (strcmp(K.nama, "")==0);
}

void tampilPasien(Pasien P) {
	int i;
	
	printf("\n\t[Pasien]");
	printf("\n\tNama Pasien : %s", P.nama);
	printf("\n\tPenyakit    : %s", P.penyakit);
	printf("\n\t\t[Jumlah Obat	: %d]\n", P.obat);
	for(i=0; i<P.obat; i++) {
		printf("\t\tObat ke-%d  : %s\n", i, P.namaObat[i]);
	}

	printf("\n\n\t[Dokter]");
	printf("\n\tNama Dokter	: %s", P.dokter.nama);
	printf("\n\tNo. Pegawai	: %s", P.dokter.induk);
	
	if(!iskamarEmpty(P.kamar)) {
		printf("\n\n\t[Kamar]");
		printf("\n\tNama Kamar	: %s", P.kamar.nama);
		printf("\n\tKelas Kamar	: %s", P.kamar.kelas);
	}
}
