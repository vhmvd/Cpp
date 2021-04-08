#ifndef AVL_h
#define AVL_h

#include<iostream>
using namespace std;

template <typename Key, typename Info>
class Dictionary
{
private:
    struct node
    {
        Info info;
        Key key;
        int height;
        node* left;
        node* right;
        node(Key k)
        {
            height = 1;
            key = k;
            left = NULL;
            right = NULL;
            info = NULL;
        }
        node(Key k,Info i)
        {
            height = 1;
            key = k;
            left = NULL;
            right = NULL;
            info = i;
        }
        ~node()
        {
            delete left;
            delete right;
        }
    };

    node* root=NULL;
    int n;

    Key max(Key a, Key b)
    {
        return (a > b) ? a : b;
    }

    int height(node* head)
    {
        if (head == NULL)
            return 0;
        return head->height;
    }

    node* rightRotation(node* head)
    {
        node* newhead = head->left;
        head->left = newhead->right;
        newhead->right = head;
        head->height = 1 + max(height(head->left), height(head->right));
        newhead->height = 1 + max(height(newhead->left), height(newhead->right));
        return newhead;
    }

    node* leftRotation(node* head)
    {
        node* newhead = head->right;
        head->right = newhead->left;
        newhead->left = head;
        head->height = 1 + max(height(head->left), height(head->right));
        newhead->height = 1 + max(height(newhead->left), height(newhead->right));
        return newhead;
    }

    void inOrderDisplay(node* head)
    {
        if (head == NULL)
            return;
        inOrderDisplay(head->left);
        cout << head->key << " ";
        inOrderDisplay(head->right);
    }

    node* inserter(node* head, Key x)
    {
        if (head == NULL)
        {
            n += 1;
            node* temp = new node(x);
            return temp;
        }
        if (x < head->key)
            head->left = inserter(head->left, x);
        else if (x > head->key)
            head->right = inserter(head->right, x);
        head->height = 1 + max(height(head->left), height(head->right));
        int bal = height(head->left) - height(head->right);
        if (bal > 1)
        {
            if (x < head->left->key)
            {
                return rightRotation(head);
            }
            else
            {
                head->left = leftRotation(head->left);
                return rightRotation(head);
            }
        }
        else if (bal < -1)
        {
            if (x > head->right->key)
            {
                return leftRotation(head);
            }
            else
            {
                head->right = rightRotation(head->right);
                return leftRotation(head);
            }
        }
        return head;
    }

    node* remover(node* head, Key x)
    {
        if (head == NULL) return NULL;
        if (x < head->key)
        {
            head->left = remover(head->left, x);
        }
        else if (x > head->key)
        {
            head->right = remover(head->right, x);
        }
        else
        {
            node* r = head->right;
            if (head->right == NULL)
            {
                node* l = head->left;
                delete(head);
                head = l;
            }
            else if (head->left == NULL)
            {
                delete(head);
                head = r;
            }
            else
            {
                while (r->left != NULL) r = r->left;
                head->key = r->key;
                head->right = remover(head->right, r->key);
            }
        }
        if (head == NULL)
            return head;
        head->height = 1 + max(height(head->left), height(head->right));
        int bal = height(head->left) - height(head->right);
        if (bal > 1)
        {
            if (x > head->left->key)
            {
                return rightRotation(head);
            }
            else
            {
                head->left = leftRotation(head->left);
                return rightRotation(head);
            }
        }
        else if (bal < -1)
        {
            if (x < head->right->key)
                return leftRotation(head);
            else
            {
                head->right = rightRotation(head->right);
                return leftRotation(head);
            }
        }
        return head;
    }

    node* searcher(node* head, Key x)
    {
        if (head == NULL)
            return NULL;
        Key k = head->key;
        if (k == x)
            return head;
        if (k > x)
            return searcher(head->left, x);
        if (k < x)
            return searcher(head->right, x);
    }

    node* changer(node* head, Key x)
    {
        if (head == NULL)
            return NULL;
        Key k = head->key;
        if (k == x)
        {
            cout << "\nEnter new data to change at key " << k << "\n";
            cin >> k;
        }
        if (k > x)
            return searcher(head->left, x);
        if (k < x)
            return searcher(head->right, x);
    }

    void print(const string& prefix, const node* n, bool isLeft)
    {
        if (n != nullptr)
        {
            cout << prefix;
            cout << (isLeft ? "|-" : "|_");
            cout << n->key << endl;
            print(prefix + (isLeft ? "|   " : "    "), n->left, true);
            print(prefix + (isLeft ? "|   " : "    "), n->right, false);
        }
    }

    void copy(node* n)
    {
        if (n)
        {
            insert(n->key);
            copy(n->left);
            copy(n->right);
        }
    }

public:
    Dictionary();
    ~Dictionary();
    void insert(Key);
    void remove(Key);
    node* search(Key x)
    {
        return searcher(root, x);
    }
    void inorder();
    void change(Key);
    void print();
    const Dictionary<Key, Info>& operator=(const Dictionary<Key, Info>&);
};

#endif // !AVL_h
