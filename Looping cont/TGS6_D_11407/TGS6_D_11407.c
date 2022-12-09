#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>

// Alexis Divasonda Sigat Ngaing / 210711407 / Kelas D

int main(int argc, char *argv[]) {
	int pil, paket, i, n, harga, diskon;
	bool menu = true;
	
	int cekInput=0, cekPaket=0, cekBukti=0;
	
	while(menu==true) {
		
		system("cls");
		printf("\n===== Alat Tulis Pak Slametz =====");
		printf("\n[1] Masukkan Pesanan");
		printf("\n[2] Print Bukti Pembayaran");
		printf("\n[3] Menu Kupon");
		printf("\n[4] Tugas");
		printf("\n[0] Exit");
		printf("\n------------------------------");
		printf("\nPilih menu ==> "); scanf("%d", &pil);
	
		switch(pil) { 
				case 1:
					printf("Masukkan Banyak Pesanan Alat Tulis (Paket) : "); scanf("%d", &paket);
						
					while (paket<=0) {
						printf("\nMaaf Anda tidak boleh memesan kurang dari 1 paket !");
						printf("\nMasukkan Banyak Pesanan Alat Tulis (Paket) : "); scanf("%d", &paket);
					} 
					printf("\n\tBerhasil memasukkan pesanan !");
					
					cekInput=1;
				break;
				
				case 2:
					if (cekInput==0) printf("\n\tAnda harus memasukkan pesanan terlebih dahulu !");
					else {
						printf("\nBukti pembelian %d paket alat tulis\n\n", paket);
						for(i=1; i<=5; i++) {
							for(n=1; n<=paket; n++) {
								printf("|* ");	
							}
							printf("\n");
						}

						harga = paket * 12000;
						printf("\nTotal Harga : Rp %d", harga);
						
						cekBukti=1;
					} 	
					diskon = harga * 0.1;					
				break;
				
				case 3:
					if (cekInput==0) printf("\n\tAnda harus memasukkan pesanan terlebih dahulu !");
					else if (cekBukti==0) printf("\n\tCetak bukti pembelian terlebih dahulu (Menu 2) !");
					else if (paket>=6) {
						printf("\nSelamat Anda mendapatkan kupon diskon !\n\n");						
        					for (i=0; i<paket; i++) {
           						for(n=0; n<paket; n++) {
                					if ((i==0) || (i==paket-1) || (n==0) || (n==paket-1)) {
                  						printf("*");
                					}
                   					else if (paket%2 != 0) {
                   						printf(" ");
									}
                					else {
                    					printf ("*");
                					}
            					}
           					 printf ("\n");
        					}						
						harga = (paket * 12000) - diskon;
						printf("\nTotal harga pembelian %d paket alat tulis menjadi: Rp %d", paket, harga);
					} 
					else {
						printf("\n\tMaaf Anda tidak mendapatkan kupon diskon");
					}					
				break;
				
				case 4:
					if (cekInput==0) printf("\n\tAnda harus memasukkan pesanan terlebih dahulu !");
					else if (cekBukti==0) printf("\n\tCetak bukti pembelian terlebih dahulu (Menu 2) !");
					else if (paket>=2 && paket%2!=0) {
						printf("\n");
						for(i=1; i<=paket; i++) {
							for(n=1; n<=i; n++) {
								if(n%2==0) {
									printf("* ");	
								}
								else {
									printf("%d ", i);
								}	
							}
							printf("\n");
						}	
						printf("\nSelamat Anda mendapatkan penggaris segitiga premium edisi Alat Tulis Pak Slametz x Supreme");
					} 
					else {
						printf("\n\tSemoga Beruntung Lain Kali :)");
					}		
				break;
				
				case 0:
					printf("\n\tBerhasil Keluar - Alexis Divasonda Sigat Ngaing / D / 210711407");
					menu = false;
				break;
				
				default:
					printf("\n\tMenu tidak ada !");
				break;
				
			} getch();
	}
	return 0;
}
