#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

//Alexis Divasonda Sigat Ngaing / D / 210711407

typedef char string[50];

int main(int argc, char *argv[]) {
	
	string nama, npm, reservasi, pembayaran, user, password, umur, telp, kodekamar, kl, bs, el, rl, em, jawab;
	int lamasewa, pil, hargakl = 1200000, hargabs = 1000000, hargael = 850000, hargarl = 500000, hargaem = 350000, uang;
	float diskon, total, kembalian;
	bool menu = true;
	
	int cekLog=0;
	int cekInput=0;
	int cekPembayaran=0;
	
	while(menu==true) {
		
		system("cls");
		printf("\n--= Kos Putra Sejahtera =--");
		printf("\n\n\tCalon Penyewa (bonus) : %s", nama);
		printf("\n\t1. Login");
		printf("\n\t2. Display");
		printf("\n\t3. Reservasi");
		printf("\n\t4. Pembayaran");
		printf("\n\t0. Exit");
		printf("\n\n\tPilih menu > "); scanf("%d", &pil); 
		
		switch(pil) { 
			case 1:
				if (cekLog==0) {
		
					printf("\n\t[LOGIN]");
					printf("\n\tUsername : "); fflush(stdin); gets(user);
					printf("\tPassword : "); fflush(stdin); gets(password);
					
					if (strcmp(user, "Alex")==0 && strcmp(password, "11407")==0 || strcmp(user, "admin")==0 && strcmp(password, "admin")==0) {
					
						printf("\n\t\tBerhasil login...");
						
						cekLog=1;
						
					} else printf("\n\t\tUsername atau Password Salah[!]");
				} else printf("\n\t\tAnda Sudah Login[!]");
			
			break;
			
			case 2:
				if (cekLog==0) printf("\n\t\tAnda harus login terlebih dahulu[!]");
				else {
					printf("\n\t[=============== Kamar Kos ================]");
					printf("\n\n\t[1] Kamar Luxury");
					printf("\n\t\tHarga Sewa/bulan	: Rp %d", hargakl);
					printf("\n\t\tKode Kamar		: KL");
					printf("\n\t\tFasilitas Lengkap	: Ya");
					
					printf("\n\n\t[2] Kamar Bussiness");
					printf("\n\t\tHarga Sewa/bulan	: Rp %d", hargabs); 
					printf("\n\t\tKode Kamar		: BS"); 
					printf("\n\t\tFasilitas Lengkap	: Ya");
					
					printf("\n\n\t[3] Kamar Eksklusif");
					printf("\n\t\tHarga Sewa/bulan	: Rp %d", hargael); 
					printf("\n\t\tKode Kamar		: EL"); 
					printf("\n\t\tFasilitas Lengkap	: Ya");
					
					printf("\n\n\t[4] Kamar Reguler");
					printf("\n\t\tHarga Sewa/bulan	: Rp %d", hargarl); 
					printf("\n\t\tKode Kamar		: RL"); 
					printf("\n\t\tFasilitas Lengkap	: Tidak");
					
					printf("\n\n\t[5] Kamar Ekonomi");
					printf("\n\t\tHarga Sewa/bulan	: Rp %d", hargaem);
					printf("\n\t\tKode Kamar		: EM");
					printf("\n\t\tFasilitas Lengkap	: Tidak");
					
					
				}
			break;
			
			case 3:
				if (cekLog==0) printf("\n\t\tAnda harus login terlebih dahulu[!]");
				else if (cekInput==1) printf("\n\t\tAnda Sudah Melakukan Reservasi[!]");
				else {
					printf("\n\t[Input Data Anda]");
					printf("\n\tNama		: "); fflush(stdin); gets(nama);
					printf("\tUmur		: "); fflush(stdin); gets(umur);
					printf("\tNo. Telp 	: "); fflush(stdin); gets(telp);
					printf("\tLama Sewa 	: "); scanf("%d", &lamasewa);
					printf("\tKode Kamar 	: "); fflush(stdin); gets(kodekamar);
					
					if (strcmpi(kodekamar, "")==0 || strcmpi(umur, "")==0) {
						printf("\n\tInput tidak valid[!]");	
					}
					
					else if (umur<=0 || lamasewa<=0) {
						printf("\n\tInput tidak valid[!]");
					}
					
					else if (strcmpi(nama, "")==0 || strcmpi(telp, "")==0) {
						printf("\n\tInput tidak valid[!]");
					}
						
					else {
					printf("\n\tAnda yakin dengan pesanan ini? [ya|tidak] (bonus) : "); fflush(stdin); gets(jawab);
					if(strcmpi(jawab, "ya")==0) {
						cekInput=0;
						printf("\n\t\tReservasi Berhasil...");
						cekInput=1;
						} 
						
						else printf("\n\t\tReservasi Gagal..."); 	
					}	
				} 
				
			break;
			
			case 4:
				if (cekLog==0) printf("\n\t\tAnda harus login terlebih dahulu[!]");
				else if (cekInput==0) printf("\n\t\tAnda harus reservasi terlebih dahulu[!]");
				else if (cekPembayaran==1) printf("\n\t\tAnda Sudah Melakukan Pembayaran[!]");
				else {
					printf("\n\t[========== Bukti Reservasi ==========]");
					if (strcmpi(kodekamar, "KL")==0) {
					printf("\n\tKamar		: Luxury"); 
					printf("\n\tUmur		: %s", umur); 
					printf("\n\tNo. Telp 	: %s", telp); 
					printf("\n\tHarga	 	: %d", hargakl); 
					printf("\n\tLama Sewa 	: %d", lamasewa);
						
					if (lamasewa>5) {
					printf("\n\tStatus (bonus)	: Mendapatkan Diskon");
					} else printf("\n\tStatus (bonus)	: Tidak Mendapatkan Diskon");
					
					total = hargakl * lamasewa;
					}
					
					else if (strcmpi(kodekamar, "BS")==0) {
					printf("\n\tKamar		: Bussiness"); 
					printf("\n\tUmur		: %s", umur); 
					printf("\n\tNo. Telp 	: %s", telp); 
					printf("\n\tHarga	 	: %d", hargabs); 
					printf("\n\tLama Sewa 	: %d", lamasewa); 
					
					if (lamasewa>5) {
					printf("\n\tStatus (bonus)	: Mendapatkan Diskon");
					} else printf("\n\tStatus (bonus)	: Tidak Mendapatkan Diskon");
					
					total = hargabs * lamasewa;
					}
					
					else if (strcmpi(kodekamar, "EL")==0) {
					printf("\n\tKamar		: Ekslusif"); 
					printf("\n\tUmur		: %s", umur); 
					printf("\n\tNo. Telp 	: %s", telp); 
					printf("\n\tHarga	 	: %d", hargael); 
					printf("\n\tLama Sewa 	: %d", lamasewa);
					
					if (lamasewa>5) {
					printf("\n\tStatus (bonus)	: Mendapatkan Diskon");
					} else printf("\n\tStatus (bonus)	: Tidak Mendapatkan Diskon");
					
					total = hargael * lamasewa;
					}
					
					else if (strcmpi(kodekamar, "RL")==0) {
					printf("\n\tKamar		: Regular"); 
					printf("\n\tUmur		: %s", umur); 
					printf("\n\tNo. Telp 	: %s", telp); 
					printf("\n\tHarga	 	: %d", hargarl); 
					printf("\n\tLama Sewa 	: %d", lamasewa);
					
					if (lamasewa>5) {
					printf("\n\tStatus (bonus)	: Mendapatkan Diskon");
					} else printf("\n\tStatus (bonus)	: Tidak Mendapatkan Diskon");
					
					total = hargarl * lamasewa;
					}
					
					else if (strcmpi(kodekamar, "EM")==0) {
					printf("\n\tKamar		: Ekonomi"); 
					printf("\n\tUmur		: %s", umur); 
					printf("\n\tNo. Telp 	: %s", telp); 
					printf("\n\tHarga	 	: %d", hargaem); 					
					printf("\n\tLama Sewa 	: %d", lamasewa);
					
					if (lamasewa>5) {
					printf("\n\tStatus (bonus)	: Mendapatkan Diskon");
					} else printf("\n\tStatus (bonus)	: Tidak Mendapatkan Diskon");
					
					total = hargaem * lamasewa;
					}
						
					printf("\n\t[=====================================]");
					
						if (lamasewa>5) {
							diskon = total * 0.06;
						}
						
					printf("\n\tDiskon		: Rp %.2f", diskon);
					
					total = total - diskon;
						
					printf("\n\tTotal		: Rp %.2f", total);
					printf("\n\tUang Anda	: Rp "); scanf("%d", &uang);
					
					if (uang<total) {
						printf("\n\tMaaf uang Anda tidak cukup[!]");
					}
						else {
							kembalian = uang - total;
							printf("\tKembalian	: Rp %.2f", kembalian);
							printf("\n\n\tPembayaran Berhasil[!]");
							printf("\n\n\tTERIMA KASIH TELAH MEMILIH KAMI :)");
							printf("\n\t[======== KOS PUTRA SEJAHTERA ========]");
							
						cekPembayaran=1;		
					}	
				}
				
			break;
			
			case 0:
				printf("\n\t\tAlexis Divasonda Sigat Ngaing | 210711407 | D");
				printf("\n\t\tMengerjakan UGD ini dengan jujur");
				printf("\n\t\tKeluar program...");
				menu = false;
			break;
			
			default:
				printf("\n\t\tMenu tidak ada[!]");
			break;
			
		} getch();
	}
	return 0;
}
