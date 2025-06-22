#include "IntegerList.h"
#include <iostream>
using namespace std;

// Copy constructor.
IntegerList::IntegerList(const IntegerList &other)
{
    ListNode *currentNode;      // To traverse the current list.
    ListNode *newNode;          // A new node.
    ListNode *otherCurrentNode; // To traverse the other list.

    // If there are no nodes in the other list, make
    // the head of the current list point to a null pointer.
    if (other.head == nullptr)
    {
        this->head = nullptr;
    }
    // Otherwise, copy all nodes.
    else
    {
        // Initialize the otherCurrentNode to the head of other.
        otherCurrentNode = other.head;

        // Copy the first node.
        newNode = new ListNode;
        newNode->value = otherCurrentNode->value;
        newNode->next = nullptr;
        this->head = newNode;

        // Move otherCurrentNode to the next node.
        otherCurrentNode = otherCurrentNode->next;

        // Move the currentNode to the head.
        currentNode = this->head;

        // Copy all nodes.
        while (otherCurrentNode != nullptr)
        {
            // Allocate a new node with the data.
            newNode = new ListNode;
            newNode->value = otherCurrentNode->value;
            newNode->next = nullptr;

            // Append the newNode to the current list.
            currentNode->next = newNode;

            // Move currentNode to the next node.
            currentNode = currentNode->next;

            // Move otherCurrentNode to the next node.
            otherCurrentNode = otherCurrentNode->next;
        }
    }
}

// Destructor.
IntegerList::~IntegerList()
{
    ListNode *nodePtr;      // To traverse the list.
    ListNode *nextNode;     // To point to the next node.

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr is not at the end of the list.
    while (nodePtr != nullptr)
    {   
        // Save the next node to nextNode.
        nextNode = nodePtr->next;

        // Delete the current node.
        delete nodePtr;

        // Position nodePtr to the next node.
        nodePtr = nextNode;
    }
}

// Operation: IntegerList::appendNode
void IntegerList::appendNode(int num)
{
    ListNode *nodePtr;      // To traverse the list.
    ListNode *newNode;      // A new node.

    // Allocate a new node and store num there.
    newNode = new ListNode;
    newNode->value = num;
    newNode->next = nullptr;

    // If there are no nodes in the list, make
    // newNode the first node.
    if (head == nullptr)
    {
        head = newNode;
    }
    // Otherwise, append newNode.
    else
    {
        // Position nodePtr to the head of the list.
        nodePtr = head;

        // Find the last node in the list.
        while (nodePtr->next != nullptr)
        {
            nodePtr = nodePtr->next;
        }

        // Insert newNode at the end of the list.
        nodePtr->next = newNode;
    }
}

// Operation: IntegerList::insertNode
void IntegerList::insertNode(int num)
{
    ListNode *nodePtr;      // To traverse the list.
    ListNode *newNode;      // A new node.
    ListNode *previousNode; // To point to the previous node.

    // Allocate a new node and store num there.
    newNode = new ListNode;
    newNode->value = num;

    // If there are no nodes in the list, make
    // newNode the first node.
    if (head == nullptr)
    {
        head = newNode;
        newNode->next = nullptr;
    }
    // Otherwise, insert newNode.
    else
    {
        // Position nodePtr at the head of the list.
        nodePtr = head;

        // Initialize previousNode to nullptr.
        previousNode = nullptr;

        // Skip all nodes whose value is less than num.
        while (nodePtr != nullptr && nodePtr->value < num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // If the newNode is to the 1st in the list,
        // then insert it before all other nodes.
        if (previousNode == nullptr)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else    // Otherwise, insert after previousNode.
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

// Operation: IntegerList::deleteNode
void IntegerList::deleteNode(int num)
{
    ListNode *nodePtr;      // To traverse the list.
    ListNode *previousNode; // To point to the previous node.

    // If there are no nodes in the list, do nothing.
    if (head == nullptr)
    {
        return;
    }
    
    // Determine if the first node is the one to delete.
    if (head->value == num)
    {
        // Save the next node.
        nodePtr = head->next;

        // Delete the first node.
        delete head;

        // Make head point to the new first node.
        head = nodePtr;
    }
    else
    {
        // Position nodePtr to the head of the list.
        nodePtr = head;

        // Skip all nodes whose value is not equal to num.
        while (nodePtr != nullptr && nodePtr->value != num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // If nodePtr is not at the end of the list,
        // link the previous node to the node after
        // nodePtr, then delete the nodePtr.
        if (nodePtr != nullptr)
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

// Operation: InegerList::dipslat
void IntegerList::display() const
{
    ListNode *nodePtr;  // To traverse the list.

    // Initialize the nodePtr to the head of the list.
    nodePtr = head;

    // While nodePtr points to a node, display the value
    // of the node.
    while (nodePtr != nullptr)
    {
        // Display the value of the node.
        cout << nodePtr->value << " ";

        // Move to the next node.
        nodePtr = nodePtr->next;
    }
    
}

// Operation: IntegerList::reverse
void IntegerList::reverse()
{
    ListNode *previousNode; // To point to the previous node.
    ListNode *currentNode;  // To point to the current node.
    ListNode *nextNode;     // To point to the next node.

    // Initialize previousNode to a null pointer.
    previousNode = nullptr;

    // If there are no nodes in the list, do nothing
    if (head == nullptr)
    {
        return;
    }
    else
    {
        // Position currentNode to the head of the list.
        currentNode = head;

        // While the currentNode is not at the end of the list.
        while (currentNode != nullptr)
        {
            // Save the next node to nextNode.
            nextNode = currentNode->next;

            // Make the current node point to the previous node.
            currentNode->next = previousNode;

            // Make the previousNode point to the current node.
            previousNode = currentNode;
            
            // Make the next node to be the current node.
            currentNode = nextNode;
        }
    }

    // Finally make the head point to the current node.
    head = previousNode;
}