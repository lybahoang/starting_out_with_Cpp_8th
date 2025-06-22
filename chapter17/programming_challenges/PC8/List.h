#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

template <class T>
class List
{
private:
    // The data structor for the node.
    struct ListNode {
        T value;      // The value of the node.
        ListNode *next; // The pointer of the next node.
    };

    // The head of the list.
    ListNode *head;

public:
    // Default constructor.
    List() { head = nullptr; }

    // Destructor.
    ~List();

    // Linked list operation.
    void appendNode(T);
    void deleteNode(T);
    void displayList() const;
    void insertNode(T);
};

/***
 * Destructor: The destructor deletes all nodes in the list
 */
template <class T>
List<T>::~List()
{
    ListNode *nodePtr;      // To traverse the list.
    ListNode *nextNode;     // To point to the next node.

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr is not at the end of the list,
    // save the next node and delete nodePtr.
    while (nodePtr)
    {
        // Save the next node to nextNode.
        nextNode = nodePtr->next;

        // Delete nodePtr.
        delete nodePtr;

        // Position nodePtr at the next node.
        nodePtr = nextNode;
    }
}

/***
 * Operation appendNode: The function allocates a new node whose value
 * is equal to 'value' and inserts the new node at the end of the list
 */
template <class T>
void List<T>::appendNode(T value)
{
    ListNode *nodePtr;      // To traverse the list.
    ListNode *newNode;      // A new node.

    // Allocate a new node, store value there, and
    // make it point to a nullptr.
    newNode = new ListNode;
    newNode->value = value;
    newNode->next = nullptr;

    // If there are no nodes in the list, then make
    // newNode the first node.
    if (head == nullptr)
    {
        head = newNode;
    }
    // Otherwise, append newNode.
    else
    {
        // Position nodePtr at the head of the list to
        // start traversing the list.
        nodePtr = head;

        // Search for the end of the list.
        while (nodePtr->next != nullptr)
        {
            nodePtr = nodePtr->next;
        }

        // Append newNode.
        nodePtr->next = newNode;
    }
}

/***
 * Operation insertNode: The function allocates a new node whose value is
 * equal to 'value' and insert the new node at the appropriate position.
 */
template <class T>
void List<T>::insertNode(T value)
{
    ListNode *nodePtr;      // To move through the list.
    ListNode *newNode;      // To point to a new node.
    ListNode *previousNode; // To point to the previous node.

    // Allocate a new node and store value there.
    newNode = new ListNode;
    newNode->value = value;

    // If there are no nodes in the list, then make
    // newNode the first node.
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

        // Skip all nodes whose value is less than value.
        while (nodePtr != nullptr && nodePtr->value < value)
        {
            // Make previousNode point to the nodePtr.
            previousNode = nodePtr;

            // Move to the next node.
            nodePtr = nodePtr->next;
        }

        // If the new node is to be the 1st in the list,
        // then make newNode the first node.
        if (previousNode == nullptr)
        {
            // Make the head point to the new node.
            head = newNode;

            // Make the next node of the head to be the nodePtr.
            head->next = nodePtr;
        }
        else
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

/***
 * Operation deleteNode: The function deletes a node whose value
 * is equal to 'value'
 */
template <class T>
void List<T>::deleteNode(T value)
{
    ListNode *previousNode;     // To point to the previous node.
    ListNode *nodePtr;          // To traverse the list.

    // If there are no nodes in the list, then
    // do nothing.
    if (head == nullptr)
    {
        return;
    }

    // If the first node is the one to delete.
    if (head->value == value)
    {
        // Save the next node to nodePtr.
        nodePtr = head->next;

        // Delete the first node.
        delete head;

        // Point the head to nodePtr.
        head = nodePtr;
    }

    // Otherwise, find the node to delete.
    else
    {
        // Position nodePtr at the head of the list to
        // start traversing the list.
        nodePtr = head;

        // Initialize previousNode to a null pointer.
        previousNode = nullptr;

        // Skip all nodes whose value is not equal to
        // value.
        while (nodePtr != nullptr && nodePtr->value != value)
        {
            // Make previousNode point to the current node.
            previousNode = nodePtr;

            // Make nodePtr point to the next node.
            nodePtr = nodePtr->next;
        }

        // If nodePtr is not at the end of the list, then
        // make previousNode point to the node after 
        // nodePtr and delete nodePtr.
        if (nodePtr != nullptr)
        {
            // Make previousNode point to the node after nodePtr.
            previousNode->next = nodePtr->next;

            // Delte nodePtr.
            delete nodePtr;
        }
    }
}

/***
 * Operation displayList: The function displays the values in nodes
 * in the list
 */
template <class T>
void List<T>::displayList() const
{
    ListNode *nodePtr;  // To traverse the list.

    // Initalize nodePtr to the head of the list.
    nodePtr = head;

    // While nodePtr is not a null pointer, display
    // the value of the node.
    while (nodePtr != nullptr)
    {
        // Display the value of the node.
        cout << nodePtr->value << " ";

        // Move to the next node.
        nodePtr = nodePtr->next;
    }
}

#endif