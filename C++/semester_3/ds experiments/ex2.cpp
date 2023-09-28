#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class linkedlist{
public:
    Node* head;

    linkedlist(){
        head = nullptr;
    }

    void insertelement(int value){
        Node* newnode = new Node;
        newnode->data = value;
        newnode->next = nullptr;

        if (head == nullptr) {
            head = newnode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newnode;
        }
    }

    void insert(int value){
        Node* newnode = new Node;
        newnode->data = value;
        newnode->next = nullptr;

        if(head == nullptr){
            head = newnode;
        }else{
            Node* current = head;
            while (current->next != nullptr){
                current = current->next;
            }

            current->next = newnode;
        }
    }

    void removeallelements(int value) {
        if (head == nullptr) {
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    void display() {
    struct Node* ptr;
    ptr = head;
    while (ptr != NULL) {
        cout<< ptr->data <<" ";
        ptr = ptr->next;
        }   
    }

};


// class List {
// public:
//     Node* head;
//     List() {
//         head = nullptr;
//     }
//     int size=0;

//     void insert(int value) {
//         Node* newNode = new Node;
//         newNode->data = value;
//         newNode->next = nullptr;

//         if (head == nullptr) {
//             head = newNode;
//         } else {
//             Node* current = head;
//             while (current->next != nullptr) {
//                 current = current->next;
//             }
//             current->next = newNode;
//             size++;
//         }
//     }

//     void remove(int value) {
//         if (head == nullptr) {
//             return;
//         }

//         if (head->data == value) {
//             Node* temp = head;
//             head = head->next;
//             delete temp;
//             return;
//         }

//         Node* current = head;
//         while (current->next != nullptr && current->next->data != value) {
//             current = current->next;
//         }

//         if (current->next != nullptr) {
//             Node* temp = current->next;
//             current->next = current->next->next;
//             delete temp;
//         }
//     }


//     int searchAndCount(int key) {
//         int count = 0;
//         Node* current = head;
//         while (current != nullptr) {
//             if (current->data == key) {
//                 count++;
//             }
//             current = current->next;
//         }
//         return count;
//     }
// };

int main() {

    linkedlist mylist;

    for(int i=0; i<20; i=i+3){
        mylist.insertelement(i);
    }

    mylist.insert(78);
    mylist.display();
}