#ifndef INTEGER_LIST_H
#define INTEGER_LIST_H

class IntegerList
{
private:
    struct ListNode
    {
        int value;          // The data of the node.
        ListNode* next;   // The pointer of the next node.
    };

    ListNode* head;       // The list head.
public:
    // Exception class.
    class InvalidIndex
    {
    private:
        int index;
    public:
        InvalidIndex(int i)
            { index = i; }
        int getInvalidIndex() const
            { return index; }
    };
    
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
    int countNode() const;
    void pop_back();

    // Overloaded operator.
    int &operator[](int);
};
#endif