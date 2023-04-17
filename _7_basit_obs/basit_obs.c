/*	Basit bir ogrenci bilgi sistemi yarat.	*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct student // tum dugumler icin gecerli olacak yapi.
{
	int ID;
	char name[20];
	float gno;
	struct student *next;
} node;

node *getStudent() // normal fonksiyon tanimlarken void bilmemne yazardik
{				   // burda ise ustteki structi dondursun diye boyle yazdik
	node *new = (node *)malloc(sizeof(node));

	printf("Ogrencinin ID'sini giriniz: ");
	scanf("%d", &new->ID);

	fflush(stdin);

	printf("Ogrencinin adini giriniz: ");
	gets(new->name); // bu olay gets ve puts icinde de calisir.

	printf("Ogrencinin GNO'sunu giriniz: ");
	scanf("%f", &new->gno);

	return new; // onemli!
}

void menu()
{
	printf("\n-------------------------------------\n\n");
	printf("(1) Ogrenci bilgisi ekle\n");
	printf("(2) Ogrenci bilgisi sil\n");
	printf("(3) Ogrencileri listele\n");
	printf("(4) Cikis yap\n\n");
	printf("Yapmak istediginiz islemi giriniz: ");
}

void printStudent(node *new)
{
	printf("%d - %s - %.2f\n", new->ID, new->name, new->gno);
}

int main()
{
	int button;

	node *root = NULL;
	node *new, *temp, *prev;

	int deleteID;

	printf("-------------------------------------\n\n");
	printf("Ogrenci Bilgi Sistemine Hos Geldiniz!\n");

	do
	{
		menu();

		scanf("%d", &button);
		printf("\n");

		switch (button)
		{
		case 1: // ADD

			new = getStudent();

			if (root == NULL)
			{
				// head bossa liste bostur zaten. ilk dugumu head'e atayabiliriz
				root = new;
				new->next = NULL;

				printf("\nOgrenci bilgisi eklendi.\n");
			}
			else
			{
				temp = root; // yedek alindi
				prev = NULL; // daha sonrasi icin

				while (temp != NULL && (temp->ID) < (new->ID))
				{
					prev = temp; // prev ve temp bulduk
					temp = temp->next;
				}

				if (prev == NULL)
				{ // basa ekledik
					new->next = root;
					root = new;

					printf("\nOgrenci bilgisi eklendi.\n");
				}
				else
				{ // while'ın else'i
					prev->next = new;
					new->next = temp;

					printf("\nOgrenci bilgisi eklendi.\n");
				}
			}

			break;

		case 2: // DELETE

			printf("Silmek istediginiz ID'yi giriniz: ");
			scanf("%d", &deleteID);

			temp = root;
			prev = NULL;

			while (temp != NULL && (temp->ID) != deleteID)
			{
				prev = temp;
				temp = temp->next;
			}

			if (temp == NULL)
			{
				printf("\nAranan ID bulunamadi!\n");
			}
			else if (prev != NULL)
			{
				prev->next = temp->next;

				free(temp);

				printf("\nOgrenci bilgisi silindi.\n");
			}
			else
			{
				root = root->next;

				free(temp);

				printf("\nOgrenci bilgisi silindi.\n");
			}

			break;

		case 3: // LIST

			if (root == NULL)
			{
				printf("Henuz liste bos.\n");

				break;
			}

			temp = root;

			printf("\n---------- Ogrenci Listesi ----------\n");
			printf("------- ID ---- Isim ---- GNO -------\n\n");

			while (temp != NULL)
			{
				printStudent(temp);

				temp = temp->next;
			}

			printf("\n-------------------------------------\n");
			
			break;

		case 4: // EXIT

			printf("\nCikis yapildi.");
			
			break;

		default:

			printf("\nHatali giris!\n\n");
			
			break;
		}

	} while (button != 4);

	getch();
}