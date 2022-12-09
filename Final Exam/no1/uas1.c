int faktorial(int n);

int main(int argc, char *argv[]) {
	
	int n, hasil;
	
	printf("Masukkan Nilai : "); scanf("%d", &n);
	hasil = faktorial(n);
	printf("\nNilai Faktorial dari %d adalah %d", n, hasil);
	return 0;
}

int faktorial(int n) {
	int m;
	
	if(n==0) {
   		return 1;
  	}
  	m = n * faktorial(n-1);
	return m;
}
