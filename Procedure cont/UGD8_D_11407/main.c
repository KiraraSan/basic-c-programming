#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Alexis Divasonda Sigat Ngaing / 210711407 / D
// Bonus 1

#define hargaA 5000
#define hargaB 7500
#define hargaC 10000
#define hargaX 25000
#define hargaY 30000


typedef char string[100];

void inisialisasi(int *toleransi, int *tipeA, int *tipeB, int *tipeC, int *tipeX, int *tipeY, int *pembeli, 
				int *pembelian, int *tambahan, int *jmlA, int *jmlB, int *jmlC, int *jmlX, int *jmlY, int *totA, int *totB, 
				int *totC, int *totX, int *totY, int *total);
void cekLogin(int *cek, string user, int pass);
void penjumlahan(int *angka, int penjumlahan);
void pengurangan(int *angka, int pengurangan);
void perkalian(int *hasil, int angka, int pengali);
void cekHarga(int *angka, string tipe);
void cekJumlahTipe(int *temp, int taliA, int taliB, int taliC, int taliX, int taliY, string tipe);
void pembaruanKetersediaanTas(int *taliA, int *taliB, int *taliC, int *taliX, int *taliY, int *jmlA, int *jmlB, int *jmlC, int *jmlX, int *jmlY, int jml, string tipe);
void printRincian(string nama, string tgl, int jmlA, int jmlB, int jmlC, int jmlX, int jmlY, int totA, int totB, int totC, int totX, int totY, int total);
void hitungTotal(int *tot, int jmlA, int jmlB, int jmlC, int jmlX, int jmlY);
void cekLogout(int *logout, string confirm);

int main(int argc, char *argv[]) {
	string user, confirm, nama, telp, tgl, jam, nik, pekerjaan, alamat, tipe, reset;
	int pass, menu, cek, logout, harga, jumlah, tempJumlah;
	int toleransi, tipeA, tipeB, tipeC, tipeX, tipeY, pembeli, pembelian, tambahan, jmlA, jmlB, jmlC, jmlX, jmlY, totA, totB, totC, totX, totY, total;
	
	inisialisasi(&toleransi, &tipeA, &tipeB, &tipeC, &tipeX, &tipeY, &pembeli, &pembelian, &tambahan, &jmlA, &jmlB, &jmlC, &jmlX, &jmlY, &totA, &totB, &totC, &totX, &totY, &total);
	
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
				printf("\n\t %d Tali A - %d Tali B - %d Tali C - %d Tali X - &d Tali Y", tipeA, tipeB, tipeC, tipeX, tipeY);
				printf("\n\t[1] Input Data Pembeli");
				printf("\n\t[2] Input Pembelian");
				printf("\n\t[3] Rincian");
				printf("\n\t[4] Reset Data");
				printf("\n\t[0] Logout");
				printf("\n\t===> "); scanf("%d", &menu);
				
				switch(menu) {
					case 1:
						if(pembeli==1) {
							printf("\n\t[!] Data pembeli sudah terinput!");
						} else {
							printf("\n\t\t== INPUT DATA PEMBELI ==\n");
							printf("\tNama : "); fflush(stdin); gets(nama);
							while(strlen(nama)==0 || strcmpi(nama, "-")==0) {
								printf("\n\t\t[!] Nama tidak boleh kosong!\n");
								printf("\tNama : "); fflush(stdin); gets(nama);
							}
							printf("\tNomor Telepon : "); fflush(stdin); gets(telp);
							while(strlen(telp)==0 || strcmpi(telp, "-")==0) {
								printf("\n\t\t[!] Nomor telepon tidak boleh kosong!\n");
								printf("\tNomor Telepon : \n"); fflush(stdin); gets(telp);
							}
							printf("\tTanggal Kedatangan (dd-mm/yyyy) : "); fflush(stdin); gets(tgl);
							while(strlen(tgl)!=10) {
								printf("\n\t\t[!] Tanggal salah!\n");
								printf("\tTanggal Kedatangan : \n"); fflush(stdin); gets(tgl);
							}
							printf("\tJam Kedatangan (hh:mm:ss) : "); fflush(stdin); gets(jam);
							while(strlen(jam)!=8) {
								printf("\n\t\t[!] Jam salah!\n");
								printf("\tJam Kedatangan : \n"); fflush(stdin); gets(jam);
							}
							printf("\n\t\tInput data pembeli berhasil...");
							pembeli=1;
						}
					break;
					
					case 2:
						if(pembeli==0) {
							printf("\n\t[!] Data pembeli belum ada!");
						} else {
							printf("\n\t\t=== INPUT PEMBELIAN ===\n");
							printf("\tJenis Tali (A | B | C | X | Y) : "); fflush(stdin); gets(tipe);
							while(strcmpi(tipe, "A")!=0 && strcmpi(tipe, "B")!=0 && strcmpi(tipe, "C")!=0 && strcmpi(tipe, "X")!=0 && strcmpi(tipe, "Y")!=0) {
								printf("\n\t\t[!] Jenis tidak diketahui / Jenis tidak ada!\n");
								printf("\tJenis Tali (A | B | C | X | Y) : "); fflush(stdin); gets(tipe);
							}
							
							if(tambahan==1) {
								printf("\n\t------------------");
							}
							else if(strcmpi(tipe, "X")==0 || strcmpi(tipe, "Y")==0) {
								printf("\n\t\t== DATA TAMBAHAN ==\n");
								printf("\tNIK		: "); fflush(stdin); gets(nik);
								while(strlen(nik)!=16 || strcmpi(nik, "-")==0) {
									printf("\n\t\t[!] Format NIK salah!\n");
									printf("\tNIK		: "); fflush(stdin); gets(nik);
								}
								printf("\tPekerjaan	: "); fflush(stdin); gets(pekerjaan);
								while(strlen(pekerjaan)==0 || strcmpi(pekerjaan, "-")==0) {
									printf("\n\t\t[!] Pekerjaan tidak boleh kosong!\n");
									printf("\tPekerjaan	: \n"); fflush(stdin); gets(pekerjaan);
								}
								printf("\tAlamat	: "); fflush(stdin); gets(alamat);
								while(strlen(tgl)!=10) {
									printf("\n\t\t[!] Alamat tidak boleh kosong!\n");
									printf("\tAlamat	: \n"); fflush(stdin); gets(alamat);
								}
								printf("\n\t\tInput data tambahan pembeli berhasil...");
								tambahan=1;
							} else;
							
							cekHarga(&harga, tipe);
							printf("\n\tHarga		 : %d", harga);
							printf("\n\tJumlah Pembelian : "); scanf("%d", &jumlah);
							cekJumlahTipe(&tempJumlah, tipeA, tipeB, tipeC, tipeX, tipeY, tipe);
							
							if(jumlah<=0) {
								printf("\n\t[!] Jumlah pembelian tidak boleh kurang dari 1 meter!");
							} 
							else if(jumlah>tempJumlah) {
								printf("\n\t[!] Jumlah pembelian melebihi ketersediaan!");
							} 
							else {
								pembaruanKetersediaanTas(&tipeA, &tipeB, &tipeC, &tipeX, &tipeY, &jmlA, &jmlB, &jmlC, &jmlX, &jmlY, jumlah, tipe);
								printf("\n\tInput pembelian berhasil...");
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
							perkalian(&totX, jmlX, hargaX);
							perkalian(&totY, jmlY, hargaY);
							
							hitungTotal(&total, totA, totB, totC, totX, totY);
							printRincian(nama, tgl, jmlA, jmlB, jmlC, jmlX, jmlY, totA, totB, totC, totX, totY, total);
						}
					break;	
					
					case 4:
					printf("\n\tIngin mereset data? [ya | tidak] : ");
					fflush(stdin); gets(reset);
					
					if(strcmpi(reset, "ya")==0) {
						inisialisasi(&toleransi, &tipeA, &tipeB, &tipeC, &tipeX, &tipeY, &pembeli, &pembelian, &tambahan, &jmlA, &jmlB, &jmlC, &jmlX, &jmlY, &totA, &totB, &totC, &totX, &totY, &total);
						printf("\n\t\tData berhasil direset...");
					}
					break;
					
					case 0:
						printf("\n\tIngin logout? (ya | tidak)\n\t"); fflush(stdin); gets(confirm);
						cekLogout(&logout, confirm);
						
						if(logout==1) {
							printf("\n\tTerima kasih...");
							inisialisasi(&toleransi, &tipeA, &tipeB, &tipeC, &tipeX, &tipeY, &pembeli, &pembelian, &tambahan, &jmlA, &jmlB, &jmlC, &jmlX, &jmlY, &totA, &totB, &totC, &totX, &totY, &total);
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
	
	printf("\n\n\tAlexis Divasonda Sigat Ngaing - 210711407 - D");
	printf("n\t\tKeluar program...");
	
	return 0;
}

void inisialisasi(int *toleransi, int *tipeA, int *tipeB, int *tipeC, int *tipeX, int *tipeY, int *pembeli, int *pembelian, int *tambahan, int *jmlA, int *jmlB, int *jmlC, int *jmlX, int *jmlY, int *totA, int *totB, int *totC, int *totX, int *totY, int *total) {
	*toleransi=3;
	*tipeA=50;  
	*tipeB=50;  
	*tipeC=50; 
	*tipeX=100;
	*tipeY=100;
	*pembeli=0;  
	*pembelian=0;
	*tambahan=0;
	*jmlA=0;  
	*jmlB=0;  
	*jmlC=0;
	*jmlX=0; 
	*jmlY=0;
	*totA=0; 
	*totB=0; 
	*totC=0; 
	*totX=0; 
	*totY=0;
	*total=0;
}

void cekLogin(int *cek, string user, int pass) {
	if(strcmp(user, "Atma")==0 && pass==11407) {
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
	} 
	else if(strcmpi(tipe, "B")==0) {
		*harga = hargaB;
	} 
	else if(strcmpi(tipe, "C")==0) {
		*harga = hargaB;
	}
	else if(strcmpi(tipe, "X")==0) {
		*harga = hargaX;
	}
	else {
		*harga = hargaY;
	}
}

void cekJumlahTipe(int *temp, int taliA, int taliB, int taliC, int taliX, int taliY, string tipe) {
	if(strcmpi(tipe, "A")==0) {
		*temp = taliA;
	} 
	else if(strcmpi(tipe, "B")==0) {
		*temp = taliB;
	} 
	else if(strcmpi(tipe, "C")==0) {
		*temp = taliC;
	} 
	else if(strcmpi(tipe, "X")==0) {
		*temp = taliX;
	} 
	else {
		*temp = taliY;
	}
}

void pembaruanKetersediaanTas(int *taliA, int *taliB, int *taliC, int *taliX, int *taliY, int *jmlA, int *jmlB, int *jmlC, int *jmlX, int *jmlY, int jml, string tipe) {
	if(strcmpi(tipe, "A")==0) {
		pengurangan(&(*taliA), jml);
		penjumlahan(&(*jmlA), jml);
	} 
	else if(strcmpi(tipe, "B")==0) {
		pengurangan(&(*taliB), jml);
		penjumlahan(&(*jmlB), jml);
	} 
	else if(strcmpi(tipe, "C")==0) {
		pengurangan(&(*taliC), jml);
		penjumlahan(&(*jmlC), jml);
	}
	else if(strcmpi(tipe, "X")==0) {
		pengurangan(&(*taliX), jml);
		penjumlahan(&(*jmlX), jml);
	}
	else {
		pengurangan(&(*taliY), jml);
		penjumlahan(&(*jmlY), jml);
	}
}

void printRincian(string nama, string tgl, int jmlA, int jmlB, int jmlC, int jmlX, int jmlY, int totA, int totB, int totC, int totX, int totY, int total) {
	printf("\n\tNama			: %s", nama);
	printf("\n\tTanggal Pembelian	: %s\n", tgl);
	printf("\n\t [Tali A]	|  %d  |\t| @Rp %d |\t---> Total : Rp %d", jmlA, hargaA, totA);
	printf("\n\t [Tali B]	|  %d  |\t| @Rp %d |\t---> Total : Rp %d", jmlB, hargaB, totB);
	printf("\n\t [Tali C]	|  %d  |\t| @Rp %d |\t---> Total : Rp %d", jmlC, hargaC, totC);
	printf("\n\t [Tali X]	|  %d  |\t| @Rp %d |\t---> Total : Rp %d", jmlX, hargaX, totX);
	printf("\n\t [Tali Y]	|  %d  |\t| @Rp %d |\t---> Total : Rp %d", jmlY, hargaY, totY);
	
	printf("\n\n\tTotal yang harus dibayar : Rp %d", total);
}

void hitungTotal(int *tot, int jmlA, int jmlB, int jmlC, int jmlX, int jmlY) {
	*tot = jmlA + jmlB + jmlC + jmlX + jmlY;
}

void cekLogout(int *logout, string confirm) {
	if(strcmpi(confirm, "ya")==0) {
		*logout=1;
	} else {
		*logout=0;
	}
}
