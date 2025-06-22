#ifndef INTEGER_LIST_H
#define INTEGER_LIST_H

class IntegerList
{
private:
    struct ListNode
    {
        int value;      // The value of the node.
        ListNode *next; // Pointer to the next node.
    };

    ListNode *head;     // The head of the list.
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
    void display() const;
    void reverse();
};
#endif