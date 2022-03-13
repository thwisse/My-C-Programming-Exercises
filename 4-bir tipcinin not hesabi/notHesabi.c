#include <stdio.h>

int main(){
    
    float k1,k2,k3,k4,k5,k6;
    int n1,n2,n3,n4,n5,n6,fin;
    float komiteOrt,yilSonuOrt,fin2;

    printf("Kaan Hatipoglu icin hazirlanan not hesaplama sihirbazina hosgeldiniz!\n\n");
    
    printf("Komite 1 icin not girin: ");
    scanf("%d", &n1);

    k1=n1*18.64/100;

    printf("Komite 2 icin not girin: ");
    scanf("%d", &n2);

    k2=n2*15.68/100;

    printf("Komite 3 icin not girin: ");
    scanf("%d", &n3);

    k3=n3*12.5/100;

    printf("Komite 4 icin not girin: ");
    scanf("%d", &n4);

    k4=n4*19.21/100;

    printf("Komite 5 icin not girin: ");
    scanf("%d", &n5);

    k5=n5*19.77/100;

    printf("Komite 6 icin not girin: ");
    scanf("%d", &n6);

    k6=n6*14.2/100;

    komiteOrt=k1+k2+k3+k4+k5+k6;
    
    printf("\nKomite agirlikli ortalaman: %.2f\n", komiteOrt);

    if(komiteOrt>=75){
        
        if(n1>=60 && n2>=60 && n3>=60 && n4>=60 && n5>=60 && n6>=60){
            printf("\nKomite ortalaman >=75 oldugu icin direkt: Gectin\n\n");
            printf("Finale girmene gerek kalmadi! Hem komiteleri hem finali hallettin.\n");
            printf("Yil sonu ortalaman: %.2f\n", komiteOrt);
        }
        else{
            printf("\nKomite ortalaman >=75 ancak herhangi bir komiten <60 old. icin: Finale girmen sart.\n\n");

            fin2=(600-komiteOrt*6)/4;

            printf("Yil sonu ortalaman >=60 olmasi icin finalden alman gereken minimum not: %.2f\n", fin2);
            printf("Eger min. not <50 ciktiysa unutma, bu teoride boyle. Final icin >=50 sarti hala gecerli.\n\n");

            printf("Final icin not girin: ");
            scanf("%d", &fin);
        
            if(fin>=50){
                fin=fin*40/100;
                komiteOrt=komiteOrt*60/100;
                yilSonuOrt=fin+komiteOrt;

                if(yilSonuOrt>=60){
                    printf("\nFinali hallettin ve yil sonu ortalaman da 60'in ustunde oldugu icin: Gectin\n\n");
                    printf("Yil sonu ortalaman: %.2f\n", yilSonuOrt);
                }
                else{
                    printf("\nFinali hallettin ancak yil sonu ortalaman dusuk oldugu icin: Kaldin\n\n");
                    printf("Yil sonu ortalaman: %.2f\n", yilSonuOrt);
                }
            }
            else{
                fin=fin*40/100;
                komiteOrt=komiteOrt*60/100;
                yilSonuOrt=fin+komiteOrt;

                printf("\nFinal notun <50 old icin finali halledemedin ve: Kaldin.\n\n");
                printf("Yil sonu ortalaman: %.2f\n", yilSonuOrt);
            }
        }
    }
    else{
            printf("\nKomite ortalaman <75 old. icin direkt gecemedin, finale girmen sart.\n\n");
            
            fin2=(600-komiteOrt*6)/4;

            printf("Yil sonu ortalaman >=60 olmasi icin finalden alman gereken minimum not: %.2f\n", fin2);
            printf("Eger min. not <50 ciktiysa unutma, bu teoride boyle. Final icin >=50 sarti hala gecerli.\n\n");

            printf("Final icin not girin: ");
            scanf("%d", &fin);

            if(fin>=50){
                fin=fin*40/100;
                komiteOrt=komiteOrt*60/100;
                yilSonuOrt=fin+komiteOrt;

                if(yilSonuOrt>=60){
                    printf("\nFinali hallettin ve yil sonu ortalaman da 60'in ustunde oldugu icin: Gectin\n\n");
                    printf("Yil sonu ortalaman: %.2f\n", yilSonuOrt);
                }
                else{
                    printf("\nFinali hallettin ancak yil sonu ortalaman dusuk oldugu icin: Kaldin\n\n");
                    printf("Yil sonu ortalaman: %.2f\n", yilSonuOrt);
                }
            }
            else{
                fin=fin*40/100;
                komiteOrt=komiteOrt*60/100;
                yilSonuOrt=fin+komiteOrt;

                printf("\nFinal notun <50 old icin finali halledemedin ve: Kaldin.\n\n");
                printf("Yil sonu ortalaman: %.2f\n", yilSonuOrt);
            } 
    } 

    printf("\n\nCikmak icin bir tusa basin.\n"); 
    getch();
}