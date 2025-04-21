
#include <iostream>
#include <cstdint>

using namespace std;

int32_t** createMatrix(int32_t rows, int32_t cols);
void fillMatrix(int32_t** matrix, int32_t rows, int32_t cols);
void printMatrix(int32_t** matrix, int32_t rows, int32_t cols);
void shiftRowsUp(int32_t** matrix, int32_t rows, int32_t cols);
void shiftRowsDown(int32_t** matrix, int32_t rows, int32_t cols);
void shiftColumnsLeft(int32_t** matrix, int32_t rows, int32_t cols);
void shiftColumnsRight(int32_t** matrix, int32_t rows, int32_t cols);
void deleteMatrix(int32_t** matrix, int32_t rows);
void printMenu();

int main() {
    int32_t rows, cols;
    
    
    cout << "Введите количество строк матрицы (1-10): ";
    cin >> rows;
    cout << "Введите количество столбцов матрицы (1-10): ";
    cin >> cols;

    
    if(rows < 1 || rows > 10 || cols < 1 || cols > 10) {
        cout << "Некорректный размер матрицы!\n";
        return 1;
    }

    
    int32_t** matrix = createMatrix(rows, cols);
    fillMatrix(matrix, rows, cols);
    
    int32_t choice;
    while (choice != 0){
        cout << "\nТекущая матрица:\n";
        printMatrix(matrix, rows, cols);
        
        printMenu();
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int32_t rowChoice;
                cout << "\nПерестановка строк:\n";
                cout << "1. Сдвиг строк вверх\n";
                cout << "2. Сдвиг строк вниз\n";
                cout << "Ваш выбор: ";
                cin >> rowChoice;
                
                if(rowChoice == 1) {
                    shiftRowsUp(matrix, rows, cols);
                    cout << "Строки сдвинуты вверх.\n";
                }
                else if(rowChoice == 2) {
                    shiftRowsDown(matrix, rows, cols);
                    cout << "Строки сдвинуты вниз.\n";
                }
                break;
            }
            case 2: {
                int32_t colChoice;
                cout << "\nПерестановка столбцов:\n";
                cout << "1. Сдвиг столбцов влево\n";
                cout << "2. Сдвиг столбцов вправо\n";
                cout << "Ваш выбор: ";
                cin >> colChoice;
                
                if(colChoice == 1) {
                    shiftColumnsLeft(matrix, rows, cols);
                    cout << "Столбцы сдвинуты влево.\n";
                }
                else if(colChoice == 2) {
                    shiftColumnsRight(matrix, rows, cols);
                    cout << "Столбцы сдвинуты вправо.\n";
                }
                break;
            }
            case 0:
                cout << "Выход из программы.\n";
                break;
            default:
                cout << "Неверный выбор!\n";
        }
        
    } 

    deleteMatrix(matrix, rows);
    return 0;
}

void printMenu() {
    cout << "\nВыберите операцию:\n";
    cout << "1. Перестановка строк\n";
    cout << "2. Перестановка столбцов\n";
    cout << "0. Выход\n";
}

int32_t** createMatrix(int32_t rows, int32_t cols) {
    int32_t** matrix = new int32_t*[rows];
    for (int32_t i = 0; i < rows; i++) {
        matrix[i] = new int32_t[cols];
    }
    return matrix;
}

void fillMatrix(int32_t** matrix, int32_t rows, int32_t cols) {
    for (int32_t i = 0; i < rows; i++) {
        for (int32_t j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j + 1;
        }
    }
}

void printMatrix(int32_t** matrix, int32_t rows, int32_t cols) {
    for (int32_t i = 0; i < rows; i++) {
        for (int32_t j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void shiftRowsUp(int32_t** matrix, int32_t rows, int32_t cols) {
    int32_t* temp = new int32_t[cols];
    for (int32_t j = 0; j < cols; j++) {
        temp[j] = matrix[0][j];
    }
    for (int32_t i = 0; i < rows - 1; i++) {
        for (int32_t j = 0; j < cols; j++) {
            matrix[i][j] = matrix[i + 1][j];
        }
    }
    for (int32_t j = 0; j < cols; j++) {
        matrix[rows - 1][j] = temp[j];
    }
    delete[] temp;
}

void shiftRowsDown(int32_t** matrix, int32_t rows, int32_t cols) {
    int32_t* temp = new int32_t[cols];
    for (int32_t j = 0; j < cols; j++) {
        temp[j] = matrix[rows - 1][j];
    }
    for (int32_t i = rows - 1; i > 0; i--) {
        for (int32_t j = 0; j < cols; j++) {
            matrix[i][j] = matrix[i - 1][j];
        }
    }
    for (int32_t j = 0; j < cols; j++) {
        matrix[0][j] = temp[j];
    }
    delete[] temp;
}

void shiftColumnsLeft(int32_t** matrix, int32_t rows, int32_t cols) {
    int32_t* temp = new int32_t[rows];
    for (int32_t i = 0; i < rows; i++) {
        temp[i] = matrix[i][0];
    }
    for (int32_t j = 0; j < cols - 1; j++) {
        for (int32_t i = 0; i < rows; i++) {
            matrix[i][j] = matrix[i][j + 1];
        }
    }
    for (int32_t i = 0; i < rows; i++) {
        matrix[i][cols - 1] = temp[i];
    }
    delete[] temp;
}

void shiftColumnsRight(int32_t** matrix, int32_t rows, int32_t cols) {
    int32_t* temp = new int32_t[rows];
    for (int32_t i = 0; i < rows; i++) {
        temp[i] = matrix[i][cols - 1];
    }
    for (int32_t j = cols - 1; j > 0; j--) {
        for (int32_t i = 0; i < rows; i++) {
            matrix[i][j] = matrix[i][j - 1];
        }
    }
    for (int32_t i = 0; i < rows; i++) {
        matrix[i][0] = temp[i];
    }
    delete[] temp;
}

void deleteMatrix(int32_t** matrix, int32_t rows) {
    for (int32_t i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
