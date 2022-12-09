#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char string_in[50], string_out[51];

void balikString() {
	int length = strlen(string_in), i=0;
	for(i=0; i<length; i++) {
		if(string_in[i]!='\0') {
			string_out[length-i] = string_in[i];
		}
		else break;
	}
}

void main() {
	int i=0;
	// inisialisasi string out (yang sudah di-reverse)
	for(i=0; i<51; i++) {
		string_out[i] = ' ';
	}
	printf("--- Pembalikan Karakter dalam String ---");
	printf("\nString asal: "); fflush(stdin); gets(string_in);
	balikString();
	printf("\nString kebalikan:%s", string_out);
}
