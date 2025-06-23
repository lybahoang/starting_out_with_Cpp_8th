#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class LinkedList
{
private:
    struct ListNode
    {
        T data;         // The data of the node.
        ListNode *next; // The next node.
    };

    // The head of the list.
    ListNode *head;

    // Exception functions.
    void subscriptError(int);
public:
    // Default constructor.
    LinkedList()
        { head = nullptr; }

    // Destructor.
    ~LinkedList();
    
    // Linked list operations.
    void appendNode(T);
    void deleteNode(T);
    void display() const;
    int countNode() const;
    int search(T) const;

    // Overloaded operators.
    T &operator[](int);
};

/***
 * Function subscriptError: The function displays an error message
 * indicating that the subscript is invalid
 */
template <class T>
void LinkedList<T>::subscriptError(int sub)
{
    cout << "Error: " << sub << " is invalid index.\n";
    exit(EXIT_FAILURE);
}

/***
 * Operation appendNode: The function appends a new node whose
 * value is 'value' to the list
 */
template <class T>
void LinkedList<T>::appendNode(T value)
{
    ListNode *nodePtr = nullptr;    // To traverse the list.
    ListNode *newNode = nullptr;    // To point to a new node.

    // Allocate a new node and store data there.
    newNode = new ListNode;
    newNode->data = value;
    newNode->next = nullptr;

    // If there are no nodes in the list, then make newNode
    // the first node.
    if (head == nullptr)
        head = newNode;
    // Otherwise, append newNode.
    else
    {
        // Position nodePtr at the head of the list.
        nodePtr = head;

        // Search for the last node in the list.
        while (nodePtr->next != nullptr)
            nodePtr = nodePtr->next;
        
        // Insert newNode at the end of the list.
        nodePtr->next = newNode;
    }
}

/***
 * Operation deleteNode: The operation delete a node whose 
 * value is equal to 'value'
 */
template <class T>
void LinkedList<T>::deleteNode(T value)
{
    ListNode *nodePtr = nullptr;      // To traverse the list.
    ListNode *previousNode = nullptr; // To point to the previous node.

    // If there are no nodes in the list, do nothing.
    if (head == nullptr)
        return;
    
    // Position nodePtr at the head of the list.
    nodePtr = head;

    // Skip all nodes whose value is not equal to value.
    while (nodePtr != nullptr && nodePtr->data != value)
    {
        previousNode = nodePtr;
        nodePtr = nodePtr->next;
    }

    // If the first node is the one to be deleted.
    if (previousNode == nullptr)
    {
        head = nodePtr->next;
        delete nodePtr;
    }
    // If nodePtr is not a null pointer, then make previousNode
    // point to the node after nodePtr and delete nodePtr.
    else if (nodePtr != nullptr)
    {
        previousNode->next = nodePtr->next;
        delete nodePtr;
    }
}

/***
 * Operation display: The operation displays the values of nodes
 * in the list
 */
template <class T>
void LinkedList<T>::display() const
{
    ListNode *nodePtr = nullptr;     // To traverse the list.

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr is not a null pointer, displays
    // the value of the node.
    while (nodePtr != nullptr)
    {
        cout << nodePtr->data << " ";
        nodePtr = nodePtr->next;
    }
}

/***
 * Destructor: The destructor deletes all nodes in the list
 */
template <class T>
LinkedList<T>::~LinkedList()
{
    ListNode *nodePtr = nullptr;    // To traverse the list.
    ListNode *nextNode = nullptr;   // To point to the next node.

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr is not a null pointer, delete the node.
    while (nodePtr != nullptr)
    {
        // Save the next node.
        nextNode = nodePtr->next;

        // Delete the current node.
        delete nodePtr;

        // Move to the next node.
        nodePtr = nextNode;
    }
}

/***
 * Function countNode: The function counts and returns the 
 * number of nodes in the list.
 */
template <class T>
int LinkedList<T>::countNode() const
{
    ListNode *nodePtr;      // To traverse the list.
    int count = 0;          // The number of nodes.

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr is not a null pointer.
    while (nodePtr != nullptr)
    {
        // Increment count.
        count++;

        // Move to the next node.
        nodePtr = nodePtr->next;
    }

    return count;
}

/***
 * Overloaded operator[]: The operator[] returns the value in the
 * node located at position 'index'
 */
template <class T>
T &LinkedList<T>::operator[](int index)
{
    ListNode *nodePtr = nullptr;  // To traverse the list.
    int count = 0;                // Loop counter.

    // If there are no nodes in the list, display a message.
    if (head == nullptr)
    {
        cout << "There are no nodes in the list." << endl;
        exit(EXIT_FAILURE);
    }

    // If the index is invalid (out-of-range).
    if (index < 0 || index >= this->countNode())
    {
        subscriptError(index);
    }

    // Otherwise, return the value of the node.
    nodePtr = head;

    while (count != index)
    {
        nodePtr = nodePtr->next;
        count++;
    }

    // Return the value of the node.
    return nodePtr->data;
}

/***
 * Opeartion search: The operation returns the position of a value
 * in the list
 */
template <class T>
int LinkedList<T>::search(T value) const
{
    ListNode *nodePtr = nullptr;    // To traverse the list.
    int positionCount = 1;          // To keep track of node's position.

    // If there are no nodes in the list, return 0.
    if (this->head == nullptr)
        return 0;
    
    // Position nodePtr at the head of the list.
    nodePtr = head;

    // Skip all nodes whose value is not equal to 'value'.
    while (nodePtr != nullptr && nodePtr->data != value)
    {
        positionCount++;
        nodePtr = nodePtr->next;
    }

    // If the value is not found, then return 0.
    if (nodePtr == nullptr)
        return 0;
    // Otherwise, return the position.
    return positionCount;
}
#endif