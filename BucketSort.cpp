#pragma warning(disable:4996)
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>

const int hor = 10;
using namespace std;

void bucketSort(int sizeA, vector<double>& array)
{
    vector<vector<double>> buckets(hor, vector<double>(sizeA));
    int ostatok, temp;
    int count;
    for (int x = 10000; x >= 10; x /= 10)
    {
        for (int i = 0; i < hor; i++)
            for (int j = 0; j < sizeA; j++)
                buckets[i][j] = -1;
        count = 0;
        for (int i = 0; i < sizeA; i++)
        {
            temp = array[i] * x;
            ostatok = temp % 10;
            buckets[ostatok][i] = array[i];
        }
        for (int i = 0; i < hor; i++)
        {
            for (int j = 0; j < sizeA; j++)
            {
                if (buckets[i][j] != -1)
                {
                    array[count] = buckets[i][j];
                    count++;
                }
            }
        }
    }

}

void printArray(int sizeA, vector<double>& array)
{
    for (int i = 0; i < sizeA; i++)
    {
        cout << setw(10) << array[i];
        if ((i + 1) % 20 == 0)
            cout << endl << endl;
    }
    cout << endl << endl;
}

int main()
{
    int sizeA = 100;

    double k = 0.0;
    vector<double> array100(sizeA);
    FILE* fin;
    fin = fopen("100.txt", "r");
    int i = 0;
    while (!feof(fin))
    {
        fscanf(fin, "%lf", &k);
        array100[i] = k;
        i++;
    }
    fclose(fin);
    cout << "Nosorted array 100: " << endl << endl;
    printArray(sizeA, array100);
    bucketSort(sizeA, array100);
    cout << "Sorted array 100: " << endl;
    printArray(sizeA, array100);
    cout << "runtime = " << clock() / 1000.0 << endl << endl;

    sizeA = 1000;
    vector<double> array1000(sizeA);
    fin = fopen("1000.txt", "r");
    i = 0;
    while (!feof(fin))
    {
        fscanf(fin, "%lf", &k);
        array1000[i] = k;
        i++;
    }
    fclose(fin);
    cout << "Nosorted array 1000: " << endl << endl;
    printArray(sizeA, array1000);
    bucketSort(sizeA, array1000);
    cout << "Sorted array 1000: " << endl;
    printArray(sizeA, array1000);
    cout << "runtime = " << clock() / 1000.0 << endl << endl;

    sizeA = 10000;
    vector<double> array10000(sizeA);
    fin = fopen("10000.txt", "r");
    i = 0;
    while (!feof(fin))
    {
        fscanf(fin, "%lf", &k);
        array10000[i] = k;
        i++;
    }
    fclose(fin);
    cout << "Nosorted array 10000: " << endl << endl;
    printArray(sizeA, array10000);
    bucketSort(sizeA, array10000);
    cout << "Sorted array 10000: " << endl;
    printArray(sizeA, array10000);
    cout << "runtime = " << clock() / 1000.0 << endl << endl;

    return 0;
}
