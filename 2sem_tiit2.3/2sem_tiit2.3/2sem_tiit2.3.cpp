#include <stdio.h>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <Windows.h>
#include <iterator>
#include <iostream>
using namespace std;

pair <int, pair<int, int> > p[100000000];
//int nodes;
int max;


int min(int a, int b) {
    if (a >= b) {
        return b;
    }
    return a;
}

int main()
{
    setlocale(LC_ALL, "rus");
    string choose;
    cin >> choose;
    choose = choose + ".in";
    fstream input(choose, ios_base::in | ios_base::binary);
    ofstream fout("output.txt");
    ifstream fin;

    int x, y, nodes, weight;

    input >> nodes;

    for (int i = 0; i <= nodes; ++i)
    {
        input >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }

    for (int a = 0; a < nodes; ++a) {
        weight = p[a].first;
        x = p[a].second.first;
        y = p[a].second.second;
    }

    int n = nodes;

    int** A = new int* [n];
    for (int i = 0; i < n; i++)
        A[i] = new int[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = 0;


    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int a = 0; a < nodes; ++a)
                if ((i == p[a].second.first - 1 && j == p[a].second.second - 1) || j == p[a].second.first - 1 && i == p[a].second.second - 1)
                    A[i][j] = p[a].first;
    //int** matrix = new int* [nodes + 1];
    //for (int i = 0; i <= nodes; i++) {
    //    matrix[i] = new int[edges + 1];
    //}//создание матрицы
    //matrix[0][0] = 0;
    //for (int i = 1; i <= nodes; i++) {
    //    for (int j = 1; j <= edges; j++) {
    //        matrix[i][j] = 1000;
    //    }
    //}//заполнение большими числами(соглсно алгоритму Флойда — Уоршелла)
    //matrix[0][0] = 0;
    //for (int i = 1; i <= nodes; i++) {
    //    matrix[i][0] = i;
    //}//заполнение первого столба номерами вершин
    //for (int i = 0; i <= edges; i++) {
    //    matrix[0][i] = i;
    //}//заполнение первой строки номерами связей

    //int node1, node2, weight;
    //for (int i = 1; i <= edges; i++) {
    //    fin >> node1 >> node2 >> weight;
    //    matrix[node1][i] = weight;
    //    matrix[node2][i] = -weight;
    //}//заполнение матрицы инцедентности
    //cout << "сама  матрица инцидентности\n";
    //for (int i = 0; i <= nodes; i++) {
    //    for (int j = 0; j <= edges; j++) {
    //        cout << matrix[i][j] << "\t";
    //    }
    //    cout << endl;
    //}
    //int** a = new int* [nodes + 1];
    //for (int i = 0; i <= nodes; i++) {
    //    a[i] = new int[nodes + 1];
    //}//создание матрицы смежности

    //for (int k = 1; k <= nodes; k++) {
    //    for (int i = 1; i <= nodes; i++) {
    //        a[k][i] = 1000;
    //    }
    //}//заполнение большими числами(соглсно алгоритму Флойда — Уоршелла)

    //for (int i = 0; i <= nodes; i++) {
    //    for (int j = 0; j <= edges; j++) {
    //        if (matrix[i][j] == 1000) {
    //            continue;
    //        }
    //        if (matrix[i][j] >= 0) {
    //            int temp = -matrix[i][j];
    //            for (int t = 0; t <= nodes; t++) {
    //                if (matrix[t][j] == temp) {
    //                    a[i][t] = matrix[i][j];
    //                    break;
    //                }
    //            }
    //        }
    //    }
    //}//переход к матрице смежности
    for (int k = 1; k <= nodes; k++) {
        for (int i = 1; i <= nodes; i++) {
            for (int j = 1; j <= nodes; j++) {
                if (i != j) {
                    A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
                }
            }
        }
    }

    int count = 0;
    int* maxes = new int[nodes];
    for (int i = 1; i <= nodes; i++) {
        int max = -1000;
        for (int j = 1; j <= nodes; j++) {
            if (A[i][j] != 1000) {
                if (A[i][j] > max) {
                    max = A[i][j];
                }
            }
        }
        if (max != -1000) {
            maxes[count] = max;
            count++;
        }
    }//находим минимальные в каждой строке
    int min = maxes[0];
    for (int p = 1; p < count; i++) {
        if (maxes[p] > min) {
            min = maxes[i];
        }
    }

    for (int i = 1; i <= nodes; i++) {
        A[i][0] = i;
    }//заполнение первого столба номерами вершин
    for (int i = 1; i <= nodes; i++) {
        A[0][i] = i;
    }//заполнение первой строки номерами связей


    cout << "радиус графа равен " << min;
}