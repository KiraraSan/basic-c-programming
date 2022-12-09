#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Soal no. 3 (bg. 1)
typedef struct {
	int X;
	int Y;
} Point;

typedef struct {
	Point Awal;
	Point Akhir;
} Line;

// Soal no. 3 (bg. 2/a)
void initPoint(Point *P) {
	(*P).X = 0;
	(*P).Y = 0;
}

// Soal no. 3 (bg. 2/b)
void initLine(Line *L) {
	initPoint(&(*L).Awal);
	initPoint(&(*L).Akhir);
}

// Soal no. 4 (bg. 1/a)
void setAwal(Point *P) {
	printf("\tTitik awal (X): "); scanf("%d", &(*P).X);
	printf("\tTitik awal (Y): "); scanf("%d", &(*P).Y);
}

// Soal no. 4 (bg. 1/b)
void setAkhir(Point *P) {
	printf("\tTitik akhir (X): "); scanf("%d", &(*P).X);
	printf("\tTitik akhir (Y): "); scanf("%d", &(*P).Y);
}

float Panjang(Line L) {
	float awalX = L.Awal.X;
	float awalY = L.Awal.Y;
	float akhirX = L.Akhir.X;
	float akhirY = L.Akhir.Y;
	float hasil, bg1, bg2;
	
	bg1 = pow((akhirX - awalX),2);
	bg2 = pow((akhirY - awalY),2);
	
	hasil = sqrt(bg1 + bg2);
	return hasil;
}

void main() {
	float panjang=0;
	Line garis;
	initLine(&garis);
	
	printf("--- Nomor 3 dan 4 ---");
	printf("\nInput: \n");
	setAwal(&garis.Awal);
	printf("\n");
	setAkhir(&garis.Akhir);
	printf("\nOutput: ");
	panjang = Panjang(garis);
	printf("\n\tPanjang: %.2f", panjang);
}
