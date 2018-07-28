/// Name     : Md. Shahriar Haque Shemul
/// Id       : 1702072
/// Level    : 2
/// Semester : I

#include<stdio.h>
#include<string.h>
#include <stdlib.h>

void menu();
void View(int *a);
void Insert(int *a);
void MemLoc(int *a);
void Search(int *a);
void Delete(int *a);
void sort_a(int *a);
void sort_d(int *a);
void menu_task(int *a);
void clear_screen();

int i, j, command, n = 0;

int main()
{
    int *arr = malloc(100000 * sizeof(int)); //dynamic memory allocation

    while(1){
        menu();

        printf("Please, enter a valid keyword from the given list: ");
        scanf("%d", &command);

        if(command == 0)
            break;

        menu_task(arr);
        clear_screen();
    }

    printf("\nThanks for using this programme..\n\n");

    return 0;
}

void menu(){
    printf("0.   Exit\n");
    printf("1.   View all items\n");
    printf("2.   Insert new item\n");
    printf("3.   Search an item\n");
    printf("4.   Delete an item\n");
    printf("5.   Sort items in ascending order\n");
    printf("6.   Sort items in descending order\n");
    printf("7.   Find memory location of an item\n");
}

void View(int* ar){
    printf("Current items are: ");
    for(i=1; i<=n; i++) printf("%d ", ar[i]);
    printf("\n");
}

void Insert(int* ar){
    printf("Please, enter a integer to insert: ");
    int x;
    scanf("%d", &x);
    ar[++n] = x;
    printf("%d is inserted successfully!\n", ar[n]);
}

void MemLoc(int* ar){
    printf("Enter the index to know the memory location: ");
    int x;
    scanf("%d", &x);
    if(x<1 || x>n) printf("Sorry,, No such index is present!\n");
    else printf("The memory location is = %d\n", ar+x+1);
}

void Search(int* ar){
    printf("Enter a data to be search: ");
    int x;
    scanf("%d", &x);
    for(i=1; i<=n; i++){
        if(x==ar[i]){
            printf("%d is found.\n", x);
            return;
        }
    }
    printf("%d is not found!\n", x);
}

void Delete(int* ar){
    printf("Enter a data to delete: ");
    int x, idx = 0;
    scanf("%d", &x);
    for(i=1; i<=n; i++){
        if(x==ar[i]){
            idx = i;
            n--;
            break;
        }
    }
    if(idx){
        for(i=idx; i<=n; i++){
            ar[i] = ar[i+1];
        }
        printf("%d is deleted successfully!\n", x);
    }
    else printf("%d is not found!\n", x);
}

void sort_a(int* ar){
    for(i=1; i<=n; i++){
        for(j=i+1; j<=n; j++){
            if(ar[i]>ar[j]){
                int temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
    }
    printf("Items sorted in ascending order!\n");
}

void sort_d(int* ar){
    for(i=1; i<=n; i++){
        for(j=i+1; j<=n; j++){
            if(ar[i]<ar[j]){
                int temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
    }
    printf("Items sorted in descending order!\n");
}


void menu_task(int* ar){
    printf("\n");
    if(command<1 || command>7) printf("Sorry! You entered an invalid keyword!\n");
    else if(command==1) View(ar);
    else if(command==2) Insert(ar);
    else if(command==3) Search(ar);
    else if(command==4) Delete(ar);
    else if(command==5) sort_a(ar);
    else if(command==6) sort_d(ar);
    else if(command==7) MemLoc(ar);
    printf("\n");
}

void clear_screen(){
    char ch = getchar();
    printf("Press any key to clear screen: ");
    char chh = getchar();
    system("CLS");
}

