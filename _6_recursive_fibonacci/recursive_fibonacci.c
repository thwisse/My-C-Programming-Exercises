/*	Recursive function ile hic bitmeyen bir fibonacci dizisi olustur.	*/

#include <stdio.h>
#include <stdlib.h>

// 1 2 3 4 5 6 7  8  9 10 11 ...
// 0 1 1 2 3 5 8 13 21 34 55 ...

//	fibo(11)= | fibo(10) + fibo(9)	// 9 ile 10. degerlerin toplami 11. degere esit. FONKSIYONU.

// 	fibo(x) = | fibo(x-1) + fibo(x-2)    x<1
//			  | x					  x=1 or x=0
//			  | -1					  else

int fibo(int i)
{
	if (i < 0)
		return -1;

	if (i == 0 || i == 1)
		return i;

	return fibo(i - 1) + fibo(i - 2);
}

int main()
{

	int j;

	for (j = 0; j <= 100; j++)
		printf("fibo(%d) = %d \n", j, fibo(j));
}
