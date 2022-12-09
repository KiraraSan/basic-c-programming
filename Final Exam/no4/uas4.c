#include <stdlib.h>
#include <stdbool.h>

#define jmlDosen 99
#define jmlJournal 99
typedef char string[50];

typedef struct{
    string title;
    string authors;
    int pages;
    int yearTerbit;
} Journal;

typedef struct{
    int noUrut;
    Journal publication[jmlJournal];
    int year;
} Dosen;

void cetakJuduldanThn(Dosen D[], int noUrut);
int hitungThn(Dosen D[], int noUrut);

int main() {
	
}

void cetakJuduldanThn(Dosen D[], int noUrut){
    int n,m, index;
    for(n=0; n < jmlDosen; n++){
        if(noUrut == D[n].noUrut){
            index = n;
        }
    }
    
    for(n=0; n < jmlJournal;n++){
        if(strcmp(D[index].publication[n].title,"-")!=0){
        printf("\nJudul        : %s",D[index].publication[n].title);
        printf("\nTahun        : %d",D[index].publication[n].yearTerbit);
        }
    }
}

int hitungThn(Dosen D[], int noUrut){
    int n,index;
    for(n=0; n < jmlDosen;n++){
        if(noUrut == D[n].noUrut){
            index = n;
        }
    }
    if(D[index].publication[0].yearTerbit != 0) {
        return D[index].year - D[index].publication[0].yearTerbit;
    }
    return -1;
}
