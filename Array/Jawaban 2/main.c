#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[100];

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void initData(string logHewan[], string logKelas[]){
	int i;
	for(i = 0; i < 10; i++){
		strcpy(logHewan[i], "-");
	}
	
	for(i = 0; i < 10; i++){
		strcpy(logKelas[i], "-");
	}
}

void tampil(string logHewan[], string logKelas[]){
	int i;
	printf("\n==== Log Hewan ====\n");
	for(i = 0; i < 10; i++){
		if(strcmpi(logHewan[i], "-") != 0){
				printf("| %s ", logHewan[i]);
			if((i+1)%5 == 0){
				printf("|\n");
			}
		}
	}
	printf("\n\n==== Log Kelas ====\n");
	
	for(i = 0; i < 10; i++){
		if(strcmpi(logKelas[i], "-") != 0){
			printf("| %s ", logKelas[i]);
			if((i+1)%5 == 0){
				printf("|\n");
			}	
		}
		
	}
}

void tampilData(string dataHewan[], string dataKelas[]){
	int i;
	printf("Data Hewan:");
	for(i = 0; i < 17; i++){
		if(i % 5 == 0){
			printf("|\n");
		}
		printf("| %s ", dataHewan[i]);
	}
	printf("|\n\n");
	
	printf("Data Kelas:");
	for(i = 0; i < 17; i++){
		if(i % 5 == 0){
			printf("|\n");
		}
		printf("| %s ", dataKelas[i]);
	}
	printf("|\n\n");
}

int isHewanFound(string dataHewan[], string nama){
	int i;
	for(i = 0; i < 17; i++){
		if(strcmpi(dataHewan[i], nama) == 0){
			return i;
		}
	}
	return -1;
}

void inputLogHewan(string logHewan[], string nama){
	int i;
	for(i = 0; i < 50; i++){
		if(strcmpi(logHewan[i], "-") == 0){
			strcpy(logHewan[i], nama);
			return;
		}
	}
}

void inputLogKelas(string logKelas[], string nama){
	int i;
	for(i = 0; i < 50; i++){
		if(strcmpi(logKelas[i], "-") == 0){
			strcpy(logKelas[i], nama);
			return;
		}
	}
}

void editData(string dataHewan[], string dataKelas[], string nama, string namaBaru, string kelasBaru){
	int i;
	int found = isHewanFound(dataHewan, nama);
	strcpy(dataHewan[found], namaBaru);
	strcpy(dataKelas[found], kelasBaru);
}

int isDataHewanFull(string dataHewan[]){
	int i;
	for(i = 0; i < 17; i++){
		if(strcmpi(dataHewan[i], "-") == 0){
			return i;
		}
	}
	return -1;
}

int isNamaHewanFound(string dataHewan[], string namaHewan){
	int i;
	for(i = 0; i < 17; i++){
		if(strcmpi(dataHewan[i], namaHewan) == 0){
			return i;
		}
	}
	return -1;
}

int main(int argc, char *argv[]) {
	string dataHewan[17] = {"Beruang Kutub", "Katak", "Burung Merak", 
                        "Singa", "Macan", "Burung Unta", "Salmon",
                        "Buaya", "Serigala", "Ikan Mas", "Ular Piton",
                        "Ikan Cupang", "Burung Elang", "Kura kura",
                        "Kelinci", "Alligator", "Paus"};
    
    string dataKelas[17] = {"Mamalia", "Amfibi", "Burung", "Mamalia",
                        "Mamalia", "Burung", "Ikan", "Reptil", "Mamalia",
                        "Ikan", "Reptil", "Ikan", "Burung", "Reptil",
                        "Mamalia", "Reptil", "Mamalia"};
    
    string reverseHewan[17];
    string reverseKelas[17];
    string nama, temp;
    string namaHewan, namaKelas, namaHewanBaru, namaKelasBaru, uname, pass;
    int login, pil, i, j;
    do{
    	system("cls");
    	printf("Username : "); fflush(stdin); gets(uname);
    	printf("Password : "); fflush(stdin); gets(pass);
    	if(strcmpi(uname, "guest") == 0 && strcmpi(pass, "guest") == 0){
    		printf("\nBerhasil login [ Guest ]");
    		getch();
			do{
				system("cls");
				printf("1. Menu Input\n");
				printf("0. Exit\n");
				printf(">> ");
				scanf("%d", &pil);
				switch(pil){
					case 1:
						printf("Masukkan nama hewan : "); fflush(stdin); gets(namaHewan);
						if(isHewanFound(dataHewan, namaHewan) != -1){
							printf("Hewan tersebut merupakan hewan [ %s ]", dataKelas[isHewanFound(dataHewan, namaHewan)]);
						} else{
							printf("\nData kelas tidak tersedia!");
						}
						break;
					
					case 0:
						break;
						
					default:
						printf("\nMenu tidak tersedia!");
						break;
				}
				getch();
			} while(pil != 0);
		} else if(strcmpi(uname, "Zooey") == 0 && strcmpi(pass, "zooeyjaya") == 0){
			login = 2;
			printf("\nBerhasil login [ Pengelola ]");
			getch();
			do{
				system("cls");
				printf("1. Input\n");
				printf("2. Edit\n");
				printf("3. Delete\n");
				printf("4. Sorting [ BONUS ]\n");
				printf("5. Reverse [ TUGAS ]\n");
				printf("0. Exit\n");
				printf(">> "); scanf("%d", &pil);
				switch(pil){
					case 1:
						if(isDataHewanFull(dataHewan) != -1){
							do{
								printf("Masukkan nama hewan : ");
								fflush(stdin); gets(namaHewan);
								if(strlen(namaHewan) == 0){
									printf("Nama hewan tidak boleh kosong!\n\n");
								} else if(isNamaHewanFound(dataHewan, namaHewan) != -1){
									printf("Nama hewan harus unik!\n\n");
								} else{
									printf("Masukkan nama kelas : ");
									fflush(stdin); gets(namaKelas);
									strcpy(dataHewan[isDataHewanFull(dataHewan)], namaHewan);
									strcpy(dataKelas[isNamaHewanFound(dataHewan, namaHewan)], namaKelas);
									tampilData(dataHewan, dataKelas);
									break;
								}
							} while(strlen(namaHewan) == 0 || isNamaHewanFound(dataHewan, namaHewan) != -1);
						} else{
							printf("\nData hewan sudah terisi penuh!");
						}
						break;
						
					case 2:
						printf("Masukkan nama hewan yang ingin diubah : "); fflush(stdin); gets(namaHewan);
						if(isHewanFound(dataHewan, namaHewan) != 0){
							do{
								printf("Masukkan nama hewan yang baru : "); fflush(stdin); gets(namaHewanBaru);
								if(isNamaHewanFound(dataHewan, namaHewanBaru) != -1){
									printf("Nama hewan harus unik\n\n");
								} else if(strlen(namaHewanBaru) == 0){
									printf("Nama hewan harus diisi!\n\n");
								}
							} while(isNamaHewanFound(dataHewan, namaHewanBaru) != -1 || strlen(namaHewanBaru) == 0);
							
							do{
								printf("Masukkan nama kelas yang baru : "); fflush(stdin); gets(namaKelasBaru);
								if(strlen(namaKelasBaru) == 0){
									printf("Nama kelas harus diisi!\n\n");
								} else{
									editData(dataHewan, dataKelas, namaHewan, namaHewanBaru, namaKelasBaru);
								}
								
							}while(strlen(namaKelasBaru) == 0);
							
							printf("\nBerhasil edit data!\n\n");
							tampilData(dataHewan, dataKelas);
						} else{
							printf("\nNama hewan [ %s ] tidak ditemukan!", namaHewan);
						}
						break;
					
					case 3:
						printf("Masukkan nama hewan yang ingin dihapus : "); fflush(stdin); gets(namaHewan);
						if(isHewanFound(dataHewan, namaHewan) != -1){
							editData(dataHewan, dataKelas, namaHewan, "-", "-");
							printf("\nBerhasil delete data\n\n");
							tampilData(dataHewan, dataKelas);
						} else{
							printf("\nNama hewan tidak ditemukan!");
						}
						break;
					
					case 4:
						if(isDataHewanFull(dataHewan) == -1){
							printf("\nSebelum sorting:\n");
							tampilData(dataHewan, dataKelas);
							for(i = 0; i < 17; i++){
								for(j = 0; j < 17-1-i; j++){
									if(strcmp(dataHewan[j], dataHewan[j+1]) > 0){
										strcpy(temp, dataHewan[j]);
			        					strcpy(dataHewan[j], dataHewan[j+1]);
			        					strcpy(dataHewan[j+1], temp);
			        					
			        					strcpy(temp, dataKelas[j]);
			        					strcpy(dataKelas[j], dataKelas[j+1]);
			        					strcpy(dataKelas[j+1], temp);
									}
								}
							}
							printf("\n\nSetelah sorting:\n");
							tampilData(dataHewan, dataKelas);
						} else{
							printf("\nArray dataHewan belum terisi seluruhnya");
						}
						break;
						
					case 5:
						printf("\nSebelum reverse:\n");
						tampilData(dataHewan, dataKelas);
						for(i = 16; i >= 0; i--){
							strcpy(reverseHewan[i], dataHewan[16-i]);
							strcpy(reverseKelas[i], dataKelas[16-i]);
						}
						printf("\n\nSetelah reverse:\n");
						tampilData(reverseHewan, reverseKelas);
						break;
					case 0:
						break;
					
					default:
						printf("\nMenu tidak tersedia!");
						break;
				}
				getch();
			} while(pil != 0);
		} else{
			printf("\nUsername atau Password salah!");
		}
		getch();
	} while(strcmpi(uname, "keluar") != 0 && strcmpi(pass, "keluar") != 0);
	
	return 0;
}
