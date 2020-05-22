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




template <typename T>
class Stack {
    Node<T> *head;
    int size;		// number of elements prsent in stack
    
    public :
    
    Stack() {
        size = 0;
        head = NULL;
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        if(size == 0){
            return true;
        }
        else{
            return false;
        }
    }
    
    void push(T element) {
        if(head == NULL){
            Node<T> *n = new Node<T>(element);
            head = n;
        }
        else{
            Node<T> *n = new Node<T>(element);
            n->next = head;
            head = n;
        }
        size++;
    }
    
    T pop() {
        // Return 0 if stack is empty. Don't display any other message
        if(isEmpty()){
            return 0;
        }
        else{
            Node<T> *tmp = head;
            head = head->next;
            T x = tmp->data;
            size--;
            free(tmp);
            return x;
        }
    }
    
    T top() {
        // Return 0 if stack is empty. Don't display any other message
        if(isEmpty()){
            return 0;
        }
        else{
            return head->data;
        }
    }
    
  
    
};




    int main() {
        
        Stack<int> st;
        
        int choice;
        cin >> choice;
        int input;
        
        while (choice !=-1) {
            if(choice == 1) {
                cin >> input;
                st.push(input);
            }
            else if(choice == 2) {
                int ans = st.pop();
                if(ans != 0) {
                    cout << ans << endl;
                }
                else {
                    cout << "-1" << endl;
                }
            }
            else if(choice == 3) {
                int ans = st.top();
                if(ans != 0) {
                    cout << ans << endl;
                }
                else {
                    cout << "-1" << endl;
                }
            }
            else if(choice == 4) {
                cout << st.getSize() << endl;
            }
            else if(choice == 5) {
		if(st.isEmpty()){
                	cout << "true" << endl;
		}else{
			cout << "false" << endl;
		}
            }
            cin >> choice;
        }
    
    }