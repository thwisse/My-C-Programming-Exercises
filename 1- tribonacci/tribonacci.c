/*	Ilk uc degeri 1 olan ve bir sonra gelecek her degerin onceki uc degerin toplamindan olustugu
tribonacci sayilarini koda dokun. Son sayiyi kullanicidan alin ve fonksiyon kullanarak calistirin.	*/

#include <stdio.h>

int tribonacci(int N){
	
	int i, first=1, middle=1, last=1, total=0;
	
	printf(" 1st value: %d\n", first);
	printf(" 2nd value: %d\n", middle);
	printf(" 3rd value: %d\n", last);
	
	// first middle last   total                                   1 1 1 3 5 9 17 31 ....
	//       first  middle last  total ...
	
	for(i=4;i<=N;i++){
		
		total=first+middle+last;    // total= 		3	5	9	.
		
		printf("%2dth value: %d\n", i, total);
		
		first=middle;               // first= 		1	1	.
		middle=last;                // middle=  	1	3	.
		last=total;                 // last= 		3	5	.		
	}
}

int main(){
	
	int N;
	
	printf("Kacinci sayiya kadar tribonacci hesaplanacak?: ");
	scanf("%d", &N);
	
	tribonacci(N);

	getch();
}