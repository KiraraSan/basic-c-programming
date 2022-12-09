#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef char string[50];



int main(int argc, char *argv[]) {
	int menu,bil,umur,temp=0;
	string nama,username,password,kuda1,kuda2,kuda3;
	int ID1,ID2,ID3;
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
		printf("================ & PACUAN KUDA & ================");
		if (isInput==1){
			printf("\n\t KUDA 1 :\t %s ",kuda1);
			printf("\n\t KUDA 2 :\t %s ",kuda2);
			printf("\n\t KUDA 3 :\t %s ",kuda3);
		}
		printf("\n[1] Login");
		printf("\n[2] Input data kuda");
		printf("\n[3] Tampil data kuda");
		printf("\n[4] Simulasi Balap Kuda");
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
					if (strcmp(username,"thomas")==0){
						break;
					}else{
						printf("\n\tUsername tersebut invalid [!]");
					}
					
				} while (strcmp(username,"thomas")!=0);
				
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
					printf("\nMasukan Nama untuk Kuda 1 : ");fflush(stdin);gets(kuda1);
					if (strlen(kuda1)==0)
					{
						printf("\nNama Kuda tidak boleh kosong !");
					}
					
				} while (strlen(kuda1)==0);

				do{
					printf("\nMasukan Nama untuk Kuda 2 : ");fflush(stdin);gets(kuda2);
					if (strlen(kuda2)==0)
					{
						printf("\nNama Kuda tidak boleh kosong !");
					}
					
				} while (strlen(kuda2)==0);
				
				do{
					printf("\nMasukan Nama untuk Kuda 3 : ");fflush(stdin);gets(kuda3);
					if (strlen(kuda3)==0)
					{
						printf("\nNama Kuda tidak boleh kosong !");
					}
					
				} while (strlen(kuda3)==0);
				
				
				kec1 = (rand() % (50 - 20 + 1)) + 20;
				kec2 = (rand() % (50 - 20 + 1)) + 20;
				kec3 = (rand() % (50 - 20 + 1)) + 20;


				ID1 = rand() % 500;
				ID2 = rand() % 500;
				ID3 = rand() % 500;
				
				isInput=1;
			}else{
				printf("\nLogin terlebih dahulu [!]");
			}
			break;

		case 3:
			if (isLogin==1 && isInput==1){
				printf("\n==== DATA PACUAN KUDA ====");
				printf("\n\n KUDA 1");
				printf("\nNama      : %s",kuda1);
				printf("\nKecepatan : %d m/s",kec1);
				printf("\nID        : %05d",ID1);

				printf("\n\n KUDA 2");
				printf("\nNama      : %s",kuda2);
				printf("\nKecepatan : %d m/s",kec2);
				printf("\nID        : %05d",ID2);

				printf("\n\n KUDA 3");
				printf("\nNama      : %s",kuda3);
				printf("\nKecepatan : %d m/s",kec3);
				printf("\nID        : %05d",ID3);
			}else if (isLogin==0){
				printf("\nLogin terlebih dahulu [!]");

			}else if (isLogin==1 && isInput ==0){
				printf("\nInput data terlebih dahulu[!]");
			}
			
			
			break;

		case 4:
			if (isLogin==1 && isInput==1){
				pos1=0,pos2=0,pos3=0,isWin=0;
				printf("\n\n========== SIMULASI PACUAN KUDA ==========");
				printf("\nJarak : 500m");
				do{

					pos1 += kec1;
					pos2 += kec2;
					pos3 += kec3;

					printf("\nPosisi Kuda 1 : %d",pos1);
					printf("\nPosisi Kuda 2 : %d",pos2);
					printf("\nPosisi Kuda 3 : %d\n",pos3);

					

					if (pos1 >500){
						printf("\nKuda %s Menang !",kuda1);
						isWin=1;
					}else if (pos2 >500){
						printf("\nKuda %s Menang !",kuda2);
						isWin=1;
					}else if (pos3 >500){
						printf("\nKuda %s Menang !",kuda3);
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
				printf("\n Kuda 1 : %d %c",odd1,persen);
				printf("\n Kuda 2 : %d %c",odd2,persen);
				printf("\n Kuda 3 : %d %c",odd3,persen);
				printf("\n\n Pilih kuda yang anda jagokan : ");scanf("%d",&bet);
				if (bet==1 ||bet==2 || bet==3 ){
					if (bet == 1){
						random = rand() % 100;
						if (random <= odd1){
							printf("\n Kuda Pilihan Anda MENANG [!]");
						}else{
							printf("\n Kuda Pilihan Anda KALAH [!]");
						}
						
					}
					if (bet == 2){
						random = rand() % 100;
						if (random <= odd2){
							printf("\n Kuda Pilihan Anda MENANG [!]");
						}else{
							printf("\n Kuda Pilihan Anda KALAH [!]");
						}
					}
					if (bet == 3){
						random = rand() % 100;
						
						if (random <= odd3){
							printf("\n Kuda Pilihan Anda MENANG [!]");
						}else{
							printf("\n Kuda Pilihan Anda KALAH [!]");
						}
					}
					
				}else{
					printf("\nPilihan kuda invalid [!]");
				}
				

				
			}else if (isLogin==0){
				printf("\nLogin terlebih dahulu [!]");

			}else if (isLogin==1 && isInput ==0){
				printf("\nInput data terlebih dahulu[!]");
			}
			
			
			break;
		
		case 0: printf("\nNama/Kelas/NPM Bonus 1,2,3 ");break;
			
		default:printf("\n[!] Menu hanya ada 1-5");
			break;
		}getch();
	} while (menu!=0);
	
	return 0;
}

