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

int main()
{
    
    return 0;
}