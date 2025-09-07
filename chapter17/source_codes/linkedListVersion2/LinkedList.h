#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

/**
 * The ListNode class creates a type used to store a node of the linked list.
 */
template <class T>
class ListNode
{
public:
    T value;            // The value of the node.
    ListNode<T> *next;  // The pointer to the next node.

    // Constructor.
    ListNode(T nodeValue)
        { value = nodeValue;
          next = nullptr; }
};

/**
 * Linkedlist class.
 */
template <class T>
class LinkedList
{
private:
    ListNode<T> *head;  // List head pointer.

public:
    // Constructor.
    LinkedList()
        { head = nullptr; }
    
    // Destructor.
    ~LinkedList();

    // Linked list operations.
    void appendNode(T);
    void insertNode(T);
    void deleteNode(T);
    void displayList() const;
};

/**
 * appendNode appends a node containing the value passed into newValue, to the
 * end of the list.
 */
template <class T>
void LinkedList<T>::appendNode(T newValue)
{
    ListNode<T> *newNode;   // To point to a new node.
    ListNode<T> *nodePtr;   // To move through the list.

    // Allocate a new node and store newValue there.
    newNode = new ListNode<T>(newValue);

    // If there are no nodes in the list make newNode the first node.
    if (!head)
    {
        head = newNode;
    }
    // Otherwise, insert newNode at end.
    else
    {
        // Initialize nodePtr to head of list.
        nodePtr = head;

        // Find the last node in the list.
        while (nodePtr->next)
        {
            nodePtr = nodePtr->next;
        }

        // Insert newNode as the last node.
        nodePtr->next = newNode;
    }
}

/**
 * displayList shows the value stored in each node of the linked list
 * pointed to by head.
 */
template <class T>
void LinkedList<T>::displayList() const
{
    ListNode<T> *nodePtr;   // To traverse the list.

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr points to a node, traverse the list.
    while (nodePtr)
    {
        // Display the value in the node.
        cout << nodePtr->value << endl;

        // Move to the next node.
        nodePtr = nodePtr->next;
    }
}

/**
 * insertNode function inserts a node with newNvalue copied to its value member.
 */
template <class T>
void LinkedList<T>::insertNode(T newValue)
{
    ListNode<T> *newNode;                   // A new node.
    ListNode<T> *nodePtr;                   // To traverse the list.
    ListNode<T> *previousNode = nullptr;    // The previous node.

    // Allocate a new node and store newValue there.
    newNode = new ListNode<T>(newValue);

    // If there are no nodes in the list, make newNode the first node.
    if (!head)
    {
        head = newNode;
    }
    // Otherwise, insert newNode.
    else
    {
        // Position nodePtr at the head of the list.
        nodePtr = head;

        // Skip all nodes whose value is less than newValue.
        while (nodePtr != nullptr && nodePtr->value < newValue)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // If the new node is to be the 1st in the list, insert it
        // before all other nodes.
        if (previousNode == nullptr)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        // Otherwise, insert after the previous node.
        else
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

/**
 * The deleteNode function searches for a node with searchValue as its value.
 * The node, if found, is deleted from the list and from memory.
 */
template <class T>
void LinkedList<T>::deleteNode(T searchValue)
{
    ListNode<T> *nodePtr;                     // To traverse the list.
    ListNode<T> *previousNode = nullptr;      // To point to the previous node.

    // If the list is empty, do nothing.
    if (!head)
        return;
    
    // If the first node is the one to be deleted.
    if (head->value == searchValue)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        // Initialize nodePtr to the head of the list.
        nodePtr = head;

        // Skip all nodes whose value member is not equal to searchValue.
        while (nodePtr != nullptr && nodePtr->value != searchValue)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // If nodePtr is not at the end of the list, link the previous node to
        // the node after nodePtr, then delete nodePtr.
        if (nodePtr)
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

/**
 * Destructor. This function deletes every node in the list.
 */
template <class T>
LinkedList<T>::~LinkedList()
{
    ListNode<T> *nodePtr;   // To traverse the list.
    ListNode<T> *nextNode;  // To point to the next node.

    // Position nodePtr at head of list.
    nodePtr = head;

    // While nodePtr is not at the end of the list, delete node.
    while (nodePtr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}
#endif