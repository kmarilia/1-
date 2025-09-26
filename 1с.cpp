#include <iostream>
#include <string>
#include <cctype> // для isalnum, tolower
using namespace std;

bool isPalindrome(string s) {
    int left = 0;
    int right = s.length() - 1;
    
    while (left < right) {
        // Пропускаем не буквенно-цифровые символы слева
        while (left < right && !isalnum(s[left])) {
            left++;
        }
        // Пропускаем не буквенно-цифровые символы справа
        while (left < right && !isalnum(s[right])) {
            right--;
        }
        
        // Сравниваем символы в нижнем регистре
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }
        
        left++;
        right--;
    }
    
    return true;
}

int main() {
    string testString = "A man, a plan, a canal: Panama";
    cout << "Является палиндромом: " << boolalpha << isPalindrome(testString) << endl; // Вывод: true
    return 0;
}