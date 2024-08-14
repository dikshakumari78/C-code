#include "DynamicArray.h"

int main() {
    try {
        DynamicArray<int> arr;
        
        // Insert elements
        arr.insert(1);
        arr.insert(2);
        arr.insert(3);
        
        std::cout << "Array contents after inserts: ";
        for (size_t i = 0; i < arr.getSize(); ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

        // Remove an element
        arr.remove(1);
        
        std::cout << "Array contents after removal: ";
        for (size_t i = 0; i < arr.getSize(); ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

        // Clear the array
        arr.clear();
        
        std::cout << "Array size after clearing: " << arr.getSize() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}
