#include <iostream>
using namespace std;
int* create_dynamic_array(int size) {
    int* dynamic_array = new int[size];
    for (int i = 0; i < size; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> dynamic_array[i];
    }
    return dynamic_array;
}

int search_element(int* array, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    try {
        int size;
        cout << "Enter the size of the array: ";
        cin >> size;

        if (size <= 0) {
            throw std::invalid_argument("Array size must be a positive integer.");
        }

        int* user_array = create_dynamic_array(size);

        int target_element;
        cout << "Enter the element you want to search for: ";
        cin >> target_element;

        int index_found = search_element(user_array, size, target_element);

        if (index_found != -1) {
            cout << "Element " << target_element << " found at index " << index_found << "." << std::endl;
        } else {
            cout << "Element " << target_element << " not found in the array." << std::endl;
        }

        
        delete[] user_array;
    } catch (exception const& e) {
        cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}

