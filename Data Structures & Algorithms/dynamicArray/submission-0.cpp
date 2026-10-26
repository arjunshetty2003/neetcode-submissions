class DynamicArray {

private:
    int* arr;
    int capacity;
    int size;

public:

    DynamicArray(int capacity) {
        arr = new int[capacity];
        this->capacity = capacity;
        this->size = 0; 
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if (size == capacity) {
            resize();
        }
        arr[size] = n;
        size++;
    }

    int popback() {
        int num = arr[size - 1];
        size--;
        return num;
    }

    void resize() {
        int* oldArray = arr;
        arr = new int[capacity * 2];
        for (int i = 0; i < capacity; i++) {
            arr[i] = oldArray[i];
        }
        capacity *= 2;
        delete[] oldArray;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
