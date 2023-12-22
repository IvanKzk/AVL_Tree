#include <iostream>

namespace AVL_Tree {

    template<class T>
    class Node
        {
        protected:
            //закрытые переменные Node N; N.data = 10 вызовет ошибку
            T data;
            //не можем хранить Node, но имеем право хранить указатель
            Node* left;
            Node* right;
            Node* parent;
            //переменная, необходимая для поддержания баланса дерева
            int height;
        public:
            //доступные извне переменные и функции
            void setData(const T& d);
            
            T getData() const;
            
            int getHeight() const;
            
            Node* getLeft() const;
            
            Node* getRight() const;
            
            Node* getParent() const;
            
            void setLeft(Node* N);
            
            void setRight(Node* N);
            
            void setParent(Node* N);
            
            //Конструктор. Устанавливаем стартовые значения для указателей
            Node(T n);
            
            Node();
            
            void setHeight(int h);
        };
}

#include "Node.cpp"