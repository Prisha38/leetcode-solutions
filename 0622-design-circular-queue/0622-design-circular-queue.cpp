
/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

 class MyCircularQueue {
public:
    vector<int> arr;
    int front;
    int rear;
    int count;
    int size;

    MyCircularQueue(int k) {
        size = k;
        arr.resize(k);

        front = 0;
        rear = 0;
        count = 0;
    }

    bool enQueue(int value) {
        if (isFull())
            return false;

        arr[rear] = value;

        rear = (rear + 1) % size;

        count++;

        return true;
    }

    bool deQueue() {
        if (isEmpty())
            return false;

        front = (front + 1) % size;

        count--;

        return true;
    }

    int Front() {
        if (isEmpty())
            return -1;

        return arr[front];
    }

    int Rear() {
        if (isEmpty())
            return -1;

        int index = (rear - 1 + size) % size;

        return arr[index];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == size;
    }
};