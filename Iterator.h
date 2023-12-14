namespace AVL_Tree {

    template<class T> class Tree;
    template<class T> class Node;

    template<class T>
    class iterator {
        private:
            const Tree<T>& parent;
            Node<T>* current;
        
        public:
            iterator(const Tree<T>& parent, Node<T>* current = nullptr);
            iterator(const iterator& it);
        
            iterator& operator++();

            iterator& operator++(int);

            iterator& operator--();

            iterator& operator--(int);
            
            bool operator!=(iterator const& other) const;

            bool operator==(iterator const& other) const;
            
            Node<T>& operator*();
        };

}

#include "Iterator.cpp"