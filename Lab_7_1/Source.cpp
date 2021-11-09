#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue> // очередь
#include <string>


using namespace std;




void BFS1(int** mas, int DIST[10], int start)
{
    queue<int> Queue;
    int nodes[7]; // вершины графа
    //for (int i = 0; i < 7; i++)

    Queue.push(start); // помещаем в очередь первую вершину
    DIST[start] = 0; // исходно все вершины равны 1000
    while (!Queue.empty())
    { // пока очередь не пуста
        start = Queue.front(); // извлекаем вершину
        Queue.pop();
        cout << start << endl; // выводим номер вершины
        for (int j = 0; j < 7; j++)
        { // проверяем для нее все смежные вершины
            if (mas[start][j] == 1 && DIST[j] > DIST[start] + mas[start][j])
            { // если вершина смежная и не обнаружена
                Queue.push(j); // добавляем ее в очередь
                //nodes[j] = 1; // отмечаем вершину как обнаруженную
                DIST[j] = DIST[start] + mas[start][j];
            }
        }

    }
}


int param(int argc, char* argv[]) {
    int** graph;



    char p1[5];
    int start;
    for (int i = 0; i < argc; ++i) {
        std::cout << i << "-й аргумент: " << argv[i] << '\n';
    }



    //char* a = argv[2];


    int size = stoi(argv[2]);
    //cout << size;
    graph = (int**)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        graph[i] = (int*)malloc(size * sizeof(int));
    }

    if (strcmp(argv[1], "OB") == 0) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                graph[i][j] = rand() % 5;
            }
        }
    }

    if (strcmp(argv[1], "ON") == 0) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                graph[i][j] = rand() % 2;
            }
        }
    }

    if (strcmp(argv[1], "NO") == 0) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < i + 1; j++) {
                int num = rand() % 5;
                graph[i][j] = num;
                graph[j][i] = num;
            }
        }
    }

    if (strcmp(argv[1], "NN") == 0) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < i + 1; j++) {
                int num = rand() % 2;
                graph[i][j] = num;
                graph[j][i] = num;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf(" %d", graph[i][j]);
        }
        printf("\n");
    }
    cout << "Введите начальную вершину \n";

    cin >> start;


    int DIST[10];

    for (int i = 0; i < size; i++) {

        DIST[i] = 1000;
    }
    cout << "обход в ширину\n";

    BFS1(graph, DIST, start);

    for (int i = 0; i < size; i++) {

        printf("рассояние от %d до %d = %d\n", start, i, DIST[i]);
    }
    return 0;
}




int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Rus");







    //cin >> p1;

    std::cout << "В программе аргументов: " << argc << " \n\n";

    if (argc > 1)
    {
        param(argc, argv);
    }

    else
    {
        cout << "Введите тип графа (ОВ или NN или NO или ON) \n";
        std::cout << "Укажите аргументы. ";
        param(argc, argv);
    }
    std::cout << '\n';

    system("pause");
}

