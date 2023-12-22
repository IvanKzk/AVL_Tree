#include <iostream>
#include "Node.h"
#include "Iterator.h"

namespace AVL_Tree {

    template<class T>
    class Tree
    {
    private:

        /**
        * @brief 
        * @param 
        * @return 
        */

        /**
        * @brief Метод, возвращающий корень дерева - его достаточно для хранения всего дерева.
        * @return указатель на корень дерева.
        */
        Node<T>* root;

        /**
        * @brief Метод, выполняющий правый поворот вокруг дерева.
        * @param Указатель на узел, вокруг которого необходимо выполнить поворот.
        * @return Указатель на узел, находившийся на месте переданног узла после выполнения поворота
        */
        Node<T>* rotateright(Node<T>* p); // правый поворот вокруг p

        /**
        * @brief Метод, выполняющий левый поворот вокруг дерева.
        * @param Указатель на узел, вокруг которого необходимо выполнить поворот.
        * @return Указатель на узел, находившийся на месте переданног узла после выполнения поворота
        */
        Node<T>* rotateleft(Node<T>* q); // левый поворот вокруг q

        /**
        * @brief Метод, возвращающий критерий выполнения поворота вокруг конкретного узла.
        * @param Указатель на узел, для которого необходимо вычислить критерий.
        * @return Значение критерия.
        */
        int bfactor(Node<T>* p) const;

        /**
        * @brief Метод, возвращающий высоту дерева до конкретного узла.
        * @param Узел до которого необходимо вычислить высоту.
        * @return Значение высоты.
        */
        int height(Node<T>* p) const;

        /**
        * @brief Метод, обновляющий высоту дерева для конкретного узла.
        * @param Узел для которого необходимо вычислить высоту.
        */
        void fixheight(Node<T>* p);
        
        /**
        * @brief Метод, перестраивающий дерево и выполняющий ребалансировку.
        * @param Узел с которого необхоимо начинать ребалансировку.
        */
        Node<T>* balance(Node<T>* p);
        

        /**
        * @brief Рекурсивно очищает память начиная с конкретного узла.
        * @param Узел с которого необхоимо начинать очистку памяти.
        */
        void destroy(Node<T>* current);

        /**
        * @brief рекуррентная функция добавления узла, вызывает сама себя - добавление в левое или правое поддерево.
        * @param Узел для добавлвения.
        * @param Узел с которого необхоимо начинать поиск места для добавления.
        */
        Node<T>* Add_R(Node<T>* N, Node<T>* Current);


        /**
        * @brief рекуррентная функция удаления узла, вызывает сама себя.
        * @param Данные для добавлвения.
        * @param Узел с которого необхоимо начинать поиск узла для удаления.
        */
        Node<T>* Remove_R(const T& data, Node<T>* Current);
        
    public:
        /**
        * @brief геттер, доступ к корневому элементу
        * @return указатель на корневой элемент
        */
        Node<T>* getRoot() const;
        
        /**
        * @brief конструктор дерева: в момент создания дерева ни одного узла нет, корень смотрит в никуда
        */
        Tree<T>(const std::initializer_list<T> = {});

        /**
        * @brief конструктор копирования дерева
        */
        Tree<T>(const Tree<T>& other);

        /**
        * @brief деструктор дерева, вызывает destroy от root
        */
        ~Tree<T>();
        
        /**
        * @brief функция для добавления элемента. Создаем новый узел с этими данными и вызываем нужную функцию добавления в дерево
        * @param Элемент для добавлвения.
        */
        void Add(T n);

        /**
        * @brief функция для удаления элемента. Вызываем рекурсивную функцию удаления
        * @param Элемент для удаления.
        */
        void Remove(T n);
        
        Node<T>* Min(Node<T>* Current=nullptr) const;
        
        Node<T>* Max(Node<T>* Current = nullptr) const;
        
        /**
        * @brief поиск узла в дереве
        * @param в каком поддереве искать
        * @param что искать
        * @return указатель на найденный элемент
        */
        Node<T>* Find(T data, Node<T>* Current) const;
        
        /**
        * @brief вывод пре-обходом
        * @param поток для вывода
        */
        void PreOrder(Node<T>* N, std::ostream& stream) const;

        /**
        * @brief вывод в отсортированном порядке
        * @param поток для вывода
        */
        void InOrder(Node<T>* N, std::ostream& stream) const;


        /**
        * @brief вывод пост-обходом
        * @param поток для вывода
        */
        void PostOrder(Node<T>* N, std::ostream& stream) const;

        /**
        * @brief вывод adv-обходом
        * @param поток для вывода
        */
        void AdvOutput(Node<T>* N, std::ostream& stream) const;

        /**
        * @brief рекурсиваня функция получения элемента по индексу
        * @param индекс
        * @param текущий элемент
        * @param текущий индекс
        */
        Node<T>* getByIndex(const size_t index, Node<T>* Current, size_t& current_index) const;
        
        /**
        * @brief перегузка оператора для получения элемента по индексу
        * @param индекс
        */
        Node<T>* operator[](const size_t index) const;

        /**
        * @brief перегузка оператора присваивания
        * @param присваемый элемент
        */
        Tree<T>& operator=(const Tree<T>& other);
        
        /**
        * @brief итератор указывающий на начальный элемент
        * @param соответствующий итератор
        */
        iterator<T> begin() const;
        
        /**
        * @brief итератор указывающий на конечный элемент
        * @param соответствующий итератор
        */
        iterator<T> end() const;
    };
}

#include "AVL_Tree.cpp"