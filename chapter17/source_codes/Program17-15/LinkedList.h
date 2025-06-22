#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>
using namespace std;

template <class T>
class LinkedList
{
private:
    // Declare a structure for the list.
    struct ListNode
    {
        T value;                // The value in this node.
        struct ListNode *next;  // To point to the next node.
    };

    // List head pointer.
    ListNode *head;

public:
    // Default constructor.
    LinkedList() { head = nullptr; }

    // Destructor.
    ~LinkedList();

    // Linked list operations.
    void appendNode(T);
    void insertNode(T);
    void deleteNode(T);
    void displayList() const;
};

/***
 * Function appendNode: The function appends a node containing
 * the value passed into num, to the end of the list.
 */
template <class T>
void LinkedList<T>::appendNode(T num)
{
    ListNode *nodePtr;      // To traverse the list.
    ListNode *newNode;      // To point to a new node.

    // Allocate a new node and store num there.
    newNode = new ListNode;
    newNode->value = num;
    newNode->next = nullptr;

    // If there are no nodes in the list, the newNode
    // the first node.
    if (head == nullptr)
        head = newNode;
    // Otherwise, append newNode.
    else
    {
        // Position nodePtr at the head of the list.
        nodePtr = head;

        // Search for the last node in the list.
        while(nodePtr->next != nullptr)
            nodePtr = nodePtr->next;

        // Insert newNode as the last node.
        nodePtr->next = newNode;
    }
}

/***
 * Function displayList: The function shows the value stored
 * in each node of the linked list pointed to by head.
 */
template <class T>
void LinkedList<T>::displayList() const
{
    ListNode *nodePtr;      // To traverse the list.

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr points to a node, traverse the list.
    while (nodePtr != nullptr)
    {
        // Display the value in this node.
        cout << nodePtr->value << endl;

        // Move to the next node.
        nodePtr = nodePtr->next;
    }
}

/***
 * Function insertNode: The function inserts a node with
 * num copied to its value member.
 */
template <class T>
void LinkedList<T>::insertNode(T num)
{
    ListNode *nodePtr;      // To traverse the list.
    ListNode *newNode;      // To point to a new node.
    ListNode *previousNode; // To point to the previous node.

    // Allocate a new node and store num there.
    newNode = new ListNode;
    newNode->value = num;

    // If there are no nodes in the list, make newNode
    // the first node.
    if (head == nullptr)
    {
        head = newNode;
        head->next = nullptr;
    }
    // Otherwise, insert newNode.
    else
    {
        // Position nodePtr at the head of the list.
        nodePtr = head;

        // Initialize previousNode to a null pointer.
        previousNode = nullptr;

        // Skip all nodes whose value is less than num.
        while (nodePtr != nullptr && nodePtr->value < num)
        {
            // Save the previous node.
            previousNode = nodePtr;

            // Move to the next node.
            nodePtr = nodePtr->next;
        }

        // If the new node is to be the 1st in the list,
        // insert it before all other nodes.
        if (previousNode == nullptr)
        {
            // Make the head point to the new node.
            head = newNode;

            // Make the next node of the head to be the nodePtr.
            head->next = nodePtr;
        }
        // Otherwise, insert newNode after the previous one.
        else
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

/***
 * Function deleteNode: The function searches for a node with
 * searchValue as its value. The node, if found, is deleted
 * from the list and from memory.
 */
template <class T>
void LinkedList<T>::deleteNode(T searchValue)
{
    ListNode *nodePtr;      // To move through the list.
    ListNode *previousNode; // To point to the previous node.

    // If there are no nodes in the list, then do nothing.
    if (head == nullptr)
        return;

    // Determine if the first node is the one.
    if (head->value == searchValue)
    {
        // Save the second node to nodePtr.
        nodePtr = head->next;

        // Delete the first node.
        delete head;

        // Make the head point to the second node.
        head = nodePtr;
    }
    else
    {
        // Position nodePtr at the head of the list.
        nodePtr = head;

        // Initialize previousNode to a null pointer.
        previousNode = nullptr;

        // Skip all nodes whose value is not equal to
        // searchValue.
        while(nodePtr != nullptr && nodePtr->value != searchValue)
        {   
            // Save the previous node.
            previousNode = nodePtr;

            // Move to the next node.
            nodePtr = nodePtr->next;
        }

        // If nodePtr is not at the end of the list, then
        // link previousNode to the node after nodePtr and
        // delete nodePtr.
        if (nodePtr != nullptr)
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

/***
 * Destructor: The destructor deletes every node in the list.
 */
template <class T>
LinkedList<T>::~LinkedList()
{
    ListNode *nodePtr;      // To traverse the list.
    ListNode *nextNode;     // To point to the next node.

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr is not at the end of the list,
    // then delete nodePtr.
    while(nodePtr != nullptr)
    {
        // Save the node after nodePtr to nextNode.
        nextNode = nodePtr->next;

        // Delete the nodePtr.
        delete nodePtr;

        // Position nodePtr at the next node.
        nodePtr = nextNode;
    }
}
#endif