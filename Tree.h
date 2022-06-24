#pragma once
#include <iostream>
#include <cstring>
#include "Exception.h"

template <class T> struct Node
{
	T data;
	Node* left = nullptr;
	Node* right = nullptr;
	int height = 0;

	Node() {};
	Node(const T& data) 
	{
		this->data = data;
		this->left = nullptr;
		this->right = nullptr;
	}
	void SetData(const T& data)
	{
		this->data = data;
	}
	void SetHeigt(int height)
	{
		this->height = height;
	}
};

template <class T> class Tree
{
protected:
	Node<T>* root;

protected:
	Node<T>* CopyTree(Node<T>* current_root);
	Node<T>* CreateTree(const T* arr, const T& symbol, int& index);
	void DeleteTree(Node<T>* current_root);
	
	void Traversal(std::string type, Node<T>* current_root, void (*operation)(T&));

	int Size(Node<T>* current_root);
	T* GetStr(std::string type, Node<T>* current_root, T* arr, const T& symbol, int& index);

	void Map(T(*operation)(T), Node<T>* current_root);


public:
	Tree();
	Tree(const Tree& tree);
	Tree(const T* arr, const T& symbol);
	~Tree();

	void Traversal(std::string type);
	void Traversal();

	int Size();

	T* GetStr(std::string type, const T& symbol);

	void Map(T(*operation)(T));
	

	bool operator==(Tree<T>& tree2);
	bool Compare(Node<T>* current_root, Node<T>* compare_root);
};

template <class T> Tree<T>::Tree() 
{
	root = nullptr;
}

template <class T> Tree<T>::Tree(const Tree& tree)
{
	root = CopyTree(tree.root);
}

template <class T> Tree<T>::Tree(const T* arr, const T& symbol)
{
	int index = 0;
	root = CreateTree(arr, symbol, index);
}

template <class T> Tree<T>:: ~Tree()
{
	DeleteTree(root);
}

template <class T> Node<T>* Tree<T>::CreateTree(const T* arr, const T& symbol, int& index)
{
	Node<T>* current_root = nullptr;
	if (arr[index] != symbol)
	{
		current_root = new Node<T>(arr[index]);
		index++;
		current_root->left = CreateTree(arr, symbol, index);
		index++;
		current_root->right = CreateTree(arr, symbol, index);
	}
	return current_root;
}


template <class T> Node<T>* Tree<T>::CopyTree(Node<T>* current_root)
{
	if (current_root)
	{
		Node<T>* new_root = new Node<T>(current_root->data);
		new_root->left = CopyTree(current_root->left);
		new_root->right = CopyTree(current_root->right);
		return new_root;
	}
	else
	{
		return nullptr;
	}
}

template <class T> void Tree<T>::DeleteTree(Node<T>* current_root)
{
	if (current_root)
	{
		if (current_root->left)
		{
			DeleteTree(current_root->left);
		}
		if (current_root->right)
		{
			DeleteTree(current_root->right);
		}
		delete current_root;
	}
}

template <class T> void PrintElem(T& item) 
{
	std::cout << item << " ";
}



template <class T> void Tree<T>::Traversal() 
{
	Traversal("LNR", this->root, PrintElem);
	std::cout << "\n";
}

template <class T> void Tree<T>::Traversal(std::string type) 
{
	Traversal(type, this->root, PrintElem);
	std::cout << "\n";
}

template <class T> void Tree<T>::Traversal(std::string type, Node<T>* current_root, void (*operation)(T&))
{
	if (type != "LNR" && type != "LRN" && type != "RNL" && type != "RLN" && type != "NLR" && type != "NRL" )
	{
		throw ExceptionError(2);
	}
	if (current_root)
	{
		for (int i = 0; i < type.size(); i++)
		{
			switch (type[i])
			{
			case 'N':
				operation(current_root->data);
				break;
			case 'L':
				Traversal(type, current_root->left, operation);
				break;
			case 'R':
				Traversal(type, current_root->right, operation);
				break;
			default:
				break;
			}
		}
	}

}



template <class T> int Tree<T>::Size() 
{
	return Size(this->root);
}

template <class T> int Tree<T>::Size(Node<T>* current_root) 
{
	if (!current_root)
	{
		return 0; 
	}
	return Size(current_root->left) + Size(current_root->right) + 1;
}



template <class T> T* Tree<T>::GetStr(std::string type, const T& symbol) 
{
    if (type != "LNR" && type != "LRN" && type != "NLR" && type != "NRL" && type != "RLN" && type != "RNL") 
	{
        throw ExceptionError(2);
    }
    int n = 3 * Size();
    T* arr = new T[n]();
    int i = 0;
    arr = GetStr(type, this->root, arr, symbol, i);
    return arr;
}

template <class T> T* Tree<T>::GetStr(std::string type, Node<T> *current_root, T* arr, const T& symbol, int& index) 
{
    if (current_root) 
	{
        for(int i = 0; i < type.size(); i++) 
		{
            switch (type[i]) 
			{
            case 'N':
                arr[index] = current_root->data;
                index++;
                break;
            case 'L':
                arr = GetStr(type, current_root->left, arr, symbol, index);
                break;
            case 'R': 
                arr = GetStr(type, current_root->right, arr, symbol, index);
                break;
            default:
                break;
            }
        }
    } 
	else 
	{
        arr[index] = symbol;
        index++;
    }
    return arr;
}



template <class T> void Tree<T>::Map(T(*operation)(T))
{
	this->Map(operation, root);
}

template <class T> void Tree<T>::Map(T(*operation)(T), Node<T>* current_root)
{
	if (current_root)
	{
		Map(operation, current_root->left);
		current_root->data = operation(current_root->data);
		Map(operation, current_root->right);
	}
}


template <class T> bool Tree<T>::Compare(Node<T>* current_root, Node<T>* compare_root)
{
	if ((compare_root == nullptr) && (current_root == nullptr)) 
	{
		return true;
	}
	else if ((!compare_root) && (current_root)) 
	{
		return false;
	}
	else if ((compare_root) && (!current_root)) 
	{
		return false;
	}
	else if (compare_root->data != current_root->data) 
	{
		return false;
	}
	return (Compare(current_root->left, compare_root->left)) && (Compare(current_root->right, compare_root->right));
}

template <class T> bool Tree<T>::operator==(Tree<T>& tree2)
{
	return Compare(this->root, tree2.root);
}