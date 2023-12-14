#include <iostream>
#include "Node.h"
#include "Iterator.h"

namespace AVL_Tree {

    template<class T>
    class Tree
    {
    private:
        //корень - его достаточно для хранения всего дерева
        Node<T>* root;

        Node<T>* rotateright(Node<T>* p); // правый поворот вокруг p

        Node<T>* rotateleft(Node<T>* q); // левый поворот вокруг q

        int bfactor(Node<T>* p) const;

        int height(Node<T>* p) const;

        void fixheight(Node<T>* p);
        
        Node<T>* balance(Node<T>* p); // балансировка узла p

        void destroy(Node<T>* current);

        //рекуррентная функция добавления узла. Устроена аналогично, но вызывает сама себя - добавление в левое или правое поддерево
        
        Node<T>* Add_R(Node<T>* N, Node<T>* Current);

        Node<T>* Remove_R(const T& data, Node<T>* Current);
        
    public:
        //доступ к корневому элементу
        Node<T>* getRoot() const;
        
        //конструктор дерева: в момент создания дерева ни одного узла нет, корень смотрит в никуда
        Tree<T>(const std::initializer_list<T> = {});

        Tree<T>(const Tree<T>& other);

        ~Tree<T>();
        
        //функция для добавления числа. Делаем новый узел с этими данными и вызываем нужную функцию добавления в дерево
        void Add(T n);

        void Remove(T n);
        
        Node<T>* Min(Node<T>* Current=nullptr) const;
        
        Node<T>* Max(Node<T>* Current = nullptr) const;

        //поиск узла в дереве. Второй параметр - в каком поддереве искать, первый - что искать
        Node<T>* Find(T data, Node<T>* Current) const;
        
        //три обхода дерева
        void PreOrder(Node<T>* N, std::ostream& stream) const;

        //InOrder-обход даст отсортированную последовательность
        void InOrder(Node<T>* N, std::ostream& stream) const;

        void PostOrder(Node<T>* N, std::ostream& stream) const;

        void AdvOutput(Node<T>* N, std::ostream& stream) const;
        
        Node<T>* getByIndex(const size_t index, Node<T>* Current, size_t& current_index) const;
        
        Node<T>* operator[](const size_t index) const;

        Tree<T>& operator=(const Tree<T>& other);
        
        iterator<T> begin() const;
        
        iterator<T> end() const;
    };
}

#include "AVL_Tree.cpp"