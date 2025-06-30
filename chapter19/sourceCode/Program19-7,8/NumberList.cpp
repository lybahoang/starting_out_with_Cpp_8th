// Implementation file for the NumberList class.
#include "NumberList.h"
#include <iostream>
using namespace std;

/**
 * Private member function - countNodes: counts the number
 * of nodes in the list by recursion.
 * @param nodePtr: The pointer to a ListNode object.
 * @return: The number of nodes in the list.
 */
int NumberList::countNodes(ListNode *nodePtr) const
{
    // Base case.
    if (nodePtr == nullptr)
    {
        return 0;
    }
    // Recursive case.
    else
    {
        return 1 + countNodes(nodePtr->next);
    }
}

/**
 * Private member function - showReverse: Displays the nodes
 * in the list in reverse order by recursion.
 * @param nodePtr: The pointer to a ListNode object.
 * @return: void.
 */
void NumberList::showReverse(ListNode *nodePtr) const
{
    if (nodePtr != nullptr)
    {
        showReverse(nodePtr->next);
        cout << nodePtr->value << " ";
    }
}

/**
 * Destructor: Deletes all nodes in the linked list.
 */
NumberList::~NumberList()
{
    ListNode *nodePtr = head;       // To traverse the list.
    ListNode *nextNode = nullptr;   // The next node.

    // While nodePtr is not at the end of the list, then
    // delete nodePtr.
    while (nodePtr != nullptr)
    {
        // Save the node after nodePtr to nextNode.
        nextNode = nodePtr->next;

        // Delete nodePtr.
        delete nodePtr;

        // Move to the next node.
        nodePtr = nextNode;
    } 
}

/**
 * Public member function - appendNode: Inserts a new node at
 * the end of the list.
 * @param num: The new value to be inserted.
 * @return: void.
 */
void NumberList::appendNode(double num)
{
    ListNode *nodePtr = head;           // To traverse the list.
    ListNode *newNode = new ListNode;   // A new node.

    // Store num in newNode.
    newNode->value = num;
    newNode->next = nullptr;
    
    // If there are no nodes in the list, then make newNode the
    // first node.
    if (nodePtr == nullptr)
    {
        head = newNode;
    }
    // Otherwise, insert newNode at the end.
    else
    {
        // Search for the end of the list.
        while (nodePtr->next != nullptr)
        {
            nodePtr = nodePtr->next;
        }

        // Insert newNode.
        nodePtr->next = newNode;
    }
}

/**
 * Public member function - insertNode: Inserts a new node at
 * its appropriate location in the list.
 * @param num: The new value to be inserted.
 * @return: void.
 */
void NumberList::insertNode(double num)
{
    ListNode *nodePtr = head;           // To traverse the list.
    ListNode *previousNode = nullptr;   // The previous node.
    ListNode *newNode = new ListNode;   // A new node.

    // Store num in newNode.
    newNode->value = num;

    // If there are no nodes in the list, then make newNode the
    // first node.
    if (nodePtr == nullptr)
    {
        head = newNode;
        newNode->next = nullptr;
    }
    // Otherwise, insert newNode.
    else
    {
        // Skip all nodes whose value is less than num.
        while (nodePtr != nullptr && nodePtr->value < num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // If newNode is going to be inserted in the first node.
        if (previousNode == nullptr)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

/**
 * Public member function - deleteNode: Deletes a node in the
 * list, whose value is equal to num.
 * @param num: The new value to be deleted.
 * @return: void.
 */
void NumberList::deleteNode(double num)
{
    ListNode *nodePtr = head;           // To traverse the list.
    ListNode *previousNode = nullptr;   // To point to the previous node.

    // If there are no nodes in the list, then do nothing.
    if (nodePtr == nullptr)
        return;
    
    // If the first node is the one to be deleted.
    if (nodePtr->value == num)
    {
        head = nodePtr->next;
        delete nodePtr;
        return;
    }

    // Skip all nodes, whose value is not equal to num.
    while (nodePtr != nullptr && nodePtr->value != num)
    {
        previousNode = nodePtr;
        nodePtr = nodePtr->next;
    }

    // If nodePtr is not at the end of the list, then make previousNode
    // point to the node after nodePtr and delete nodePtr.
    if (nodePtr)
    {
        previousNode->next = nodePtr->next;
        delete nodePtr;
    }
}

/**
 * Public member function - displayList: Displays the values in
 * the list.
 */
void NumberList::displayList() const
{
    ListNode *nodePtr = head;       // To traverse the list.

    while (nodePtr != nullptr)
    {
        cout << nodePtr->value << " ";
        nodePtr = nodePtr->next;
    }
}