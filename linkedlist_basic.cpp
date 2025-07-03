#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert at beginning
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Insert after a node with value = pos
    void insertAtMiddle(int data, int pos) {
        Node* newNode = new Node(data);
        Node* temp = head;

        while (temp) {
            if (temp->data == pos) {
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
    }

    // Insert at end
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Delete first node
    void deleteFirstNode() {
        if (!head) return;

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete node with specific value
    void deleteSpecificNode(int value) {
        if (!head) return;

        Node* temp = head;

        while (temp && temp->next) {
            if (temp->next->data == value) {
                Node* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
                return;
            }
            temp = temp->next;
        }
    }

    // ✅ Delete last node
    void deleteLastNode() {
        if (!head) return;

        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->next) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    // Display the list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Destructor to free memory
    ~LinkedList() {
        while (head) {
            deleteFirstNode();
        }
    }
};

int main() {
    LinkedList list;

    list.insertAtBeginning(5);
    list.insertAtBeginning(2);
    list.insertAtBeginning(1);
    list.display();  // 1 -> 2 -> 5 -> NULL
    cout << "##########\n";

    list.insertAtMiddle(3, 2);
    list.insertAtMiddle(4, 3);
    list.display();  // 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    cout << "##########\n";

    list.insertAtEnd(6);
    list.insertAtEnd(7);
    list.display();  // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> NULL
    cout << "##########\n";

    list.deleteFirstNode();
    list.display();  // 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> NULL
    cout << "##########\n";

    list.deleteSpecificNode(7);
    list.display();  // 2 -> 3 -> 4 -> 5 -> 6 -> NULL
    cout << "##########\n";

    list.deleteLastNode();
    list.display();  // 2 -> 3 -> 4 -> 5 -> NULL

    return 0;
}
