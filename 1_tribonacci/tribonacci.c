/*	Ilk uc degeri 1 olan ve bir sonra gelecek her degerin 
onceki uc degerin toplamindan olustugu
tribonacci sayilarini koda dokun. Son sayiyi kullanicidan 
alin ve fonksiyon kullanarak calistirin.	*/

#include <stdio.h>
#include <conio.h>

int tribonacci(int N){
	
	int i, first=1, middle=1, last=1, total=0;
	
	printf("Value  1: %d\n", first);
	printf("Value  2: %d\n", middle);
	printf("Value  3: %d\n", last); 
	
	// first middle last   total         1 1 1 3 5 9 17 31 ....
	//       first  middle last  total ...
	
	for(i=4; i<=N; i++){		
		// algoritmayla gelecek olan "dogal" sayi 4 tur. 
		// bu yuzden i'yi 4 le baslattik.
		
		total= first+middle+last;    // total= 		3	5	9	.
		
		printf("Value %2d: %d\n", i, total);
		
		first= middle;               // first= 		1	1	.
		middle= last;                // middle=  	1	3	.
		last= total;                 // last= 		3	5	.		
	}
} 

int main(){
	
	int N;
	
	printf("Kac deger tribonacci hesaplanacak?: ");
	scanf("%d", &N);
	
	tribonacci(N);

	getch();
}
