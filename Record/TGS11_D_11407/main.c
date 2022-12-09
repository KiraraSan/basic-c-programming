#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Alexis Divasonda Sigat Ngaing / 210711407 / D

typedef char string[50];

typedef struct {
	string nama;
	string kelas;
} Kamar_11407;

typedef struct {
	string nama;
	string induk;
} Dokter_11407;

typedef struct {
	string nama;
	string penyakit;
	int obat;
	string namaObat[10]; 
	Kamar_11407 kamar;
	Dokter_11407 dokter;
} Pasien_11407;

void initPasien(Pasien_11407 *P);
void inputPasien(Pasien_11407 *P, int ubah, int obat, int inpasien);
void inputDokter(Dokter_11407 *D);
void inputKamar(Kamar_11407 *K);
int isPasienEmpty(Pasien_11407 P);
int isdokterEmpty(Dokter_11407 D);
int iskamarEmpty(Kamar_11407 K);
void tampilPasien(Pasien_11407 P);
//int cariObat(string namaObat[], string cariObat);
//void editObat(string namaObat[], string cariObat, string obatBaru);

void main() {
	Pasien_11407 P;
	int menu, ubah=0, obat=0, inpasien=0;
	string cariObat, obatBaru, namaObat; 
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
					inpasien=1;
					inputPasien(&P, ubah, obat, inpasien);
					printf("\n\t--- Dokter ---\n");
					inputDokter(&P.dokter);
					
					string confirm;
					printf("\n\tInput data kamar? [Y/N]: "); fflush(stdin); gets(confirm);
					if(strcmpi(confirm, "Y")==0) {
						inputKamar(&P.kamar);
						printf("\n\tData berhasil disimpan...");
					} else {
						printf("\n\tData berhasil disimpan...");
					}
				} else {
					printf("\n\t[!] Data Pasien sudah diisi");
				}
			break;
			
			case 2 :
				if(!isPasienEmpty(P)) {
					printf("\n\t--- Tampil Semua ---\n");	
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
					printf("\n\t[4] Ganti Semua Obat");
					printf("\n\t[5] Ganti Salah Satu Obat");
					printf("\n\t>>> "); scanf("%d", &submenu);
					
					switch(submenu) {
						case 1 :
							printf("\n\t--- Ubah Data Pasien ---\n");
							ubah=1;
							inpasien=0;
							inputPasien(&P, ubah, obat, inpasien);
							printf("\n\tBerhasil mengubah data Pasien...");
						break;
						
						case 2 :
							printf("\n\t--- Ubah Data Dokter ---\n");
							inputDokter(&P.dokter);
							printf("\n\tBerhasil mengubah data Dokter...");
						break;
							
						case 3 :
							printf("\n\t--- Ubah Data Kamar ---\n");
							inputKamar(&P.kamar);
							printf("\n\tBerhasil mengubah data Kamar...");
						break;
						
						case 4 :
							printf("\n\t--- Ganti Semua Obat ---\n");
							obat=1;
							ubah=0;
							inpasien=0;
							inputPasien(&P, ubah, obat, inpasien);
							printf("\n\tBerhasil mengganti semua obat...");
						break;
						
						case 5 :
							printf("\n\t--- Ganti Salah Satu Semua ---\n");
							//printf("\nMasukkan nama obat yang ingin diubah : "); fflush(stdin); gets(cariObat);
							//printf("Masukkan nama obat yang baru : "); fflush(stdin); gets(obatBaru);
						//	editObat(namaObat, cariObat, obatBaru);
							printf("\n\t\n\tBerhasil mengganti salah satu obat...");
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
						printf("\n\tBerhasil menghapus data...");
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

void initPasien(Pasien_11407 *P) {
	strcpy((*P).nama, "");
	strcpy((*P).penyakit, "");
	(*P).obat = 0;
	
	strcpy((*P).dokter.nama, "");
	strcpy((*P).dokter.induk, "");
	strcpy((*P).kamar.nama, "");
	strcpy((*P).kamar.kelas, "");
}

void inputPasien(Pasien_11407 *P, int ubah, int obat, int inpasien) {
	Pasien_11407 input = (*P);
	
	int i, j=0;
	
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
	} else if(inpasien==1) {
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
			j++;	
			while(true) {
				printf("\t\tObat ke-%d  : ", j); fflush(stdin); gets(input.namaObat[i]);
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
	} else if(obat==1) {
		while(true) {
			printf("\tJumlah obat  : "); scanf("%d", &input.obat);
			if(input.obat<1 && input.obat>10) {
				printf("\t[!] Jumlah obat tidak boleh < 1 & >10\n");
			} else {
				break;
			}
		}
		for(i=0; i<input.obat; i++) {
			j++;
			while(true) {
				printf("\t\tObat ke-%d  : ", j); fflush(stdin); gets(input.namaObat[i]);
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

void inputDokter(Dokter_11407 *D) {
	Dokter_11407 input = (*D);
	
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
			printf("\t[!] Nomor pegawai invalid (nb. harus 9 digit)\n");
		} else {
			break;
		}
	}
	
	(*D) = input;
}

void inputKamar(Kamar_11407 *K) {
	Kamar_11407 input = (*K);
	
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

int isPasienEmpty(Pasien_11407 P) {
	return (strcmp(P.nama, "")==0);
}

int isdokterEmpty(Dokter_11407 D) {
	return (strcmp(D.nama, "")==0);
}

int iskamarEmpty(Kamar_11407 K) {
	return (strcmp(K.nama, "")==0);
}

void tampilPasien(Pasien_11407 P) {
	int i, j=0;
	
	printf("\n\t[Pasien]");
	printf("\n\tNama Pasien : %s", P.nama);
	printf("\n\tPenyakit    : %s", P.penyakit);
	printf("\n\t\t[Jumlah Obat	: %d]\n", P.obat);
	for(i=0; i<P.obat; i++) {
		j++;
		printf("\t\tObat ke-%d  : %s\n", j, P.namaObat[i]);
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
/*
int cariObat(string namaObat[]) {
	int i;
	for(i=0; i<10; i++) {
		if(strcmpi(namaObat[i], cariObat)==0) {
			return i;
		}
	}
	return -1;
}

void editObat(string namaObat[], string cariObat, string obatBaru) {
	int i;
	int index = cariObat(namaObat, cariObat);
	if(index != -1) {
		strcpy(namaObat[index], obatBaru);
	} else {
		printf("\n\t[!] Data obat tidak ditemukan");
	}
}
*/
