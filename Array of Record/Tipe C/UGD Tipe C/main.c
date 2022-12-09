#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define tampungChild 8
#define tampungParent 2

typedef char string[50];

//bonus 1 / 2 / 3 / 4

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct{
	string kodePetak;
	int jumlahAyam;
	string namaPetugas;
	int jumlahTelurAyam;
}Child;

typedef struct{
	string namaPeternakan;
	Child C[tampungChild];
}Parent;

void inisialisasiData(Parent P[]);
void tampilParent(Parent P[],int index);
void tampilDataChild(Child C);
void tampilAllChild(Parent P[],int index);
void swapChild(Child *C1, Child *C2);
int searchParent(Parent P[],string namaPeternakan);
int searchChild(Child C[], string kodePetak);
Child isiDataChild(string kodePetak, string namaPetugas, int jumlahAyam, int jumlahTelurAyam);
int cekEmpty(Child C[]);
int cekIsi(Child C[]);



int main(int argc, char *argv[]) {
	Parent P[tampungParent];
	string namaParent, kodePetak, namaPenjaga;
	int pil,temp,tempChild,tempChild2,i,jumlahAyam,jumlahTelurAyam;
	bool menu = true;
	
	inisialisasiData(P);
		
	while(menu){
		system("cls");
		printf("\n [Peternakan]");
		printf("\n [1]. Set Nama Peternakan");
		printf("\n [2]. Set Data");
		printf("\n [3]. Tampil Data Petak Peternakan");
		printf("\n [0]. Keluar");
		printf("\n >> ");scanf("%d",&pil);
		switch(pil){
			case 1:
				if(searchParent( P,"-")!=-1){
					for(i = 0; i < tampungParent; i++){
						printf("\n Nama Peternakan Ke - %d : ",(i+1));fflush(stdin);gets(P[i].namaPeternakan);		
					}
					printf("\n Berhasil Set Nama Semua Peternakan");
				}else{
					printf("\n Anda telah melakukan set nama Peternakan [!]");
				}
				
						
				break;
				
			case 2:
				printf("\n Nama Peternakan : ");fflush(stdin);gets(namaParent);
				if(searchParent( P,namaParent)!=-1){
					temp = searchParent( P,namaParent);
					printf("\n [1]. Mengisi Petak");
					printf("\n [2]. Edit Petak");
					printf("\n [TUGAS]");
					printf("\n [3]. Swap Petak");
					printf("\n >> ");scanf("%d",&pil);
					switch(pil){
							
						case 1:
							if(cekEmpty(P[temp].C)!=-1){
								tempChild = cekEmpty(P[temp].C);
									printf("\n Kode Petak : ");fflush(stdin);gets(kodePetak);
									printf("\n Nama Penjaga : ");fflush(stdin);gets(namaPenjaga);
									printf("\n Jumlah Ayam : ");scanf("%d",&jumlahAyam);
									printf("\n Jumlah Telur Ayam : ");scanf("%d",&jumlahTelurAyam);
									
									P[temp].C[tempChild] = isiDataChild(kodePetak, namaPenjaga, jumlahAyam, jumlahTelurAyam);
									printf("\n Berhasil MengisiPetak [!]");	
									
							}else{
								printf("\n Semua Petak telah terisi [!]");
							}
							

							break;
							
						case 2:
							
							if(cekIsi(P[temp].C)!=-1){
								printf("\n Kode Petak : ");fflush(stdin);gets(kodePetak);
								tempChild = searchChild(P[temp].C,kodePetak);
								if(tempChild!=-1){
									printf("\n Kode Petak : ");fflush(stdin);gets(kodePetak);
									printf("\n Nama Penjaga : ");fflush(stdin);gets(namaPenjaga);
									printf("\n Jumlah Ayam : ");scanf("%d",&jumlahAyam);
									printf("\n Jumlah Telur Ayam : ");scanf("%d",&jumlahTelurAyam);
									
									P[temp].C[tempChild] = isiDataChild(kodePetak, namaPenjaga, jumlahAyam, jumlahTelurAyam);
									printf("\n Berhasil Mengedit Petak [!]");	
								}else{
									printf("\n Petak Tidak Ditemukan [!]");
								}
		
							}else{
								printf("\n Semua Petak Masih Kosong [!]");
							}
	
							break;
							
						case 3:
							
							if(cekIsi(P[temp].C)!=-1){
								printf("\n Kode Petak 1 : ");fflush(stdin);gets(kodePetak);
								tempChild = searchChild(P[temp].C,kodePetak);
								if(tempChild!=-1){
									printf("\n Kode Petak 2 : ");fflush(stdin);gets(kodePetak);
									tempChild2 = searchChild(P[temp].C,kodePetak);
									if(tempChild2!=-1){
										swapChild(&(P[temp].C[tempChild]),&(P[temp].C[tempChild2]));
										printf("\n Berhasil Swap Petak [!]");
									}else{
										printf("\n Petak 2 Tidak Ditemukan [!]");
									}
								}else{
									printf("\n Petak 1 Tidak Ditemukan [!]");
								}
		
							}else{
								printf("\n Semua Petak Masih Kosong [!]");
							}
							
							break;
					}
				
				}else{
					printf("\n Peternakan Tidak Ditemukan [!]");
				}
			break;
				
			case 3:
				
				printf("\n Nama Peternakan : ");fflush(stdin);gets(namaParent);
				temp = searchParent( P,namaParent);
				if(temp!=-1){
					if(cekIsi(P[temp].C)!=-1){
						tampilAllChild(P,temp);
						printf("\n Kode Petak : ");fflush(stdin);gets(kodePetak);
						tempChild = searchChild(P[temp].C,kodePetak);
						if(tempChild!=-1){
							tampilDataChild(P[temp].C[tempChild]);
						}else{
							printf("\n Petak Tidak Ditemukan [!]");
						}
					}else{
						printf("\n Semua Petak Masih Kosong [!]");
					}
	
				}else{
					printf("\n Peternakan Tidak Ditemukan [!]");
				}
				break;
				
			case 0:
				printf("\nDandy Candra Oktaviano / 200710670 / B");
				menu = false;
				break;
		}
		getch();
		
		
	}
	
	return 0;
}

void inisialisasiData(Parent P[]){
	int i, j;
	for(i = 0; i < tampungParent; i++){
		strcpy(P[i].namaPeternakan,"-");
		for(j = 0; j < tampungChild; j++){
			strcpy(P[i].C[j].kodePetak,"-");
			strcpy(P[i].C[j].namaPetugas,"-");
			P[i].C[j].jumlahAyam = 0;
			P[i].C[j].jumlahTelurAyam = 0;
		}
	}
}

void tampilAllChild(Parent P[],int index){
	int j;
	printf("\n Peternakan	: %s\n\n",P[index].namaPeternakan);
	for(j = 0; j < tampungChild; j++){
		printf(" [%s] ",P[index].C[j].kodePetak);
		if(j+1==tampungChild/2)
			printf("\n\n");
	}
	
}

void tampilDataChild(Child C){
	printf("\n [ Tampil Data Petak ] ");
	printf("\n Kode Petak 	      : %s",C.kodePetak);
	printf("\n Nama Penjaga	  	  : %s",C.namaPetugas);
	printf("\n Jumlah Ayam        : %d",C.jumlahAyam);
	printf("\n Jumlah Telur Ayam  : %d",C.jumlahTelurAyam);
}

int searchParent(Parent P[],string namaPeternakan){
	int i;
	for(i = 0; i < tampungParent; i++){
		if(strcmp(P[i].namaPeternakan,namaPeternakan) == 0){
			return i;
		}
	}
	return -1;
}

int searchChild(Child C[], string kodePetak){
	int i;
	for(i = 0; i < tampungChild; i++){
		if(strcmp(C[i].kodePetak,kodePetak)==0){
			return i;
		}
	}
	return -1;
}

Child isiDataChild(string kodePetak, string namaPetugas, int jumlahAyam, int jumlahTelurAyam){
	Child temp;
	strcpy(temp.kodePetak,kodePetak);
	strcpy(temp.namaPetugas,namaPetugas);
	temp.jumlahAyam = jumlahAyam;
	temp.jumlahTelurAyam = jumlahTelurAyam;
	
	return temp;
	
}
int cekEmpty(Child C[]){
	int i;
	for(i = 0; i < tampungChild; i++){
		if(strcmp(C[i].kodePetak,"-")==0){
			return i;
		}
	}
	return -1;
}
int cekIsi(Child C[]){
	int i;
	for(i = 0; i < tampungChild; i++){
		if(strcmp(C[i].kodePetak,"-")!=0){
			return i;
		}
	}
	return -1;
}

void swapChild(Child *C1, Child *C2){
	Child temp;
	
	temp = *C1;
    *C1 = *C2;
    *C2 = temp;
}
