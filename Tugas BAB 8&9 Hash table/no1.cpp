#include <iostream>

class HashTable {
private:
    int size;
    int* slots;
    std::string* data;

public:
    HashTable(int size) {
        this->size = size;
        this->slots = new int[size];
        this->data = new std::string[size];
        for (int i = 0; i < size; i++) {
            slots[i] = -1; // -1 menandakan slot kosong
        }
    }

    int hashFunction(int key) {
        return key % size;
    }

    int rehash(int oldHash, int stepSize) {
        return (oldHash + stepSize) % size;
    }

    void put(int key, std::string data) {
        int hashValue = hashFunction(key);

        if (slots[hashValue] == -1 || slots[hashValue] == key) {
            slots[hashValue] = key;
            this->data[hashValue] = data;
        } else {
            int stepSize = hashFunction(key) % 7 + 1; // memilih langkah (step) size
            int nextSlot = rehash(hashValue, stepSize);

            while (slots[nextSlot] != -1 && slots[nextSlot] != key) {
                nextSlot = rehash(nextSlot, stepSize);
            }

            if (slots[nextSlot] == -1) {
                slots[nextSlot] = key;
                this->data[nextSlot] = data;
            } else {
                this->data[nextSlot] = data; // ganti data
            }
        }
    }

    std::string get(int key) {
        int startSlot = hashFunction(key);
        int stepSize = hashFunction(key) % 7 + 1;

        int position = startSlot;
        while (slots[position] != -1) {
            if (slots[position] == key) {
                return data[position];
            }
            position = rehash(position, stepSize);

            if (position == startSlot) {
                break;
            }
        }

        return ""; // jika key tidak ditemukan
    }
};

int main() {
    // Contoh penggunaan
    HashTable hashTable(11);

    hashTable.put(1, "A");
    hashTable.put(2, "B");
    hashTable.put(3, "C");
    hashTable.put(4, "D");
    hashTable.put(5, "E");

    std::cout << hashTable.get(1) << std::endl; // Output: A
    std::cout << hashTable.get(5) << std::endl; // Output: E
    std::cout << hashTable.get(6) << std::endl; // Output: ""

    return 0;
}