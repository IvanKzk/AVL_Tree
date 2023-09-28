
namespace AVL_Tree {

	//доступные извне переменные и функции
    template<class T>
	void Node<T>::setData(const T& d) { data = d; }
	
    template<class T>
	T Node<T>::getData() const { return data; }
	
    template<class T>
	int Node<T>::getHeight() const { return height; }
	
    template<class T>
	Node<T>* Node<T>::getLeft() const { return left; }
	
    template<class T>
	Node<T>* Node<T>::getRight() const { return right; }
	
    template<class T>
	Node<T>* Node<T>::getParent() const { return parent; }
	
    template<class T>
	void Node<T>::setLeft(Node<T>* N) { left = N; }
	
    template<class T>
	void Node<T>::setRight(Node<T>* N) { right = N; }
	
    template<class T>
	void Node<T>::setParent(Node<T>* N) { parent = N; }
	
	//Конструктор. Устанавливаем стартовые значения для указателей
    template<class T>
	Node<T>::Node(T n)
	{
		data = n;
		left = right = parent = nullptr;
		height = 1;
	}
	
    template<class T>
	Node<T>::Node()
	{
		left = right = parent = nullptr;
		data = T();
		height = 1;
	}
	
    template<class T>
	void Node<T>::setHeight(int h)
	{
		height = h;
	}
	
    template<class T>
	std::ostream& operator<< (std::ostream& stream, const Node<T>& N) {
		stream << N.getData();
		return stream;
	};

}