#pragma once


namespace jtd
{
    template <class T>
    class tree
    {
        private:
        struct node
        {
            T data;
            node * left;
            node * right;

            node(T data);
            node();
            node(const node& copy);
        }* root = 0;

        void delete_root_help(node*& root);

        void delete_value_help(T data, node*& root);

        void inorder_help(node* root) const;

        void insert_help(T data, node*& root);

        T max_help(node* root) const;

        T min_help(node* root) const;

        void postorder_help(node* root) const;

        void preorder_help(node* root) const;

        bool search_help(T data, node* root) const;

        public:
        tree();
        tree(const tree& copy);
        void insert(T data);
        void preorder() const;
        void inorder() const;
        void postorder() const;
        bool search(T data) const;
        T max() const;
        T min() const;
        void delete_root();
        void delete_value(T data);
    };
}