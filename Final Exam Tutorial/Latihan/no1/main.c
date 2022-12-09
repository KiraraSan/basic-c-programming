#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hitung(int hari, int bulan, int tahun, int *hasil);

int main(int argc, char *argv[]) {
	int hari, bln, thn, hasil;
	
	printf("Masukkan tanggal (dd) : "); scanf("%d, %d, %d", &hari, &bln, &thn);
	
	hitung(hari, bln, thn, &hasil);
	printf("\nTanggal berjarak %d hari dari tanggal 2-2-2000", hasil);
	
	return 0;
}

void hitung(int hari, int bulan, int tahun, int *hasil) {
	*hasil = abs((2000-tahun)*365 + (2-bulan)*30 + (2-hari));
}
