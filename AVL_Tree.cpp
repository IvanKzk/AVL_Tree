#include <algorithm>
namespace AVL_Tree {

	template<class T>
	Node<T>* Tree<T>::rotateright(Node<T>* p) // правый поворот вокруг p
	{	
		if (!p) return p;

		Node<T>* q = p->getLeft();
		if (p->getParent() == nullptr) root = q;
		p->setLeft(q ? q->getRight() : q);
		if (q) {
			q->setRight(p);
			q->setParent(p ? p->getParent() : p);
		}
		p->setParent(q);

		fixheight(p);
		fixheight(q);
		return q;
	}

	template<class T>
	Node<T>* Tree<T>::rotateleft(Node<T>* q) // левый поворот вокруг q
	{
		if (!q) return q;

		Node<T>* p = q->getRight();
		if (q->getParent() == nullptr) root = p;
		q->setRight(p ? p->getLeft() : p);
		if (p) {
			p->setLeft(q);
			p->setParent(q ? q->getParent() : q);
		}
		q->setParent(p);

		fixheight(q);
		fixheight(p);
		return p;
	}

	template<class T>
	int Tree<T>::bfactor(Node<T>* p) const
	{
		return p ? (height(p->getRight())-height(p->getLeft())) : 0;
	}

	template<class T>
	int Tree<T>::height(Node<T>* p) const
	{
		return p?p->getHeight():0;
	}

	template<class T>
	void Tree<T>::fixheight(Node<T>* p)
	{
		if (!p) return;
		int hl = height(p->getLeft());
		int hr = height(p->getRight());
		p->setHeight((hl>hr?hl:hr)+1);
	}
	
	template<class T>
	Node<T>* Tree<T>::balance(Node<T>* p) // балансировка узла p
	{
		fixheight(p);
		if( bfactor(p)==2 )
		{
			if( bfactor(p->getRight()) < 0 )
				p->setRight(rotateright(p->getRight()));
			return rotateleft(p);
		}
		if( bfactor(p)==-2 )
		{
			if( bfactor(p->getLeft()) > 0  )
				p->setLeft(rotateleft(p->getLeft()));
			return rotateright(p);
		}
		return p; // балансировка не нужна
	}

	template<class T>
	void Tree<T>::destroy(Node<T>* current) {
		if (current == nullptr)
			return;
		
		if (current->getLeft())
			destroy(current->getLeft());
		
		if (current->getRight())
			destroy(current->getRight());
		
		delete current;
	}

	//рекуррентная функция добавления узла. Устроена аналогично, но вызывает сама себя - добавление в левое или правое поддерево
	template<class T>
	Node<T>* Tree<T>::Add_R(Node<T>* N, Node<T>* Current)
	{
		if (N == nullptr) return nullptr;
		if (root == nullptr)
		{
			root = N;
			return N;
		}
		
		if (Current->getData() > N->getData())
		{
			//идем влево
			if (Current->getLeft() != nullptr)
				Current->setLeft(Add_R(N, Current->getLeft()));
			else
				Current->setLeft(N);
				Current->getLeft()->setParent(Current);
		}
		if (Current->getData() < N->getData())
		{
			//идем вправо
			if (Current->getRight() != nullptr)
				Current->setRight(Add_R(N, Current->getRight()));
			else
				Current->setRight(N);
				Current->getRight()->setParent(Current);
		}
		if (Current->getData() == N->getData())
		//нашли совпадение
			;
		
		return balance(Current);
	}

	template<class T>
	Node<T>* Tree<T>::Remove_R(const T& data, Node<T>* Current)
	{	
		if (Current == nullptr)
			return Current;

		//ищем элемент
		if ( data < Current->getData() )
			Current->setLeft(Remove_R(data, Current->getLeft()));
	
		else if( data > Current->getData() )
			Current->setRight(Remove_R(data, Current->getRight()));
	
		//нашли
		else if (data == Current->getData())
		{
			// у элемента одного поддерево или нет вообще
			if( (Current->getLeft() == nullptr) ||
				(Current->getRight() == nullptr) )
			{
				Node<T> *temp = Current->getLeft() ?
							Current->getLeft() :
							Current->getRight();
	
				//нет поддеревьев
				if (temp == nullptr)
				{
					temp = Current;
					Current = nullptr;
				}
				else //одно поддерево
				*Current = *temp; //копируем данные
							// не пустого поддерева
				free(temp);
			}
			else
			{
				// два поддерева
				// получаем наименьшее в правом поддереве
				Node<T>* temp = Min(Current->getRight());
	
				// копируем из него данные в текущий элемент
				Current->setData(temp->getData());
	
				//рекурсивно вызываем функцию
				Current->setRight((Remove_R(temp->getData(), Current->getRight())));
			}
		}
	
		//если в дереве только один элемент
		if (Current == nullptr)
		return Current;
	
		//Обновляем высоту текущего элемента
		Current->setHeight(1 + std::max(height(Current->getLeft()), height(Current->getRight())));
	
		//получаем результат вызова bfactor от текущего элемента
		int balance = bfactor(Current);
	
		//проверяем не расбалансировался ли элемент
	
		// Первый случай
		if (balance > 1 && bfactor(Current->getLeft()) >= 0)
			return rotateright(Current);
	
		// Второй случай
		if (balance > 1 && bfactor(Current->getLeft()) < 0)
		{
			Current->setLeft(rotateleft(Current->getLeft()));
			return rotateright(Current);
		}
	
		// Третий случай
		if (balance < -1 && bfactor(Current->getRight()) <= 0)
			return rotateleft(Current);
	
		// Четвертый случай
		if (balance < -1 && bfactor(Current->getRight()) > 0)
		{
			Current->setRight(rotateright(Current->getRight()));
			return rotateleft(Current);
		}
	
		return Current;
	}
	
	//доступ к корневому элементу
	template<class T>
	Node<T>* Tree<T>::getRoot() const { return root; }
	
	//конструктор дерева: в момент создания дерева ни одного узла нет, корень смотрит в никуда
	template<class T>
	Tree<T>::Tree(const std::initializer_list<T> elements) : root(nullptr) { 
		for (const auto& el : elements) {
			Add(el);
		}
	}

	template<class T>
	Tree<T>::Tree(const Tree<T>& other) : root(nullptr) { 
		for (const auto& el : other) {
			Add(el.getData());
		}
	}

	template<class T>
	Tree<T>::~Tree() { destroy(root); }
	
	//функция для добавления числа. Делаем новый узел с этими данными и вызываем нужную функцию добавления в дерево
	template<class T>
	void Tree<T>::Add(T n)
	{
		Node<T>* N = new Node<T>;
		N->setData(n);
		Add_R(N, root);
	}

	template<class T>
	void Tree<T>::Remove(T n)
	{
		Remove_R(n, root);
	}
	
	template<class T>
	Node<T>* Tree<T>::Min(Node<T>* Current) const
	{
		//минимум - это самый "левый" узел. Идём по дереву всегда влево
		if (root == nullptr) return nullptr;
		
		if(Current==nullptr)
			
		Current = root;
		
		while (Current->getLeft() != nullptr)
			Current = Current->getLeft();
		
		return Current;
	}
	
	template<class T>
	Node<T>* Tree<T>::Max(Node<T>* Current) const
	{
		//минимум - это самый "правый" узел. Идём по дереву всегда вправо
		if (root == nullptr) return nullptr;
		
		if (Current == nullptr)
			Current = root;
	
		while (Current->getRight() != nullptr)
			Current = Current->getRight();
	
		return Current;
	}

	//поиск узла в дереве. Второй параметр - в каком поддереве искать, первый - что искать
	template<class T>
	Node<T>* Tree<T>::Find(T data, Node<T>* Current) const
	{
		//база рекурсии
		if (Current == nullptr) return nullptr;
		if (Current->getData() == data) return Current;
		//рекурсивный вызов
		if (Current->getData() > data) return Find(data, Current->getLeft());
		if (Current->getData() < data) return Find(data, Current->getRight());
		return nullptr;
	}
	
	//три обхода дерева
	template<class T>
	void Tree<T>::PreOrder(Node<T>* N, std::ostream& stream) const
	{
		if (N != nullptr)
			stream << N->getData();
		
		if (N != nullptr && N->getLeft() != nullptr)
			PreOrder(N->getLeft(), stream);
		
		if (N != nullptr && N->getRight() != nullptr)
			PreOrder(N->getRight(), stream);
	}

	//InOrder-обход даст отсортированную последовательность
	template<class T>
	void Tree<T>::InOrder(Node<T>* N, std::ostream& stream) const
	{
		if (N != nullptr && N->getLeft() != nullptr)
			InOrder(N->getLeft(), stream);
		
		if (N != nullptr)
			stream << N->getData();
		
		if (N != nullptr && N->getRight() != nullptr)
			InOrder(N->getRight(), stream);
	}

	template<class T>
	void Tree<T>::PostOrder(Node<T>* N, std::ostream& stream) const
	{
		if (N != nullptr && N->getLeft() != nullptr)
			PostOrder(N->getLeft(), stream);
		
		if (N != nullptr && N->getRight() != nullptr)
			PostOrder(N->getRight(), stream);
		
		if (N != nullptr)
			stream << N->getData();
	}

	template<class T>
	void Tree<T>::AdvOutput(Node<T>* N, std::ostream& stream) const {
		if (N != nullptr && N->getLeft() != nullptr)
			InOrder(N->getLeft(), stream);
		
		if (N != nullptr)
			stream << "\nCurrent: " << N << ", left: " << N->getLeft() << ", right: " << N->getRight() << '\n' << N->getData() << '\n';
		
		if (N != nullptr && N->getRight() != nullptr)
			InOrder(N->getRight(), stream);
	}
	
	template<class T>
	Node<T>* Tree<T>::getByIndex(const size_t index, Node<T>* Current, size_t& current_index) const
	{
		if (Current->getLeft() != nullptr) {
			Node<T>* result = getByIndex(index, Current->getLeft(), current_index);
			if (result != nullptr) return result;
		}
		
		if (current_index == index) return Current;
		++current_index;
		
		if (Current->getRight() != nullptr) {
			Node<T>* result = getByIndex(index, Current->getRight(), current_index);
			if (result != nullptr) return result;
		}
		return nullptr;
	}
	
	template<class T>
	Node<T>* Tree<T>::operator[](const size_t index) const {
		size_t start_index=0;
		Node<T>* found = getByIndex(index, root, start_index);
		return found;
	}

	template<class T>
	Tree<T>& Tree<T>::operator=(const Tree<T>& other) {
		if (this == &other)
        	return *this;

		Tree<T> temp(other);
		root = temp.root;
		temp.root = nullptr;

    	return *this;
	}
	
	template<class T>
	iterator<T> Tree<T>::begin() const {
		return iterator<T>(*this, Min());
	}
	
	template<class T>
	iterator<T> Tree<T>::end() const {
		return iterator<T>(*this, nullptr);
	}
}