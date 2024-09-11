#include <iostream>


class smart_array {
private:
    int* arr;
    unsigned int size;
    unsigned int capacity;

    
    void resize(unsigned int new_capacity) {
        int* new_arr = new int[new_capacity];
        for (unsigned int i = 0; i < size; i++) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        capacity = new_capacity;
    }

public:
    
    smart_array(unsigned int initial_capacity) :size(0), capacity(initial_capacity) {
        if (initial_capacity == 0) {
            throw std::invalid_argument("Initial capacity must be greater than zero.");
        }
        arr = new int[capacity];
    }
    
    ~smart_array() { 
        delete[] arr;
    }
    
    void add_element(int element) {
        if (size >= capacity) { 
            resize(capacity * 2);
        }
        arr[size++] = element;
    }
    
    int get_element(unsigned int index) const {
        if (index >= size) { 
            throw std::out_of_range("Index out of bounds.");
        }
        return arr[index];
    }
};

int main() {
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        
        
        std::cout << arr.get_element(0) << std::endl;
        std::cout << arr.get_element(1) << std::endl;
        std::cout << arr.get_element(2) << std::endl;
        std::cout << arr.get_element(3) << std::endl;
        std::cout << arr.get_element(4) << std::endl;
        
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}