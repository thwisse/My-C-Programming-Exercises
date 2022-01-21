/*	Tavla oynayacaksiniz ama zarlar kayip diyelim.
Sana 1-6 arasinda rastgele iki sayi veren kodu yaz.	*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	int a=0, dice1, dice2, button;            // dice: zar
	
	srand(time(NULL));

	while(a==0){
		
		printf("\tZarlari at:");
		scanf("%d", &button); 
		
		if(button==0){                       // 0a bastikca devamli zarlari atacak.
			
			dice1= rand() % 6 + 1;
			dice2= rand() % 6 + 1;
			
			printf("\n\t\tDice 1= %d\t Dice 2= %d\n\n", dice1, dice2);
		}
		else
			printf("\n\tZarlari atmak icin 0'a basmalisin!\n\n");
	}

	getch();
}