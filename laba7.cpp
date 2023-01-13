#include <iostream>
#include <locale>
#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

void DFS(int v, int n, int* M[], bool vis[])
{
    vis[v] = 1;
    cout << v << "\t";
    for (int i = 0; i < n; i++)
    {
        if (M[v][i] == 1 && vis[i] == 0) {
            DFS(i, n, M, vis);
        }
    }

}

int main()
{
    setlocale(LC_ALL, "rus");

    int n;
    cout << "Введите размерность квадратной матрицы смежности: ";
    cin >> n;

    int** matrix = new int* [n];
    for (int i = 0; i < n; ++i)
    {
        matrix[i] = new int[n];
    }

    srand(time(NULL));

    cout << "\nМатрица смежности:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = rand() % 100;
            if (i == j) {
                matrix[i][j] = 0;
            }
            if (matrix[i][j] >= 0 && matrix[i][j] <= 20)
            {
                matrix[i][j] = 0;
            }
            else if (matrix[i][j] >= 21 && matrix[i][j] < 100)
            {
                matrix[i][j] = 1;
            }

        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            matrix[i][j] = matrix[j][i];
            cout << matrix[i][j] << " ";

        }
        cout << endl;
    }

    int v;
    cout << "\nВведите вершину от 0 до " << n - 1 << ": ";
    cin >> v;
    cout << endl;

    bool* vis = new bool[v];
    for (int i = 0; i < n; i++)
    {
        vis[i] = { 0 };
    }
    DFS(v, n, matrix, vis);

    //очищение памяти:
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] vis;

    return 0;
}
