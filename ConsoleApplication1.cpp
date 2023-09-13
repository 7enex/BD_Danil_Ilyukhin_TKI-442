#include <iostream>
#include <string>

class DynamicArray {
private:
    int* data;       // Указатель на массив
    int size;        // Текущий размер массива
    int capacity;    // Емкость массива

public:
    DynamicArray(int initialCapacity = 10) {
        capacity = initialCapacity;
        data = new int[capacity];
        size = 0;
    }

    ~DynamicArray() {
        delete[] data;
    }

    void push_back(int value) {

        if (size == capacity) {
            int* newData = new int[2 * capacity];
            for (int i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity *= 2;
        }

        data[size] = value;
        ++size;
    }

    void bubbleSort() {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (data[j] > data[j + 1]) {
                    int temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }

   
    void display() {
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    
    std::locale::global(std::locale("ru_RU.utf8"));

    DynamicArray arr;

    int input;
    std::wcout << L"Введите элементы массива (-1 для завершения ввода):\n"; 
    while (true) {
        std::wcin >> input; 
        if (input == -1) {
            wchar_t choice;
            std::wcout << L"Хотите завершить ввод (y/n)? ";
            std::wcin >> choice;
            if (choice == L'y' || choice == L'Y') {
                break;
            }
        } else {
            arr.push_back(input);
        }
    }

    std::wcout << L"Данные массива до сортировки:\n"; 
    arr.display();

   
    arr.bubbleSort();

    std::wcout << L"Данные массива после сортировки:\n"; 
    arr.display();

    return 0;
}