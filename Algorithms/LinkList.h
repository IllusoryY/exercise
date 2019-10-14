#ifndef LINKLIST_H__
#define LINKLIST_H__
//This is exercise code for List

using Position = int;
struct Node
{
    int val;
    Node* next;
};

class LinkList
{
public:
    LinkList()
        : node(new Node()) { header->val = 0; header->next = nullptr; }
    ~LinkList() 
    {
        delete header;
            
    }
    void InitLinklist(int n);
    void InsertNode(Position , int );
    void PrintLinkList();
    int Length();
    bool IsEmpty();
    void DeleteNode(Position);
    void DeleteLinkList();
private:
    Node* header; 
};


#endif
