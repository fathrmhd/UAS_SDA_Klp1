#include "header.h"

//awal bagian person5 (melanie)
void tampilData() {

    struct Kampus *k = headKampus;

    while (k != NULL) {

        printf("\n=====================================\n");
        printf("KAMPUS : %s\n", k->nama);
        printf("=====================================\n");

        struct Jurusan *j = k->headerJurusan;

        while (j != NULL) {

            printf("\nJurusan : %s\n", j->nama);
            printf("Kuota   : %d\n", j->kuota);

            printf("--------------------------------------------------\n");
            printf("%-3s %-20s %-10s\n", "No", "Nama", "Rata-rata");
            printf("--------------------------------------------------\n");

            for (int i = 0; i < j->jumlahPeserta; i++) {

                printf("%-3d %-20s %-10.2f\n",
                    i + 1,
                    j->data_kursi[i].nama,
                    j->data_kursi[i].nilai.rataRata);
            }

            j = j->next;
        }

        k = k->next;
    }
}

void distribusiFrekuensi(struct Jurusan *j) {
    int freq[11] = {0};

    for (int i = 0; i < j->jumlahPeserta; i++) {

        int index = j->data_kursi[i].nilai.rataRata / 100;

        if (index > 10) {
            index = 10;
        }

        freq[index]++;
    }

    printf("\nDistribusi Frekuensi Nilai\n");
    printf("----------------------------------\n");

    for (int i = 0; i <= 10; i++) {

        int batasBawah = i * 100;
        int batasAtas = batasBawah + 99;

        printf("%3d - %3d : %d\n",
            batasBawah,
            batasAtas,
            freq[i]);
    }
}

void analisisDistribusiNilai(struct Jurusan *j) {
    int freq[11] = {0};

    for (int i = 0; i < j->jumlahPeserta; i++) {

        int index = j->data_kursi[i].nilai.rataRata / 100;

        if (index > 10) {
            index = 10;
        }

        freq[index]++;
    }

    printf("\nHistogram Distribusi Nilai\n");
    printf("====================================\n");

    for (int i = 0; i <= 10; i++) {

        int batasBawah = i * 100;
        int batasAtas = batasBawah + 99;

        printf("%3d - %3d : ",
            batasBawah,
            batasAtas);

        for (int jml = 0; jml < freq[i]; jml++) {
            printf("*");
        }

        printf(" (%d)\n", freq[i]);
    }
}
//akhir bagian person5 (melanie)