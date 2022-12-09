#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef char string[100];

#define ARRAY_SIZE 5

void tampilArray(int array[]);
void deleteElementAt(int array[], int index);
int cari(int array[], int bilanganDicari);

void gantiArray(int array[]);

int main(int argc, char *argv[]) {
	int daftarNilai[ARRAY_SIZE] = {4, 13, 5, 6, 9};
	printf("Operasi pada array 1 dimensi:");
	printf("\nMenampilkan semua elemen array:\n");
	tampilArray(daftarNilai);
	
	printf("\nMenghapus (set 0) elemen pada indeks 1:\n");
	deleteElementAt(daftarNilai, 1);
	tampilArray(daftarNilai);
	
	printf("\nMencari elemen dengan value=6, kemudian mengubah value menjadi '-100':\n");
	int indexElemen = cari(daftarNilai, 6);
	daftarNilai[indexElemen] = -100;
	tampilArray(daftarNilai);
	
	int array2d[3][5] = {
		{1, 2, 3, 4, 5}, // array2D[0]
		{6, 7, 8, 9, 10}, // array2D[1]
		{11, 12, 13, 14, 15} // array2D[2]
	};
	
	// Cara mengakses array 2 dimensi:
	int indexI = 2;
	int indexJ = 3;
	printf("\nMengakses elemen dari array 2 dimensi:\n");
	printf("Value dari 'array2d[%d][%d]' = %d\n\n", indexI, indexJ, array2d[indexI][indexJ]);
	
	return 0;
}

void tampilArray(int array[]) {
	int i;
	for(i=0; i<ARRAY_SIZE; i++) {
		printf("Index ke-%d: %d\n", i, array[i]);
	}
}

void deleteElementAt(int array[], int index) {
	array[index] = 0;
}

int cari(int array[], int bilanganDicari) {
	int i;
	for(i=0; i<ARRAY_SIZE; i++) {
		if(array[i] == bilanganDicari) {
			return i;
		}
	}
	return -1;
}


