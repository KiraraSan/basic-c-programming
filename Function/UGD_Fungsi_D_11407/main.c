#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>

// Alexis Divasonda Sigat Ngaing / 210711407 / D

typedef char string[20];

int login(int cek, string username, string password);
int inputPesanan(int menu, int hydrocodone, int lisinopril, int antibiotikamoxicilin, int epogen, int pembeli, string nama, string nomor);

int main(int argc, char *argv[]) {
	
	int menu, cek=0;
	int batal;
	int hydrocodone, lisinopril, antibiotikamoxicilin, epogen, pembeli;
	float jari, tinggi;
	string ans, username, password, nama, nomor;
		
		do {
			system("color 60");
			system("cls");
			printf("\n\t===== APOTEK 24 OK =====\n\n");
			printf("\n\t[1] Login");
			printf("\n\t[2] Input Pesanan");
			printf("\n\t[3] Pembayaran");
			printf("\n\t[4] Batalkan Pesanan");
			printf("\n\t[5] [TUGAS] Edit Pesanan");
			printf("\n\t[ESC] Keluar");
			printf("\n\tPilih Menu >>> "); scanf("%d", &menu);
			
			switch(menu) {
				case 1 :
					do {
						printf("\n\tUsername : "); fflush(stdin); gets(username);
						printf("\tPassword : "); scanf("%d", &password); 
						
						cek=login(cek, username, password);
						
					} while(cek!=0);
				break;
				
				case 2 :
					if(cek==0) {
						printf("[!] Login terlebih dahulu");
					} 
					else {	
						pembeli=inputPesanan(menu, hydrocodone, lisinopril, antibiotikamoxicilin, epogen, pembeli, nama, nomor);
					}
				break;
				
				case 3 :
				
				break;
				
				case 4 :
					printf("\n\tIngin membatalkan pesanan? [ya / tidak] : "); fflush(stdin); gets(batal);
					
					if(strcmpi(batal, "ya")==0) {
			
						printf("\n\t\tBatal...");
					}
				break;
			}
			getch();
		} 
		while(menu != 0);
	
	return 0;
}

int login(int cek, string username, string password) {
	
	if (strcmp(username, "Apotek24OK")==0 && strcmp(password, "11407")==0) {
		cek=1;
		printf("\n\tSelamat Datang...");
	} 
	else {
		printf("\n\t[!] Username / Password invalid");		
		cek=0;
	}							
	return cek;
}

int inputPesanan(int menu, int hydrocodone, int lisinopril, int antibiotikamoxicilin, int epogen, int pembeli, string nama, string nomor) {
do {
	system("cls");
	printf("\n\t===== APOTEK LIST =====\n\n");
	printf("\n\t[1] Hydrocodone			Rp 30.000,00");
	printf("\n\t[2] Lisinopril			Rp 20.000,00");
	printf("\n\t[3] Antibiotik Amoxicilin	Rp 40.000,00");
	printf("\n\t[4] Epogen			Rp 15.000,00");
	printf("\n\t[0] Keluar");
	printf("\n\tMasukkan Pilihan >>> "); scanf("%d", &menu);
							
		switch(menu) {
			case 1 :
				printf("\n\tMasukkan jumlah Hydrocodone	: "); scanf("%d", &hydrocodone);
				printf("\n\tBerhasil memesan Hydrocodone dengan jumlah %d...", hydrocodone);
			break;
						
			case 2 :
				printf("\n\tMasukkan jumlah Lisinopril	: "); scanf("%d", &lisinopril);
				printf("\n\tBerhasil memesan Lisinopril dengan jumlah %d...", lisinopril);
			break;
						
			case 3 :
				printf("\n\tMasukkan jumlah Antibiotik Amoxicilin	: "); scanf("%d", &antibiotikamoxicilin);
				printf("\n\tBerhasil memesan Antibiotik Amoxicilin dengan jumlah %d...", antibiotikamoxicilin);
			break;
						
			case 4 :
				printf("\n\tMasukkan jumlah Epogen	: "); scanf("%d", &epogen);
				printf("\n\tBerhasil memesan Epogen dengan jumlah %d...", epogen);
			break;
							
			case 0 :
				printf("\tNama				: "); fflush(stdin); gets(nama);
				while(strlen(nama)==0 || strcmpi(nama, "-")==0) {
					printf("\n\t\t[!] Nama tidak boleh kosong!\n");
					printf("\tNama				: "); fflush(stdin); gets(nama);
				}
				printf("\tMasukkan Nomor Pesanan [1-30 GANJIL]			: "); fflush(stdin); gets(nomor);
			//	while(strlen(nomor)mod2=0 || strcmpi(nomor, "-")==0 || strlen(nomor)>30 || strlen(nomor)<0) {
					printf("\n\t\t[!] Nomor meja harus 0-30 dan bernilai ganjil\n");
					printf("\tMasukkan Nomor Pesanan [1-30 GANJIL]			: "); fflush(stdin); gets(nomor);
			//	}
				printf("\n\n\t===========================================================================");
				printf("\n\t[1] Hydrocodone			: %d", hydrocodone);
				printf("\n\t[2] Lisinopril			: %d", lisinopril);
				printf("\n\t[3] Antibiotik Amoxicilin	: %d", antibiotikamoxicilin);
				printf("\n\t[4] Epogen			: %d", epogen);
				printf("\n\t===========================================================================");
				printf("\n\tSilakan lanjut ke menu pembayaran");
				printf("\n\n\tKlik apapun untuk melanjutkan...");
							
				pembeli=1;
			break;
						
			default :
				printf("\n\t[!] Pilihan invalid");
			break;
		} getch();
		} while(menu!=0);
					
		return pembeli;
} 


