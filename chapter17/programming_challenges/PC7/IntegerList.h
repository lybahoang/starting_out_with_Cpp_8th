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
    void appendNode(int);
    void deleteNode(int);
    void displayList() const;
    void insertNode(int);
    void reverse();
    int search(int);
    void insertNodeByPosition(int, int);
    int countNode() const;
    void removeByPosition(int);
};
#endif