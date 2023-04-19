#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//////////// Stack (Yigin)

// Struct
typedef struct n
{
    int data;
    struct n *next;
} node;

// Top (En ustteki eleman)
node *top = NULL;

// Push (Eleman ekle)
int push(int sayi)
{
    // Stack bossa
    if (top == NULL)
    {
        node *new = (node *)malloc(sizeof(node));
        new->data = sayi;
        new->next = NULL; // null'u goster

        top = new;
    }
    // Stack bos degilse (yeni elemani basa ekliyoruz hep)
    else
    {
        node *new = (node *)malloc(sizeof(node));
        new->data = sayi;
        new->next = top;    // bir sonrakini goster

        top = new;
    }

    printf("Push islemi basarili.\n");
    return 1;
}

// Pop (Eleman sil) 
int pop()
{
    // Stack bossa
    if (top == NULL)
    {
        printf("Stack bos. Pop islemi basarisiz.\n");
        return 1;
    }
    // Stack bos degilse    (bastan siliyoruz)
    else
    {
        node *temp = top;
        top = top->next;
        free(temp);
    }

    printf("Pop islemi basarili.\n");
    return 1;
}

// Display (Listele)
int display()
{
    // Stack bossa
    if (top == NULL)
    {
        printf("Stack bos. Display islemi basarisiz.\n");
        return 1;
    }
    // Stack bos degilse
    else
    {
        node *iter = top;    // iter (gezgin) yarat
        while (iter != NULL) // sona kadar git
        {
            printf("%d\n", iter->data);
            iter = iter->next; // ilerle
        }
        printf("'''\n");
        printf("Top: %d (son eklenen & gidici)\n\n", top->data);
    }

    printf("Display islemi basarili.\n");
    return 1;
}

void menu()
{
    printf("1- Push (Ekle)\n");
    printf("2- Pop (Sil)\n");
    printf("3- Display (Listele)\n");
    printf("4- Cikis\n\n");
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
            printf("Push edilecek sayiyi girin: ");
            scanf("%d", &sayi);
            push(sayi);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            getch();
            return 1;
        default:
            printf("Hatali giris. Tekrar deneyin.\n");
            break;
        }
    }

    getch();
    return 1;
}