#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[100];

void naive();
void semiNaive(int input);
void nettEffect(int *input);

void passedByValue(int bilA, int bilB);
void passedByReference(int *bilA, int *bilB);

int main(int argc, char *argv[]) {
	int bilanganA = 10;
	int bilanganB = 5;
	
	naive();
	semiNaive(20);
	
	printf("\n\nProsedur nett effect, tidak ada input dan output dari standard device:\n");
	nettEffect(&bilanganA);
	printf("Output: %d", bilanganA);
	
	printf("\n\nPassing by value dan reference:");
	bilanganA =10; bilanganB = 5;
	printf("\nKeadaan awal:");
	printf("\nBilangan A: %d, bilangan B: %d\n", bilanganA, bilanganB);
	
	printf("\n>> Passing by value:");
	passedByValue(bilanganA, bilanganB);
	printf("\nBilangan A: %d, bilangan B: %d\n", bilanganA, bilanganB);
	
	printf("\n>> Passing by reference:");
	passedByReference(&bilanganA, &bilanganB);
	printf("\nBilangan A: %d, bilangan B: %d", bilanganA, bilanganB);
	
	return 0;
}

void naive() {
	printf("Prosedur naive: input dan output melalui standard device (printf dan scanf):\n");
	int bil;
	printf("Masukkan angka: "); scanf("%d", &bil);
	printf("Angka input: %d", bil);
}

void semiNaive(int input) {
	printf("\n\nProsedur semi-naive: input melalui parameter, output melalui standard device (printf dan scanf):\n");
	printf("Angka masuk: %d", input);
}

void nettEffect(int *input) {
	*input = (*input) * (*input);
}

void passedByValue(int bilA, int bilB) {
	// bilA dan bilB BUKAN POINTER MAUPUN ARRAY, sehingga PASSING BY VALUE.
	// Program akan membuat salinan dari input bilA dan bilB, dan salinan itu yang akan dimanipulasi di dalam prosedur ini,
	// bukan value asli yang dimasukkan dari main program.
	int bilC;
	bilC = bilA + bilB;
	bilA = bilC;
}

void passedByReference(int *bilA, int *bilB) {
	// bilA adalah POINTER, sehingga PASSING BY REFERENCE.
	// Pointer akan dipelajari lebih lanjut di MK Struktur Data, sem. 3
	int bilC;
	bilC = *bilA + *bilB;
	*bilA = bilC;
	*bilB = 100;
}


