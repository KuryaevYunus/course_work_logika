#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <iostream>
using namespace std;

int  i, j, m, v, n;

int** graph;

int main()
{
    char output_file[10000];
    FILE *output;
    printf("Имя файла результата: ");
    scanf("%s", output_file);

    output = fopen(output_file, "w+");

    printf("Размерность:  ");
    scanf("%d", &m);
    n = m;
    graph = new int* [m];
    for (int i = 0; i < m; i++) {
        graph[i] = new int[m];
    }

    int t;
    printf("1 - Автоматическая задание графа\n2 - Ручной ввод\n> ");
    scanf("%d", &t);
    if (t == 1) {
        //srand(time(NULL));
        for (i = 0; i < m; ++i) {
            for (j = i; j < m; ++j) {
                graph[i][j] = graph[j][i] = rand() % 2;
            }
            graph[i][i] = 0;
        }
    }
    else {
        printf("Введите элементы матрицы 0 и 1:\n");
        for (i = 0; i < m; ++i) {
            for (j = i; j < m; ++j) {
                if (i != j) {
                    ret:
                    printf("a[%d][%d] = ", i, j);
                    scanf("%d", &graph[i][j]);
                    if (graph[i][j] > 1 || graph[i][j] < 0) {
                        printf("\nОшибка!\n");
                        goto ret;
                    }
                }
            }
            graph[i][i] = 0;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            graph[j][i] = graph[i][j];
        }
    }


    fprintf(output, "Матрица смежности: \n");
    printf("Матрица смежности: \n");


    fprintf(output, "\n");
    printf("\n");

    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < m; ++j) {
            fprintf(output, "%3d", graph[i][j]);
            printf("%3d", graph[i][j]);
        }
        fprintf(output, "\n");
        printf("\n");
    }

    fprintf(output, "\nМатрица инцидентности: \n");
    printf("\nМатрица инцидентности: \n");
    int reb = 0;
    int ch = 0;

    while (ch != n)
        for (int i = 0; i < n; i++)
        {
            for (int j = 0 + ch; j < n; j++)
                if (graph[i][j] != 0)
                    reb++;
            ch++;
        }

    ///

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (graph[i][j] != 0)
                graph[j][i] = 0;

    int** inc;

    inc = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        inc[i] = (int*)malloc(reb * sizeof(int));
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < reb; j++)
            inc[i][j] = 0;


    reb = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (graph[i][j] != 0)
            {
                inc[i][reb] = 1;
                inc[j][reb] = 1;
                reb++;
            }
    }


    for (int i = 0; i < n; i++)
    {
        printf("\n", i+1);
        fprintf(output, "\n", i+1);
        for (int j = 0; j < reb; j++)
        {
            printf("%3d", inc[i][j]);
            fprintf(output, "%3d", inc[i][j]);
        }
    }

    fprintf(output, "\n\n");
    printf("\n\n");
    fprintf(output, "Независимые рёбра:\n");
    printf("Независимые рёбра:\n");
    for (int i = 0; i < reb; i++) {
        bool sr = false;
        for (int j = i + 1; j < reb; j++) {
            sr = false;
            for (int k = 0; k < n; k++) {
                if (inc[k][i] == 1 && inc[k][j] == 1) {
                    sr = true;
                }
            }
            if (sr == false) { fprintf(output, "%d - %d\n", i + 1, j + 1);
                printf("%d - %d\n", i + 1, j + 1);}
        }
    }
    return 0;
    fclose(output);
}
