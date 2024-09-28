class MyCircularDeque {
public:
    vector<int> arr;
    int front = 0;
    int back = 0;
    int sze = 0, capacity=0;
    MyCircularDeque(int k) {
        arr =  vector<int>(k, -1);
        capacity = k;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        if(front == 0) front = capacity - 1;
        else front--;
        arr[front] = value;
        sze++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        arr[back] = value;
        if(back == capacity - 1) back = 0;
        else back++;
        sze++;
        return true;

    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        arr[front] = -1; 

        if(front == capacity - 1) front = 0;
        else front++;
        sze--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        if(back == 0) back = capacity - 1;
        else back--;
        arr[back] = -1;
        sze--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return arr[front];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        if(back == 0) return arr[capacity - 1];
        else return arr[back - 1];
    }
    
    bool isEmpty() {
        return (sze == 0);
    }
    
    bool isFull() {
        return (sze == capacity) ;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */