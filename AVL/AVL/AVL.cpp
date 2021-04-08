#include "AVL.h"

template<typename Key, typename Info>
Dictionary<Key, Info>::Dictionary()
{
    Dictionary<Key, Info>::n = 0;
    Dictionary<Key, Info>::root = NULL;
}

template<typename Key, typename Info>
Dictionary<Key, Info>::~Dictionary()
{
    delete root;
    cout << "\nAll clean";
}

template<typename Key, typename Info>
void Dictionary<Key, Info>::insert(Key x)
{
    root = inserter(root, x);
}

template<typename Key, typename Info>
void Dictionary<Key, Info>::remove(Key x)
{
    root = remover(root, x);
}

template<typename Key, typename Info>
void Dictionary<Key, Info>::inorder()
{
    inOrderDisplay(root);
    cout << endl;
}


template<typename Key, typename Info>
void Dictionary<Key, Info>::change(Key x)
{
    changer(root, x);
}

template<typename Key, typename Info>
void Dictionary<Key, Info>::print()
{
    print("", root, false);
}

template<typename Key, typename Info>
const Dictionary<Key, Info>& Dictionary<Key, Info>::operator=(const Dictionary<Key, Info>& other)
{
    if (this != &other)
     {
        root = NULL;
        copy(other.root);
     }
     return *this;
}