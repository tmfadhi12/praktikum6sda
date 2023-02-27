#ifndef modul_h
#define modul_h
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

typedef const char* String;

typedef struct penduduk* alamat;
typedef struct kota* alamatkota;

typedef struct kota {
	String nama;
	alamatkota Q;
	alamat P;
} kota;

typedef struct penduduk {
	String nama;
	alamat P;
} penduduk;


void entryData(alamatkota p, alamatkota q, int index );

void entryDataWarga(alamatkota p, int indeks);

void deleteKota(alamatkota p, int indexkota);

void deleteWarga(alamatkota p, int kota, int warga);

void displayKota(alamatkota p);

void displayAll(alamatkota p);

int jumlahWarga(alamatkota p, int indekskota);

#endif // !modul_h


