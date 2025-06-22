#ifndef INTEGER_LIST_H
#define INTEGER_LIST_H

class IntegerList
{
private:
    struct ListNode
    {
        int value;              // The value of the node.
        struct ListNode *next;  // The pointer of next node.
    };

    ListNode *head;             // The head list.
public:
    // Default constructor.
    IntegerList()
        { head = nullptr; }
    
    // Copy constructor.
    IntegerList(const IntegerList &other);

    // Destructor.
    ~IntegerList();

    // Linked list operations.
    void appendNode(int num);
    void insertNode(int num);
    void deleteNode(int num);
    void displayList() const;
};
#endif