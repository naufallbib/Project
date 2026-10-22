#include <stdio.h>
#define PIN 123456

void tampilanMenu(){
    printf("\n======= BANK =======\n");
    printf("1.Cek saldo\n");
    printf("2.Pemasukan\n");
    printf("3.Pengeluaran\n");
    printf("4.Keluar\n");
}
int ceksaldo(long long saldo){
    int pilihan_lanjut;
    printf("Saldo rekening anda %lld\n", saldo);
    printf("1.Kembali ke menu utama\n");
    printf("2.Keluar\n");
    printf("silahkan pilih: ");
    scanf("%d", &pilihan_lanjut);
    while (getchar() != '\n');
    if (pilihan_lanjut== 2){
        return 0;
    }
    return 1;
}
int pemasukan(long long *saldo){
    int pilihan_lanjut;
    long long jumlah;
    printf("Masukkan nominal yang ingin ditambahkan: ");
    scanf("%lld",&jumlah);
    while (getchar() != '\n');
    if (jumlah < 1){
        printf("Masukkan nomminal > 0!");
    }else{
        *saldo += jumlah;
        printf("Saldo rekening anda berhasil ditambahkan!\n");
    }
    printf("1.Kembali ke menu utama\n");
    printf("2.Keluar\n");
    printf("silahkan pilih: ");
    scanf("%d", &pilihan_lanjut);
    while (getchar() != '\n');
    if (pilihan_lanjut== 2){
        return 0;
    }
    return 1;
}
int pengeluaran(long long *saldo){
    int pilihan_lanjut;
    long long jumlah;
    printf("Masukkan nominal yang ingin dikurangkan: ");
    scanf("%lld",&jumlah);
    while (getchar() != '\n');
    if (jumlah > *saldo){
        printf("Saldo tidak cukup!\n");
    }else{
        *saldo -= jumlah;
        printf("Transaksi berhasil!\n");
    }
    printf("1.Kembali ke menu utama\n");
    printf("2.Keluar\n");
    printf("silahkan pilih: ");
    scanf("%d", &pilihan_lanjut);
    while (getchar() != '\n');
    if (pilihan_lanjut== 2){
        return 0;
    }
    return 1;
}

int main()
{
   long long saldo= 0;
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
           printf("Anda sudah mencapai limit untuk memasukkan sandi!\n");
           return 0;
   }

    return 0;
}