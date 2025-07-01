#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu();
void depo();
void withdraw();
void tranfer();
void accdetail();
void trdetails();
void divider();

char nama[50];
int rek,pilih;
int dip_amt,wd_amt,tf_amt;
int amt=10000;
int count =0;


void divider(){
    for (int i = 0; i < 30; i++)
    {
        printf("-");
    }
}

int main(){

    printf("WELCOME TO AMBABANK\n");
    divider();

    printf("\nMasukan Nama anda: ");
    gets(nama);

    printf("Masuka nomer rekening anda: ");
    scanf("%d", &rek);getchar;

    system("pause");

    menu();

    return 0;
}


void menu(){

    system("cls");

    printf("MAIN MENU\n");
    divider();

    printf("\n1.Deposit Money\n");
    printf("2.Withdraw Money\n");
    printf("3.Transfer Money\n");
    printf("4.Account Details\n");
    printf("5.Transaction Details\n");
    printf("6.Exit\n");
    printf("7.Stop program\n");
    printf("Pilih: ");
    scanf("%d", &pilih);

    switch (pilih)
    {
        case 1:
            depo();
        break;

        case 2:
            withdraw();
        break;

        case 3:
            tranfer();
        break;

        case 4:
            accdetail();
        break;

        case 5:
            trdetails();
        break;

        case 6:
            menu();
        break;

        default:
            ;
        break;
    }

}


void depo(){

    system("cls");
    time_t tm;
    time(&tm);


    FILE *ptr = fopen("Account.txt", "a");

    printf("DEPOSIT MONEY\n");
    divider();

    printf("\nMasukan jumlah uang: ");
    scanf("%d", &dip_amt);

    amt += dip_amt;

    printf("Money Deposited\n");

    fprintf(ptr,"Rp%d Sudah masuk kedalam rekeningmu \n", dip_amt);
    fprintf(ptr, "Waktu transaksi %s\n", ctime(&tm));

    printf("Saldo tersisa: %d\n", amt);
    count++;

    system("pause");
    menu();

}


void withdraw(){

    system("cls");

    time_t tm;
    time(&tm);

    FILE *ptr = fopen("Account.txt", "a");

    printf("\nWITHDRAW MENU\n");
    divider();

    printf("\nJumlah yang diingkan: ");
    scanf("%d", &wd_amt);

    amt -= wd_amt;

    fprintf(ptr,"Rp%d Sudah dikurangi dari rekeningmu \n", wd_amt);
    fprintf(ptr, "Waktu transaksi %s\n", ctime(&tm));

    printf("Saldo tersisa: %d\n", amt);
    count++;

    system("pause");
    menu();
}


void tranfer(){
    int id;

    system("cls");

    time_t tm;
    time(&tm);

    FILE *ptr = fopen("Account.txt", "a");

    printf("TRANSFERING MONEY\n");
    divider();

    printf("\nMasukan jumlah uang yang ingin di transfer: ");
    scanf("%d", &tf_amt);

    printf("Masukan No Rekening yang ingin di transfer: ");
    scanf("%d", &id);

    if (amt < tf_amt)
    {
        printf("Saldo anda tidak mencukupi\n");
    }else
    {
        printf("Transfer Berhasil\n");
        amt -= tf_amt;
        count++;

        fprintf(ptr,"Rp%d Sudah di transfer dari rekeningmu \n", tf_amt);
        fprintf(ptr, "Waktu transaksi %s\n", ctime(&tm));
    }

    fclose(ptr);
    
    system("pause");
    menu();
}


void accdetail(){

    system("cls");

    printf("\nACCOUNT INFORMATION\n");

    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }
    printf("\n%d Transaksi dalam akun anda\n", count);
    printf("Nama akun: %s\n", nama);
    printf("Nomor rekening: %d\n", rek);
    printf("Total saldo: %d\n", amt);

    system("pause");
    menu();
}


void trdetails(){

    system("cls");

    FILE *ptr;
    ptr = fopen("Account.txt", "r");

    char c = fgetc(ptr);

    printf("DETAIL TRANSACTION\n");
    printf("------------------------------\n");

    if (c == EOF)
    {
        printf("\nData tidak ditemukan\n");
        system("pause");
        menu();
    }else
    {

        while (c != EOF)
        {
            printf("%c", c);

            c = fgetc(ptr);
        }

        system("pause");
        menu();   
    }
}