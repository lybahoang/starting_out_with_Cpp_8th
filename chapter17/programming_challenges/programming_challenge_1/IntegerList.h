#ifndef INTEGER_LIST_H
#define INTEGER_LIST_H

class IntegerList
{
private:
    struct LinkedNode
    {
        int value;          // The data of the node.
        LinkedNode* next;   // The pointer of the next node.
    };

    LinkedNode* head;       // The list head.
public:
    // Constructor.
    IntegerList()
        { head = nullptr; }

    // Destructor.
    ~IntegerList();

    // Linked list operations.
    void appendNode(int value);
    void insertNode(int value);
    void deletingNode(int value);
    void displayList() const;
};
#endif