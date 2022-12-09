#include <stdio.h>
#include <stdlib.h>

// Nama		: Alexis Divasonda Sigat Ngaing
// NPM		: 210711407
// Kelas	: D

int main() {
	char tipe, jenis, nama;
	float kecepatan_a, kecepatan_b, kecepatan_c, mean = 0;
	int penumpang = 100, model, harga_a, harga_b, harga_c, jumlah, jmlh_a, jmlh_b, jmlh_c;
	
	printf("===[WELCOME TO PT AKI]===");
	printf("Input your data");
	
	printf("\n\nKereta api 1 : ");
	printf("\nNama				: "); scanf("%s", &nama);
	printf("Model				: 11000");
	printf("\nTipe				: A");
	printf("\nJenis				: "); scanf("%s", &jenis);
	printf("Harga				: "); scanf("%d", &harga_a);
	printf("Kecepatan Maksimum		: "); scanf("%d", &kecepatan_a);
	
	jmlh_a = harga_a * penumpang * 0.05 * 0.06;
			printf("\n[Harga Kereta : Rp %d ,-]",jmlh_a);
	
	printf("\n\nKereta api 2 : ");
	printf("\nNama				: "); scanf("%s", &nama);
	printf("Model				: 12000");
	printf("\nTipe				: B");
	printf("\nJenis				: "); scanf("%s", &jenis);
	printf("Harga				: "); scanf("%d", &harga_b);
	printf("Kecepatan Maksimum		: "); scanf("%d", &kecepatan_b);
	
	jmlh_b = harga_b * penumpang * 0.05 * 0.06;
			printf("\n[Harga Kereta : Rp %d ,-]", jmlh_b);
	
	printf("\n\nKereta api 3 : ");
	printf("\nNama				: "); scanf("%s", &nama);
	printf("Model				: 13000");
	printf("\nTipe				: C");
	printf("\nJenis				: "); scanf("%s", &jenis);
	printf("Harga				: "); scanf("%d", &harga_c);
	printf("Kecepatan Maksimum		: "); scanf("%d", &kecepatan_c);
	
	jmlh_c = harga_c * penumpang * 0.05 * 0.06;	
			printf("\n[Harga Kereta : Rp %d ,-]", jmlh_c);
	
	mean += kecepatan_a;
	mean += kecepatan_b;
	mean += kecepatan_c;
	mean /= 3;
	
	//nyerah :(
	
	return 0;
}
