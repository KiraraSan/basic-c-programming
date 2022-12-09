#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define hargaA 5000
#define hargaB 7500
#define hargaC 10000
#define hargaX 25000
#define hargaY 30000

//untuk SOAL BONUS 
#define pabrikA 3000
#define pabrikB 5000
#define pabrikC 7000
#define pabrikX 19000
#define pabrikY 23000

typedef char string[50];

void inisialisasi(int *cekIn, int *toleransi, int *pembeli, int *pembelian, int *pembelianKhusus, int *tempJenis, int *jmlA, int *jmlB, int *jmlC, int *jmlX, int *jmlY, 
                    int *totA, int *totB, int *totC, int *totX, int *totY, int *tempA, int *tempB, int *tempC, int *tempX, int *tempY, int *total);
void pengurangan(int *m, int pengurang);
void penjumlahan(int *m, int penjumlah);
void perkalian(int *hasil, int harga, int pengali);
void cekLogin(int *cekIn, string nama, int pass);
void cekJenis(int *tempJenis, string jenis, int A, int B, int C, int X, int Y);
void pembaruanKetersediaan(int *jmlA, int *jmlB, int *jmlC, int *jmlX, int *jmlY, int *totA, int *totB, int *totC, int *totX, int *totY, string jenis, int jumlah);
void tampilDataPembeli(string nama, string tanggal, string jam);
void tampilDataPembeliKhusus(string nik, string pekerjaan, string alamat);
void rincianPembelian(int jmlA, int jmlB, int jmlC, int jmlX, int jmlY, int hA, int hB, int hC, int hX, int hY, int totA, int totB, int totC, int totX, int totY);
void hitungTotal(int *total, int totA, int totB, int totC, int totX, int totY);

// Untuk Bonus
void inisialisasiSoalBonus(int *kA, int *kB, int *kC, int *kX, int *kY);
void hitungKeuntungan(int *keuntungan, int jml, int hargaJual, int hargaPabrik);


int main(){
    string username, nama, telp, tgl, jam, jenis, nik, pekerjaan, alamat, konfirm;
    int pass, pil, jumlah, cekIn, toleransi, pembeli, pembelian, tempJenis, pembelianKhusus;
    int jmlA, jmlB, jmlC, jmlX, jmlY, totA, totB, totC, totX, totY;
    int tempA, tempB, tempC, tempX, tempY, total;
    int keuntunganA, keuntunganB, keuntunganC, keuntunganX, keuntunganY, totalUntung;

    inisialisasi(&cekIn, &toleransi, &pembeli, &pembelian, &tempJenis, &pembelianKhusus, &jmlA, &jmlB, &jmlC, &jmlX, &jmlY, 
                    &totA, &totB, &totC, &totX, &totY, &tempA, &tempB, &tempC, &tempX, &tempY, &total);
	inisialisasiSoalBonus(&keuntunganA, &keuntunganB, &keuntunganC, &keuntunganX, &keuntunganY);
	
    do{
        system("cls");
        printf("\n\n\n\n");
        printf("\n\t\t\t\t     --------------------------------------");
        printf("\n\t\t\t\t     |         -UGD PROSEDUR 2-           |");
        printf("\n\t\t\t\t     |              TIPE B                |");
        printf("\n\t\t\t\t     |          TOKO TALI ATMA            |");
        printf("\n\t\t\t\t     --------------------------------------\n");
        printf("\n\t\t\t\t\t\t=== LOGIN ===");
        printf("\n\t\t\t\t\t\tToleransi : %d\n", toleransi);
        printf("\n\t\t\t\t\tUsername (Atma): "); fflush(stdin); gets(username);
        printf("\t\t\t\t\tPassword (10659) : "); scanf("%d", &pass);
        cekLogin(&cekIn, username, pass);

        if(cekIn==1){
            do{
                system("cls");
                printf("\n\t\t==== MENU ====");
                printf("\n\t  Ketersediaan Tali : \n\t  %d Tali A - %d Tali B - %d Tali C - %d Tali X - %d Tali Y", jmlA, jmlB, jmlC, jmlX, jmlY);
                printf("\n\t[1] Input Pembeli");
                printf("\n\t[2] Input Pembelian");
                printf("\n\t[3] Rincian");
                printf("\n\t[4] Reset Data");
                printf("\n\t[0] Logout");
                
                printf("\n\n\t[5] Hitung Keuntungan [TUGAS]\n");
                printf("\n\t>>> "); scanf("%d", &pil);

                switch (pil){
                    case 1:
                        if(pembeli==1){
                            printf("\n\t\t[!] Data Pembeli sudah terinput!");
                        }else{
                            printf("\n\t\t===== INPUT PEMBELI =====\n");
                            printf("\t Nama               : "); fflush(stdin); gets(nama);
                            while(strlen(nama)==0 || strcmpi(nama,"-")==0){
                                printf("\n\t\t[!] Nama tidak boleh kosong!\n");
                                printf("\n\t Nama               : "); fflush(stdin); gets(nama);
                            }
                            printf("\t No. Telp           : "); fflush(stdin); gets(telp);
                            while(strlen(telp)==0 || strcmpi(telp,"-")==0){
                                printf("\n\t\t[!] No. Telp tidak boleh kosong!\n");
                                printf("\n\t No. Telp           : "); fflush(stdin); gets(telp);
                            }
                            printf("\t Tanggal Kedatangan : "); fflush(stdin); gets(tgl);
                            while(strlen(tgl)!=10){
                                printf("\n\t\t[!] Tanggal salah!\n");
                                printf("\n\t Tanggal Kedatangan : "); fflush(stdin); gets(tgl);
                            }
                            printf("\t Jam Kedatangan     : "); fflush(stdin); gets(jam);
                            while(strlen(jam)!=8){
                                printf("\n\t\t[!] Jam salah!\n");
                                printf("\n\t Jam Kedatangan     : "); fflush(stdin); gets(jam);
                            }
                            printf("\n\t\tBerhasil Input Data...");
                            pembeli=1;
                        }  
                        getch(); 
                        break;
                    
                    case 2:
                        if(pembeli==0){
                            printf("\n\t\t[!] Input Data Pembeli Dulu!");
                        }else{
                            printf("\n\t\t===== INPUT PEMBELIAN =====");
                            printf("\n\tJenis Tali yang ingin dibeli (A/B/C/X/Y) : "); fflush(stdin); gets(jenis);
                            cekJenis(&tempJenis, jenis, jmlA, jmlB, jmlC, jmlX, jmlY);

                            if(tempJenis==-1){
                                printf("\n\t\t[!] Jenis Tali tidak diketahui!");
                            }else{
                                printf("\n\tJumlah Tali yang ingin dibeli (m): "); scanf("%d", &jumlah);
                                if(tempJenis==0){
                                    printf("\n\t\t[!] Tali jenis ini sudah habis!");	
                                }else if(jumlah>tempJenis){
                                    printf("\n\t\t[!] Jumlah melebihi ketersediaan!");
                                }else{
                                    pembaruanKetersediaan(&jmlA, &jmlB, &jmlC, &jmlX, &jmlY, &totA, &totB, &totC, &totX, &totY, jenis, jumlah);
                                    if((strcmpi(jenis,"X")==0 || strcmpi(jenis,"Y")==0) && pembelianKhusus==0){
                                        printf("\n\n\tNIK                : "); fflush(stdin); gets(nik);
                                        while(strlen(nik)!=16){
                                            printf("\n\t\t[!] NIK salah!\n");
                                            printf("\n\tNIK                : "); fflush(stdin); gets(nik);
                                        }
                                        printf("\tPekerjaan          : "); fflush(stdin); gets(pekerjaan);
                                        while(strlen(pekerjaan)==0){
                                            printf("\n\t\t[!] Pekerjaan harus diisi!\n");
                                            printf("\n\tPekerjaan          : "); fflush(stdin); gets(pekerjaan);
                                        }
                                        printf("\tAlamat             : "); fflush(stdin); gets(alamat);
                                        while(strlen(alamat)==0){
                                            printf("\n\t\t[!] Alamat harus diisi!\n");
                                            printf("\n\tAlamat             : "); fflush(stdin); gets(alamat);
                                        }
                                        pembelianKhusus=1;
                                    }
                                    printf("\n\t\tBerhasil Input Pembelian...");
                                    pembelian=1;
                                }
                            }
                        }
                        getch();
                        break;
                    
                    case 3:
                        if(pembeli!=1 && pembelian!=1){
                            printf("\n\t\t[!] Input Data Pembeli dan Data Pembelian dulu!");
                        }else if(pembeli!=1){
                            printf("\n\t\t[!] Input Data Pembeli dulu!");
                        }else if(pembelian!=1){
                            printf("\n\t\t[!] Input Data Pembelian dulu!");
                        }else{
                            printf("\n\t\t\t=== PEMBAYARAN ===");
                            tampilDataPembeli(nama, tgl, jam);
                            if(pembelianKhusus==1){
                                tampilDataPembeliKhusus(nik, pekerjaan, alamat);
                            }
                            perkalian(&tempA, hargaA, totA);
                            perkalian(&tempB, hargaB, totB);
                            perkalian(&tempC, hargaC, totC);
                            perkalian(&tempX, hargaX, totX);
                            perkalian(&tempY, hargaY, totY);

                            rincianPembelian(totA, totB, totC, totX, totY, hargaA, hargaB, hargaC, hargaX, hargaY, tempA, tempB, tempC, tempX, tempY);
                            hitungTotal(&total,tempA, tempB, tempC, tempX, tempY);
                            printf("\n\n\tTotal : Rp %d", total);
                        }
                        getch();
                        break;
                    
                    case 4:
                        printf("\n\t\t=== RESET DATA ===");
                        printf("\n\tApakah Anda yakin ingin mereset data? [ya/tidak]\n");
                        printf("\t"); fflush(stdin); gets(konfirm);
                        if(strcmpi(konfirm,"ya")==0){
                            inisialisasi(&cekIn, &toleransi, &pembeli, &pembelian, &tempJenis, &pembelianKhusus, &jmlA, &jmlB, &jmlC, &jmlX, &jmlY, 
						                    &totA, &totB, &totC, &totX, &totY, &tempA, &tempB, &tempC, &tempX, &tempY, &total);
							inisialisasiSoalBonus(&keuntunganA, &keuntunganB, &keuntunganC, &keuntunganX, &keuntunganY);
							cekIn=1;
                            printf("\n\t\tBerhasil Reset Data...");
                        }
                        getch();
                        break;
                    
                    case 5:
						if(pembeli!=1 && pembelian!=1){
							printf("\n\t\t[!] Input Data Pembeli dan Data Pembelian dulu!");
						}else if(pembeli!=1){
							printf("\n\t\t[!] Input Data Pembeli dulu!");
						}else if(pembelian!=1){
							printf("\n\t\t[!] Input Data Pembelian dulu!");
						}else{
							hitungKeuntungan(&keuntunganA, totA, hargaA, pabrikA);
							printf("\n\tKeuntungan Tali A  = Rp %d", keuntunganA);
							hitungKeuntungan(&keuntunganB, totB, hargaB, pabrikB);
							printf("\n\tKeuntungan Tali B  = Rp %d", keuntunganB);
							hitungKeuntungan(&keuntunganC, totC, hargaC, pabrikC);
							printf("\n\tKeuntungan Tali C  = Rp %d", keuntunganC);
							hitungKeuntungan(&keuntunganX, totX, hargaX, pabrikX);
							printf("\n\tKeuntungan Tali X  = Rp %d", keuntunganX);
                            hitungKeuntungan(&keuntunganY, totY, hargaY, pabrikY);
							printf("\n\tKeuntungan Tali Y  = Rp %d", keuntunganY);
							
							hitungTotal(&totalUntung, keuntunganA, keuntunganB, keuntunganC, keuntunganX, keuntunganY);
							printf("\n\n\tTotal Keuntungan : Rp %d", totalUntung);
						}
						getch();
						break;

                    case 0:
                        printf("\n\t\tTerima Kasih...");
                        toleransi=3;
                        break;

                    default:
                        printf("\n\t\t[!] Menu tak diketahui!");
                        getch();
                        break;
                }
            }while(pil!=0);
            getch();
        }else if(cekIn==-1){
            printf("\n\t\t\t\t\t[!] Username / Password Salah!");
			toleransi--;
            getch();
        }
		
    }while(toleransi!=0 && cekIn!=0);

        printf("\n\n\t\t\t\t\tBerhasil Keluar...");
		printf("\n\t\t\t\t\tNama - NPM - Kelas");
		getch();
    return 0;
}

void inisialisasi(int *cekIn, int *toleransi, int *pembeli, int *pembelian, int *pembelianKhusus, int *tempJenis, int *jmlA, int *jmlB, int *jmlC, int *jmlX, int *jmlY, 
                    int *totA, int *totB, int *totC, int *totX, int *totY, int *tempA, int *tempB, int *tempC, int *tempX, int *tempY, int *total){
    *cekIn=0;
    *toleransi=3;
    *pembeli=0;
    *pembelian=0;
    *tempJenis=0;
    *pembelianKhusus=0;
    *jmlA=50;
    *jmlB=50;
    *jmlC=50;
    *jmlX=100;
    *jmlY=100;
    *totA=0;
    *totB=0;
    *totC=0;
    *totX=0;
    *totY=0;
    *tempA=0;
    *tempB=0;
    *tempC=0;
    *tempX=0;
    *tempY=0;
    *total=0;
}

void pengurangan(int *m, int pengurang){
	
	if(*m >= pengurang){
		*m = *m - pengurang;
	}
	
}

void penjumlahan(int *m, int penjumlah){
	
	*m = *m + penjumlah;
}

void perkalian(int *hasil, int harga, int pengali){
	
	*hasil = harga * pengali;
}

void cekLogin(int *cekIn, string nama, int pass){
    if(strcmp(nama,"Atma")==0 && pass==10659){
        *cekIn=1;
    }else if(strcmp(nama,"0")==0 && pass==0){
        *cekIn=0;
    }else{
        *cekIn=-1;
    }
}

void cekJenis(int *tempJenis, string jenis, int A, int B, int C, int X, int Y){
    if(strcmpi(jenis,"A")==0){
		*tempJenis=A;
	}else if(strcmpi(jenis,"B")==0){
		*tempJenis=B;
	}else if(strcmpi(jenis,"C")==0){
		*tempJenis=C;
	}else if(strcmpi(jenis,"X")==0){
		*tempJenis=X;
	}else if(strcmpi(jenis,"Y")==0){
		*tempJenis=Y;
	}else{
		*tempJenis=-1;
	}
}

void pembaruanKetersediaan(int *jmlA, int *jmlB, int *jmlC, int *jmlX, int *jmlY, int *totA, int *totB, int *totC, int *totX, int *totY, string jenis, int jumlah){
    if(strcmpi(jenis,"A")==0){
		pengurangan(&(*jmlA), jumlah);
        penjumlahan(&(*totA), jumlah);
	}else if(strcmpi(jenis,"B")==0){
		pengurangan(&(*jmlB), jumlah);
        penjumlahan(&(*totB), jumlah);
	}else if(strcmpi(jenis,"C")==0){
		pengurangan(&(*jmlC), jumlah);
        penjumlahan(&(*totC), jumlah);
	}else if(strcmpi(jenis,"X")==0){
		pengurangan(&(*jmlX), jumlah);
        penjumlahan(&(*totX), jumlah);
	}else if(strcmpi(jenis,"Y")==0){
		pengurangan(&(*jmlY), jumlah);
        penjumlahan(&(*totY), jumlah);
	}
}

void tampilDataPembeli(string nama, string tanggal, string jam){
	
	printf("\n\tNama             : %s", nama);
	printf("\n\tWaktu Kedatangan : %s %s", tanggal, jam);
}

void tampilDataPembeliKhusus(string nik, string pekerjaan, string alamat){
	
	printf("\n\tNIK              : %s", nik);
	printf("\n\tPekerjaan        : %s", pekerjaan);
	printf("\n\tAlamat           : %s", alamat);
}

void rincianPembelian(int jmlA, int jmlB, int jmlC, int jmlX, int jmlY, int hA, int hB, int hC, int hX, int hY, int totA, int totB, int totC, int totX, int totY){
	
	printf("\n\n\t\t\t===== RINCIAN =====");
	printf("\n\tTali A      | %d |\t| @Rp %d  |\t---> Total : Rp %d", jmlA, hA, totA);
	printf("\n\tTali B      | %d |\t| @Rp %d  |\t---> Total : Rp %d", jmlB, hB, totB);
	printf("\n\tTali C      | %d |\t| @Rp %d |\t---> Total : Rp %d", jmlC, hC, totC);
	printf("\n\tTali X      | %d |\t| @Rp %d |\t---> Total : Rp %d", jmlX, hX, totX);
	printf("\n\tTali Y      | %d |\t| @Rp %d |\t---> Total : Rp %d", jmlY, hY, totY);
}

void hitungTotal(int *total, int totA, int totB, int totC, int totX, int totY){
	
	*total=totA+totB+totC+totX+totY;
}


//Untuk bonus
void inisialisasiSoalBonus(int *kA, int *kB, int *kC, int *kX, int *kY){
	
	*kA=0;
	*kB=0;
	*kC=0;
	*kX=0;
    *kY=0;
}

void hitungKeuntungan(int *keuntungan, int jml, int hargaJual, int hargaPabrik){
	int penjualan, pabrik;
	
	perkalian(&penjualan,hargaJual,jml);
	perkalian(&pabrik,hargaPabrik,jml);
	pengurangan(&penjualan,pabrik);
	
	*keuntungan = penjualan;
}


