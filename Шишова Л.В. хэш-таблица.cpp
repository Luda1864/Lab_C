// хэш-таблица.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#define compEQ(a, b) (a == b)
using namespace std;

typedef int T; // тип элементов
typedef int hashTableIndex; //индекс в хеш-таблице

typedef struct Node_ {
    T data; // данные, хранящиеся в вершине
    struct Node_* next; // следующая вершина
} Node;

Node** hashTable;
int hashTableSize;
hashTableIndex myhash(T data);
Node* insertNode(T data);
void deleteNode(T data);
Node* findNode(T data);

int main()
{ setlocale(LC_ALL,"Rus");
    int i, *a, maxnum;
    cout << "Введите количество элементов maxnum : ";
    cin >> maxnum;
    cout << "Введите размер хеш-таблицы HashTableSize :";
    cin >> hashTableSize;
    a = new int[maxnum];
    hashTable = new Node*[hashTableSize];
    for (i = 0; i < hashTableSize; i++)
        hashTable[i] = NULL;
    // генерация массива
    for (i = 0; i < maxnum; i++)
        a[i] = rand();
    // заполнение хеш-таблицы элементами массива
    for (i = 0; i < maxnum; i++) {
        insertNode(a[i]);
    }
    // поиск элементов массива по хеш-таблице
    for (i = maxnum - 1; i >= 0; i--) {
        findNode(a[i]);
    }
    // вывод элементов массива в файл List.txt
    ofstream out("List.txt");
    for (i = 0; i < maxnum; i++) {
        out << a[i];
        if (i < maxnum - 1)
            out << "\t";
    }
    out.close();
    // сохранение хеш-таблицы в файл HashTable.txt
    out.open("HashTable.txt");
    for (i = 0; i < hashTableSize; i++) {
        out << i << " : ";
        Node* Temp = hashTable[i];
        while (Temp) {
            out << Temp->data << "->";
            Temp = Temp->next;
        }
        out << endl;
    }

    out.close();
    // очистка хеш-таблицы
    for (i = maxnum - 1; i >= 0; i--) {
        deleteNode(a[i]);
    }
    system("pause");
    return 0;
}

// хеш-функция размещения вершины
hashTableIndex myhash(T data)
{
    return (data % hashTableSize);
}

// функция поиска местоположения и вставки вершины в таблицу
Node* insertNode(T data)
{
    Node *p, *p0;
    hashTableIndex bucket;

    // вставка вершины в начало списка
    bucket = myhash(data);
    if ((p = new Node) == 0) {
        fprintf(stderr, "Нехватка памяти (insertNode)\n");
        exit(1);
    }
    p0 = hashTable[bucket];
    hashTable[bucket] = p;
    p->next = p0;
    p->data = data;
    return p;
}

//функция удаления вершины из таблицы
void deleteNode(T data)
{
    Node *p0, *p;
    hashTableIndex bucket;
    p0 = 0;
    bucket = myhash(data);
    p = hashTable[bucket];
    while (p && !compEQ(p->data, data)) {
        p0 = p;
        p = p->next;
    }
    if (!p)
        return;
    if (p0)
        p0->next = p->next;
    else
        hashTable[bucket] = p->next;
    free(p);
}

// функция поиска эл. массива
Node* findNode(T data)
{
    Node* p;
    p = hashTable[myhash(data)];
    while (p && !compEQ(p->data, data))
        p = p->next;
    return p;
}

