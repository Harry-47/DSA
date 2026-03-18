//Binary search tree
#include<iostream>
#include<limits>

class TreeNode{
  public:
  
  int value;
  TreeNode *left;
  TreeNode *right;

  TreeNode(): value(0), left(NULL), right(NULL) {}
  TreeNode(int d): value(d), left(NULL), right(NULL) {}
};

class BST{
public:
    TreeNode *root;
    BST(): root(NULL) {}
    BST(TreeNode *node): root(node) {}
    
    
  int height(TreeNode *Node){
    if(Node == NULL){
        return -1;
    }
    int leftHeight = height(Node->left);
    int rightHeight = height(Node->right);
    return std::max(leftHeight, rightHeight) + 1;
   }
  
  // Get Balance factor of node N  
  int getBalanceFactor(TreeNode * n) {
    if (n == NULL)
      return -1;
    return height(n -> left) - height(n -> right);
  }

  TreeNode * rightRotate(TreeNode * y) {
    TreeNode * x = y -> left;
    TreeNode * T2 = x -> right;

    // Perform rotation  
    x -> right = y;
    y -> left = T2;

    return x;
  }

  TreeNode * leftRotate(TreeNode * x) {
    TreeNode * y = x -> right;
    TreeNode * T2 = y -> left;

    // Perform rotation  
    y -> left = x;
    x -> right = T2;

    return y;
  }

    void insert(int value){
    root = Recursive_insertion(root, value);
    }

    void printPreorder(TreeNode *root){
        if(root == NULL){
             return;
        }
        std::cout << root->value << " ";
        printPreorder(root->left);
        printPreorder(root->right);
        }

    void printInorder(TreeNode *root){
        if(root == NULL){
             return;
        }
        printInorder(root->left);
        std::cout << root->value << " ";
        printInorder(root->right);
        }

     void printPostorder(TreeNode *root){
        if(root == NULL){
             return;
        }
        printPostorder(root->left);
        printPostorder(root->right);
        std::cout << root->value << " ";
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

        std::cout << root->value << std::endl;
        printIn2_D(root->left, space);
    }

    void iterativeSearch(int value)
    {
        TreeNode *current = root;
        while (current!= NULL) {
            if (value < current->value)
                current = current->left;

            else if (value > current->value)
                current = current->right;

            else {
                std::cout << "Found " << value <<"!" << std::endl;
                return;
            }
        }
        std::cout << "Not Found: " << value << std::endl;
    }
    
    void RecursiveSearch(TreeNode *Node,int value){
        if(Node == NULL){
        std::cerr << "Value not found!" << std::endl;
            return; 
        }


        if(Node->value == value){
            std::cout << "Found " << value << "!" << std::endl;
            return;
        }

       else if(Node->value > value)
         RecursiveSearch(Node->left, value);
       else 
          RecursiveSearch(Node->right, value);
    }
   
void breadth_firstPrinting(TreeNode *Node, int level){
    if(Node == NULL)
        return;
    if(level == 0)
        std::cout << Node->value << " ";
    else{
        breadth_firstPrinting(Node->left, level - 1);
        breadth_firstPrinting(Node->right, level - 1);
      }
    }
int minValue(TreeNode* Node) {
   int minValue = Node->value;
   while (Node->left != NULL) {
      minValue = Node->left->value;
      Node = Node->left;
     }
    return minValue;
}
TreeNode* deltenode(TreeNode *r, int value){
    if(r == NULL)
        return r;
    if(value < r->value)
        r->left = deltenode(r->left, value);
    else if(value >r->value)
        r->right = deltenode(r->right, value);

    else{
        if(r->left == NULL) {
          TreeNode * temp = r->right;
          delete r;
          return temp;
        }

        else if(r->right == NULL){
          TreeNode * temp = r->left;
          delete r;
          return temp;
        
        }
        else{
        r->value = minValue(r->right);
        r->right = deltenode(r->right, r->value);
        }
    }
     int bf = getBalanceFactor(r);
    // Left Left Imbalance/Case or Right rotation 
    if (bf == 2 && getBalanceFactor(r -> left) >= 0)
      return rightRotate(r);
    // Left Right Imbalance/Case or LR rotation 
    else if (bf == 2 && getBalanceFactor(r -> left) == -1) {
      r -> left = leftRotate(r -> left);
      return rightRotate(r);
    }
    // Right Right Imbalance/Case or Left rotation	
    else if (bf == -2 && getBalanceFactor(r -> right) <= -0)
      return leftRotate(r);
    // Right Left Imbalance/Case or RL rotation 
    else if (bf == -2 && getBalanceFactor(r -> right) == 1) {
      r -> right = rightRotate(r -> right);
      return leftRotate(r);
    }

    return r;
   }

 TreeNode * Recursive_insertion(TreeNode *r, int value)
 {
    if(r== NULL)
        return new TreeNode(value);

    if(value < r->value)
        r->left = Recursive_insertion(r->left, value);
   
    else if(value > r->value)
        r->right = Recursive_insertion(r->right, value);
   
    else {std::cerr << "Duplicates not allowed!" << std::endl;
      return r;
       }
    
    int bf = getBalanceFactor(r);
    // Left Left Case  
    if (bf > 1 && value < r -> left -> value)
      return rightRotate(r);

    // Right Right Case  
    if (bf < -1 &&  value > r -> right -> value)
      return leftRotate(r);

    // Left Right Case  
    if (bf > 1 &&  value > r -> left -> value) {
      r -> left = leftRotate(r -> left);
      return rightRotate(r);
    }

    // Right Left Case  
    if (bf < -1 &&  value < r -> right -> value) {
      r -> right = rightRotate(r -> right);
      return leftRotate(r);
    }

    /* return the (unchanged) node pointer */
    return r;
 }

void deleteTree(TreeNode* node) {
        if (node != nullptr) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

 ~BST(){
    
    deleteTree(root);
    root = NULL;
 }
};
int main() {
    BST myTree;
    int choice, value;

    do {

        std::cout << "\nAVL Tree Operations Menu:\n";
        std::cout << "1. Insert a value\n";
        std::cout << "2. Delete a value\n";
        std::cout << "3. Search for a value (Iterative)\n";
        std::cout << "4. Search for a value (Recursive)\n";
        std::cout << "5. Print In-order\n";
        std::cout << "6. Print Pre-order\n";
        std::cout << "7. Print Post-order\n";
        std::cout << "8. Print Level-order\n";
        std::cout << "9. Print height of the tree\n";
        std::cout << "10. Print tree in 2D\n";
        std::cout << "11. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                myTree.insert(value);
                break;
            case 2:
                std::cout << "Enter value to delete: ";
                std::cin >> value;
                myTree.root = myTree.deltenode(myTree.root, value);
                break;
            case 3:
                std::cout << "Enter value to search (Iterative): ";
                std::cin >> value;
                myTree.iterativeSearch(value);
                break;
            case 4:
                std::cout << "Enter value to search (Recursive): ";
                std::cin >> value;
                myTree.RecursiveSearch(myTree.root, value);
                break;
            case 5:
                std::cout << "In-order traversal: ";
                myTree.printInorder(myTree.root);
                std::cout << std::endl;
                break;
            case 6:
                std::cout << "Pre-order traversal: ";
                myTree.printPreorder(myTree.root);
                std::cout << std::endl;
                break;
            case 7:
                std::cout << "Post-order traversal: ";
                myTree.printPostorder(myTree.root);
                std::cout << std::endl;
                break;
            case 8:
                std::cout << "Level-order traversal: ";
                for (int i = 0; i <= myTree.height(myTree.root); i++) {
                    myTree.breadth_firstPrinting(myTree.root, i);
                }
                std::cout << std::endl;
                break;
            case 9:
                std::cout << "Height of the tree: " << myTree.height(myTree.root) << std::endl;
                break;
            case 10:
                std::cout << "Tree in 2D:\n";
                myTree.printIn2_D(myTree.root, 0);
                break;
            case 11:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice! Please enter a number between 1 and 11.\n";
        }
    } while (choice != 11);

    return 0;
}
