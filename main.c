#include <stdio.h>
#include <stdlib.h>
int aracDizi[10][4];
int UcretDizi[10];
int main()
{
    int islemNo,aracTipi,plaka,girisSaat,cikisSaat;
    int i=0;
    do
    {
        printf("\n\n*************MENU*************\n\n");
        printf("Aracinizi Eklemek Icin --->1'e Basiniz\n");
        printf("Arac tipleri: \n");
        printf("Kisisel tasiti secmek icin 1'e\n ");
        printf("Buyuk tasiti secmek icin 2'ye\n ");
        printf("Agir Vasita tasiti secmek icin 3'e basiniz\n");
        printf("Araclari Listelemek Icin --->2'ye Basiniz\n");
        printf("Otopark Ucreti Icin---> 3'e Basiniz\n");
        printf("Maksimum Ve Minimum Ucreti Ogrenmek Icin--->4'e Basiniz\n");
        printf("Cikis Icin--->5'e Basiniz\n");
        printf("Islem No Seciniz : \t");
        scanf("%d",&islemNo);
        printf("\n\n**********GIRIS BILGILERI********** \n \n");
       if(islemNo == 1)
    {
        if(i > 10)
        {
            printf("\nOtopark kapasitesi dolmustur...");
        }
        else
        {
        do
      {
        printf(" Tipini Seciniz : \t");
        scanf("%d", &aracTipi);

        if(aracTipi == 1)
            {
                aracDizi[i][0] = aracTipi;
                printf("Kisisel Tasit Tipini Sectiniz...\n");
                break;
            }
        else if(aracTipi == 2)
            {
                 aracDizi[i][0] = aracTipi;
                printf("Buyuk Tasit Tipini Sectiniz... \n");
                 break;
            }
        else if(aracTipi == 3)
            {
                 aracDizi[i][0] = aracTipi;
                printf("Agir Vasita Tasit Tipini Sectiniz... \n");
                 break;
            }
        else
            {
                printf("Arac Tipini Yanlis Girdiniz...\n");
            }
        }
        while(aracTipi < 1 || aracTipi > 3);

        printf("\nPlaka Giriniz : \t");
        scanf("%d", &plaka);
        aracDizi[i][1] = plaka;
        printf("Giris Saatini Giriniz : \t");
        scanf("%d", &girisSaat);
        aracDizi[i][2] = girisSaat;
        printf("Cikis Saatini Giriniz : \t");
        scanf("%d", &cikisSaat);
        aracDizi[i][3] = cikisSaat;
        UcretHesapla(aracDizi,plaka);
        printf("\nArac bilgileriniz basariyla kaydedildi...\n");
        i++;
        }
    }
    else if(islemNo == 2)
    {
        AracListele();
    }

     else if(islemNo == 3)
     {
         int plaka_no = 0;
         printf("\nLutfen ucretini gormek istediginiz aracin plakasini giriniz \t");
         scanf("%d", &plaka_no);
         printf("\nOdenecek tutar : %d ," , UcretHesapla(aracDizi,plaka_no));
     }
     else if(islemNo == 4)
     {
        printf("\nMinimum ucret : %d", MinUcretBul(UcretDizi));
         printf("\nMaksimum ucret : %d", MaksUcretBul(UcretDizi));
     }
     else if(islemNo == 5)
        break;
     else
        printf("\nYanlis bir islem no sectiniz..");
    }while(islemNo!=5);
    return 0;
}
int MaksUcretBul(int UcretDizi[])
{
    int i = 0 , j = 0;
    int gecici = 0;
    int maksimum = 0;
    for(i=0; i<10;i++){
        for(j=0; j<i; j++){
            if(UcretDizi[i] < UcretDizi[j]){
                gecici = UcretDizi[i];
                UcretDizi[i] = UcretDizi[j];
                UcretDizi[j] = gecici;
            }
        }

    maksimum = UcretDizi[i];
    }
    return maksimum;
}
int MinUcretBul(int UcretDizi[])
{
    int i = 0 , j = 0;
    int gecici = 0;
    int minimum = 0;
    for(i=0; i<10;i++)
    {   for(j=0; j<i; j++)
        {
            if(UcretDizi[i] > UcretDizi[j])
            {
                gecici = UcretDizi[i];
                UcretDizi[i] = UcretDizi[j];
                UcretDizi[j] = gecici;
            }
        }
        if(UcretDizi[i] != 0)
        {

        minimum = UcretDizi[i];
        }
    }
    return minimum;

}

int UcretHesapla(int arabadizi[], int plaka)
{
int giris_ucret = 5;
int ek_ucret;
int ucret;
int i = 0;
int k = 0;
for(i =0; i<10; i++)
{
     if(aracDizi[i][1] == plaka)
     {
         k = 1;
         if(aracDizi[i][0] == 1)
         {
             ek_ucret = aracDizi[i][3] - aracDizi[i][2];
        }
        else if(aracDizi[i][0] == 2)
         {
             ek_ucret = (aracDizi[i][3] - aracDizi[i][2])*2;
        }
        else  if(aracDizi[i][0] == 3)
         {
             ek_ucret = (aracDizi[i][3] - aracDizi[i][2])*3;
        }
        ucret = giris_ucret + ek_ucret ;
        UcretDizi[i]=ucret;
     }
}
if(k == 0)
{
    printf("\nAranan plakaya sahip arac bulunamadi...");
}
return ucret;
}
void  AracListele()
{
  int i = 0;
  int  k= 0;
  for(i =0; i<10; i++)
 {
     if(aracDizi[i][0] != 0)
     {
        printf("%d. Aracin tipi : %d \n", i+1, aracDizi[i][0]);
        printf("%d. Aracin plakasi : %d \n", i+1, aracDizi[i][1]);
        printf("%d. Aracin giris saati: %d \n", i+1, aracDizi[i][2]);
        printf("%d. Aracin cikis saati : %d \n", i+1, aracDizi[i][3]);
     }
 }
}
