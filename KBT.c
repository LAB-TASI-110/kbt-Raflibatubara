#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Untuk exit()

#define MAX_STRING_LENGTH 100
#define MAX_DESTINATIONS 5

// Struktur untuk menyimpan data tujuan dan harganya
typedef struct {
    char nama[MAX_STRING_LENGTH];
    int harga_executive;
    int harga_ekonomi;
} Destinasi;

// Daftar tujuan dari Siborong-borong
Destinasi daftar_destinasi[MAX_DESTINATIONS] = {
    {"Medan", 150000, 95000},
    {"Berastagi", 170000, 110000},
    {"Pekanbaru", 300000, 200000},
    {"Padang", 250000, 160000},
    {"Jambi", 350000, 230000}
};

int jumlah_destinasi = 5; // Jumlah destinasi yang tersedia

// Fungsi untuk menampilkan menu jenis mobil
void tampilkanJenisMobil() {
    printf("\nPilih Jenis Mobil:\n");
    printf("1. KBT Executive\n");
    printf("2. KBT Ekonomi\n");
    printf("Pilihan Anda (1/2): ");
}

// Fungsi untuk menampilkan daftar tujuan
void tampilkanDestinasi() {
    printf("\nPilih Tujuan Pemberangkatan dari Siborong-borong:\n");
    for (int i = 0; i < jumlah_destinasi; i++) {
        printf("%d. %s (Executive: Rp %d, Ekonomi: Rp %d)\n",
               i + 1, daftar_destinasi[i].nama,
               daftar_destinasi[i].harga_executive,
               daftar_destinasi[i].harga_ekonomi);
    }
    printf("Pilihan Anda: ");
}

// Fungsi untuk mendapatkan harga berdasarkan jenis mobil dan tujuan
int dapatkanHarga(int jenis_mobil_pilihan, int destinasi_pilihan_idx) {
    if (destinasi_pilihan_idx >= 0 && destinasi_pilihan_idx < jumlah_destinasi) {
        if (jenis_mobil_pilihan == 1) { // Executive
            return daftar_destinasi[destinasi_pilihan_idx].harga_executive;
        } else if (jenis_mobil_pilihan == 2) { // Ekonomi
            return daftar_destinasi[destinasi_pilihan_idx].harga_ekonomi;
        }
    }
    return 0; // Invalid choice
}

// Fungsi utama program
int main() {
    char nama_pemesan[MAX_STRING_LENGTH];
    char no_whatsapp[MAX_STRING_LENGTH];
    char no_mobil[MAX_STRING_LENGTH];
    int jenis_mobil_pilihan;
    char jenis_mobil_str[MAX_STRING_LENGTH];
    int destinasi_pilihan_idx;
    char tanggal_pemesanan[MAX_STRING_LENGTH];
    char no_bangku[MAX_STRING_LENGTH];
    char jam_berangkat[MAX_STRING_LENGTH];
    char metode_pembayaran[MAX_STRING_LENGTH];
    int harga_tiket;

    printf("=============================================\n");
    printf("     Sistem Ticketing Koperasi Bintang Tapanuli (KBT)\n");
    printf("           Pusat Loket: Siborong-borong\n");
    printf("=============================================\n\n");

    printf("Masukkan Nama Pemesan: ");
    fgets(nama_pemesan, MAX_STRING_LENGTH, stdin);
    nama_pemesan[strcspn(nama_pemesan, "\n")] = 0; // Hapus newline

    printf("Masukkan No WhatsApp: ");
    fgets(no_whatsapp, MAX_STRING_LENGTH, stdin);
    no_whatsapp[strcspn(no_whatsapp, "\n")] = 0;

    printf("Masukkan No Mobil: ");
    fgets(no_mobil, MAX_STRING_LENGTH, stdin);
    no_mobil[strcspn(no_mobil, "\n")] = 0;

    // Pilih Tujuan
    tampilkanDestinasi();
    scanf("%d", &destinasi_pilihan_idx);
    while (getchar() != '\n'); // Membersihkan buffer input
    destinasi_pilihan_idx--; // Konversi ke indeks array (0-based)

    if (destinasi_pilihan_idx < 0 || destinasi_pilihan_idx >= jumlah_destinasi) {
        printf("Pilihan tujuan tidak valid. Program berakhir.\n");
        return 1;
    }

    // Pilih Jenis Mobil
    tampilkanJenisMobil();
    scanf("%d", &jenis_mobil_pilihan);
    while (getchar() != '\n'); // Membersihkan buffer input

    harga_tiket = dapatkanHarga(jenis_mobil_pilihan, destinasi_pilihan_idx);

    if (harga_tiket == 0) {
        printf("Pilihan jenis mobil tidak valid. Program berakhir.\n");
        return 1;
    }

    if (jenis_mobil_pilihan == 1) {
        strcpy(jenis_mobil_str, "KBT Executive");
    } else if (jenis_mobil_pilihan == 2) {
        strcpy(jenis_mobil_str, "KBT Ekonomi");
    } else {
        printf("Pilihan jenis mobil tidak valid. Program berakhir.\n");
        return 1;
    }

    printf("Masukkan Tanggal Pemesanan (DD-MM-YYYY): ");
    fgets(tanggal_pemesanan, MAX_STRING_LENGTH, stdin);
    tanggal_pemesanan[strcspn(tanggal_pemesanan, "\n")] = 0;

    printf("Masukkan No Bangku: ");
    fgets(no_bangku, MAX_STRING_LENGTH, stdin);
    no_bangku[strcspn(no_bangku, "\n")] = 0;

    printf("Masukkan Jam Berangkat (HH:MM): ");
    fgets(jam_berangkat, MAX_STRING_LENGTH, stdin);
    jam_berangkat[strcspn(jam_berangkat, "\n")] = 0;

    printf("Pilih Metode Pembayaran (QRIS/CASH): ");
    fgets(metode_pembayaran, MAX_STRING_LENGTH, stdin);
    metode_pembayaran[strcspn(metode_pembayaran, "\n")] = 0;

    printf("\n=============================================\n");
    printf("            DETAIL PEMESANAN TIKET\n");
    printf("=============================================\n");
    printf("Nama Pemesan     : %s\n", nama_pemesan);
    printf("No WhatsApp      : %s\n", no_whatsapp);
    printf("No Mobil         : %s\n", no_mobil);
    printf("Jenis Mobil      : %s\n", jenis_mobil_str);
    printf("Tujuan           : Siborong-borong ke %s\n", daftar_destinasi[destinasi_pilihan_idx].nama);
    printf("Tanggal Pesan    : %s\n", tanggal_pemesanan);
    printf("No Bangku        : %s\n", no_bangku);
    printf("Jam Berangkat    : %s\n", jam_berangkat);
    printf("Harga Tiket      : Rp %d\n", harga_tiket);
    printf("Metode Pembayaran: %s\n", metode_pembayaran);
    printf("============================================================================================================================================================================================================================================================\n");
    printf("Terima kasih telah melakukan pemesanan di KBT. Kami sangat menghargai kepercayaan Anda dalam menggunakan layanan Koperasi Bintang Tapanuli. Semoga perjalanan Anda menyenangkan dan kami berharap dapat melayani Anda kembali di kesempatan berikutnya.\n");
    printf("============================================================================================================================================================================================================================================================\n");

    return 0;
}
