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
            virtual void setData(const T& d);
            
            virtual T getData() const;
            
            int getHeight() const;
            
            virtual Node* getLeft() const;
            
            virtual Node* getRight() const;
            
            virtual Node* getParent() const;
            
            virtual void setLeft(Node* N);
            
            virtual void setRight(Node* N);
            
            virtual void setParent(Node* N);
            
            //Конструктор. Устанавливаем стартовые значения для указателей
            Node(T n);
            
            Node();
            
            virtual void setHeight(int h);
        };
}

#include "Node.cpp"