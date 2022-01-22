/*	Vize notunu ve yuzdesini kullanicidan alin. Sonra bunlari, ortalamanin 60 olmasi yani gecmek icin 
finalden minimum kac almasi gerekli bunun kodunu yazin.	*/

#include <stdio.h>
#include <locale.h>

int main(){
	
	int vizeNotu, vizeYuzdesi;
	int finalNotu;
	int canDegeri=60;
	
	printf("Lutfen sirasiyla vize notunuzu ve vize yuzdenizi giriniz: ");
	scanf("%d%d", &vizeNotu, &vizeYuzdesi);
	
	printf("\nVize notunuz: %d (yuzdesi: %d)\n", vizeNotu, vizeYuzdesi);
	
	finalNotu = ((canDegeri*100 - vizeNotu*40)/60);
	
	printf("Gecmek icin finalden minimum almaniz gereken not: %d", finalNotu);
	
	getch();
}