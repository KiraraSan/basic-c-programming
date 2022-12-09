#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Alexis Divasonda Sigat Ngaing / 210711407 / D

typedef char string[50];

void cekLogin(int *cekA, int *cekB, string user, string pass);
void cekLogout(int *logout, int *cekA, int *cekB);
void inisialisasi(int *cekA, int *cekB, int *cek);

void tampilArray(string arr[]) {
	int i;
	for(i=0; i<5; i++) {
		printf("| %s ", arr[i]);	
	}
	printf("\n");
	for(i=5; i<10; i++) {
		printf("| %s ", arr[i]);
	}
	printf("\n");
	for(i=10; i<15; i++) {
		printf("| %s ", arr[i]);	
	}
	printf("\n");
	for(i=15; i<17; i++) {
		printf("| %s ", arr[i]);
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

void input() {
	
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

void hapus(string dataHewan[], string dataKelas[], string cariHewan, int *cek) {
	int i;
	int indexDicari = cariData(dataHewan, cariHewan);
	
        if(indexDicari != -1) {
			strcpy(dataHewan[indexDicari], "-");
			strcpy(dataKelas[indexDicari], "-");
			
			*cek=1;
		} else {
		printf("\n\t[!] Data hewan tidak ditemukan");
		
		*cek=0;
	}
}

/*
void reverse(string dataHewan[], string dataKelas[], string hewanReverse) {
	
	int i, d;
	
	for(i = 17 - 1, d = 0; i >= 0; i--, d++) {
		(strlen(hewanReverse[d]) == strlen(dataHewan[i]));
	}

	for(i = 0; i < 17; i++) {
		(strlen(dataHewan[i]) == strlen(hewanReverse[i])); 
	}
	
	printf("\n");
	 
	for(i = 0; i < 17; i++) {
		printf("%s ", dataHewan[i]);
	}
}
*/

void reverseDua() {

	char string[] = "Beruang Kutub Katak Burung Merak Singa Macan Burung Unta Salmon Buaya Serigala Ikan Mas Ular Piton Ikan Cupang Burung Elang Kura kura Kelinci Alligator Paus";
    int i;
	char n = strlen(string);
    int tail = n-1;
    
    for(i=n-1;i>=0;i--) {
        if(string[i] == ' ' || i == 0) {
            int cursor = (i==0? i: i+1);
            while(cursor <= tail)
                printf("%c", string[cursor++]);
            printf(" ");
            tail = i-1;
        }
    }
}

int main(int argc, char *argv[]) {
	
	string dataHewan[17] = {"Beruang Kutub", "Katak", "Burung Merak", "Singa", "Macan", "Burung Unta", 
							"Salmon", "Buaya", "Serigala", "Ikan Mas", "Ular Piton", "Ikan Cupang", 
							"Burung Elang", "Kura kura", "Kelinci", "Alligator", "Paus"};

	string dataKelas[17] = {"Mamalia", "Amfibi", "Burung", "Mamalia", "Mamalia", "Burung", 
							"Ikan", "Reptil", "Mamalia", "Ikan", "Reptil", "Ikan", 
							"Burung", "Reptil", "Mamalia", "Reptil", "Mamalia"};
	
	int cekA=0, cekB=0, cek=0, menu;
	int logout, username, password, i, j;
	string cari;
	int ceka, cekb, temp=-1;
	string hewan, user, pass, hewanBaru, kelasBaru, hewanReverse;
	
	do {	
		logout=0;
		system("cls");
		printf("\n\tUsername   : "); fflush(stdin); gets(user);
		printf("\tPassword   : "); fflush(stdin); gets(pass);
		cekLogin(&ceka, &cekb, user, pass);
		
		if(ceka==1) {
			printf("\n\t\tBerhasil login [PENGELOLA]"); getch();
			do {
				system("cls");
				printf("\n\n====== ZOOEY KOEY ASOEY [ADMIN] ======\n");
				printf("\n[1] Input");
				printf("\n[2] Edit");
				printf("\n[3] Delete");
				printf("\n[4] Sorting [BONUS]");
				printf("\n[5] Reverse [TUGAS]");
				printf("\n[0] Exit");
				printf("\n\n===> "); scanf("%d", &menu);
				
				switch(menu) {
					case 1 :
						if(cek==1) {
							
						} else {
							printf("\n\t[!] Data Hewan sudah terisi penuh");
						}
						
					break;
					
					case 2 :
						printf("\nMasukkan nama hewan yang ingin diubah : "); fflush(stdin); gets(cari);
						printf("Masukkan nama hewan yang baru : "); fflush(stdin); gets(hewanBaru);
						printf("Masukkan nama kelas yang baru : "); fflush(stdin); gets(kelasBaru);
						editHewan(dataHewan, dataKelas, cari, hewanBaru, kelasBaru);
						
						printf("\nData Hewan :\n");
						tampilArray(dataHewan);
						
						printf("\n\nData Kelas :\n");
						tampilArray(dataKelas);
					break;
					
					case 3 :
						printf("\nMasukkan data hewan yang ingin dihapus : "); fflush(stdin); gets(cari);
						hapus(dataHewan, dataKelas, cari, &cek);
						
						if(cek==1) {
							printf("\n\tData Hewan berhasil dihapus...\n");
							
							printf("\nData Hewan :\n");
							tampilArray(dataHewan);
							
							printf("\n\nData Kelas :\n");
							tampilArray(dataKelas);	
						} else {
							printf("\n\n\tBatal menghapus data Hewan...");
						}	
					break;
					
					case 4 :
						printf("\n\tProgram Maintenance");
					break;
						
					case 5 :
						reverseDua();
						printf("\nData Hewan :\n");
						tampilArray(dataHewan);
							
						printf("\n\nData Kelas :\n");
						tampilArray(dataKelas);
					break;
					
					case 0 :
						logout=1;
						cekLogout(&logout, &ceka, &cekb);
						getch();
						
						printf("\n\tTekan beberapa kali key apapun untuk keluar");
					break;
				}
				getch();
			} while(logout!=1);
		}
		
		else if(cekb==1) {
			printf("\n\t\tBerhasil login [PENGUNJUNG]"); getch();
			do {
				system("cls");
				printf("\n\n====== WELCOME TO ZOOEY KOEY ASOEY [GUEST] ======\n");
				printf("\n[1] Input");
				printf("\n[0] Exit");
				printf("\n\n===> "); scanf("%d", &menu);
				
				switch(menu) {
					case 1 :
						printf("\nMasukkan nama hewan : "); fflush(stdin); gets(hewan);
						for(i=0; i<17; i++) {
							if(strcmpi(dataHewan[i], hewan)==0)	{
								temp=i;
							}
						}
						if(temp==-1) {
							printf("\n\t[!] Invalid");
						} else {
							printf("Hewan tersebut merupakan hewan [%s]", dataKelas[temp]);
							temp=-1;	
						}
					break;
					
					case 0 :
						cekLogout(&logout, &cekA, &cekB);
						getch();
						printf("\n\tTekan beberapa kali key apapun untuk keluar");
					break;
				}
				getch();
			} while(logout!=1);
		}
		
		else {
			printf("\n\t\t[!] Username / Password Salah!");
		}
		getch();
	} while(cekA!=1 || cekB!=1);
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

void cekLogout(int *logout, int *cekA, int *cekB) {
	*logout=1;
	*cekA=0;
	*cekB=0;
}
