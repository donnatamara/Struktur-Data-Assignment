#include <iostream>
#include <queue>

using namespace std;

struct TNode
{
    int data;
    TNode *left;
    TNode *right;

    // Constructor
    TNode(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }

    // Destructor
    ~TNode()
    {
        delete left;
        delete right;
    }
};

// Fungsi untuk pencarian node berdasarkan data
TNode* findNode(TNode *root, int data)
{
    if (root == nullptr)
        return nullptr;

    queue<TNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TNode *current = q.front();
        q.pop();
        if (current->data == data)
            return current;
        if (current->left != nullptr)
            q.push(current->left);
        if (current->right != nullptr)
            q.push(current->right);
    }
    return nullptr;
}

void preOrder(TNode *node)
{
    if (node != nullptr)
    {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(TNode *node)
{
    if (node != nullptr)
    {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void postOrder(TNode *node)
{
    if (node != nullptr)
    {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

void displayChildAndDescendant(TNode *node)
{
    if (node == nullptr)
        return;

    cout << "Children of " << node->data << ": ";
    if (node->left != nullptr)
        cout << node->left->data << " ";
    if (node->right != nullptr)
        cout << node->right->data << " ";
    cout << endl;

    cout << "Descendants of " << node->data << ": ";
    queue<TNode *> q;
    q.push(node->left);
    q.push(node->right);
    while (!q.empty())
    {
        TNode *current = q.front();
        q.pop();
        if (current != nullptr)
        {
            cout << current->data << " ";
            q.push(current->left);
            q.push(current->right);
        }
    }
    cout << endl;
}

void addNode(TNode *root)
{
    int parentData, childData;
    cout << "Enter data for the parent node: ";
    cin >> parentData;
    cout << "Enter data for the child node: ";
    cin >> childData;

    TNode *parentNode = findNode(root, parentData);
    if (parentNode == nullptr)
    {
        cout << "Parent node not found. Please try again." << endl;
        return;
    }

    TNode *childNode = new TNode(childData);
    if (parentNode->left == nullptr)
        parentNode->left = childNode;
    else if (parentNode->right == nullptr)
        parentNode->right = childNode;
    else
    {
        cout << "Parent node already has two children." << endl;
        delete childNode;
    }
}

void showChildAndDescendant(TNode *root)
{
    int nodeData;
    cout << "Enter data for a node to display its children and descendants: ";
    cin >> nodeData;

    TNode *selectedNode = findNode(root, nodeData);
    if (selectedNode != nullptr)
    {
        displayChildAndDescendant(selectedNode);
    }
    else
    {
        cout << "Node not found." << endl;
    }
}

int main()
{
    cout << "Enter data for the root node: ";
    int rootData;
    cin >> rootData;

    TNode *root = new TNode(rootData);

    char choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Add a new node\n";
        cout << "2. PreOrder traversal\n";
        cout << "3. InOrder traversal\n";
        cout << "4. PostOrder traversal\n";
        cout << "5. Display children and descendants of a node\n";
        cout << "6. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            addNode(root);
            break;
        case '2':
            cout << "PreOrder traversal: ";
            preOrder(root);
            cout << endl;
            break;
        case '3':
            cout << "InOrder traversal: ";
            inOrder(root);
            cout << endl;
            break;
        case '4':
            cout << "PostOrder traversal: ";
            postOrder(root);
            cout << endl;
            break;
        case '5':
            showChildAndDescendant(root);
            break;
        case '6':
            cout << "Thank you, program terminated." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != '6');

    delete root; // Menghapus root dan semua turunannya
    return 0;
}
