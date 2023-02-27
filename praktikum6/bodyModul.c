#include "modul.h"
void entryData(alamatkota first, alamatkota newkota, int index) {
	String nama;
	nama = malloc(sizeof(char));

	printf("Masukkan nama kota : ");
	scanf(" %[^\n]s", nama);

	if (index == 0)
	{
		first->nama = nama;
		first->P = NULL;
		first->Q = NULL;
	}
	else {
		newkota->nama = nama;
		newkota->Q = NULL;
		newkota->P = NULL;

		alamatkota temp = first;
		while (temp->Q != NULL) {
			temp = temp->Q;
		}
		temp->Q = newkota;
	}
}

void entryDataWarga(alamatkota p, int indeks) {
	alamatkota ak = p;
	alamat w;
	alamat pend = (alamat)malloc(sizeof(penduduk));
	String nama = malloc(sizeof(String));

	for (int i = 0; i < indeks; i++) {
		ak = ak->Q;
	}
	
	printf("Masukkan nama penduduk : ");
	scanf(" %[^\n]s", nama);

	pend->nama = nama;
	pend->P = NULL;
	if (ak->P == NULL) {
		ak->P = pend;
	}
	else {
		w = ak->P;
		while (w->P != NULL) {
			w = w->P;
		}
		w->P = pend;
	}
}

void deleteKota(alamatkota p, int indexkota) {
	alamatkota ak1 = p, ak2 = p;
	alamat del1,del2;
	for (int i = 0; i < indexkota; i++) {
		ak2 = ak1;
		ak1 = ak1->Q;
	}
	ak2->Q = ak1->Q;
	del1 = ak1->P;
	ak1->P = NULL;
	ak1->Q = NULL;
	free(ak1);
	while (del1 != NULL) {
		del2 = del1;
		del1 = del1->P;
		del2->P = NULL;
		free(del2);
	}
}

void deleteWarga(alamatkota p, int kota, int warga) {
	alamat Q, O;
	alamatkota ak;
	int jumlah = 1;

	ak = p;
	for (int i = 0; i < kota; i++) {
		ak = ak->Q;
	}
	Q = ak->P;
	O = Q;
	for (int i = 0; i < warga; i++) {
		O = Q;
		Q = Q->P;
	}
	if (Q == ak->P) {
		ak->P = Q->P;
	}
	else {
		O->P = Q->P;
	}
	Q->P = NULL;
	free(Q);
}

void displayKota(alamatkota p) {
	alamatkota ak = p;
	printf("Print data : \n");
	int i = 1;
	while (ak != NULL) {
		printf("%d. %s\n", i, ak->nama);
		ak = ak->Q;
		i++;
	}
}

void displayAll(alamatkota p) {
	alamatkota ak = p;
	alamat a = ak->P;
	printf("Print data : \n");
	int i = 1, j;
	while (ak != NULL) {
		printf("%d. %s :\n", i, ak->nama);
		j = 1;
		a = ak->P;
		while (a != NULL) {
			printf("\t%d. %s\n", j, a->nama);
			a = a->P;
			j++;
		}
		ak = ak->Q;
		i++;
	}
}

int jumlahWarga(alamatkota p, int indekskota) {
	alamatkota ak;
	alamat a;
	int jumlah = 1;

	ak = p;
	for (int i = 0; i < indekskota; i++) {
		ak = ak->Q;
	}

	a = ak->P;
	while (a != NULL) {
		a = a->P;
		jumlah++;
	}

	return jumlah;
}
