#include <iostream>
#include <vector>

using namespace std;

// Функция для проверки, можно ли разместить ферзя в заданной позиции
bool isSafe(vector<int>& board, int row, int col) {
    // Проверяем все предыдущие строки
    for (int i = 0; i < row; i++) {
        // Проверяем, есть ли ферзь на той же колонке или на диагонали
        if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row) {
            return false;
        }
    }
    return true;
}

// Рекурсивная функция для размещения ферзей на доске
void placeQueens(vector<int>& board, int row, int n, int& count) {
    // Если разместили все ферзи, выводим результат
    if (row == n) {
        count++;
        cout << "Расстановка " << count << ":\n";
        // Выводим обозначения полей сверху
        cout << "   ";
        for (int i = 0; i < n; i++) {
            cout << static_cast<char>('a' + i) << " ";
        }
        cout << endl;
        // Выводим доску с ферзями
        for (int i = 0; i < n; i++) {
            // Выводим обозначение поля слева
            cout << i + 1 << " ";
            for (int j = 0; j < n; j++) {
                if (board[i] == j) {
                    cout << "Q ";
                } else {
                    cout << "- ";
                }
            }
            // Выводим обозначение поля справа
            cout << i + 1 << endl;
        }
        // Выводим обозначения полей снизу
        cout << "   ";
        for (int i = 0; i < n; i++) {
            cout << static_cast<char>('a' + i) << " ";
        }
        cout << endl;
        cout << endl;
        return;
    }

    // Перебираем все колонки в текущей строке
    for (int col = 0; col < n; col++) {
        // Проверяем, можно ли разместить ферзя в данной позиции
        if (isSafe(board, row, col)) {
            // Размещаем ферзя
            board[row] = col;
            // Переходим к следующей строке
            placeQueens(board, row + 1, n, count);
        }
    }
}

// Функция для решения задачи о восьми ферзях
void solveNQueens(int n) {
    vector<int> board(n, 0); // Инициализируем доску

    int count = 0; // Счетчик для подсчета количества решений

    placeQueens(board, 0, n, count); // Размещаем ферзей на доске

    if (count == 0) {
        cout << "Решений не найдено." << endl;
    } else {
        cout << "Найдено " << count << " решений." << endl;
    }
}

int main() {
    int n = 8; // Размер доски (8 ферзей)
    solveNQueens(n); // Решаем задачу о восьми ферзях

    return 0;
}
