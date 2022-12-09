#include <stdio.h>
#include <stdlib.h>

int nilai[100];

int sumNilai() {
	int i, opt=0;
	for(i=0; i<100; i++) {
		if(nilai[i]!=0) opt+=nilai[i];
		else break;
	}
	return opt;
}

int countNilai() {
	int i, opt=0;
	for(i=0; i<100; i++) {
		if(nilai[i]!=0) opt++;
		else break;
	}
	return opt;
}

float avgNilai() {
	float sum = sumNilai();
	float count = countNilai();
	return sum/count;
}

void tampilSelisihNilai() {
	int i, opt=0;
	float avg, selisih=0;
	avg = avgNilai();
	for(i=0; i<100; i++) {
		selisih = nilai[i] - avg;
		if(nilai[i]!=0) {
			printf("\n\t%d\t%.1f", nilai[i], selisih);
		}
		else break;
	}
}

int main(int argc, char *argv[]) {
	int tmp_nilai=0, input=0, i=0, menu, error;
	for(i=0; i<100; i++) {
		nilai[i] = 0;
	}

	do {
		system("cls");
		printf("--- Program Nomor 1 ---");
		printf("\n[1] Input nilai (hanya boleh 1 kali)");
		printf("\n[2] Jumlah nilai");
		printf("\n[3] Rata-rata nilai");
		printf("\n[4] Selisih rata-rata dengan nilai");
		printf("\n[9] Exit");
		printf("\n>> "); scanf("%d", &menu);

		switch(menu) {
			case 1:
				printf("\n\t--- Input Nilai ---");
				if(input==0) {
					printf("\n\tKetik 0 jika sudah selesai menginput nilai.\n\n");
					for(i=0; i<100; i++) {
						do {
							error=1;
							printf("\tInput nilai ke-%d: ", (i+1)); scanf("%d", &nilai[i]);
							if(nilai[i]==0) {
								input=1;
								printf("\n\t[+] Nilai berhasil diinput.");
								break;
							}

							if(nilai[i] < 0 || nilai[i] > 10) {
								printf("\t[-] Nilai tidak valid (harus 1-10)\n");
							} else error=0;
						} while(error==1);
						if(input==1) break;
					}
				} else printf("\n\t[-] Nilai sudah pernah diinput.");
				break;

			case 2:
				if(input==1) {
					printf("\n\t--- Jumlah Nilai ---");
					printf("\n\tJumlah (SUM) nilai: %d", sumNilai());
					printf("\n\tJumlah (COUNT) nilai: %d", countNilai());
					printf("\n\n\t[+] Data berhasil ditampilkan.");
				} else printf("\n\t[-] Nilai belum diinput.");
				break;

			case 3:
				if(input==1) {
					printf("\n\t--- Rata-rata Nilai ---");
					printf("\n\tRata-rata nilai: %.1f", avgNilai());
					printf("\n\n\t[+] Data berhasil ditampilkan.");
				} else printf("\n\t[-] Nilai belum diinput.");
				break;
			
			case 4:
				if(input==1) {
					printf("\n\t--- Nilai dan selisih dengan rata-rata ---");
					tampilSelisihNilai();
				} else printf("\n\t[-] Nilai belum diinput.");
				break;

			case 9:
				printf("\n\t[+] Terima kasih.");
				break;
		}
		getch();
	} while (menu!=9);
	return 0;
}
