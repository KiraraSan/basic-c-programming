#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[100];

void inputData(int *sisi, string nama);
int getLuasPersegi(sisi);
void prosedurReturnArray(int array[]);
char fungsiChar();
float fungsiFloat();

int main(int argc, char *argv[]) {
	int panjangSisi;
	string namaBangun;
	
	printf("Fungsi yang mereturn float: %.2f\n", fungsiFloat());
	printf("Fungsi yang mereturn char: %c\n", fungsiChar());
	
	// Fungsi tidak dapat mengembalikan array, sehingga harus kita ganti bentuk menjadi prosedur:
	int arrayInteger[3];
	prosedurReturnArray(arrayInteger);
	
	printf("\nGunakan PROSEDUR untuk hal seperti input data, tampil data, karena tidak tidak ada return value.");
	printf("\nGunakan FUNGSI untuk hal seperti perhitungan yang sudah pasti memiliki return value.\n");
	// Prosedur input data
	inputData(&panjangSisi, namaBangun);
	// Fungsi get luas persegi
	int luasPersegi = getLuasPersegi(panjangSisi);
	
	printf("Nama Bangun Datar: %s\n", namaBangun);
	printf("Panjang sisi: %dcm\n", panjangSisi);
	printf("Luas persegi: %dcm^2\n", luasPersegi);
	
	return 0;
}

void inputData(int *sisi, string nama) {
	*sisi = 10;
	strcpy(nama, "Persegi by Jolly");
}

int getLuasPersegi(sisi) {
	return sisi * sisi;
}

void prosedurReturnArray(int array[]) {
	array[0] = 10;
	array[1] = 20;
	array[2] = 30;
}

char fungsiChar() {
	return 'C';
}

float fungsiFloat() {
	float varA = 10.2;
	int varB = 2;
	return (float) varB * varA;
}

