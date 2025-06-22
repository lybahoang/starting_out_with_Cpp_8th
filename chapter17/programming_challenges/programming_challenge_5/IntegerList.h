#ifndef INTEGER_LIST_H
#define INTEGER_LIST_H

class IntegerList
{
private:
    // The data structor for the node.
    struct ListNode {
        int value;      // The value of the node.
        ListNode *next; // The pointer of the next node.
    };

    // The head of the list.
    ListNode *head;

public:
    // Default constructor.
    IntegerList() { head = nullptr; }

    // Destructor.
    ~IntegerList();

    // Linked list operation.
    void appendNode(const int &value);
    void insertNode(const int &value, const int &index);
    void deleteNode(const int &value);
    void sort();
    void reverse();
    int search(const int &value);
};
#endif