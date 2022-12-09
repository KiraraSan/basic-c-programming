#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>

// Alexis Divasonda Sigat Ngaing / 210711407 / Kelas D
//Bonus 1, 2

typedef char string[100];

int main(int argc, char *argv[]) {
	string nama, user, password;
	int stoka=0, stokb=0, stokc=0, bid=0, pil, pilLelang, hargaa=0, hargab=0, hargac=0;
	bool menu = true;
	
	int cekLog=0;
	int cekInput=0;
	int cekPembayaran=0;
	
	while(menu==true) {
		
		system("cls");
		printf("\n===== Rumah Lelang Tebri =====");
		printf("\n[1] Login");
		printf("\n[2] Input Stok");
		printf("\n[3] Tampil Barang");
		printf("\n[4] Pelelangan");
		printf("\n[5] Pelelangan Auto (Tugas)");
		printf("\n[0] Exit");
		printf("\n------------------------------");
		printf("\n\n\tPilih menu > "); scanf("%d", &pil);
	
		switch(pil) { 
				case 1:
					if (cekLog==0) {
			
							printf("\n\t[LOGIN]");
						while (cekLog==0) {
							printf("\n\tUsername : "); fflush(stdin); gets(user);
							printf("\tPassword : "); fflush(stdin); gets(password);
						
							if (strcmp(user, "tebri")==0 && strcmp(password, "1407")==0) {
							
								printf("\n\t\tBerhasil login...");
								
								cekLog=1;
								
							} else printf("\n\t\tUsername atau Password Salah[!]");
						} 
					} else printf("\n\t\tAnda Sudah Login[!]");
				
				break;
				
				case 2:
					if (cekLog==0) printf("\n\t\tAnda harus login terlebih dahulu[!]");
					else {
						while (stoka<=0) {
						printf("\n\nMasukkan jumlah stok yang ingin Anda masukkan untuk Lukisan Van Gogh");
						printf("\nJumlah stok : "); scanf("%d", &stoka);
						} 
					
						while (stokb<=0) {
						printf("\n\nMasukkan jumlah stok yang ingin Anda masukkan untuk Patung I Nyoman Nuarta");
						printf("\nJumlah stok : "); scanf("%d", &stokb);
						} 
					
						while (stokc<=0) {
						printf("\n\nMasukkan jumlah stok yang ingin Anda masukkan untuk Lukisan Basuki Abdullah");
						printf("\nJumlah stok : "); scanf("%d", &stokc);
						} 
						
						cekInput=1;
						
					} 
						
				break;
				
				case 3:
					if (cekLog==0) printf("\n\t\tAnda harus login terlebih dahulu[!]");
					else if (cekInput==0) printf("\n\t\tAnda harus menginput stok terlebih dahulu[!]");
					else {
						printf("\n========== STOK BARANG ==========");
						
						printf("\n\nNama Barang	: Lukisan Van Gogh");
						printf("\nStok Barang	: %d", stoka);
					
						printf("\n\nNama Barang	: Patung I Nyoman Nuarta");
						printf("\nStok Barang	: %d", stokb);

						printf("\n\nNama Barang	: Lukisan Basuki Abdullah");
						printf("\nStok Barang	: %d", stokc);	
						
					}
					
				break;
				
				case 4:
					if (cekLog==0) printf("\n\t\tAnda harus login terlebih dahulu[!]");
					else if (cekInput==0) printf("\n\t\tAnda harus menginput stok terlebih dahulu[!]");
					else {
						
						printf("\n[========== PELELANGAN ==========]"); 
						printf("\n[11] Lukisan Van Gogh			: %d", hargaa); 
						printf("\n[12] Patung I Nyoman Nuarta		: %d", hargab); 
						printf("\n[13] Lukisan Basuki Abdullah	 	: %d", hargac); 
						printf("\nPilih barang yang ingin Anda bid (11-13) : "); scanf("%d", &pilLelang);
						
						// for (bid=0, bid<=5; bid++;) 
						switch(pilLelang) {
							
							for (bid=0, bid<=5; bid++;)
							
							case 11 :
								printf("\nJumlah uang yang Anda pasang 	: "); scanf("%d", hargaa);
							break;
							
							case 12:
								printf("\nJumlah uang yang Anda pasang 	: "); scanf("%d", hargab);
							break;
							
							case 13:
								printf("\nJumlah uang yang Anda pasang 	: "); scanf("%d", hargac);
							break;

							default:
								printf("\nInput tidak ada[!]");			
						
							
						} 
					}
				break;
				
				case 0:
					printf("\n\t\tAlexis Divasonda Sigat Ngaing | D | 210711407");
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
