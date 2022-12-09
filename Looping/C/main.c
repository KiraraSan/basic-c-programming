#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef char string[50];



int main(int argc, char *argv[]) {
	int menu,bil,umur,temp=0;
	string nama,username,password,mobil1,mobil2,mobil3;
	string merk1,merk2,merk3;
	int kec1,kec2,kec3;
	int pos1=0,pos2=0,pos3=0;
	int isInput=0,isLogin=0,isWin=0;
	int odd1,odd2,odd3;
	int bet=0;
	srand(time(NULL));
	char huruf;
	char persen;
	


	do
	{
		system("cls");
		printf("================ & BALAP MOBIL & ================");
		if (isInput==1){
			printf("\n\t Mobil 1 :\t %s ",mobil1);
			printf("\n\t Mobil 2 :\t %s ",mobil2);
			printf("\n\t Mobil 3 :\t %s ",mobil3);
		}
		printf("\n[1] Login");
		printf("\n[2] Input data mobil");
		printf("\n[3] Tampil data mobil");
		printf("\n[4] Simulasi Balap mobil");
		printf("\n[5] Pasang Taruhan (Tugas)");
		printf("\n[0] Exit");
		printf("\n---------------------------------");
		printf("\n>>> ");scanf("%d",&menu);
		switch (menu)
		{
		case 1:
			if (isLogin==0)
			{
				do
				{
					printf("\nUsername : ");fflush(stdin);gets(username);
					if (strcmp(username,"nana")==0){
						break;
					}else{
						printf("\n\tUsername tersebut invalid [!]");
					}
					
				} while (strcmp(username,"nana")!=0);
				
				do
				{
					printf("\nPassword : ");fflush(stdin);gets(password);
					if (strcmp(password,"1234")==0){
						break;
					}else{
						printf("\n\tPassword tersebut invalid [!]");
					}
					
				} while (strcmp(password,"1234")!=0);

				printf("\n\tSelamat Datang BOS !");
				isLogin=1;
			}else{
				printf("\nAnda Sudah Login [!]");
			}
				

			break;

		case 2:
			if (isLogin==1){
				do{
					printf("\nMasukan Nama untuk mobil 1 : ");fflush(stdin);gets(mobil1);
					if (strlen(mobil1)==0)
					{
						printf("\nNama mobil tidak boleh kosong !");
					}
					
				} while (strlen(mobil1)==0);

				do{
					printf("\nMasukan Nama untuk mobil 2 : ");fflush(stdin);gets(mobil2);
					if (strlen(mobil2)==0)
					{
						printf("\nNama mobil tidak boleh kosong !");
					}
					
				} while (strlen(mobil2)==0);
				
				do{
					printf("\nMasukan Nama untuk mobil 3 : ");fflush(stdin);gets(mobil3);
					if (strlen(mobil3)==0)
					{
						printf("\nNama mobil tidak boleh kosong !");
					}
					
				} while (strlen(mobil3)==0);
				
				
				kec1 = (rand() % (100 - 20 + 1)) + 20;
				kec2 = (rand() % (100 - 20 + 1)) + 20;
				kec3 = (rand() % (100 - 20 + 1)) + 20;


				do{
					printf("\nMasukan merk untuk mobil 1 : ");fflush(stdin);gets(merk1);
					if (strlen(merk1)==0)
					{
						printf("\nNama merk tidak boleh kosong !");
					}
					
				} while (strlen(merk1)==0);

				do{
					printf("\nMasukan merk untuk mobil 2 : ");fflush(stdin);gets(merk2);
					if (strlen(merk2)==0)
					{
						printf("\nNama merk tidak boleh kosong !");
					}
					
				} while (strlen(merk2)==0);

				do{
					printf("\nMasukan merk untuk mobil 3 : ");fflush(stdin);gets(merk3);
					if (strlen(merk3)==0)
					{
						printf("\nNama merk tidak boleh kosong !");
					}
					
				} while (strlen(merk3)==0);
				
				isInput=1;
			}else{
				printf("\nLogin terlebih dahulu [!]");
			}
			break;

		case 3:
			if (isLogin==1 && isInput==1){
				printf("\n==== DATA BALAPAN MOBIL ====");
				printf("\n\n MOBIL 1");
				printf("\nNama      : %s",mobil1);
				printf("\nKecepatan : %d m/s",kec1);
				printf("\nMerk      : %s",merk1);

				printf("\n\n MOBIL 2");
				printf("\nNama      : %s",mobil2);
				printf("\nKecepatan : %d m/s",kec2);
				printf("\nMerk      : %s",merk2);

				printf("\n\n MOBIL 3");
				printf("\nNama      : %s",mobil3);
				printf("\nKecepatan : %d m/s",kec3);
				printf("\nMerk      : %s",merk3);
			}else if (isLogin==0){
				printf("\nLogin terlebih dahulu [!]");

			}else if (isLogin==1 && isInput ==0){
				printf("\nInput data terlebih dahulu[!]");
			}
			
			
			break;

		case 4:
			if (isLogin==1 && isInput==1){
				pos1=0,pos2=0,pos3=0,isWin=0;
				printf("\n\n========== SIMULASI BALAPAN MOBIL ==========");
				printf("\nJarak : 1000m");
				do{

					pos1 += kec1;
					pos2 += kec2;
					pos3 += kec3;

					printf("\nPosisi Mobil 1 : %d",pos1);
					printf("\nPosisi Mobil 2 : %d",pos2);
					printf("\nPosisi Mobil 3 : %d\n",pos3);

					

					if (pos1 >1000){
						printf("\nMobil %s Menang !",mobil1);
						isWin=1;
					}else if (pos2 >1000){
						printf("\nMobil %s Menang !",mobil2);
						isWin=1;
					}else if (pos3 >1000){
						printf("\nMobil %s Menang !",mobil3);
						isWin=1;
					}
					
					
				} while (isWin==0);
				
			}else if (isLogin==0){
				printf("\nLogin terlebih dahulu [!]");

			}else if (isLogin==1 && isInput ==0){
				printf("\nInput data terlebih dahulu[!]");
			}
			
			
			break;

		case 5:
			
			persen = 37;
			if (isLogin==1 && isInput==1){
				int random;
				odd1 = (rand() % (100 - 20 + 1)) + 20;
				odd2 = (rand() % (100 - 20 + 1)) + 20;
				odd3 = (rand() % (100 - 20 + 1)) + 20;
				printf("\n\n========== TABEL TARUHAN ==========");
				printf("\n Mobil 1 : %d %c",odd1,persen);
				printf("\n Mobil 2 : %d %c",odd2,persen);
				printf("\n Mobil 3 : %d %c",odd3,persen);
				printf("\n\n Pilih Mobil yang anda jagokan : ");scanf("%d",&bet);
				if (bet==1 ||bet==2 || bet==3 ){
					if (bet == 1){
						random = rand() % 100;
						
						if (random <= odd1){
							printf("\n Mobil Pilihan Anda MENANG [!]");
						}else{
							printf("\n Mobil Pilihan Anda KALAH [!]");
						}
						
					}
					if (bet == 2){
						random = rand() % 100;
						
						if (random <= odd2){
							printf("\n Mobil Pilihan Anda MENANG [!]");
						}else{
							printf("\n Mobil Pilihan Anda KALAH [!]");
						}
					}
					if (bet == 3){
						random = rand() % 100;
					
						if (random <= odd3){
							printf("\n Mobil Pilihan Anda MENANG [!]");
						}else{
							printf("\n Mobil Pilihan Anda KALAH [!]");
						}
					}
					
				}else{
					printf("\nPilihan Mobil invalid [!]");
				}
				

				
			}else if (isLogin==0){
				printf("\nLogin terlebih dahulu [!]");

			}else if (isLogin==1 && isInput ==0){
				printf("\nInput data terlebih dahulu[!]");
			}
			
			
			break;
		
		case 0: printf("\nNama/Kelas/NPM ");break;
			
		default:printf("\n[!] Menu hanya ada 1-5");
			break;
		}getch();
	} while (menu!=0);
	
	return 0;
}


