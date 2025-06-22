#ifndef INTEGER_LIST_H
#define INTEGER_LIST_H

class IntegerList
{
private:
    struct ListNode
    {
        int value;      // The value of the node.
        ListNode *next; // The pointer of the next node.
    };

    ListNode *head;     // The list head.
public:
    // Default constructor.
    IntegerList()
        { head = nullptr; }
    
    // Destructor.
    ~IntegerList();

    // Linked list operations.
    void appendNode(const int &num);
    void insertNode(const int &num);
    void deleteNode(const int &num);
    void print() const;
};
#endif