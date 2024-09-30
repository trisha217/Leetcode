class MyCircularDeque {
public:
    int front, last, size, capacity;
    vector<int> deque;

    MyCircularDeque(int k) {
        front = 0;
        last = 0;
        size = 0;
        capacity = k;
        deque = vector<int>(k);
    }
    
    bool insertFront(int value) {
        if (isFull())   return false;
        front = front == 0 ? capacity - 1 : front - 1;
        deque[front] = value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull())   return false;
        deque[last] = value;
        last = last == capacity - 1 ? 0 : last + 1;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty())  return false;
        front = front == (capacity - 1) ? 0 : front + 1;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty())  return false;
        last = last == 0 ? capacity - 1 : last - 1;
        size--;
        return true;
    }
    
    int getFront() {
        if (isEmpty())  return -1;
        return deque[front];
    }
    
    int getRear() {
        if (isEmpty())  return -1;
        return last == 0 ? deque[capacity - 1] : deque[last - 1];
    }
    
    bool isEmpty() {
        return size == 0 ? true : false;
    }
    
    bool isFull() {
        return size == capacity ? true : false;
    }
};