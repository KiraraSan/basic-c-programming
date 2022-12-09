#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

typedef char string[50];

int main(int argc, char *argv[]) {
	
	string nama, npm, reservasi, pembayaran, user, password, umur, telp, kodekamar, kl, bs, el, rl, em;
	int lamasewa, pil, hargakl = 12000000, hargabs = 1000000, hargael = 850000, hargarl = 500000, hargaem = 350000, uang, total, kembalian;
	bool menu = true;
	
	int cekLog=0;
	int cekInput=0;
	
	while(menu==true) {
		
		system("cls");
		printf("\n\t--= Kos Putra Sejahtera =--");
		printf("\n\t1. Login");
		printf("\n\t2. Display");
		printf("\n\t3. Reservasi");
		printf("\n\t4. Pembayaran");
		printf("\n\t0. Keluar");
		printf("\n\tPilih menu > "); scanf("%d", &pil); 
		
		switch(pil) { 
			case 1:
				if( cekLog==0 ) {
		
					printf("\n\t[LOGIN]");
					printf("\n\tUsername : "); fflush(stdin); gets(user);
					printf("\n\tPassword : "); fflush(stdin); gets(password);
					
					if( strcmp(user, "Alex")==0 && strcmp(password, "11407")==0 || strcmp(user, "Admin")==0 && strcmp(password, "admin")==0) {
					
						printf("\n\t\tBerhasil login...");
						
						cekLog=1;
						
					} else printf("\n\t\tUsername atau Password Salah[!]");
				} else printf("\n\t\tAnda Sudah Login[!]");
			
			break;
			
			case 2:
				if(cekLog==0) printf("\n\t\tAnda harus login terlebih dahulu[!]");
				else {
					printf("\n\t[Kamar Kos]");
					printf("\n\n[1] Kamar Luxury");
					printf("\n\tHarga Sewa/bulan		: Rp %d", hargakl);
					printf("\n\tKode Kamar			: KL");
					printf("\n\tFasilitas Lengkap		: Ya");
					
					printf("\n\n[2] Kamar Bussiness");
					printf("\n\tHarga Sewa/bulan		: Rp %d", hargabs); 
					printf("\n\tKode Kamar			: BS"); 
					printf("\n\tFasilitas Lengkap		: Ya");
					
					printf("\n\n[3] Kamar Eksklusif");
					printf("\n\tHarga Sewa/bulan		: Rp %d", hargael); 
					printf("\n\tKode Kamar			: EL"); 
					printf("\n\tFasilitas Lengkap		: Ya");
					
					printf("\n\n[4] Kamar Reguler");
					printf("\n\tHarga Sewa/bulan		: Rp %d", hargarl); 
					printf("\n\tKode Kamar			: RL"); 
					printf("\n\tFasilitas Lengkap		: Tidak");
					
					printf("\n\n[5] Kamar Ekonomi");
					printf("\n\tHarga Sewa/bulan		: Rp %d", hargaem);
					printf("\n\tKode Kamar			: EM");
					printf("\n\tFasilitas Lengkap		: Tidak");
					
					cekInput=1;
				}
			break;
			
			case 3:
				if(cekLog==0) printf("\n\t\tAnda harus login terlebih dahulu[!]");
				else {
					printf("\n\t[Input Data Anda]");
					printf("\n\tNama		:"); fflush(stdin); gets(nama);
					printf("\n\tUmur		:"); fflush(stdin); gets(umur);
					printf("\n\tNo. Telp 	:"); fflush(stdin); gets(telp);
					printf("\n\tLama Sewa 	:"); scanf("%d", &lamasewa);
					printf("\n\tKode Kamar 	:"); fflush(stdin); gets(kodekamar);
					
					printf("\n\t\tBerhasil Input Data..."); 
					
					cekInput=1;
				}
				
			break;
			
			case 4:
				if(cekLog==0) printf("\n\t\tAnda harus login terlebih dahulu[!]");
				else {
					printf("\n\t[========= Bukti Reservasi =========]");
					if (strcmpi(kodekamar, "KL")==0) {
					printf("\n\tKamar		: %s", kodekamar); 
					printf("\n\tUmur		: %s", umur); 
					printf("\n\tNo. Telp 	: %s", telp); 
					printf("\n\tHarga	 	: %d", hargakl); 
					printf("\n\tLama Sewa 	: %d", lamasewa);
					
					total = hargakl * lamasewa;
					
					}
					
					else if (strcmpi(kodekamar, "BS")==0) {
					printf("\n\tKamar		: %s", kodekamar); 
					printf("\n\tUmur		: %s", umur); 
					printf("\n\tNo. Telp 	: %s", telp); 
					printf("\n\tHarga	 	: %d", hargabs); 
					printf("\n\tLama Sewa 	: %d", lamasewa);
					
					total = hargabs * lamasewa;
					
					}
					
					else if (strcmpi(kodekamar, "EL")==0) {
					printf("\n\tKamar		: %s", kodekamar); 
					printf("\n\tUmur		: %s", umur); 
					printf("\n\tNo. Telp 	: %s", telp); 
					printf("\n\tHarga	 	: %d", hargael); 
					printf("\n\tLama Sewa 	: %d", lamasewa);
					
					total = hargael * lamasewa;
					
					}
					
					else if (strcmpi(kodekamar, "RL")==0) {
					printf("\n\tKamar		: %s", kodekamar); 
					printf("\n\tUmur		: %s", umur); 
					printf("\n\tNo. Telp 	: %s", telp); 
					printf("\n\tHarga	 	: %d", hargarl); 
					printf("\n\tLama Sewa 	: %d", lamasewa);
					
					total = hargarl * lamasewa;
					
					}
					
					else if (strcmpi(kodekamar, "EM")==0) {
					printf("\n\tKamar		: %s", kodekamar); 
					printf("\n\tUmur		: %s", umur); 
					printf("\n\tNo. Telp 	: %s", telp); 
					printf("\n\tHarga	 	: %d", hargaem); 					
					printf("\n\tLama Sewa 	: %d", lamasewa);
					
					total = hargaem * lamasewa;
					
					}
					
					printf("\n\t[================================]");
					printf("\n\tTotal				: %d", total);
					printf("\n\tUang Anda			: "); scanf("%d", uang);
					
					if (uang<total) {
						printf("\n\tMaaf uang Anda tidak cukup[!]");
					}
						else {
						kembalian = uang-total;
							
							printf("\n\tKembalian	: %d", kembalian);
							printf("\n\tPembayaran berhasil[!]");
					}	
					
					
					cekInput=1;
				}
			break;
			
			case 0:
				printf("\n\t\tAlexis Divasonda Sigat Ngaing | 210711407 | D");
				printf("\n\t\tMengerjakan UGD ini dengan jujur");
				printf("\n\t\tKeluar dari program...");
				menu = false;
			break;
			default:
				printf("\n\t\tMenu tidak ada[!]");
			break;
			
		} getch();
	}
	return 0;
}
