#include <stdio.h>
#include <stdlib.h>

void tukarNilai(int *N1, int *N2);
void kuadrat(int *nilai);

int main(int argc, char *argv[]) {
	int nilai1, nilai2;
	
	printf("\t\t GUIDED 1 \n");
	printf("\n Masukkan Nilai 1 : "); scanf("%d", &nilai1);
	printf("\n Masukkan Nilai 2 : "); scanf("%d", &nilai2);
	printf("\n Input Berhasil [!]");
	getch();
	system("cls");
	
	printf("\t\t GUIDED 1 \n");
	printf("\n Nilai awal");
	printf("\n Nilai 1 = %d", nilai1);
	printf("\n Nilai 2 = %d", nilai2);
	
	kuadrat(&nilai1);
	kuadrat(&nilai2);
	
	printf("\n\n Setelah dikuadratkan");
	printf("\n Nilai 1 = %d", nilai1);
	printf("\n Nilai 2 = %d", nilai2);
	
	tukarNilai(&nilai1, &nilai2);
	
	printf("\n\n Setelah Nilai1 & Nilai2 ditukar");
	printf("\n Nilai1 = %d", nilai1);
	printf("\n Nilai2 = %d", nilai2);
	
	return 0;
}

void tukarNilai(int *N1, int *N2) {
	int temp;
	
	temp=*N1;
	*N1=*N2;
	*N2=temp;
}

void kuadrat(int *nilai) {
	
	*nilai=(*nilai) * (*nilai);
}
