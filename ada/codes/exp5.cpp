// Strassen’s Matrix Multiplication

#include <iostream>
#include <vector>
using namespace std;
using Matrix = vector<vector<int>>;

Matrix add(Matrix arr1, Matrix arr2, int n)
{
    Matrix res(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    return res;
}

Matrix mult(Matrix &arr1, Matrix &arr2)
{
    int n = arr1.size();

    Matrix res(n, vector<int>(n, 0));

    if (n == 1)
    {
        res[0][0] = arr1[0][0] * arr2[0][0];
        return res;
    }

    vector<Matrix> subMat(8, Matrix(n / 2, vector<int>(n / 2, 0)));

    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            subMat[0][i][j] = arr1[i][j];
            subMat[1][i][j] = arr1[i][j + n / 2];
            subMat[2][i][j] = arr1[i + n / 2][j];
            subMat[3][i][j] = arr1[i + n / 2][j + n / 2];
            subMat[4][i][j] = arr2[i][j];
            subMat[5][i][j] = arr2[i][j + n / 2];
            subMat[6][i][j] = arr2[i + n / 2][j];
            subMat[7][i][j] = arr2[i + n / 2][j + n / 2];
        }
    }

    vector<Matrix> resMat(4, Matrix(n / 2, vector<int>(n / 2, 0)));

    resMat[0] = add(mult(subMat[0], subMat[4]), mult(subMat[1], subMat[6]), n / 2);
    resMat[1] = add(mult(subMat[0], subMat[5]), mult(subMat[1], subMat[7]), n / 2);
    resMat[2] = add(mult(subMat[2], subMat[4]), mult(subMat[3], subMat[6]), n / 2);
    resMat[3] = add(mult(subMat[2], subMat[5]), mult(subMat[3], subMat[7]), n / 2);

    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            res[i][j] = resMat[0][i][j];
            res[i][j + n / 2] = resMat[1][i][j];
            res[i + n / 2][j] = resMat[2][i][j];
            res[i + n / 2][j + n / 2] = resMat[3][i][j];
        }
    }

    return res;
}

int main()
{
    cout << endl;
    Matrix arr1 = {{7, 8}, {2, 9}};
    Matrix arr2 = {{14, 5}, {5, 18}};
    Matrix res = mult(arr1, arr2);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
// ok