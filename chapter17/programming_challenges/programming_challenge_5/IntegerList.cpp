#include "IntegerList.h"

// Destructor.
IntegerList::~IntegerList()
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

// Operation IntegerList::appendNode
void IntegerList::appendNode(const int &value)
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

// Operation IntegerList::insertNode
// Operation IntegerList::deleteNode
void IntegerList::deleteNode(const int &value)
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

// Operation IntegerList::reverse
void IntegerList::reverse()
{
    // Base case: If the list is empty or has only
    // one node, do nothing as it is already
    // reversed.
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }
    // Recursive step: Reverse the linked list 
    // starting from the second node.
    
}