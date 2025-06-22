#ifndef LINKED_LIST_H
#define LINKED_LIST_H

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
};

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

#endif