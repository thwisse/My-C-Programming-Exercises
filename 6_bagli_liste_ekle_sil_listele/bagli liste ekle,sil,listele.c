/*   Bagli liste icin struct olustur. Ekleme, silme, listeleme
 fonksiyonlarini yaz.   */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct n{

    int x;
    struct n * next;

} node;

// add to the end: sona ekle
node * add_to_the_end(node * root, int data){

    while(root->next != NULL){
        root= root->next;
    }

    node * temp= (node *)malloc(sizeof(node));
    root->next= temp;
    temp->x= data;
    temp->next= NULL;
}

// add by sorting: sıralayrak ekle
node * add_by_sorting(node * root, int data){   // data = id

    // 1
    if(root == NULL){

        root= (node *)malloc(sizeof(node));
        root->next= NULL;
        root->x= data;

        return root;
    }

    // 2
    if(data < root->x){

        node * temp= (node *)malloc(sizeof(node));
        temp->next= root;
        temp->x= data;

        return temp; 
    }

    // 3
    node * iter= root;

    while(iter->next != NULL && data > iter->next->x)
        iter= iter->next;

    node * temp= (node *)malloc(sizeof(node));

    temp->next= iter->next;
    iter->next= temp;
    temp->x= data;

    return root;
}

void print_the_list(node * root){

    while(root!=NULL){

        printf("%d ", root->x);
        root= root->next;
    }
    
    printf("\n");
}

node * delete(node * root, int data){

    node * temp;
    node * iter= root; 

    // baştan sil

    if(root->x == data){

        temp= (node *)malloc(sizeof(node));
        temp= root;
        root= root->next;
        free(temp);

        return root;
    }

    // bulana dek ara

    while(iter->next != NULL && iter->next->x != data){
        iter= iter->next;
    }

    // sayi yoksa

    if(iter->next == NULL){
        printf("Sayi bulunamadi.\n");
        return root;
    }

    // aradan veya sondan sil

    temp= (node *)malloc(sizeof(node));
    temp= iter->next;
    iter->next= temp->next;
    free(temp);

    return root;
}

int main(){

    node * root= NULL;

    // senaryolar

    root= add_by_sorting(root, 5);   
    print_the_list(root);  
    root= add_by_sorting(root, 7);
    print_the_list(root);
    root= add_by_sorting(root, 2);
    print_the_list(root);
    root= add_by_sorting(root, 6);
    print_the_list(root);
    root= add_by_sorting(root, 10);
    print_the_list(root);     
    
    
    root= delete(root, 7);
    print_the_list(root);
    root= delete(root, 5);
    print_the_list(root);
    root= delete(root, 15);
    print_the_list(root);
    root= delete(root, 10);
    print_the_list(root);
    root= delete(root, 2);  
    print_the_list(root); 
    root= delete(root, 6);
    print_the_list(root);

    root= add_by_sorting(root, 3);     
    print_the_list(root);
    root= add_by_sorting(root, 1);
    print_the_list(root);

    add_to_the_end(root, 20);
    print_the_list(root);
    add_to_the_end(root, 18);
    print_the_list(root);

    root= add_by_sorting(root, 5);   
    print_the_list(root);  
    root= add_by_sorting(root, 7);
    print_the_list(root);
    root= add_by_sorting(root, 2);
    print_the_list(root);
    

    getch();
    return 0;
}