struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
};

class Tree
{
public:
    Tree();
    ~Tree();
    void insert(int data);
    TreeNode* search(int data);
    void dele(int data);
private:
    TreeNode* T;
};
