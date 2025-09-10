/**
 * This is a generic template class for number linked lists with
 * several basic operations.
 */

#ifndef NUMBER_LIST_H
#define NUMBER_LIST_H

#include <string>
#include <iostream>
using namespace std;

template <class T>
class NumberList
{
private:
    // A structure for the list node.
    struct ListNode
    {
        T value;            // The value of the node.
        ListNode *next;     // The pointer to the next node.
    };

    ListNode *head;         // The head of the list.

    void show(const ListNode *) const;
    T findMax(const ListNode *) const;
public:
    // Constructor.
    NumberList() { head = nullptr; }

    // Destructor.
    ~NumberList();

    // Basic operations.
    void appendNode(T);
    void deleteNode(T);
    void displayList() const;
    T maxNode() const;
};

/**
 * Destructor. The destructor deletes all nodes in the list.
 */
template <class T>
NumberList<T>::~NumberList()
{
    ListNode *nodePtr = head;        // To traverse the list.
    ListNode *nextNode = nullptr;   // To point to the next node.

    // While nodePtr is not nullPtr, delete nodePtr.
    while (nodePtr)
    {
        // Save the node after nodePtr to nextNode.
        nextNode = nodePtr->next;

        // Delete nodePtr;
        delete nodePtr;

        // Move nodePtr to the next node.
        nodePtr = nextNode;
    }
}

/**
 * Operation appendNode(T): The function accepts an argument and then add
 * a new node containing the value at the end of the list.
 * @param num (T): The value of the new node.
 * @return void.
 */
template <class T>
void NumberList<T>::appendNode(T num)
{
    // Allocate a new node and store num there.
    ListNode *newNode = new ListNode;
    newNode->value = num;
    newNode->next = nullptr;

    // Create a ListNode to traverse the list.
    ListNode *nodePtr = nullptr;

    // If the list is empty, then make newNode the first node.
    if (!head)
    {
        head = newNode;
    }
    // Otherwise, insert newNode at end.
    else
    {
        // Position nodePtr at the head of the list.
        nodePtr = head;
        
        // Search for the last node in the list.
        while (nodePtr->next)
        {
            nodePtr = nodePtr->next;
        }

        // Insert newNode as the last node.
        nodePtr->next = newNode;
    }
}

/**
 * Operation deleteNode(T): The function accepts an argument about a value in
 * the node, which will be deleted.
 * @param num (T): The value in the node, which will be deleted.
 * @return void.
 */
template <class T>
void NumberList<T>::deleteNode(T num)
{
    // If there are no nodes in the list, do nothing.
    if (!head)
        return;
    
    // Otherwise, search for the node containing num.
    ListNode *nodePtr = head;           // To traverse the list.
    ListNode *previousNode = nullptr;   // To point to the previous node.

    // Skip all nodes whose value is not equal to num.
    while (nodePtr != nullptr && nodePtr->value != num)
    {
        previousNode = nodePtr;
        nodePtr = nodePtr->next;
    }

    // If nodePtr is not at the end of the list, link the previous
    // node to the node after nodePtr, then delete nodePtr.
    if (nodePtr)
    {
        previousNode->next = nodePtr->next;
        delete nodePtr;
    }
}

/**
 * Operation displayList(): The function displays the contents of the list.
 * @param void.
 * @return void.
 */
template <class T>
void NumberList<T>::displayList() const
{
    show(head);
}

/**
 * Operation maxNode(): The function returns the largest value stored in the list.
 * @param void.
 * @return the largest value in the list (T).
 */
template <class T>
T NumberList<T>::maxNode() const
{
    return findMax(head);
}

/**
 * Function show(ListNode *): The function accepts a pointer to the head of a 
 * list, and then display the contents of the list.
 * @param nodePtr (ListNode *): The head of the list.
 * @return void.
 */
template <class T>
void NumberList<T>::show(const ListNode *nodePtr) const
{
    if (nodePtr != nullptr)
    {
        cout << nodePtr->value << " ";
        show(nodePtr->next);
    }
}

/**
 * Function findMax(ListNode *): The function finds the largest value stored in
 * the list.
 * @param nodePtr (ListNode *): The head of a list.
 * @return The largest value in the list (T).
 */
template <class T>
T NumberList<T>::findMax(const ListNode *nodePtr) const
{
    // Base case 1: If the nodePtr is nullptr, then throws an exception.
    if (nodePtr == nullptr)
    {
        string exceptStr = "No maximum value found: The list is empty.";
        throw exceptStr;
    }

    // Base case 2: If the list contains only one node.
    if (nodePtr->next == nullptr)
    {
        return nodePtr->value;
    }
    // Recursive step: Return the larger value between the nodePtr and
    // the largest value in all next node.
    return (nodePtr->value > findMax(nodePtr->next) ? 
            nodePtr->value : findMax(nodePtr->next));
}
#endif