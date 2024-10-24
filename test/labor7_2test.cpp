#include <gtest/gtest.h>
#include "../labor7_2.hpp"


TEST(MatrixTest, CreateFunction) {
    const int k = 3;
    const int n = 3;
    const int Low = -21;
    const int High = 24;

    int** a = new int*[k];
    for (int i = 0; i < k; i++) {
        a[i] = new int[n];
    }

    Create(a, k, n, Low, High);

    
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            EXPECT_GE(a[i][j], Low);
            EXPECT_LE(a[i][j], High);
        }
    }

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;
}

TEST(MatrixTest, SearchMinMaxOddColumnsFunction) {
    const int k = 3;
    const int n = 5;  
    int** a = new int*[k];
    for (int i = 0; i < k; i++) {
        a[i] = new int[n];
    }

    a[0][0] = 1; a[0][1] = 2; a[0][2] = 3; a[0][3] = 4; a[0][4] = 5;
    a[1][0] = 6; a[1][1] = 7; a[1][2] = 8; a[1][3] = 9; a[1][4] = 10;
    a[2][0] = 11; a[2][1] = 12; a[2][2] = 13; a[2][3] = 14; a[2][4] = 15;

    int minMaxOddCol;
    bool result = SearchMinMaxOddColumns(a, k, n, minMaxOddCol);

    EXPECT_TRUE(result);
    EXPECT_EQ(minMaxOddCol, 11); // 11 - максимальне з 1, 6, 11 (первинні непарні стовпці)

    // Тест з відсутніми непарними стовпцями
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;  // Обнулюємо всі значення
        }
    }

    result = SearchMinMaxOddColumns(a, k, n, minMaxOddCol);
    EXPECT_FALSE(result);  // Не повинно бути елементів в непарних стовпцях

    // Очищення пам'яті
    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;
}


