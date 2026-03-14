// Binary search tree
#include <iostream>
#include <limits>

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int d) : data(d), left(NULL), right(NULL) {}
};

class BST
{
public:
    TreeNode *root;
    BST() : root(NULL) {}
    BST(TreeNode *node) : root(node) {}

    TreeNode *insert(int value)
    {
        root = Recursive_insertion(root, value);
        return root;
    }

    void printPreorder(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        std::cout << root->data << " ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
    int countNodes(TreeNode *root, int &Count) {
    if (root == NULL) {
        return Count;
    }

    Count++;  // Increment the count for the current node
    countNodes(root->left, Count);  // Recursive call for the left subtree
    countNodes(root->right, Count); // Recursive call for the right subtree

    return Count; // Return the count (optional if not used elsewhere)
}

void Max(TreeNode *root) {
    if (root->right == NULL) {
        std::cout << "The largest node: " << root->data << std::endl;
        return ;
    }
    
     Max(root->right); // Recursive call for the right subtree
}
void Min(TreeNode *root) {
    if (root->left == NULL) {
        std::cout << "The smallest node: " << root->data << std::endl;
        return;
    }
    
     Min(root->left); // Recursive call for the right subtree
}

    void printInorder(TreeNode *root)
    {
        if (root == NULL)
        {
            return;          
        }
        printInorder(root->left);
        std::cout << root->data << " ";
        printInorder(root->right);
    }

    void printPostorder(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        printPostorder(root->left);
        printPostorder(root->right);
        std::cout << root->data << " ";
    }

    void printIn2_D(TreeNode *root, int space)
    {
        if (root == NULL)
            return;

        space += 5;
        printIn2_D(root->right, space);
        std::cout << std::endl;

        for (int i = 5; i < space; i++)
            std::cout << " ";

        std::cout << root->data << std::endl;
        printIn2_D(root->left, space);
    }

    void iterativeSearch(int value)
    {
        TreeNode *current = root;
        while (current != NULL)
        {
            if (value < current->data)
                current = current->left;

            else if (value > current->data)
                current = current->right;

            else
            {
                std::cout << "Found: " << value << std::endl;
                return;
            }
        }
        std::cout << "Not Found: " << value << std::endl;
    }

    void RecursiveSearch(TreeNode *Node, int value)
    {
        if (Node == NULL)
        {
            std::cerr << "Value not found!" << std::endl;
            return;
        }

        if (Node->data == value)
        {
            std::cout << "Found: " << value << std::endl;
            return;
        }

        else if (Node->data > value)
            RecursiveSearch(Node->left, value);
        else
            RecursiveSearch(Node->right, value);
    }

    int height(TreeNode *Node)
    {
        if (Node == NULL)
        {
            return -1;     
        }
        int leftHeight = height(Node->left);
        int rightHeight = height(Node->right);
        return std::max(leftHeight, rightHeight) + 1;
    }

    void breadth_firstPrinting(TreeNode *Node, int level)
    {
        if (Node == NULL)
            return;
        if (level == 0)
            std::cout << Node->data << " ";
        else
        {
            breadth_firstPrinting(Node->left, level - 1);
            breadth_firstPrinting(Node->right, level - 1);
        }
    }
    int minValue(TreeNode *Node)
    {
        int minValue = Node->data;
        while (Node->left != NULL)
        {
            minValue = Node->left->data;
            Node = Node->left;
        }
        return minValue;
    }
    TreeNode *deletenode(TreeNode *Node, int value)
    {
        if (Node == NULL)
            return Node;
        if (value < Node->data)
            Node->left = deletenode(Node->left, value);
        else if (value > Node->data)
            Node->right = deletenode(Node->right, value);

        else
        {
            if (Node->left == NULL)
            {
                TreeNode *temp = Node->right;
                delete Node;
                return temp;
            }

            else if (Node->right == NULL)
            {
                TreeNode *temp = Node->left;
                delete Node;
                return temp;
            }
            else
            {
                Node->data = minValue(Node->right);
                Node->right = deletenode(Node->right, Node->data);
            }
        }
        return Node;
    }

    TreeNode *Recursive_insertion(TreeNode *Node, int value)
    {
        if (Node == NULL)
            return new TreeNode(value);
        if (value < Node->data)
            Node->left = Recursive_insertion(Node->left, value);

        else if (value > Node->data)
            Node->right = Recursive_insertion(Node->right, value);

        else
        {
            std::cerr << "Duplicates not allowed!" << std::endl;
            return Node;
        }
        return Node;
    }

    void deleteTree(TreeNode *node)
    {
        if (node != nullptr)
        {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

    ~BST()
    {

        deleteTree(root);
        root = NULL;
    }
};
int main()
{
    BST tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.printPreorder(tree.root);
    std::cout << std::endl;
    tree.printInorder(tree.root);
    std::cout << std::endl;
    tree.printPostorder(tree.root);
    std::cout << std::endl;
    tree.printIn2_D(tree.root, 0);
    tree.iterativeSearch(5);
    std::cout << std::endl;
    tree.RecursiveSearch(tree.root, 69);
    tree.insert(20);
    tree.printIn2_D(tree.root, 0);
    int c = 0;
    std::cout << "The no of nodes is: " << tree.countNodes(tree.root, c);
    tree.Min(tree.root);
    tree.Max(tree.root);
    int height = tree.height(tree.root);
    for (int i = 0; i < height; i++)
    {
        std::cout << "Level " << i << ": ";
        tree.breadth_firstPrinting(tree.root, i);
        std::cout << std::endl;
    }

    std::cout << "Height of the tree: " << height << std::endl;
    tree.breadth_firstPrinting(tree.root, height);
    tree.root = tree.deletenode(tree.root, 15);
    tree.printIn2_D(tree.root, 0);
    return 0;
}