#include <iostream>
#include "Node.h"
#include "Iterator.h"

namespace AVL_Tree {

    template<class T>
    class Tree
    {
    protected:
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
        
        virtual Node<T>* Add_R(Node<T>* N, Node<T>* Current);

        virtual Node<T>* Remove_R(const T& data, Node<T>* Current);
        
    public:
        //доступ к корневому элементу
        virtual Node<T>* getRoot() const;
        
        //конструктор дерева: в момент создания дерева ни одного узла нет, корень смотрит в никуда
        Tree<T>();

        ~Tree<T>();
        
        //функция для добавления числа. Делаем новый узел с этими данными и вызываем нужную функцию добавления в дерево
        virtual void Add(T n);

        virtual void Remove(T n);
        
        virtual Node<T>* Min(Node<T>* Current=NULL) const;
        
        virtual Node<T>* Max(Node<T>* Current = NULL) const;

        //поиск узла в дереве. Второй параметр - в каком поддереве искать, первый - что искать
        virtual Node<T>* Find(T data, Node<T>* Current) const;
        
        //три обхода дерева
        virtual void PreOrder(Node<T>* N, std::ostream& stream) const;

        //InOrder-обход даст отсортированную последовательность
        virtual void InOrder(Node<T>* N, std::ostream& stream) const;

        virtual void PostOrder(Node<T>* N, std::ostream& stream) const;

        virtual void AdvOutput(Node<T>* N, std::ostream& stream) const;
        
        Node<T>* getByIndex(const size_t index, Node<T>* Current, size_t& current_index) const;
        
        Node<T>* operator[](const size_t index) const;
        
        iterator<T> begin();
        
        iterator<T> end();
    };
}

#include "AVL_Tree.cpp"