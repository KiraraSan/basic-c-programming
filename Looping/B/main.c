#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef char string[50];



int main(int argc, char *argv[]) {
	int menu,bil,umur,temp=0;
	string nama,username,password,barang1,barang2,barang3;// nama barang terinisialisasi terlebih dahulu
	int stok1=0,stok2=0,stok3=0;
	int bid1=0,bid2=0,bid3=0;
	int pil=0,count=0;
	int isInput=0,isLogin=0,isWin=0;
	int bet=0;
	srand(time(NULL));
	char huruf;
	char persen;
	
	strcpy(barang1,"Barang1");
	strcpy(barang2,"Barang2");
	strcpy(barang3,"Barang3");

	do
	{
		system("cls");
		printf("================ TOKO MASZEH ================");
		printf("\n[1] Login");
		printf("\n[2] Input Stok");
		printf("\n[3] Tampil Barang");
		printf("\n[4] Pelelangan");
		printf("\n[5] Pelelangan Auto (Tugas)");
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
					if (strcmp(username,"tebri")==0){
						break;
					}else{
						printf("\n\tUsername tersebut invalid [!]");
					}
					
				} while (strcmp(username,"tebri")!=0);
				
				do
				{
					printf("\nPassword : ");fflush(stdin);gets(password);
					if (strcmp(password,"1234")==0){
						break;
					}else{
						printf("\n\tPassword tersebut invalid [!]");
					}
					
				} while (strcmp(password,"1234")!=0);

				printf("\n\tSelamat Datang Bosquu !");
				isLogin=1;
			}else{
				printf("\nAnda Sudah Login [!]");
			}
				

			break;

		case 2:
			if (isLogin==1){
				do{
					printf("\n\nMasukkan jumlah stok yang ingin Anda masukkan untuk barang %s",barang1);
					printf("\nJumlah Stok : ");scanf("%d",&stok1);
				} while (stok1<=0);
				
				do{
					printf("\n\nMasukkan jumlah stok yang ingin Anda masukkan untuk barang %s",barang2);
					printf("\nJumlah Stok : ");scanf("%d",&stok2);
				} while (stok2<=0);
				
				do{
					printf("\n\nMasukkan jumlah stok yang ingin Anda masukkan untuk barang %s",barang3);
					printf("\nJumlah Stok : ");scanf("%d",&stok3);
				} while (stok3<=0);
				isInput=1;
			}else{
				printf("\nLogin terlebih dahulu [!]");
			}
			break;

		case 3:
			if (isLogin==1 && isInput==1){
				printf("\n\n========== STOK BARANG ==========");
				printf("\n\nNama Barang : %s",barang1);
				printf("\nStok Barang  : %d",stok1);

				printf("\n\nNama Barang : %s",barang2);
				printf("\nStok Barang  : %d",stok2);

				printf("\n\nNama Barang : %s",barang3);
				printf("\nStok Barang  : %d",stok3);
				
			}else if (isLogin==0){
				printf("\nLogin terlebih dahulu [!]");
			}else if (isLogin==1 && isInput ==0){
				printf("\nInput data terlebih dahulu[!]");
			}
			
			
			break;

		case 4:
			if (isLogin==1 && isInput==1){
				bid1=0,bid2=0,bid3=0,count=0;

				
				do{
					system("cls");
					printf("\n\n========== PELELANGAN ==========");
					printf("\n1. %s : %d",barang1,bid1);
					printf("\n2. %s : %d",barang2,bid2);
					printf("\n3. %s : %d",barang3,bid3);
					printf("\nPilih Barang yang ingin anda bid (1-3) :");scanf("%d",&pil);
					printf("\nJumlah uang yang anda pasang :");scanf("%d",&bet);
					if (pil==1){
						bid1 +=bet;
						count++;
					}else if (pil==2){
						bid2 +=bet;
						count++;
					}else if (pil==3){
						bid3 +=bet;
						count++;
					}else{
						printf("\nBarang yang anda pilih invalid !");
					}
					
					
				} while (count!=5);

				if (bid1>bid2 && bid1>bid3 ){
					printf("\nSelamat barang %s Memenangkan Lelang",barang1);
				}else if (bid2>bid3 && bid2>bid1){;
					printf("\nSelamat barang %s Memenangkan Lelang",barang2);
				}else if (bid3>bid1 && bid3>bid2){;
					printf("\nSelamat barang %s Memenangkan Lelang",barang3);
				}else{
					printf("\nTidak ada barang yang memenangkan lelang ");
				}
				
				
				
			}else if (isLogin==0){
				printf("\nLogin terlebih dahulu [!]");

			}else if (isLogin==1 && isInput ==0){
				printf("\nInput data terlebih dahulu[!]");
			}
			
			
			break;

		case 5:
			
			if (isLogin==1 && isInput==1){
				bid1=0,bid2=0,bid3=0,count=0;

				
				do{
					system("cls");
					printf("\n\n========== PELELANGAN ==========");
					printf("\n1. %s : %d",barang1,bid1);
					printf("\n2. %s : %d",barang2,bid2);
					printf("\n3. %s : %d",barang3,bid3);
					printf("\nPilih Barang yang ingin anda bid (1-3) :");scanf("%d",&pil);
					printf("\nJumlah uang yang anda pasang :");scanf("%d",&bet);
					if (pil==1){
						bid1 +=bet;
						bid2 += rand() % 100;
						bid3 += rand() % 100;
						count++;
					}else if (pil==2){
						bid2 +=bet;
						bid1 += rand() % 100;
						bid3 += rand() % 100;
						count++;
					}else if (pil==3){
						bid3 +=bet;
						bid1 += rand() % 100;
						bid2 += rand() % 100;
						count++;
					}else{
						printf("\nBarang yang anda pilih invalid !");
					}
					
					
				} while (count!=5);

				
				system("cls");
				printf("\n\n========== PELELANGAN ==========");
				printf("\n1. %s : %d",barang1,bid1);
				printf("\n2. %s : %d",barang2,bid2);
				printf("\n3. %s : %d",barang3,bid3);
				
				if (bid1 > bid2){
			        if (bid1 > bid3){
			            printf("\nSelamat barang %s Memenangkan Lelang",barang1);
			        }else{
			            printf("\nSelamat barang %s Memenangkan Lelang",barang3);
			        }
			    }else if (bid2 > bid3){
			    	printf("\nSelamat barang %s Memenangkan Lelang",barang2);
				}else{
					printf("\nSelamat barang %s Memenangkan Lelang",barang3);
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


