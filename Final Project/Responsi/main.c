// Alexis Divasonda Sigat Ngaing / 210711407 / Kelas D

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXMahasiswa 3
#define MAXMataKuliah 2

typedef char string[50];

typedef struct {
	string namaMK;
	int sks;
} MataKuliah;

typedef struct {
	string username;
	string password;
	string nama;
	MataKuliah Mk[MAXMataKuliah];
} Mahasiswa;

void inisialisasi(Mahasiswa M[]);
void cekLogin(int *cekA, int *cekB, string user, string pass);
void cekLogout(int *logout, int *cekA, int *cekB);
MataKuliah isiDataMataKuliah(string namaMK, int sks);
Mahasiswa isiDataMahasiswa(string username, string password, string nama, MataKuliah temp[]);
int cekEmpty(Mahasiswa M[]);
int cekIsi(Mahasiswa M[]);
int cariMahasiswa(Mahasiswa M[], string cariNama);
int cariMataKuliah(Mahasiswa[], string namaMK);
int cekMK(Mahasiswa M[], string cariNama);
void hapusMataKuliah(Mahasiswa M[], string cariNama, string namaMK, int *cek);
void tampilAdmin(Mahasiswa M[]); 
void tampilMahasiswa(Mahasiswa M[], string cariNama);

int main(int argc, char *argv[]) {
	
	MataKuliah temp[MAXMataKuliah];
	Mahasiswa M[MAXMahasiswa];
	int menu_one, menu_two;
	int cekA=0, cekB=0, cek=0, ta=0;
	int i, ceka, cekb;
	int logout, out, sks, cari;
	string user, pass;
	string username, password, nama, namaMK, cariNama;
	
	inisialisasi(M);
	
	do {
		logout=0;
		system("cls");
		printf("\n\t\t=== Login ===\n");
		printf("\tUsername  : "); fflush(stdin); gets(user);
		printf("\tPassword  : "); fflush(stdin); gets(pass);
		
		if(strcmpi(user, "Admin")==0) {
			cekLogin(&ceka, &cekb, user, pass);	
		} 
		else if(strcmpi(user, "Logout")==0) {
			printf("\n\n\t\tTerima kasih :)");
			printf("\n\t\tAlexis Divasonda Sigat Ngaing - 210711407 - Praktikum Dasar Pemrograman D");
			printf("\n\n\t\tProgram keluar...");
			out=1;
		} else {
			cari = cariMahasiswa(M, user);
			cekb=1;
		}
		
		if(ceka==1) {
			printf("\n\t\t[*] Login sebagai Admin"); getch();
			do {
				system("cls");
				printf("\n=== RESPONSI ADMIN ===");
				printf("\n[1] Input Mahasiswa");
				printf("\n[2] Tampil Mahasiswa");
				printf("\n[0] Logout");
				printf("\n>> "); scanf("%d", &menu_one);
				
				switch(menu_one) {
					case 1 :
						if(cekEmpty(M)!=-1) {
							printf("\n\t\t=== Input Data Mahasiswa ===\n");
							while(true) {
								printf("\tInput Username   : "); fflush(stdin); gets(username);
								if(strlen(username)==0) {
									printf("\t[!] Username tidak boleh kosong\n");
								} else {
									break;
								}
							}
							while(true) {
								printf("\tInput Password   : "); fflush(stdin); gets(password);
								if(strlen(password)==0) {
									printf("\t[!] Password tidak boleh kosong\n");
								} else {
									break;
								}
							}
							while(true) {
								printf("\tInput Nama       : "); fflush(stdin); gets(nama);
								if(strlen(nama)==0) {
									printf("\t[!] Nama tidak boleh kosong\n");
								} else {
									break;
								}
							}
							
							M[cekEmpty(M)] = isiDataMahasiswa(username, password, nama, temp);
							printf("\n\t\t[*] Berhasil input Data Mahasiswa...");
						} else {
							printf("\n\t[!] Data Mahasiswa penuh");
						}
					break;	
					
					case 2 :
					//	if(cekIsi(M)!=-1) {
							tampilAdmin(M);
					//	} else {
					//		printf("\n[!] Data kosong");
					//	}
					break;
					
					case 0 :
						logout=1;
						cekLogout(&logout, &ceka, &cekb);
					break;
					
					default :
						printf("\n\t[!] Menu invalid");
					break;
				} getch();
			} while(logout!=1);
		}
		else if(cekb==1) {
			printf("\n\t\t[*] Login sebagai salah satu Mahasiswa"); getch();
			do {
				system("cls");
				printf("\n\n=== RESPONSI MAHASISWA ===");
				printf("\n\tHalo : %s", user);
				printf("\n[1] Input Mata Kuliah");
				printf("\n[2] Hapus Mata Kuliah");
				printf("\n[3] Tampil Mahasiswa");
				printf("\n[0] Logout");
				printf("\n\n===> "); scanf("%d", &menu_two);
				
				switch(menu_two) {
					case 1 :
					//	if(cekMK(M, cariNama)!=-1) {
							printf("\n\t\t=== Input Mata Kuliah ===");
							while(true) {
								printf("\n\tInput Nama Mata Kuliah : "); fflush(stdin); gets(namaMK);
								if(strlen(namaMK)==0) {
									printf("\t[!] Mata Kuliah tidak boleh kosong\n");
								} else {
									break;
								}
							}
							while(true) {
								printf("\tInput Jumlah SKS       : "); scanf("%d", &sks);
								if(sks==0) {
									printf("\t[!] SKS tidak boleh nol\n");
								} 
								else if (sks<0) {
									printf("\t[!] SKS tidak boleh negatif\n");
								} else {
									break;
								}
							}
							
							temp[i] = isiDataMataKuliah(namaMK, sks);
							i++;
							M[cari] = isiDataMahasiswa(username, password, nama, temp);
							ta=1;
							printf("\n\t\tBerhasil input Mata Kuliah...");
					//	} else {
					//		printf("\n\t[!] Mata Kuliah penuh");
					//	}
					break;
					
					case 2 :
						printf("\n\t\t=== Hapus Mata Kuliah ===");
						printf("\n\tInput Nama Mata Kuliah : "); fflush(stdin); gets(namaMK);
						hapusMataKuliah(M, cariNama, namaMK, &cek);
						
						if(cek==1) {
							printf("\n\t\tBerhasil menghapus Mata Kuliah...");
						} else {
							printf("\n\t\tBatal menghapus Mata Kuliah...");
						}
					break;
					
					case 3 :
						tampilMahasiswa(M, cariNama);
					break; 
										
					case 0 :
						logout=1;
						cekLogout(&logout, &ceka, &cekb);
					break;
					
					default :
						printf("\n\t[!] Menu invalid");
					break;
				} getch();
			} while(logout!=1);
		}		
	} while(out!=1);
	return 0;
}

void inisialisasi(Mahasiswa M[]) {
	int i, n, ta=0;
	
	for(i=0; i<MAXMahasiswa; i++) {
		strcpy(M[i].username, "-");
		strcpy(M[i].password, "-");
		strcpy(M[i].nama, "-");
		
		for(n=0; n<MAXMataKuliah; n++) {
			strcpy(M[i].Mk[n].namaMK, "-");
			M[i].Mk[n].sks = 0;
		}
	}
}

void cekLogin(int *cekA, int *cekB, string user, string pass) {
	if(strcmpi(user, "Admin")==0 && strcmpi(pass, "Admin")==0) {
		*cekA=1;
	} else {
		printf("\n\t\t[!] Username / Password invalid"); getch();
		*cekA=0;
		*cekB=0;
	}
}

void cekLogout(int *logout, int *cekA, int *cekB) {
	*logout=1;
	*cekA=0;
	*cekB=0;
}

MataKuliah isiDataMataKuliah(string namaMK, int sks) {
	MataKuliah Mk;
	strcpy(Mk.namaMK, namaMK);
	Mk.sks = sks;
	return Mk;
}

Mahasiswa isiDataMahasiswa(string username, string password, string nama, MataKuliah temp[]) {
	Mahasiswa M;
	int i;
	
	strcpy(M.username, username);
	strcpy(M.password, password);
	strcpy(M.nama, nama);
	
	for(i=0; i<MAXMataKuliah; i++) {
		M.Mk[i] = temp[i];
	}
	return M;
}

int cekEmpty(Mahasiswa M[]) {
	int i;
	for(i=0; i<MAXMahasiswa; i++) {
		if(strcmp(M[i].nama, "-")==0) {
			return i;
		}
	}
	return -1;
}

int cekIsi(Mahasiswa M[]) {
	int i;
	for(i=0; i<MAXMahasiswa; i++) {
		if(strcmp(M[i].username, "-")!=0) {
			return i;
		}
	}
	return -1;
}

int cariMahasiswa(Mahasiswa M[], string cariNama) {
	int i;
	for(i=0; i<MAXMahasiswa; i++) {
		if(strcmp(M[i].nama, cariNama) == 0) {
			return i;
		}
	}
	return -1;
}

int cariMataKuliah(Mahasiswa M[], string namaMK) {
	int i;
	int index = cariMahasiswa(M, namaMK);
	for(i=0; i<MAXMataKuliah; i++) {
		if(strcmp(M[index].Mk[i].namaMK, namaMK) == 0) {
			return i;
		}
	}
	return -1;
}

int cekMK(Mahasiswa M[], string cariNama) {
	int i;
	int index = cariMahasiswa(M, cariNama);
	for(i=0; i<MAXMataKuliah; i++) {
		if(strcmp(M[index].Mk[i].namaMK, "-")==0) {
			return i;
		}
	}
	return -1;
}

void hapusMataKuliah(Mahasiswa M[], string cariNama, string namaMK, int *cek) {
	int i = cariMahasiswa(M, cariNama);
	int n = cariMataKuliah(M, namaMK);
	
        if(n !=-1) {
			strcpy(M[i].Mk[n].namaMK, "-");
			M[i].Mk[n].sks = 0;
			
			*cek=1;
		} else {
		printf("\n\t[!] Data tidak ditemukan");
		
		*cek=0;
	}
}

void tampilAdmin(Mahasiswa M[]) {
	int i, j;
	
	printf("\n\t\t=== Data Mahasiswa ===\n");
	for(i=0; i<MAXMahasiswa; i++) {
	//	if(strcmp(M[i].nama, "-")!=0) {
			printf("\n\tMahasiswa ke-%d", (i+1));
			printf("\n\tUsername Mahasiswa  : %s", M[i].username);
			printf("\n\tPassword Mahasiswa  : %s", M[i].password);
			printf("\n\tNama Mahasiswa      : %s\n", M[i].nama);
		/*	
			if(ta==1) {
				printf("\n\n\t\t--- Data Mata Kuliah ---");
				for(j=0; j<MAXMataKuliah; j++) {
					printf("\n\n\t\tMata Kuliah - %d", (j+1));
					printf("\n\t\tNama Mata Kuliah  : %s", M[index].Mk[j].namaMK);
					printf("\n\t\tSKS               : %d", M[index].Mk[j].sks);
				}
			} */	
	//	} else { 
	//		printf("\n\t[!] Invalid");
	//	} 	
	}
}

void tampilMahasiswa(Mahasiswa M[], string cariNama) {
	int i, j;
	int index = cariMahasiswa(M, cariNama);
	
	printf("\n\t\t=== Data Mahasiswa ===");
		if(strcmp(M[index].nama, "-")!=0) {
			printf("\n\tUsername Mahasiswa  : %s", M[index].username);
			printf("\n\tPassword Mahasiswa  : %s", M[index].password);
			printf("\n\tNama Mahasiswa      : %s\n", M[index].nama); 
			
			printf("\n\n\t\t--- Data Mata Kuliah ---");
			for(j=0; j<MAXMataKuliah; j++) {
				printf("\n\n\t\tMata Kuliah - %d", (j+1));
				printf("\n\t\tNama Mata Kuliah  : %s", M[index].Mk[j].namaMK);
				printf("\n\t\tSKS               : %d", M[index].Mk[j].sks);
			}
		} else {
			printf("\n\t[!] Invalid");
		}
	
} 
