/*	Banka atmsi yapin. Para cekme, para yatirma, bakiye goruntuleme gibi islemler yapilabilsin.
Para cekme ve yatirma limiti olsun. Sifreyle giris yapilsin.	*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>

int main(void){

    float cash=0.0, balance=1000.00, witLimit=2000.00, depLimit=5000.00;    // withdraw = cekme, deposit = yatirma
    char button1='i', button2;

    printf("\tMerhaba, thwisse Bankasi'na hosgeldiniz!\n\tLutfen kartinizi okutun.\n\n");
    sleep(1);
    printf("\tKartiniz algilandi. Menuye aktariliyorsunuz. Lutfen bekleyin.\n\n");
    sleep(2);

    while(button1=='i'){
        system("CLS");

        printf("\tBakiye sorgulama icin s, para cekme icin c, para yatirma icin y\n");
        printf("\n\tIslemlerden birini giriniz: ");
        scanf("%s", &button2);
    
        switch(button2){
            case 's':
                printf("\n\t\tBakiyeniz %.2f tl'dir.\n", balance); 
                break;
            case 'c':
                printf("\n\tHatirlatma: Tek seferde maksimum 2000.00 tl cekebilirsiniz.\n");
                printf("\n\tCekilecek miktari giriniz: ");
                scanf("%f", &cash);

                if(cash>witLimit){
                    printf("\tGirdiginiz miktar cekme limitinden fazla. Isleminiz gerceklesmedi.\n");
                    break;
                }
                else if(cash<=0){
                    printf("\tGirdiginiz miktarin gecerli bir degeri yok. Isleminiz gerceklesmedi.\n");
                    break;
                }
                else if(cash>balance){
                    printf("\n\tBakiyenizde o kadar para yok. Isleminiz gerceklesmedi.\n");
                    printf("\n\t\tBakiyeniz %.2f tl'dir.\n", balance);   
                    break;
                }
                else{
                    balance-= cash;
                    printf("\n\tIsleminiz basariyla gerceklesti.\n");
                    printf("\n\t\tBakiyeniz %.2f tl'dir.\n", balance); 
                    break;
                }
            case 'y':
                printf("\n\tHatirlatma: Tek seferde maksimum 5000.00 tl yatirabilirsiniz.\n");
                printf("\n\tYatirilacak miktari giriniz: ");
                scanf("%f", &cash);
            
                if(cash>depLimit){
                    printf("\tGirdiginiz miktar yatirma limitinden fazla. Isleminiz gerceklesmedi.\n");
                    break;
                }
                else if(cash<= 0){
                    printf("\tGirdiginiz miktarin gecerli bir degeri yok. Isleminiz gerceklesmedi.\n");
                    break;
                }
                else{
                    balance+= cash;
                    printf("\n\tIsleminiz basariyla gerceklesti.\n");
                    printf("\n\t\tBakiyeniz %.2f tl'dir.\n", balance); 
                    break;
                }
            case 'a':
                break;
            default:
                printf("\n\tGecersiz bir islem girdiniz! Lutfen tekrar deneyin.\n");
                break;
        }
        printf("\n\tYeniden islem yapmak icin i tusuna, ayrilmak icin farkli herhangi bir tusa basiniz: ");
        scanf("%s", &button1);
    }
    printf("\n\tthwisse Bankasi esenlikler diler. Hoscakalin!\n");

    getch();
}
