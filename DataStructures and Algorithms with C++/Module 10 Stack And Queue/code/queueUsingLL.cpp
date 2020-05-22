#include<iostream>
using namespace std;


template <typename T>
class Node {
    public :
    T data;
    Node<T> *next;
    
    Node(T data) {
        this -> data = data;
        next = NULL;
    }
};



template<typename T>
class Queue {
    Node<T>* head;
    Node<T>* end;
    int size;
    public :
    
    
    Queue() {
        head = NULL;
        end = NULL;
        size = 0;
    }
    
    void enqueue(T data) {
        Node<T>* newNode = new Node<T>(data);
        
        if(end == NULL){
            head = end = newNode;
        }
        else{
            end->next = newNode;
            end =  newNode;
        }
        size++;
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        return (size == 0);
    }
    
    T dequeue() {
        // Return 0 if queue is empty
        if(isEmpty()){
            return 0;
        }
        T ans = head->data;
        Node<T>* tmp=NULL;
        tmp = head;
        head = head->next;
        free(tmp);
        size--;
        return ans;
    }
    
    T front()  {
        // Return 0 if queue is empty
        if(isEmpty()){
            return 0;
        }
        return head->data;
    }
};



int main() {
    
    Queue<int> q;
    
    int choice;
    cin >> choice;
    int input;
    
    while (choice !=-1) {
        if(choice == 1) {
            cin >> input;
            q.enqueue(input);
        }
        else if(choice == 2) {
            int ans = q.dequeue();
            if(ans != 0) {
                cout << ans << endl;
            }
            else {
                cout << "-1" << endl;
            }
        }
        else if(choice == 3) {
            int ans = q.front();
            if(ans != 0) {
                cout << ans << endl;
            }
            else {
                cout << "-1" << endl;
            }
        }
        else if(choice == 4) {
            cout << q.getSize() << endl;
        }
        else if(choice == 5) {
            if(q.isEmpty()) {
                cout << "true" << endl;
            }
            else {
                cout << "false" << endl;
            }
        }
        cin >> choice;
    }
    
}
