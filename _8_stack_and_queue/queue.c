#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

///////////// Queue (Kuyruk)

// Struct
typedef struct n
{
    int data;
    struct n *next;
} node;

// Front (On) & Rear (Arka)
node *front = NULL;
node *rear = NULL;

// Enqueue (Eleman ekle)
int enqueue(int sayi)
{
    // Queue bossa
    if (front == NULL)
    {
        node *new = (node *)malloc(sizeof(node));
        new->data = sayi;
        new->next = NULL;

        front = rear = new;
    }
    // Queue bos degilse (yeni elemanı sona ekliyoruz hep)
    else
    {
        node *new = (node *)malloc(sizeof(node));
        new->data = sayi;
        new->next = NULL;

        rear->next = new;
        rear = new;
    }

    printf("Enqueue basarili.\n");
    return 1;
}

// Dequeue (Eleman cikar)
int dequeue()
{
    // Queue bossa
    if (front == NULL)
    {
        printf("Queue bos. Silme basarisiz.\n");
        return 1;
    }
    // Queue bos degilse
    else                    // bastan siliyoruz.
    {
        node *temp = front;
        front = front->next;    // basi degistir.
        free(temp);
    }

    printf("Dequeue basarili.\n");
    return 1;
}

// Listele
int display()
{
    // Queue bossa
    if (front == NULL)
    {
        printf("Queue bos. Listeleme basarisiz.\n");
        return 1;
    }
    else
    {
        node *iter = front;
        while (iter != NULL)
        {
            printf("%d\n", iter->data);
            iter = iter->next;
        }
        printf("'''\n");
        printf("Front: %d (gidici)\n", front->data);
        printf("Rear: %d (son eklenen)\n", rear->data);
    }

    printf("Listeleme basarili.\n");
    return 1;
}

void menu()
{
    printf("1-Enqueue\n");
    printf("2-Dequeue\n");
    printf("3-Display\n");
    printf("4-Cikis\n\n");
}

int main()
{
    menu();

    int secim, sayi;

    while (1)
    {
        printf("Secim girin: ");
        scanf("%d", &secim);

        switch (secim)
        {
        case 1:
            printf("Enqueue yapilacak sayiyi girin: ");
            scanf("%d", &sayi);
            enqueue(sayi);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            getch();
            return 1;
        default:
            printf("Hatali giris.\n");
            break;
        }
    }

    getch();
    return 1;
}