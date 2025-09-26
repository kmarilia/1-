#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int* findSecondMax(vector<int>& arr) {
    // Проверка на минимальную длину
    if (arr.size() < 2) {
        return nullptr;
    }
    
    int max = INT_MIN;
    int secondMax = INT_MIN;
    
    for (int num : arr) {
        if (num > max) {
            secondMax = max;
            max = num;
        } else if (num > secondMax && num < max) {
            secondMax = num;
        }
    }
    
    // Проверяем, был ли найден второй максимум
    if (secondMax == INT_MIN) {
        return nullptr;
    }
    
    // Возвращаем через указатель (в реальном коде лучше исключения или optional)
    int* result = new int(secondMax);
    return result;
}

int main() {
    vector<int> array = {10, 5, 8, 10, 15, 3};
    int* result = findSecondMax(array);
    
    if (result != nullptr) {
        cout << "Второй максимум: " << *result << endl; // Вывод: 10
        delete result; // Не забываем освободить память
    } else {
        cout << "Второго максимума не существует" << endl;
    }
    
    return 0;
}