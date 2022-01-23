#include <stdio.h>
#include <iostream>

struct Node
{
    int x;
    int key;
    Node* Next;
};
struct set
{
    Node* data;
};
struct set* y;
struct set* array;



class hash
{
    Node* First;

public:
    ~hash();
    int T = 0;
    int N = 8;
    int size = 0;
    int hashFunction(int key);
    void insert(int key, int data);
    void init();
    void del(int key);
    void print();
    void copy();
    void printkey(int key);
};
hash::~hash()
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (array[i].data->x != 0)
        {
          
                Node* tmp = array[i].data;
                Node* tmpNext = tmp;
                 if (tmp != NULL) {
                    while (tmp->Next != NULL)
                    {
                        tmpNext = tmp->Next;
                        free(tmp);
                        tmp = tmpNext;
                    }
                }
                 else
                 {
                     free(array[i].data);
                 }
           
            
        }
        else
        {
            free(array[i].data);
        }
    }
    delete array;
}
int hash::hashFunction(int key)
{
    return (key % N);
}

void hash::init()
{


    array = new set[N];
     for (int i = 0; i < N; i++)
    {
        Node* temp = new Node;
        temp->Next = NULL;
        temp->key = 0;
        temp->x = 0;
        array[i].data = temp;
      
 
    }
}
void hash::insert(int key, int data)
{
    if (key < 0) key = key * -1;
    int index = hashFunction(key);
        Node* temp = new Node;
        temp->key = key;
    if (array[index].data->x == 0)
    {
        
        temp->Next = NULL;
        temp->x = data;

        array[index].data = temp;
     
         size++;
        printf("\n Ключ (%d) вставлен \n", key);
    }
    else {
        Node* tmp = array[index].data;
        while (tmp->Next != NULL)  tmp = tmp->Next;
    temp->Next = NULL;
    temp->x = data;

    tmp->Next = temp;
    }
    if (N == size * 2) copy();


}

void hash::copy()
{
    T = N;
    N = N * 2;
    y = new set[T];

    
    for (int i = 0; i < T; i++) y[i].data = array[i].data;
    delete[] array;
    init();
    for (int i = 0; i < T; i++) array[i].data = y[i].data;
    delete[] y;
    printf("Новый размер хеш-таблицы %d\n", N);
};
void hash::del(int key)
{
    

    int index = hashFunction(key);
    Node* temp = array[index].data;
    if (array[index].data->x == 0)
    {
        printf("\n Данного ключа не существует \n");
    }
     else if (temp->Next == NULL)
    {  
        temp->key = 0;
        temp->x = 0;

        size--;
        printf("\n Ключ (%d) удален \n", key);
    }
    else
    {
        while (temp->Next != NULL)

            if (temp->Next->Next == NULL) {
                
                free(temp->Next->Next);
                temp->Next = NULL;
            }
        
        temp = temp->Next;
      
    }
       
   
}

void hash::printkey(int key)
{


    int index = hashFunction(key);
    Node* temp = array[index].data;
    if (array[index].data->x == 0)
    {
        printf("\n Данного ключа не существует \n");
    }
    else if (temp->Next == NULL)
    {
    

        printf(" key: %d value[%d] \t", temp->key, temp->x);
    }
    else
    {
        printf("\n");
        if (temp != NULL) {

            while (temp->Next != NULL)
            {
                printf(" key: %d value[%d] ", temp->key, temp->x);
                temp = temp->Next;
            }
        }

    }


}
void hash::print()
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (array[i].data->x == 0)
        {
            printf("\n value[%d]: / ", i);
        }
        else
        {
           Node* tmp = array[i].data;
           printf("\n");
           if (tmp != NULL) {
               
            while (tmp->Next != NULL)
            {
                printf(" key: %d value[%d]: %d ", array[i].data->key, i, tmp->x);
                tmp = tmp->Next;
            }
           }
            printf(" key: %d value[%d]: %d \t", array[i].data->key, i, array[i].data->x);
        }
    }
}


int main()
{
    hash hash;
    setlocale(LC_ALL, ("RUS"));
    int choice, key, data;
    int c = 0;
    hash.init();

    do
    {
        printf("\n1.Вставить элемент в хэш-таблицу"
            "\n2.Удалить элемент из хэш-таблицы"
            "\n3.Вывести хэш-таблицу"
            "\n4.Получить значение по ключу"
            "\n5.Завершить"
            "\n\n Пожалуйста, выберите нужный вариант: ");

        scanf_s("%d", &choice);


        switch (choice)
        {
        case 1:

            printf("Введите ключ -:\t");
            scanf_s("%d", &key);
            printf("Введите данные-:\t");
            scanf_s("%d", &data);
            hash.insert(key, data);

            break;

        case 2:

            printf("Введите ключ, который хотите удалить-:");
            scanf_s("%d", &key);
            hash.del(key);

            break;

   

        case 3:

            hash.print();

            break;
        case 4:

            printf("Введите ключ:");
            scanf_s("%d", &key);
            hash.printkey(key);

            break;
        case 5:

            c = 1;
    
            break;

        default:

            printf("Недействительный ввод\n");
        }


    } while (c != 1);
}
