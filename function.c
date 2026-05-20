#include "header.h"

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

}

void analisisDistribusiNilai(struct Jurusan *j) {

}