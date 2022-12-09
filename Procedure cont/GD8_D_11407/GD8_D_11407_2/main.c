#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define hargaA 500000
#define hargaB 650000
#define hargaC 700000

typedef char string[50];

void inisialisasi(int *toleransi, int *tipeA, int *tipeB, int *tipeC, int *pembeli, int *pembelian, int *jmlA, int *jmlB, int *jmlC, int *totA, int *totB, int *totC, int *total);
void cekLogin(int *cek, string user, int pass);
void penjumlahan(int *angka, int penjumlahan);
void pengurangan(int *angka, int pengurangan);
void perkalian(int *hasil, int angka, int pengali);
void cekHarga(int *angka, string tipe);
void cekJumlahTipe(int *temp, int tasA, int tasB, int tasC, string tipe);
void pembaruanKetersediaanTas(int *tasA, int *tasB, int *tasC, int *jmlA, int *jmlB, int *jmlC, int jml, string tipe);
void printRincian(string nama, string tgl, int jmlhA, int jmlhB, int jmlhC, int totA, int totB, int totC, int total);
void hitungTotal(int *tot, int jmlA, int jmlB, int jmlC);
void cekLogout(int *logout, string konfirm);

int main(int argc, char *argv[]) {
	string user, konfirm, nama, tgl, tipe;
	int pass, menu, cek, logout, harga, jumlah, tempJumlah;
	int toleransi, tipeA, tipeB, tipeC, pembeli, pembelian, jmlA, jmlB, jmlC, totA, totB, totC, total;
	
	inisialisasi(&toleransi, &tipeA, &tipeB, &tipeC, &pembeli, &pembelian, &jmlA, &jmlB, &jmlC, &totA, &totB, &totC, &total);
	
	do {
		logout=0;
		system("cls");
		printf("\n\t\t=== LOGIN SYSTEM ===");
		printf("\n\t\tToleransi : %d\n", toleransi);
		printf("\tUsername : "); fflush(stdin); gets(user);
		printf("\tPassword : "); scanf("%d", &pass); 
		cekLogin(&cek, user, pass);
		
		if(cek==1) {
			do {
				system("cls");
				printf("\n\t\tTOKO TAS SISKA");
				printf("\n\t\t==== MENU ====");
				printf("\n\t %d Tipe A - %d Tipe B - %d Tipe C", tipeA, tipeB, tipeC);
				printf("\n\t[1] Input Data Pembeli");
				printf("\n\t[2] Input Pembelian");
				printf("\n\t[3] Rincian");
				printf("\n\t[0] Logout");
				printf("\n\t>>> "); scanf("%d", &menu);
				
				switch(menu) {
					case 1:
						if(pembeli==1) {
							printf("\n\t[!] Data Pembeli Sudah Terinput!");
						} else {
							printf("\n\t\t== INPUT DATA PEMBELI ==\n");
							printf("\tNama : "); fflush(stdin); gets(nama);
							while(strlen(nama)==0 || strcmpi(nama, "-")==0) {
								printf("\n\t\t[!] Nama tidak boleh kosong!\n");
								printf("\tNama : "); fflush(stdin); gets(nama);
							}
							printf("\tTanggal Pembelian : "); fflush(stdin); gets(tgl);
							while(strlen(tgl)!=10) {
								printf("\n\t\t[!] Tanggal salah!\n");
								printf("\tTanggal Pembelian : \n"); fflush(stdin); gets(tgl);
							}
							printf("\n\t\tBerhasil Input Data Pembeli...");
							pembeli=1;
						}
					break;
					
					case 2:
						if(pembeli==0) {
							printf("\n\t[!] Data Pembeli belum ada!");
						} else {
							printf("\n\t\t== INPUT PEMBELIAN ==\n");
							printf("\tTipe Tas (A/B/C) : "); fflush(stdin); gets(tipe);
							while(strcmpi(tipe, "A")!=0 && strcmpi(tipe, "B")!=0 && strcmpi(tipe, "C")!=0) {
								printf("\n\t\t[!] Tipe tidak diketahui!\n");
								printf("\tTipe Tas (A/B/C) : "); fflush(stdin); gets(tipe);
							}
							
							cekHarga(&harga, tipe);
							printf("\n\tHarga		 : %d", harga);
							printf("\n\tJumlah Pembelian : "); scanf("%d", &jumlah);
							cekJumlahTipe(&tempJumlah, tipeA, tipeB, tipeC, tipe);
							
							if(jumlah<=0) {
								printf("\n\t[!] Jumlah Pembelian tidak boleh kurang dari 1!");
							} else if(jumlah>tempJumlah) {
								printf("\n\t[!] Jumlah Pembelian melebihi ketersediaan!");
							} else {
								pembaruanKetersediaanTas(&tipeA, &tipeB, &tipeC, &jmlA, &jmlB, &jmlC, jumlah, tipe);
								printf("\n\tBerhasil Input Pembelian...");
								pembelian=1;
							}						
						}
					break;
					
					case 3:
						if(pembeli==0) {
							printf("\n\t[!] Data Pembeli belum ada!");
						} else if(pembelian==0) {
							printf("\n\t[!] Belum ada Pembelian!");
						} else {
							printf("\n\t\t==RINCIAN==\n");
							perkalian(&totA, jmlA, hargaA);
							perkalian(&totB, jmlB, hargaB);
							perkalian(&totC, jmlC, hargaC);
							
							hitungTotal(&total, totA, totB, totC);
							printRincian(nama, tgl, jmlA, jmlB, jmlC, totA, totB, totC, total);
						}
					break;	
					
					case 0:
						printf("\n\tYakin ingin logout? (ya/tidak)\n\t"); fflush(stdin); gets(konfirm);
						cekLogout(&logout, konfirm);
						
						if(logout==1) {
							printf("\n\tTerima Kasih");
							inisialisasi(&toleransi, &tipeA, &tipeB, &tipeC, &pembeli, &pembeli, &jmlA, &jmlB, &jmlC, &totA, &totB, &totC, &total);
						}
					break;
					
					default:
						printf("\n\t[!] Menu tidak ada!");
					break;
				} 
				getch();
			} while(logout!=1);
		} else {
			printf("\n\t\t[!] Username / Password Salah!");
			pengurangan(&toleransi, 1);
		}
		getch();
	} while(toleransi!=0);
	
	printf("\n\n\t\tKeluar");
	printf("\n\t\tTerima Kasih...");
	
	return 0;
}

void inisialisasi(int *toleransi, int *tipeA, int *tipeB, int *tipeC, int *pembeli, int *pembelian, int *jmlA, int *jmlB, int *jmlC, int *totA, int *totB, int *totC, int *total) {
	*toleransi=5;
	*toleransi=10;
	*tipeA=10;  
	*tipeB=10;  
	*tipeC=10;  
	*pembeli=0;  
	*pembelian=0;
	*jmlA=0;  
	*jmlB=0;  
	*jmlC=0;  
	*totA=0; 
	*totB=0; 
	*totC=0; 
	*total=0;
}

void cekLogin(int *cek, string user, int pass) {
	if(strcmp(user, "Siska")==0 && pass==12345) {
		*cek=1;
	} else {
		*cek=0;
	}
}

void penjumlahan(int *angka, int penjumlah) {
	(*angka) = (*angka) + penjumlah;
}

void pengurangan(int *angka, int pengurang) {
	(*angka) = (*angka) - pengurang;
}

void perkalian(int *hasil, int angka, int pengali) {
	(*hasil) = angka * pengali;
}

void cekHarga(int *harga, string tipe) {
	if(strcmpi(tipe, "A")==0) {
		*harga = hargaA;
	} else if(strcmpi(tipe, "B")==0) {
		*harga = hargaB;
	} else {
		*harga = hargaC;
	}
}

void cekJumlahTipe(int *temp, int tasA, int tasB, int tasC, string tipe) {
	if(strcmpi(tipe, "A")==0) {
		*temp = tasA;
	} else if(strcmpi(tipe, "B")==0) {
		*temp = tasB;
	} else {
		*temp = tasC;
	}
}

void pembaruanKetersediaanTas(int *tasA, int *tasB, int *tasC, int *jmlA, int *jmlB, int *jmlC, int jml, string tipe) {
	if(strcmpi(tipe, "A")==0) {
		pengurangan(&(*tasA), jml);
		penjumlahan(&(*jmlA), jml);
	} else if(strcmpi(tipe, "B")==0) {
		pengurangan(&(*tasB), jml);
		penjumlahan(&(*jmlB), jml);
	} else {
		pengurangan(&(*tasC), jml);
		penjumlahan(&(*jmlC), jml);
	}
}

void printRincian(string nama, string tgl, int jmlA, int jmlB, int jmlC, int totA, int totB, int totC, int total) {
	printf("\n\tNama			: %s", nama);
	printf("\n\tTanggal Pembelian	: %s\n", tgl);
	printf("\n\t [Tas A]	| %d |\t| @Rp %d |\t---> Total : Rp %d", jmlA, hargaA, totA);
	printf("\n\t [Tas B]	| %d |\t| @Rp %d |\t---> Total : Rp %d", jmlB, hargaB, totB);
	printf("\n\t [Tas C]	| %d |\t| @Rp %d |\t---> Total : Rp %d", jmlC, hargaC, totC);
	
	printf("\n\n\tTotal yang harus dibayar : Rp %d", total);
}

void hitungTotal(int *tot, int jmlA, int jmlB, int jmlC) {
	*tot = jmlA + jmlB + jmlC;
}

void cekLogout(int *logout, string konfirm) {
	if(strcmpi(konfirm, "ya")==0) {
		*logout=1;
	} else {
		*logout=0;
	}
}
