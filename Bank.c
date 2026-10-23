#include <stdio.h>
#define PIN 123456
#define MAX 100

long long riwayat[MAX];
int jumlah_transaksi = 0;
void tampilanMenu(){
    printf("\n======= BANK =======\n");
    printf("1.Cek saldo\n");
    printf("2.Pemasukan\n");
    printf("3.Pengeluaran\n");
    printf("4.Keluar\n");
}
int ceksaldo(long long saldo_rek, long long tabungan_a){
    printf("======= Saldo =======\n");
    printf("Saldo Rekening anda: Rp %lld\n", saldo_rek);
    printf("Saldo Tabungan A anda: Rp %lld\n", tabungan_a);
    return 1;
    }

int pemasukan(long long *saldo_rek, long long *tabungan_a){
    int pilihan_tabungan;
    long long jumlah;
    printf("======= Pemasukan =======\n");
    printf("Masukkan nominal yang ingin ditambahkan: Rp. ");
    scanf("%lld",&jumlah);
    while (getchar() != '\n');
    if (jumlah < 1){
        printf("Masukkan nomminal > 0!");
    }else{
        printf("Pilih jenis tabungan:\n");
        printf("1. Tabungan Rekening\n");
        printf("2. Tabungan A\n");
        printf("silahkan pilih: ");
        scanf("%d", &pilihan_tabungan);
        while (getchar() != '\n');
        if (pilihan_tabungan == 1) {
            *saldo_rek += jumlah;
            printf("Saldo rekening anda berhasil ditambahkan!\n");
        } else if (pilihan_tabungan == 2) {
            *tabungan_a += jumlah;
            printf("Saldo tabungan anda berhasil ditambahkan!\n");
        } else {
            printf("Pilihan tidak valid!\n");
        }
        if (jumlah_transaksi < MAX) {
            riwayat[jumlah_transaksi] = jumlah;
            jumlah_transaksi++;
        }
        return 1;
    }
    }
int pengeluaran(long long *saldo_rek, long long *tabungan_a){
    int pilihan_tabungan;
    long long jumlah;
    printf("======= Pengeluaran =======\n");
    printf("Pilih jenis tabungan:\n");
    printf("1. Tabungan Rekening\n");
    printf("2. Tabungan A\n");
    printf("silahkan pilih: ");
    scanf("%d", &pilihan_tabungan);
    while (getchar() != '\n');

    printf("Masukkan nominal yang ingin dikurangkan: Rp.");
    scanf("%lld",&jumlah);
    while (getchar() != '\n');
    
    if (jumlah > *saldo_rek && jumlah > *tabungan_a){
        printf("Saldo tidak cukup!\n");
    }else{
        if (pilihan_tabungan == 1) {
            *saldo_rek -= jumlah;
        } else if (pilihan_tabungan == 2) {
            *tabungan_a -= jumlah;
        }
        if (jumlah_transaksi < MAX) {
            riwayat[jumlah_transaksi] = -jumlah;
            jumlah_transaksi++;
        }
        printf("Transaksi berhasil!\n");
        return 1;
    }
    }

int main()
{
   long long saldo_rek= 0;
   long long tabungan_a= 0;
   int pilih, pin_input, kesempatan;
   kesempatan= 3;
   
   while (kesempatan > 0){
       printf("Masukkan PIN Anda (6 digit): ");
       scanf("%d", &pin_input);
       while (getchar() != '\n');
       if (pin_input != PIN){
           kesempatan--;
           printf("PIN salah, masukkan dengan benar!\n");
       }else{
           printf("PIN benar, silahkan lanjutkan\n");
           break;
       }
   }
       if (kesempatan == 0){
           printf("Anda sudah mencapai limit untuk memasukkan sandi, silahkan coba lagi nanti!\n");
           return 0;
   }
   do {
       tampilanMenu();
       printf("Pilih menu: ");
       scanf("%d",&pilih);
       while (getchar() != '\n');
    
       switch (pilih){
        case 1:
        if (ceksaldo(saldo_rek, tabungan_a) == 0){
            pilih = 4;
        }
        break;
        case 2:
        if (pemasukan(&saldo_rek, &tabungan_a) == 0){
            pilih = 4;
        }
        break;
        case 3:
        if (pengeluaran(&saldo_rek, &tabungan_a) == 0){
            pilih = 4;
        }
        break;
        case 4:
        break;
        default:
        printf("Pilihan tidak valid\n");
    }
} while (pilih != 4);
printf("======= Riwayat Transaksi =======\n");
for (int i = 0; i < jumlah_transaksi; i++) {
    if (riwayat[i] > 0) {
        printf("%d. Pemasukan: %lld\n", i + 1, riwayat[i]);
    } else{
        printf("%d. Pengeluaran: %lld\n", i + 1, -riwayat[i]);
        printf("-------- Terimakasih! -------\n");
    }
}
    return 0;
}