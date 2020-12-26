// Lab8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h> 
#include <string>
using namespace std;

class Exception{
private:
    string data;
public:
    Exception(string data) {
        this->data = data;
    }
    string getData() {
        return this->data;
    }
};

bool isNumber(string n) {
    for (int i = 0; i < n.length(); i++) {
        if (!isdigit(n[i])) {
            return false;
        }
    }
    return true;
}

void CountX() {
    string a;
    string b;
    string c;
    double answer;

    cout << "Введите a" << endl;    
    cin >> a;
    if (!isNumber(a)) { throw Exception("ОШИБКА: введено не верное значение A"); }
    cout << "Введите b" << endl;
    cin >> b;
    if (!isNumber(b)) throw Exception("ОШИБКА: введено не верное значение B");
    cout << "Введите c" << endl;
    cin >> c;
    if (!isNumber(c)) throw Exception("ОШИБКА: введено не верное значение C");
   
    answer = (stod(c) - stod(b)) / stod(a);

    cout.width(12);
    cout.fill('%');
    cout << "x = " << setprecision(5) << answer << endl;

    ofstream out;
    out.open("test.txt",ofstream::app);
    if (out.is_open()) {
        out << setw(12) << setprecision(5) << answer << endl;
    }
    else {
        throw Exception("ОШИБКА: файл не открылся");
    }
    out.close();
    
}

int main() {
    setlocale(LC_ALL, "Russian");
    try {
        CountX();
    }
    catch (Exception& e) {
        cout << e.getData();
        return 1;
    }
}

