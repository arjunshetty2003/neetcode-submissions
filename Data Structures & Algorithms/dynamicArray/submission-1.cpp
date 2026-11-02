class DynamicArray {
private:
    int* arr;
    int size;
    int capacity;

public:

    DynamicArray(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        size = 0;
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if (size == capacity)
            resize();
        arr[size] = n;
        size++;
    }

    int popback() {
        int n = arr[size - 1];
        size--;
        return n;
    }

    void resize() {
        int* oldArray = arr;
        arr = new int[2 * capacity];
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
