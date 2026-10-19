#include <stdio.h>
#include <string.h>
int main()
{
    char pin [7]= "123456";
    printf("===================\n        Bank  \n===================\nSelamat datang user\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Masukkan PIN Anda: ");
        scanf("%6s", pin);
         if (strcmp(pin, "123456") == 0){
           printf("====================\n        Menu  \n===================\n1. tabungan\n2. Cek saldo\n3. Pemasukan\n4. Pengeluaran");
            break;
        }
        else
        {
            printf("PIN salah, silahkan coba lagi\n");
        }
    }    
    return 0;
}