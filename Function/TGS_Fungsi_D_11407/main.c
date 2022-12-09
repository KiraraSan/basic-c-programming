#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>

// Alexis Divasonda Sigat Ngaing / 210711407 / D

#define hargahydrocodone 70000
#define hargalisinopril 30000
#define hargaantibiotikamoxicilin 60000
#define hargaepogen 150000

typedef char string[20];

int login(string username, int password);
int inputPesanan(int hydrocodone, int lisinopril, int antibiotikamoxicilin, int epogen);
int pembayaran(string nama, int nomor, int hydrocodone, int lisinopril, int antibiotikamoxicilin, int epogen);
float hargaTotal(int hydrocodone, int lisinopril, int antibiotikamoxicilin, int epogen, int harga);
float hitungPajak(float total);

int main(int argc, char *argv[]) {
	
	int menu, cek, pass, nomor; 
	int bayar, logout, pembeli;
	int hydrocodone, lisinopril, antibiotikamoxicilin, epogen;
	float harga, pajak, total;
	string ans, user, nama, batal, member;
		
		do {
		//	system("color 60");
			logout=0;
			system("cls");
			printf("\n\t===== APOTEK 24 OK =====\n");
			printf("\n\t[1] Login");
			printf("\n\t[2] Input Pesanan");
			printf("\n\t[3] Pembayaran");
			printf("\n\t[4] Batalkan Pesanan");
			printf("\n\t[5] [TUGAS] Edit Pesanan");
			printf("\n\t[ESC] Keluar");
			printf("\n\tPilih Menu >>> "); scanf("%d", &menu);
			
			switch(menu) {
				case 1 :
					if(cek==1) {
						printf("\n\t\t[!] Anda sudah login");
					} 
					else {
						printf("\n\n\t\tUsername : "); fflush(stdin); gets(user);
						printf("\t\tPassword : "); scanf("%d", &pass); 
						
						cek = login(user, pass);
					}	
				break;
				
				case 2 :
					if(cek==0) {
						printf("\n\t\t[!] Login terlebih dahulu");
					} 
					else {	
						do {
							system("cls");
							printf("\n\t===== APOTEK LIST =====\n");
							printf("\n\t[1] Hydrocodone			Rp 30.000,00");
							printf("\n\t[2] Lisinopril			Rp 20.000,00");
							printf("\n\t[3] Antibiotik Amoxicilin	Rp 40.000,00");
							printf("\n\t[4] Epogen			Rp 15.000,00");
							printf("\n\t[0] Keluar");
							printf("\n\tMasukkan Pilihan >>> "); scanf("%d", &menu);
													
								
									if(menu==1) {
										printf("\n\tMasukkan jumlah Hydrocodone	: "); scanf("%d", &hydrocodone);
										printf("\n\tBerhasil memesan Hydrocodone dengan jumlah %d...", hydrocodone);
									} 
																				
									else if(menu==2) {
										printf("\n\tMasukkan jumlah Lisinopril	: "); scanf("%d", &lisinopril);
										printf("\n\tBerhasil memesan Lisinopril dengan jumlah %d...", lisinopril);
									}															
												
									else if(menu==3) {
										printf("\n\tMasukkan jumlah Antibiotik Amoxicilin	: "); scanf("%d", &antibiotikamoxicilin);
										printf("\n\tBerhasil memesan Antibiotik Amoxicilin dengan jumlah %d...", antibiotikamoxicilin);
									}										
												
									else if(menu==4) {
										printf("\n\tMasukkan jumlah Epogen	: "); scanf("%d", &epogen);
										printf("\n\tBerhasil memesan Epogen dengan jumlah %d...", epogen);
									}											
													
									else if(menu==0) {
										printf("\n\tMasukkan Nama				: "); fflush(stdin); gets(nama);
										while(strlen(nama)==0 || strcmpi(nama, "-")==0) {
											printf("\n\t\t[!] Nama tidak boleh kosong!\n");
											printf("\n\tMasukkan Nama				: "); fflush(stdin); gets(nama);
										}
										printf("\tMasukkan Nomor Pesanan [1-30 GANJIL]	: "); scanf("%d", &nomor);
										while(nomor % 2==0 || nomor>30 || nomor<0) {
											printf("\n\t\t[!] Nomor meja harus 0-30 dan bernilai ganjil\n");
											printf("\tMasukkan Nomor Pesanan [1-30 GANJIL]	: "); scanf("%d", &nomor);
										}
										printf("\tApakah pelanggan merupakan member? [y / n]"); fflush(stdin); gets(member);
			
										pembeli=inputPesanan(hydrocodone, lisinopril, antibiotikamoxicilin, epogen);
										logout=1;
									}
										
									else {
										printf("\n\n\t\t[!] Menu invalid");
									}					
								 getch();
						} while(logout!=1);
					
					}
				break;
				
				case 3 :
					if(cek==0) {
						printf("\n\t\t[!] Login terlebih dahulu");
					} 
					else if(pembeli==0) {
						printf("\n\t\t[!] Belum ada pembelian");
					}
					else {	
						bayar=pembayaran(nama, nomor, hydrocodone, lisinopril, antibiotikamoxicilin, epogen);
					}
				break;
				
				case 4 :
					if(cek==0) {
						printf("\n\t\t[!] Login terlebih dahulu");
					} 
					else {
						printf("\n\tAnda yakin ingin menghapus data? [Y / N] : "); fflush(stdin); gets(batal);
						
						if(strcmpi(batal, "Y")==0) {
				
							printf("\n\t\tBatal...");
						}
					}	
				break;
				
				case 5 :
					if(cek==0) {
						printf("\n\t\t[!] Login terlebih dahulu");
					} 
					else if(pembeli==0) {
						printf("\n\t\t[!] Belum ada pembelian");
					}
					else {
						printf("\n\tUBAH DATA");
						printf("\n\t====================================================================");
						printf("\n\t[1] Hydrocodone			: %d", hydrocodone);
						printf("\n\t[2] Lisinopril			: %d", lisinopril);
						printf("\n\t[3] Antibiotik Amoxicilin	: %d", antibiotikamoxicilin);
						printf("\n\t[4] Epogen			: %d", epogen);
						printf("\n\t====================================================================");
						printf("\n\t[0] Selesai");
						printf("\n\n\tMasukkan Pilihan >>> "); scanf("%d", &menu);
						
							if(menu==1) {
								printf("\n\t[1] Tambah"); 
								printf("\n\t[2] Kurang"); 
							} 
																					
							else if(menu==2) {
								printf("\n\t[1] Tambah"); 
								printf("\n\t[1] Kurang");
							}															
													
							else if(menu==3) {
								printf("\n\t[1] Tambah"); 
								printf("\n\t[1] Kurang");
							}										
													
							else if(menu==4) {
								printf("\n\t[1] Tambah"); 
								printf("\n\t[1] Kurang");
							}											
														
							else if(menu==0) {
								
							}
											
							else {
								printf("\n\n\t\t[!] Menu invalid");
							}
					}
				break;
			}
			getch();
		} 
		while(menu != 0);
	
	return 0;
}

int login(string username, int password) {
	
	int cek=0;
	
	if(strcmp(username, "Apotek24OK")==0 && password == 11407) {
		printf("\n\t\t\tSelamat Datang...");
		cek=1;
	} 
	else {
		printf("\n\t\t\t[!] Username / Password invalid");		
	}							
	return cek;
}

int inputPesanan(int hydrocodone, int lisinopril, int antibiotikamoxicilin, int epogen) {

	int pembeli;
	
	printf("\n\t====================================================================");
	printf("\n\t[1] Hydrocodone			: %d", hydrocodone);
	printf("\n\t[2] Lisinopril			: %d", lisinopril);
	printf("\n\t[3] Antibiotik Amoxicilin	: %d", antibiotikamoxicilin);
	printf("\n\t[4] Epogen			: %d", epogen);
	printf("\n\t====================================================================");
	printf("\n\tSilakan lanjut ke menu pembayaran");
	printf("\n\n\tKlik apapun untuk melanjutkan...");
								
	pembeli=1;		
						
	return pembeli;
} 

int pembayaran(string nama, int nomor, int hydrocodone, int lisinopril, int antibiotikamoxicilin, int epogen) {
	
	int bayar;
	
	printf("\n\t\t\t\tRINCIAN PEMBAYARAN");
	printf("\n\t====================================================================");
	printf("\n\tNama			: %s", nama);
	printf("\n\tNomor Pesanan		: %d", nomor);
	
	printf("\n\n\t\t\tRINCIAN PESANAN");
	printf("\n\t====================================================================");
	printf("\n\t[1] Jumlah Hydrocodone			: %d", hydrocodone);
	printf("\n\t[2] Jumlah Lisinopril			: %d", lisinopril);
	printf("\n\t[3] Jumlah Antibiotik Amoxicilin	: %d", antibiotikamoxicilin);
	printf("\n\t[4] Jumlah Epogen			: %d", epogen);
	printf("\n\t====================================================================");
	
//	printf("\n\n\tTotal Harga		: %.2f", harga);
//	printf("\n\tPajak			: %.2f", pajak);
//	printf("\n\tTotal Bayar		: %.2f", total);
	
	return bayar;
}

float hargaTotal(int hydrocodone, int lisinopril, int antibiotikamoxicilin, int epogen, int harga) {
	return (hydrocodone * hargahydrocodone) + (lisinopril * hargalisinopril) + (antibiotikamoxicilin * hargaantibiotikamoxicilin) + (epogen * hargaepogen);
}

float hitungPajak(float total) {
	return total * 0.12;
}

//float totalBayar() {
//	hargaTotal(hydrocodone, lisinopril, antibiotikamoxicilin, epogen, harga) + hitungPajak(total);
//}

// DAHLAH PUSINGGGGG :') 
