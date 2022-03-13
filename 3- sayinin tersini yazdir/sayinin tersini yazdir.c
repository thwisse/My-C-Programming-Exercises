/*	Kullanicidan aldiginiz sayinin tersini ekrana yazdirin.	*/

#include <stdio.h>

int main(){
	
	int num, reverse;		// reverse = tersi
	
    	printf("Gireceginiz sayiyi ters cevirecek. Sayiyi girin: ");
    	scanf("%d", &num);
    	
    	if(num>9){
    		
    		printf("Sayinin tersten yazilmis hali: ");
    		
   			while(num>0){
		
				reverse= num % 10;	 // sayinin son basamagi tersi'ne esit olmus olacak.
			
      			printf("%d", reverse);
      		
      			num= num/10;		// sayi ondalikli ciksa bile sadece int kismini gosterecek. isleme oyle devam edecek sonucta.
    		}
   		}
    	else
	    	printf("Hatali bir giris yaptiniz. 0'dan buyuk, en az 2 bas. bir sayi giriniz.");	

	getch();
} 
    	
    /* Ornegin kullanici 1972 sayisi girdigi zaman olacak islemler soyledir:
    
	(1972 % 10 = 2) tersi = 2, (1972 / 10 = 197) sayi = 197			
	(197 % 10 = 7) tersi = 7, (197 / 10 = 19) sayi = 19
	(19 % 10 = 9) tersi = 9, (19 / 10 = 1) sayi = 1
	(1 % 10 = 1) tersi = 1, (1 / 10 = 0.1) sayi = 0.1  dongu sonlanir.
	*/
