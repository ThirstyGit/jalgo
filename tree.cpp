#pragma once

#include <iostream>

#include "tree.h"

//Private methods that help the public methods.
template <class T>
jtd::tree<T>::node::node(T data) : data(data), left(0), right(0)
{
    
}

template <class T>
jtd::tree<T>::node::node()
{

}

template <class T>
jtd::tree<T>::node::node(const node& copy)
{
    
}

template <class T>
void jtd::tree<T>::delete_root_help(node*& root)
{
    if(!root) return;
    if(!root->left) root = root->right;
    else if(!root->left->right)
    {
        root->left->right = root->right;
        root = root->left;
    }
    else
    {
        node* temp = root->left;
        while(temp->right->right)
        {
            temp = temp->right;
        }
        temp->right->left = root->left;
        temp->right->right = root->right;
        root = temp->right;
        temp->right = 0;
    }
}

template <class T>
void jtd::tree<T>::delete_value_help(T data, node*& root)
{
    if(!root) return;
    else if(data == root->data) delete_root_help(root);
    else if(data < root->data) delete_value_help(data, root->left);
    else delete_value_help(data, root->right);
}

template <class T>
void jtd::tree<T>::inorder_help(node* root) const
{
    if(!root) return;
    inorder_help(root->left);
    std::cout << root->data << "\t";
    inorder_help(root->right);
}

template <class T>
void jtd::tree<T>::insert_help(T data, node*& root)
{
    if(root)
    {
        if(data < root->data) insert_help(data, root->left);
        else insert_help(data, root->right);
    }
    else
    {
        root = new node(data);
    }
}

template <class T>
T jtd::tree<T>::max_help(node* root) const
{
    if(!root) return INT32_MIN;
    if(!root->right) return root->data;
    else return max_help(root->right);
}

template <class T>
T jtd::tree<T>::min_help(node* root) const
{
    if(!root) return INT32_MAX;
    if(!root->left) return root->data;
    else return min_help(root->left);
}

template <class T>
void jtd::tree<T>::postorder_help(node* root) const
{
    if(!root) return;
    postorder_help(root->left);
    postorder_help(root->right);
    std::cout << root->data << "\t";
}

template <class T>
void jtd::tree<T>::preorder_help(node* root) const
{
    if(!root) return;
    std::cout << root->data << "\t";
    preorder_help(root->left);
    preorder_help(root->right);
}

template <class T>
bool jtd::tree<T>::search_help(T data, node* root) const
{
    if(!root) return false;
    if(data == root->data) return true;
    if(data < root->data) search_help(data, root->left);
    else search_help(data, root->right);
}

//All public methods.
template <class T>
jtd::tree<T>::tree() { }
template <class T>
jtd::tree<T>::tree(const tree& copy) { }
template <class T>
void jtd::tree<T>::insert(T data) {jtd::tree<T>::insert_help(data, root);}
template <class T>
void jtd::tree<T>::preorder() const {jtd::tree<T>::preorder_help(root);}
template <class T>
void jtd::tree<T>::inorder() const {jtd::tree<T>::inorder_help(root);}
template <class T>
void jtd::tree<T>::postorder() const {jtd::tree<T>::postorder_help(root);}
template <class T>
bool jtd::tree<T>::search(T data) const {return jtd::tree<T>::search_help(data, root);}
template <class T>
T jtd::tree<T>::max() const {return jtd::tree<T>::max_help(root);}
template <class T>
T jtd::tree<T>::min() const {return jtd::tree<T>::min_help(root);}
template <class T>
void jtd::tree<T>::delete_root() {jtd::tree<T>::delete_root_help(root);}
template <class T>
void jtd::tree<T>::delete_value(T data) {jtd::tree<T>::delete_value_help(data, root);}
