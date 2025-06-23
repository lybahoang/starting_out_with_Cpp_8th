#include "IntegerList.h"
#include "iostream"
using namespace std;


// Linked list operation: ListNode::appendNote
void IntegerList::appendNode(int value)
{
    ListNode* nodePtr;    // To move through the list.
    ListNode* newNode;    // The new node.

    // Create a new node.
    newNode = new ListNode;

    // Store data in the new node.
    newNode->value = value;
    newNode->next = nullptr;

    // If there are no nodes in the list, then
    // make the new node the first node.
    if (head == nullptr)
    {
        head = newNode;
    }
    // Else, find the last node and add the new node to
    // the end of the list.
    else
    {
        // Initialize nodePtr to head of list.
        nodePtr = head;

        // Find the last node in the list.
        while(nodePtr->next != nullptr)
        {
            nodePtr = nodePtr->next;
        }

        // Add the new node to the end of the list.
        nodePtr->next = newNode;
    }
}

// Linked list operation: IntegerList::insertNode
void IntegerList::insertNode(int value)
{
    ListNode *newNode;        // A new node.
    ListNode *previousNode;   // The previous node.
    ListNode *nodePtr;        // To traverse the list.

    // Allocate a new node and store value there.
    newNode = new ListNode;
    newNode->value = value;
    
    // If there are no nodes in the list, then make
    // the new node the first node.
    if (head == nullptr)
    {
        head = newNode;
        newNode->next = nullptr;
    }
    else    // Otherwise, insert newNode.
    {
        // Position nodePtr at the head of the list.
        nodePtr = head;

        // Initialize previousNode to nullptr.
        previousNode = nullptr;

        // Skip all nodes whose value is less than value.
        while (nodePtr != nullptr && nodePtr->value < value)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        
        // If the new node is to be the 1st in the list
        // insert it before all other nodes.
        if (previousNode == nullptr)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else    // Otherwise, insert after the previousNode.
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

// Linked list operation: IntegerList::deleteNode
void IntegerList::deletingNode(int value)
{
    ListNode *nodePtr;        // To traverse the list.
    ListNode *previousNode;   // To point to the previous node.

    // If the list is empty, do nothing.
    if (head == nullptr)
    {
        return;
    }

    // Determine if the first node is the one.
    if (head->value == value)
    {   
        // Initalize nodePtr to the next node.
        nodePtr = head->next;
        // Delete the first node.
        delete head;
        // Assign the nodePtr to the head.
        head = nodePtr;
    }
    else
    {
        // Initialize nodePtr to head of list.
        nodePtr = head;

        // Skip all nodes whose value member is not
        // equal to value.
        while (nodePtr != nullptr && nodePtr->value != value)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // If nodePtr is not at the of the list,
        // link the previous node to the node after
        // nodePtr, then delete nodePtr.
        if (nodePtr != nullptr)
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

// Destructor.
IntegerList::~IntegerList()
{
    ListNode *nodePtr;    // To traverse the list.
    ListNode *nextNode;   // To point to the next node.

    // Position the nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr is not at the end of the list.
    while (nodePtr != nullptr)
    {
        // Save a pointer to the next node.
        nextNode = nodePtr->next;

        // Delete the current node.
        delete nodePtr;

        // Position nodePtr at the next node.
        nodePtr = nextNode;
    }
}

// Function IntegerList::displayList
void IntegerList::displayList() const
{
    ListNode *nodePtr;    // To traverse the list.

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr points to a node, traverse
    // the list.
    while (nodePtr != nullptr)
    {
        // Display the value in the node.
        cout << nodePtr->value << " ";

        // Move to the next node.
        nodePtr = nodePtr->next;
    }

}

/***
 * Operation countNode: The operation counts and returns the number
 * of nodes in the linked list
 */
int IntegerList::countNode() const
{
    ListNode *nodePtr = nullptr;    // To traverse the list.
    int count = 0;                    // To count the node.

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // Count the number of nodes.
    while (nodePtr != nullptr)
    {
        count++;
        nodePtr = nodePtr->next;
    }

    return count;
}
/***
 * Overloaded operator[]: The operator returns a reference to
 * a node specified by 'index'
 */
int &IntegerList::operator[](int index)
{
    // If the 'index' is invalid, then throw an exception.
    if (index < 0 || index >= this->countNode())
        throw InvalidIndex(index);

    // Otherwise, return a reference to the value in the node.
    ListNode *nodePtr = head;     // To traverse the list.
    int count = 0;                  // Loop counter.

    while (count != index)
    {
        nodePtr = nodePtr->next;
        count++;
    }

    return nodePtr->value;
}

/***
 * Operation pop_back: The operation removes the last node
 * in the linked list.
 */
void IntegerList::pop_back()
{
    ListNode *nodePtr = nullptr;        // To traverse the list.
    ListNode *previousNode = nullptr;   // To point to the previous node.

    // If there are no nodes in the list, do nothing.
    if (head == nullptr)
        return;

    // If there's only one node in the list, delete it and set head to nullptr.
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    // Position nodePtr at the head of the list.
    nodePtr = head;

    // Search for the last node in the list.
    while (nodePtr->next != nullptr)
    {
        previousNode = nodePtr;
        nodePtr = nodePtr->next;
    }

    // Remove the last node in the list.
    delete nodePtr;

    // Make the node after the previous node a nullptr.
    previousNode->next = nullptr;
}