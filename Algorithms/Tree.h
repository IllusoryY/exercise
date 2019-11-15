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
    void insert(int val);
    TreeNode* search(int val);
    void dele(int val);
private:
    TreeNode* T;
};
