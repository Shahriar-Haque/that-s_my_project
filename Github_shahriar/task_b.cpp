/// Name     : Md. Shahriar Haque Shemul
/// Id       : 1702072
/// Level    : 2
/// Semester : I


#include<bits/stdc++.h>
using namespace std;

void menu();
void View(int *a);
void Insert(int *a);
void Search(int *a);
void Delete(int *a);
void sort_a(int *a);
void sort_d(int *a);
void memAllocate(int *a);
void menu_task(int *a);
void clear_screen();

int command=1, n = 0;

int main()
{
    int *arr;
    arr = new int [100000]; //dynamic memory allocation

    while(true)
    {
        menu();

        cout  <<  "Please, enter a valid keyword from the given list: ";
        cin >> command;

        if(command == 0)
            break;

        menu_task(arr);
        clear_screen();
    }

    cout<<"\nThanks for using this programme ..."<<endl;

    return 0;
}

void menu()
{
    cout << "0.   Exit" << endl;
    cout << "1.   View all items" << endl;
    cout << "2.   Insert new item" << endl;
    cout << "3.   Search an item" << endl;
    cout << "4.   Delete an item" << endl;
    cout << "5.   Sort items in ascending order" << endl;
    cout << "6.   Sort items in descending order" << endl;
    cout << "7.   Find memory location of an item" << endl;
}

void View(int* ar)
{

    cout<<"Current items: ";
    for(int i=1; i<=n; i++)
        cout  <<  ar[i]<<" ";
    cout  <<  endl;
}

void Insert(int* ar)
{
    cout<<"Please, enter an integer to insert : ";
    int x;
    cin >> x;
    ar[++n] = x;
}

void Search(int* ar)
{
    cout<<"Enter a data to be searched: ";
    int x;
    cin >> x;
    for(int i=1; i<=n; i++)
    {
        if(x==ar[i])
        {
            cout  <<  x<<" is found."<<endl;
            return;
        }
    }
    cout  <<  x<<" is not found!"<<endl;
}

void Delete(int* ar)
{
    cout<<"Enter a data to be deleted: ";
    int x, idx = 0;
    cin >> x;
    for(int i=1; i<=n; i++)
    {
        if( x == ar[i] )
        {
            idx = i;
            n--;
            break;
        }
    }
    if(idx)
    {
        for(int i=idx; i<=n; i++)
        {
            ar[i] = ar[i+1];
        }
        cout  <<  x<<" is deleted successfully!"<<endl;
    }
    else
        cout  <<  x<<" is not found!"<<endl;
}

void sort_a(int* ar)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(ar[i]>ar[j])
                swap(ar[i], ar[j]);
        }
    }
    cout<<"Items sorted in ascending order."<<endl;
}

void sort_d(int* ar)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(ar[i]<ar[j])
                swap(ar[i], ar[j]);
        }
    }
    cout<<"Items sorted in descending order."<<endl;
}

void memAllocate(int* ar)
{
    cout<<"Enter the index to know the memory location: ";
    int x;
    cin >> x;
    if(x<1 || x>n)
        cout<<"Sorry, No such index is present!"<<endl;
    else
        cout<<"The memory location is = "<<&ar[x]<<endl;
}

void menu_task(int* ar)
{
    cout  <<  endl;
    if(command<1 || command>7)
        cout<<"Sorry! You entered an invalid keyword!"<<endl;
    else if(command==1)
        View(ar);
    else if(command==2)
        Insert(ar);
    else if(command==3)
        Search(ar);
    else if(command==4)
        Delete(ar);
    else if(command==5)
        sort_a(ar);
    else if(command==6)
        sort_d(ar);
    else if(command==7)
        memAllocate(ar);
    cout  <<  endl;
}

void clear_screen()
{
    char ch = getchar();
    cout<<"Press any key to clear screen: ";
    char chh = getchar();
    system("CLS");
}

