#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Alexis Divasonda Sigat Ngaing / 210711407 / D

typedef char string[20];

void cekLogin(int *cekA, int *cekB, string user, string pass);
void cekLogout(int *logout);
void inisialisasi(int *cekA, int *cekB, int *cek);

void tampilArray(string arr[]) {
	int i;
	for(i=0; i<17; i++) {
		printf("%s | ", arr[i]);
	}
}

int cariData(string dataHewan[], string cariHewan) {
	int i;
	for(i=0; i<17; i++) {
		if(strcmpi(dataHewan[i], cariHewan)==0) {
			return i;
		}
	}
	return -1;
}

void editHewan(string dataHewan[], string dataKelas[], string cariHewan, string hewanBaru, string kelasBaru) {
	int i;
	int indexDicari = cariData(dataHewan, cariHewan);
	if(indexDicari != -1) {
		strcpy(dataHewan[indexDicari], hewanBaru);
		strcpy(dataKelas[indexDicari], kelasBaru);
	} else {
		printf("\n\t[!] Data hewan tidak ditemukan");
	}
}

int main(int argc, char *argv[]) {
	
	string dataHewan[17] = {"Beruang Kutub", "Katak", "Burung Merak", "Singa", "Macan", "Burung Unta", 
							"Salmon", "Buaya", "Serigala", "Ikan Mas", "Ular Piton", "Ikan Cupang", 
							"Burung Elang", "Kura kura", "Kelinci", "Alligator", "Paus"};

	string dataKelas[17] = {"Mamalia", "Amfibi", "Burung", "Mamalia", "Mamalia", "Burung", 
							"Ikan", "Reptil", "Mamalia", "Ikan", "Reptil", "Ikan", 
							"Burung", "Reptil", "Mamalia", "Reptil", "Mamalia"};
	
	int cekA=0, cekB=0, cek, menu;
	int logout, username, password, i;
	string cari;
	int ceka, cekb, temp=-1;
	string hewan, user, pass, hewanBaru, kelasBaru;
	
	do {	
		logout=0;
		system("cls");
		printf("\n\tUsername   : "); fflush(stdin); gets(user);
		printf("\tPassword   : "); fflush(stdin); gets(pass);
		cekLogin(&ceka, &cekb, user, pass);
		
		if(ceka==1) {
			printf("Berhasil login [PENGELOLA]");
			do {
				system("cls");
				printf("\n\n\t====== KEBUN BINATANG  ======");
				printf("\n\t[1] Input");
				printf("\n\t[2] Edit");
				printf("\n\t[3] Delete");
				printf("\n\t[4] Sorting [BONUS]");
				printf("\n\t[5] Reverse [TUGAS]");
				printf("\n\t[0] Exit");
				printf("\n\n\t===> "); scanf("%d", &menu);
				
				switch(menu) {
					case 1 :
						printf("Program Maintenance");
					break;
					
					case 2 :
						printf("\n\n\tMasukkan nama hewan yang ingin diubah : "); fflush(stdin); gets(cari);
						printf("\tMasukkan nama hewan yang baru : "); fflush(stdin); gets(hewanBaru);
						printf("\tMasukkan nama kelas yang baru : "); fflush(stdin); gets(kelasBaru);
						editHewan(dataHewan, dataKelas, cari, hewanBaru, kelasBaru);
						
						printf("\n\tData Hewan :\n");
						tampilArray(dataHewan);
						
						printf("\n\n\tData Kelas :\n");
						tampilArray(dataKelas);
					break;
					
					case 3 :
						printf("Program Maintenance");
					break;
					
					case 4 :
						printf("Program Maintenance");
					break;
						
					case 5 :
						printf("Program Maintenance");
					break;
					
					case 0 :
						logout=1;
						cekLogout(&logout);
					break;
				}
				getch();
			} while(logout!=1);
		}
		
		else if(cekb==1) {
			printf("Berhasil login [PENGUNJUNG]");
			do {
				system("cls");
				printf("\n\n\t====== KEBUN BINATANG  ======");
				printf("\n\t[1] Input");
				printf("\n\t[0] Exit");
				printf("\n\n\t===> "); scanf("%d", &menu);
				
				switch(menu) {
					case 1 :
						printf("\n\tMasukkan nama hewan : "); fflush(stdin); gets(hewan);
						for(i=0; i<17; i++) {
							if(strcmpi(dataHewan[i], hewan)==0)	{
								temp=i;
							}
						}
						if(temp==-1) {
							printf("\n\t\t[!] Invalid");
						}
						else {
							printf("\tHewan tersebut merupakan hewan [%s]", dataKelas[temp]);
							temp=-1;	
						}
					break;
					
					case 0 :
						cekLogout(&logout);
					break;
				}
				getch();
			} while(logout!=1);
		}
		
		else {
			
		}
		getch();
	} while(menu!=0);
	return 0;
}

void cekLogin(int *cekA, int *cekB, string user, string pass) {
	if(strcmp(user, "Zooey")==0 && strcmp(pass, "zooeyjaya")==0) {
		*cekA=1;
	} 
	else if(strcmp(user, "guest")==0 && strcmp(pass, "guest")==0) {
		*cekB=1;
	}
	else {
		*cekA=0;
		*cekB=0;
	}
}

void cekLogout(int *logout) {
	*logout=1;
	
}
