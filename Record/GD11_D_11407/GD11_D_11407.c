#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char string[50];

typedef struct {
	string nama;
	string nidn;
} DosenPembimbing;

typedef struct {
	string nama;
	float ipk;
	int umur;
	DosenPembimbing dosBim;
} Mahasiswa;

void initMahasiswa(Mahasiswa *M);
void inputMahasiswa(Mahasiswa *M);
void inputDosenPembimbing(DosenPembimbing *DP);
int tahunLahirMahasiswa(int umur);
int isMahasiswaEmpty(Mahasiswa M);
int isDosBimEmpty(DosenPembimbing DP);
void tampilMahasiswa(Mahasiswa M);

void main() {
	Mahasiswa M;
	int menu;
	initMahasiswa(&M);
	
	do {
		system("cls");
		printf("--- Guided Record: Mahasiswa x Dosen Pembimbing ---");
		printf("\n[1] Input Data");
		printf("\n[2] Tampil Data");
		printf("\n[3] Edit Data");
		printf("\n[4] Hapus Data");
		printf("\n[0] Exit");
		printf("\n>>> "); scanf("%d", &menu);
		
		switch(menu) {
			case 1 :
				if(isMahasiswaEmpty(M)) {
					printf("\n\t--- Input Data ---\n");
					inputMahasiswa(&M);
					string confirm;
					printf("\n\tApakah sudah ada Dosen Pembimbing? [Y/N]: "); fflush(stdin); gets(confirm);
					if(strcmpi(confirm, "Y")==0) {
						inputDosenPembimbing(&M.dosBim);
						printf("\n\t[+] Berhasil menginput data Mahasiswa dan Dosen Pembimbing!");
					} else {
						printf("\n\t[+] Berhasil menginput data Mahasiswa tanpa Dosen Pembimbing!");
					}
				} else {
					printf("\n\t[-] Data Mahasiswa sudah diisi!");
				}
			break;
			
			case 2 :
				printf("\n\t--- Tampil Data ---");
				if(!isMahasiswaEmpty(M)) {
					tampilMahasiswa(M);
				} else {
					printf("\n\t[-] Data Mahasiswa belum diisi!");
				}
			break;
			
			case 3 :
				if(!isMahasiswaEmpty(M)) {
					int submenu;
					printf("\n\t--- Ubah Data ---");
					printf("\n\t[1] Ubah data Mahasiswa");
					printf("\n\t[2] Ubah data Dosen Pembimbing");
					printf("\n\t>>> "); scanf("%d", &submenu);
					
					switch(submenu) {
						case 1 :
							printf("\n\t--- Ubah Data Mahasiswa ---\n");
							inputMahasiswa(&M);
							printf("\n\t[+] Berhasil menginput data Mahasiswa!");
						break;
						
						case 2 :
							printf("\n\t--- Ubah Data Dosen Pembimbing ---\n");
							inputDosenPembimbing(&M.dosBim);
							printf("\n\t[+] Berhasil menginput data Dosen Pembimbing!");
						break;
						
						default :
							printf("\n\t[-] Menu tidak tersedia!");
						break;
					}
				} else {
					printf("\n\t[-] Data Mahasiswa belum diisi!");
				}
			break;
			
			case 4 :
				if(!isMahasiswaEmpty(M)) {
					string confirm;
					printf("\n\tApakah Anda yakin benar-benar ingin menghapus data? [Y/N]: "); fflush(stdin); gets(confirm);
					if(strcmpi(confirm, "Y")==0) {
						initMahasiswa(&M);
						printf("\n\t[+] Berhasil menghapus data Mahasiswa dan Dosen Pembimbing!");
					} else {
						printf("\n\t[-] Batal menghapus data Mahasiswa dan Dosen Pembimbing!");
					}
				} else {
					printf("\n\t[-] Data Mahasiswa belum diisi!");
				}
			break;
			
			case 0 :
				printf("\n\t[+] Terima kasih...");
				printf("\n\tAlexis Divasonda Sigat Ngaing - 210711407 - Praktikum Dasar Pemrograman D");
			break;
			
			default :
				printf("\n\t[-] Menu tidak tersedia!");
			break;
		}
		getch();
	} while(menu!=0);
}

void initMahasiswa(Mahasiswa *M) {
	strcpy((*M).nama, "");
	(*M).ipk = 0;
	(*M).umur = 0;
	
	strcpy((*M).dosBim.nama, "");
	strcpy((*M).dosBim.nidn, "");
}

void inputMahasiswa(Mahasiswa *M) {
	Mahasiswa input = (*M);
	
	while(true) {
		printf("\tNama Mahasiswa  : "); fflush(stdin); gets(input.nama);
		if(strlen(input.nama)==0) {
			printf("\t[-] Nama Mahasiswa tidak boleh kosong!\n");
		} else {
			break;
		}
	}
	
	printf("\tIPK Mahasiswa   : "); scanf("%f", &input.ipk);
	// error handling
	printf("\tUmur Mahasiswa  : "); scanf("%d", &input.umur);
	// error handling
	(*M) = input;
}

void inputDosenPembimbing(DosenPembimbing *DP) {
	DosenPembimbing input = (*DP);
	
	while(true) {
		printf("\tNama Dosen Pembimbing  : "); fflush(stdin); gets(input.nama);
		if(strlen(input.nama)==0) {
			printf("\t[-] Nama Dosen Pembimbing tidak boleh kosong!\n");
		} else {
			break;
		}
	}
	
	printf("\tNIDN Dosen Pembimbing  : "); fflush(stdin); gets(input.nidn);
	
	(*DP) = input;
}

int tahunLahirMahasiswa(int umur) {
	return 2022 - umur;
}

int isMahasiswaEmpty(Mahasiswa M) {
	return (strcmp(M.nama, "")==0);
}

int isDosBimEmpty(DosenPembimbing DP) {
	return (strcmp(DP.nama, "")==0);
}

void tampilMahasiswa(Mahasiswa M) {
	printf("\n\t[*] Data Mahasiswa :");
	printf("\n\tNama Mahasiswa	: %s", M.nama);
	printf("\n\tIPK Mahasiswa	: %.2f", M.ipk);
	printf("\n\tUmur Mahasiswa	: %d", M.umur);
	printf("\n\tTahun Lahir	: %d\n", tahunLahirMahasiswa(M.umur));
	
	if(!isDosBimEmpty(M.dosBim)) {
		printf("\n\t\t[*] Data Dosen Pembimbing :");
		printf("\n\t\tNama Dosen Pembimbing	: %s", M.dosBim.nama);
		printf("\n\t\tNIDN Dosen Pembimbing	: %s", M.dosBim.nidn);
	}
}
