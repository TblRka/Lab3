#pragma once
#pragma once
#include "Tree.h"
template <class T> class SearchTree : public Tree<T>
{
protected:
    Node<T>* AddNode(T item, Node<T>* current_root);

    Node<T>* FindItem(T item, Node<T>* current_root);

    Node<T>* DeleteNode(T item, Node<T>* current_root);;

    Node<T>* MinItem(Node<T>* current_root);

public:
    SearchTree();
    SearchTree(const SearchTree& tree);
    SearchTree(const T* arr, const T& symbol);
    ~SearchTree() {};

    void AddNode(T item);
    bool FindItemBool(T item);
    void DeleteNode(T item);
    Node<T>* FindItem(T item);
    bool operator ==(SearchTree<T>&);
};

template <class T> SearchTree<T>::SearchTree()
{
    this->root = nullptr;
}

template <class T> SearchTree<T>::SearchTree(const SearchTree<T>& tree)
{
    this->root = Tree<T>::CopyTree(tree.root);
}

template <class T> SearchTree<T>::SearchTree(const T* arr, const T& symbol)
{
    int index = 0;
    this->root = Tree<T>::CreateTree(arr, symbol, index);
}

template <class T> bool SearchTree<T>::operator==(SearchTree<T>& compare_tree)
{
    return this->Compare(this->root, compare_tree.root);
}


template <class T> void SearchTree<T>::AddNode(T item)
{
    this->root = AddNode(item, this->root);
}

template <class T> Node<T>* SearchTree<T>::AddNode(T item, Node<T>* current_root)
{
    if (!current_root)
    {
        current_root = new Node<T>(item);
    }
    else  if (item == current_root->data)
    {
        throw ExceptionError(2);
    }
    else  if (item < current_root->data)
    {
        current_root->left = AddNode(item, current_root->left);
    }
    else
    {
        current_root->right = AddNode(item, current_root->right);
    }
    return current_root;
}


template <class T> Node<T>* SearchTree<T>::FindItem(T item)
{
    return FindItem(item, this->root);
}

template <class T> bool SearchTree<T>::FindItemBool(T item)
{
    if (FindItem(item))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T> Node<T>* SearchTree<T>::FindItem(T item, Node<T>* current_root)
{
    if (!current_root)
    {
        return nullptr;
    }
    else if (current_root->data == item)
    {
        return current_root;
    }
    else  if (item < current_root->data)
    {
        return FindItem(item, current_root->left);
    }
    else
    {
        return FindItem(item, current_root->right);
    }
}


template <class T> Node<T>* SearchTree<T>::MinItem(Node<T>* current_root)
{
    Node<T>* nodeItem = current_root;
    while (nodeItem && nodeItem->left)
        nodeItem = nodeItem->left;
    return nodeItem;
}

template <class T> void SearchTree<T>::DeleteNode(T item)
{
    this->root = DeleteNode(item, this->root);
}

template <class T> Node<T>* SearchTree<T>::DeleteNode(T item, Node<T>* current_root) {
    if (!current_root)
    {
        return nullptr;
    }
    else  if (item < current_root->data)
    {
        current_root->left = DeleteNode(item, current_root->left);
    }
    else if (item > current_root->data)
    {
        current_root->right = DeleteNode(item, current_root->right);
    }
    else
    {
        if (!current_root->left && !current_root->right)
        {
            delete current_root;
            return nullptr;
        }
        else if (!current_root->left)
        {
            Node<T>* nodeItem = current_root->right;
            delete current_root;
            return nodeItem;
        }
        else if (!current_root->right)
        {
            Node<T>* nodeItem = current_root->left;
            delete current_root;
            return nodeItem;
        }
        Node<T>* nodeItemMin = MinItem(current_root->right);
        current_root->data = nodeItemMin->data;
        current_root->right = DeleteNode(nodeItemMin->data, current_root->right);
    }
    return current_root;
}
