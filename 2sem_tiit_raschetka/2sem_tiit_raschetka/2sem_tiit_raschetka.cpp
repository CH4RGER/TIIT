#include <iostream>
#include <stdlib.h>
#include <set>
#include <fstream>
#include <Windows.h>
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

int nodes;
int v0 = 0;    // индекс начальной вершины


//подпрограмма нахождения гамильтонова цикла
int gamilton(int** A, int k, int* path, int* notchecked)
{
    int v, q1 = 0;
    for (v = 0; v < nodes && !q1; v++)
    {
        if (A[v][path[k - 1]] || A[path[k - 1]][v])
        {
            if (k == nodes && v == v0)
                q1 = 1;
            else if (notchecked[v] == -1)
            {
                notchecked[v] = k;
                path[k] = v;
                q1 = gamilton(A, k + 1, path, notchecked);
                if (!q1)
                    notchecked[v] = -1;
            }
            else continue;
        }
    }   return q1;
}

int main()

{
    while (true) {
        cout << "Nomer testa\n";
        string test;
        cin >> test;
        test = test + ".txt";
        ifstream fin(test);
        int edges;
        fin >> nodes >> edges;
        int** matrix = new int* [nodes + 1];

        for (int i = 0; i <= nodes; i++) {
            matrix[i] = new int[edges + 1];
        }

        for (int i = 0; i <= nodes; i++) {
            for (int j = 0; j <= edges; j++) {
                matrix[i][j] = 0;
            }
        }

        for (int i = 1; i <= edges; i++) {
            int from;
            int to;
            fin >> from >> to;
            matrix[to][i] = 1;
            matrix[from][i] = 1;
        }

        cout << "\n";

        for (int i = 1; i <= nodes; i++) {
            for (int j = 1; j <= edges; j++) {
                cout << matrix[i][j] << "    ";
            }
            cout << endl;
        }

        int** a = new int* [nodes + 1];
        for (int i = 0; i <= nodes; i++) {
            a[i] = new int[nodes + 1];
        }

        for (int i = 0; i <= nodes; i++) {
            for (int j = 0; j <= nodes; j++) {
                a[i][j] = 0;
            }
        }

        for (int i = 1; i <= nodes; i++) {
            for (int j = 1; j <= edges; j++) {
                if (matrix[i][j] == 1) {
                    for (int t = i + 1; t <= nodes; t++) {
                        if (matrix[t][j] == 1) {
                            a[i][t] = 1;
                            a[t][i] = 1;
                            break;
                        }
                    }
                }
            }
        }

        int size = nodes;

        //удаляем строку матрицы
        for (int i = 1; i <= size; i++)
            for (int j = 0; j <= size; j++)
                a[i - 1][j] = a[i][j];

        //удаляем столбец матрицы
        for (int i = 0; i <= size; i++)
            for (int j = 1; j <= size; j++)
                a[i][j - 1] = a[i][j];

        //уменьшаем размер матрицы
        size--;

        /*cout << "\n";

        for (int i = 0; i <= size; i++) {
            for (int j = 0; j <= size; j++) {
                cout << a[i][j] << "    ";
            }
            cout << endl;
        }

        cout << "\n";*/

        int* notchecked = new int[nodes];
        int* path = new int[nodes];
        int j;

        for (j = 0; j < nodes; j++)
        {
            notchecked[j] = -1;
        }
        path[0] = v0;
        notchecked[v0] = v0;
        if (gamilton(a, 1, path, notchecked))
        {
            cout << "Hamilton Graph\n\n";
        }
        else cout << "No Hamilton Graph\n\n";
    }
    return 0;
}