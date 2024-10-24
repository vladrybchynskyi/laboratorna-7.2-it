#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
bool SearchMinMaxOddColumns(int** a, const int k, const int n, int& minMaxOddCol);

int main() {
    srand((unsigned)time(NULL)); 

    int Low = -21; 
    int High = 24; 
    int k, n;

    cout << "k (rows) = "; cin >> k; 
    cout << "n (columns) = "; cin >> n; 


    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

 
    Create(a, k, n, Low, High);
    Print(a, k, n);

    int minMaxOddCol;
   
    if (SearchMinMaxOddColumns(a, k, n, minMaxOddCol)) {
        cout << "Minimum of max elements in odd columns = " << minMaxOddCol << endl;
    }
    else {
        cout << "There are no elements in odd columns" << endl;
    }


    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}


void Create(int** a, const int k, const int n, const int Low, const int High) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = Low + rand() % (High - Low + 1); 
        }
    }
}


void Print(int** a, const int k, const int n) {
    cout << endl;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << a[i][j]; 
        }
        cout << endl;
    }
    cout << endl;
}


bool SearchMinMaxOddColumns(int** a, const int k, const int n, int& minMaxOddCol) {
    bool found = false; 
    for (int j = 0; j < n; j += 2) { 
        int tempMax = a[0][j]; 
        for (int i = 1; i < k; i++) {
            if (a[i][j] > tempMax) { 
                tempMax = a[i][j];
            }
        }
        if (!found || tempMax < minMaxOddCol) { 
            minMaxOddCol = tempMax;
            found = true; 
        }
    }
    return found; 
}