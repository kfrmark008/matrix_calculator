#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

using Matrix = vector<vector<double>>;

Matrix readMatrix(int rows, int cols, const string& name) {
    Matrix matrix(rows, vector<double>(cols));
    cout << "Enter values for matrix " << name << " (" << rows * cols << " values):\n";
    for (int r = 0; r < rows; ++r)
        for (int c = 0; c < cols; ++c)
            cin >> matrix[r][c];
    return matrix;
}

void printMatrix(const Matrix& matrix) {
    for (const auto& row : matrix) {
        for (double value : row)
            cout << setw(10) << value;
        cout << '\n';
    }
}

int main() {
    int rows, cols;
    cout << "Rows and columns (1-10): ";
    if (!(cin >> rows >> cols) || rows < 1 || cols < 1 || rows > 10 || cols > 10) {
        cerr << "Dimensions must be between 1 and 10.\n";
        return 1;
    }

    Matrix a = readMatrix(rows, cols, "A");
    Matrix b = readMatrix(rows, cols, "B");
    Matrix sum(rows, vector<double>(cols));
    Matrix difference(rows, vector<double>(cols));

    for (int r = 0; r < rows; ++r)
        for (int c = 0; c < cols; ++c) {
            sum[r][c] = a[r][c] + b[r][c];
            difference[r][c] = a[r][c] - b[r][c];
        }

    cout << fixed << setprecision(2);
    cout << "\nA + B:\n";
    printMatrix(sum);
    cout << "\nA - B:\n";
    printMatrix(difference);
    return 0;
}
