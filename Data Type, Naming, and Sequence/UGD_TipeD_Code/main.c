#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>

typedef char string[20];
int main() {
	string nama, nama2, nama3, gender, gender2, gender3;
	int tahun, tahun2, tahun3, biaya, biaya2, biaya3;
	unsigned long long int noReg = 5000000000;
	char ruang = 'A';
	
	int jumlah = 0;
	int totalBiaya, mean;
	
	int day, month, year, today = 738128, umur;
	bool boolean;
	
	printf("\n===[ WELCOME TO MARIO BROS HOSPITAL ]===");
	printf("\n\tPlease input your data");
	printf("\nCostumer 1 : ");
	printf("\n\tNama             : "); fflush(stdin); gets(nama);
	printf("\tNomor Registrasi : %llu", noReg++);
	ruang = ruang+1;
	printf("\n\tRuang            : %c", ruang);
	printf("\n\tJenis Kelamin    : "); fflush(stdin); gets(gender);
	printf("\tTahun Registrasi : "); scanf("%d", &tahun);
	printf("\tBiaya            : "); scanf("%d", &biaya);
	jumlah++;
	biaya -= biaya * 0.6;
	printf("\n\t\t[ Biaya pengobatan : Rp %d,- ]", biaya);
	
	printf("\nCostumer 2 : ");
	printf("\n\tNama             : "); fflush(stdin); gets(nama2);
	printf("\tNomor Registrasi : %llu", noReg++);
	printf("\n\tRuang            : %c", ruang++);
	printf("\n\tJenis Kelamin    : "); fflush(stdin); gets(gender2);
	printf("\tTahun Registrasi : "); scanf("%d", &tahun2);
	printf("\tBiaya            : "); scanf("%d", &biaya2);
	jumlah++;
	biaya2 -= biaya2 * 0.6;
	printf("\n\t\t[ Biaya pengobatan : Rp %d,- ]", biaya2);	

	printf("\nCostumer 3 : ");
	printf("\n\tNama             : "); fflush(stdin); gets(nama3);
	printf("\tNomor Registrasi : %llu", noReg++);
	printf("\n\tRuang            : %c", ruang++);
	printf("\n\tJenis Kelamin    : "); fflush(stdin); gets(gender3);
	printf("\tTahun Registrasi : "); scanf("%d", &tahun3);
	printf("\tBiaya            : "); scanf("%d", &biaya3);
	jumlah++;
	biaya3 -= biaya3 * 0.6;
	printf("\n\t\t[ Biaya pengobatan : Rp %d,- ]", biaya3);	

	
	totalBiaya = biaya + biaya2 + biaya3;
	mean = totalBiaya/jumlah;
	printf("\n\n\t===[ Tampil Data ]===");
	printf("\n\tJumlah Pasien   : %d", jumlah);
	printf("\n\tRata-rata Biaya : Rp %d", mean);
	printf("\n\tTotal Biaya     : Rp %d", totalBiaya);
	
	printf("\n\n\t===[ Hitung Umur ]===");
	printf("\n\tTahun Lahir : "); scanf("%d:%d:%d", &year, &month, &day);
	day += year*365 + month*31;
	umur = today - day;
	umur = umur/365;

	printf("\tUmur :  %d tahun", umur);
	boolean = umur > 18;
	printf("\n\tApakah lebih dari 18 tahun ? : %d", boolean);
	
	int x, y, z;
	int bantuan;
	
	x = abs(tahun2 - tahun);
	x = x/2;
	y = tahun + tahun2;
	y = y/2;
	z = x - y;
	
	x = abs(tahun3 - z);
	x = x/2;
	y = tahun3 + z;
	y = y/2;
	z = x - y;
	
	bantuan = totalBiaya * 0.1;
	
	printf("\n\n\t===[ Bantuan RS Mario Bros ]===");
	printf("\n\tTahun Registrasi :  %d", z);
	printf("\n\tBantuan          : Rp %d", bantuan);
	
	getch();
	return 0;
}
