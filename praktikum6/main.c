#include "modul.h"

int main() {
	alamatkota first = (alamatkota)malloc(sizeof(kota));
	alamatkota ak;
	alamat a;
	char loop = 'y';
	int opsi;
	int pilihkota;
	int pilihpenduduk;
	int i = 0;

	/*first->nama = "bandung";
	first->P = NULL;
	first->Q = NULL;*/

	while (loop == 'y') {
		printf("1. Tambah Kota\n");
		printf("2. Tambah Penduduk\n");
		printf("3. Hapus Kota\n");
		printf("4. Hapus Penduduk\n");
		printf("5. Menampilkan Semua Data\n");
		printf("Pilih opsi : ");
		if (scanf("%d", &opsi) != 1)
		{
			scanf(" %c", &loop);
			puts("Input hanya berupa integer.");
		}
		else {
			switch (opsi)
			{
			case 1:
				ak = (alamatkota)malloc(sizeof(kota));
				entryData(first ,ak, i);
				i++;
				break;
			case 2:
				displayKota(first);
				printf("Pilih kota yang ingin ditambahkan penduduk : ");
				scanf("%d", &pilihkota);
				if (pilihkota - 1 < i && pilihkota > 0)
				{
					entryDataWarga(first, pilihkota-1);
				}
				else {
					puts("Pilihan kota tidak ada");
				}
				break;
			case 3:
				displayKota(first);
				printf("Pilih kota yang ingin dihapus : ");
				scanf("%d", &pilihkota);
				if (pilihkota - 1 < i && pilihkota > 0)
				{
					if (pilihkota == 1) {
						alamatkota del = (alamatkota)malloc(sizeof(kota));
						del = first;
						first = first->Q;
						deleteKota(del, pilihkota - 1);
					}
					else
					{
						deleteKota(first, pilihkota - 1);
					}
					i--;
				}
				else {
					puts("Pilihan kota tidak ada");
				}
				break;
			case 4:
				displayAll(first);
				printf("Pilih kota yang ingin penduduknya diusir : ");
				scanf("%d", &pilihkota);
				if (pilihkota - 1 < i && pilihkota > 0)
				{
					printf("Pilih penduduk yang ingin diusir : ");
					scanf("%d", &pilihpenduduk);
					if (pilihpenduduk < jumlahWarga(first, pilihkota-1) && pilihpenduduk > 0)
					{
						deleteWarga(first, pilihkota - 1,pilihpenduduk-1);
					}
					else {
						puts("Penduduk lain diditu");
					}

				}
				else {
					puts("Pilihan kota tidak ada");
				}
				break;
			case 5:
				if (i == 0)
				{
					printf("Data kosong.\n");
				}
				else {
					displayAll(first);
				}

				break;
			default:printf("Input Salah\n");
				break;
			}
		}

		printf("Masih ingin melanjutkan program ? ");
		scanf(" %c", &loop);
		system("cls");
	}
}