#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Array {
    int size;
    int *arr;

    Array & operator= (const Array &a2) {
        if (arr != NULL) delete[] arr;
        arr = new int[a2.size];
        size = a2.size;

        for (int i = 0; i < size; i++) arr[i] = a2.arr[i];
        return *this;
    }

    void fillArray() {
        srand(time(NULL));
        for (size_t i = 0; i < size; i++) {  
            arr[i] = rand()%100;
        }  
    }

    void printArray() {
        for (size_t i = 0; i < size; i++) 
            {std::cout << arr[i] << " ";}
            std::cout << std::endl;
    }
};

int main() {
    Array a1, a2;
    a1.size = a2.size = 8;
    a1.arr = new int[8];
    a2.arr = new int[8];
    a1.fillArray();
    a2 = a1;
    a1.printArray();
    a2.printArray();
}