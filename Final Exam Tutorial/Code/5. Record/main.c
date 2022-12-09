#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

#define MAX 3

typedef char string[100];

// Struct harus dideklarasikan secara berurutan
typedef struct {
	string nama;
} Dosen; // struct Dosen akan digunakan di MataKuliah, maka deklarasikanlah terlebih dahulu

typedef struct {
	string nama;
	Dosen dosen;
} MataKuliah; // struct MataKuliah akan digunakan di Mahasiswa, maka deklarasikanlah terlebih dahulu

typedef struct {
	string nama;
	float ipk;
	MataKuliah MK;
} Mahasiswa;

void setData(Mahasiswa *M);
void printAOR(Mahasiswa arrayMhs[]);
int cariAOR(Mahasiswa arrayMhs[], string namaDicari);

int main(int argc, char *argv[]) {
	// Struct yang bukan merupakan tipe data, sehingga hanya dapat digunakan satu kali
	struct {
		string nama;
		int jumlahMahasiswa;
	} Fakultas;
	
	// Array of Mahasiswa:
	Mahasiswa angkatan21[MAX];
	printf("Mengeset data pada record:");
	strcpy(angkatan21[0].nama, "A");
	strcpy(angkatan21[1].nama, "B");
	strcpy(angkatan21[2].nama, "C");
	setData(&angkatan21[2]);
	
	printAOR(angkatan21);
	
	string namaDicari = "D";
	printf("\n\nPencarian AOR: nama mahasiswa '%s' ditemukan di indeks %d", namaDicari, cariAOR(angkatan21, namaDicari));
	
	return 0;
}

void setData(Mahasiswa *M) {
	// Dot operator pada pointer:
	strcpy((*M).nama, "Nama Mahasiswa");
	
	// Arrow operator pada pointer:
	M->ipk = 4.0;
	strcpy(M->MK.nama, "Nama Mata Kuliah");
	strcpy(M->MK.dosen.nama, "Nama Dosen");
}

void printAOR(Mahasiswa arrayMhs[]) {
	int i;
	for(i=0; i<MAX; i++) {
		printf("\nNama mahasiswa: %s", arrayMhs[i]);
	}
}

int cariAOR(Mahasiswa arrayMhs[], string namaDicari) {
	// Mencari nama mahasiswa di dalam sebuah Array of Mahasiswa
	int i;
	for(i=0; i<3; i++) {
		if(strcmp(arrayMhs[i].nama, namaDicari) == 0) {
			return i;
		}
	}
	return -1;
}
