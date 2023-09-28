
namespace AVL_Tree {

    template<typename T>
	iterator<T>::iterator(Tree<T>& parent, Node<T>* current = nullptr) : parent(parent), current(current) {}

    template<typename T>
	iterator<T>::iterator(const iterator& it) : parent(it.parent), current(it.current) {}
	
    template<typename T>
	iterator<T>::iterator& operator++()
	{ 
		if (current == NULL || parent.getRoot() == NULL) return *this;

		if (current->getRight() != NULL) { 
		current = parent.Min(current->getRight()); 
		return *this; 
		}

		Node<T>* Current = current;
		while(true) {
		if (Current->getParent() == NULL) {
			current = NULL;
			return *this;
		}

		if (Current->getParent()->getLeft() == Current){
			current = Current->getParent();
			return *this;
		}

		Current = Current->getParent();
		}

		current = NULL;
		return *this;
	}

    template<typename T>
	iterator<T>::iterator& operator++(int)
	{ 
		iterator notModified = *this;
		++(*this);
		return notModified;
	}

    template<typename T>
	iterator<T>::iterator& operator--()
	{ 
		if (current == NULL || parent.getRoot() == NULL) return *this;

		if (current->getLeft() != NULL) { 
		current = parent.Max(current->getLeft()); 
		return *this; 
		}

		Node<T>* Current = current;
		while(true) {
		if (Current->getParent() == NULL) {
			current = NULL;
			return *this;
		}

		if (Current->getParent()->getRight() == Current){
			current = Current->getParent();
			return *this;
		}

		Current = Current->getParent();
		}

		current = NULL;
		return *this;
	}

    template<typename T>
	iterator<T>::iterator& operator--(int)
	{ 
		iterator notModified = *this;
		--(*this);
		return notModified;
	}
	
    template<typename T>
	bool iterator<T>::operator!=(iterator const& other) const { return (current != other.current); }

    template<typename T>
	bool iterator<T>::operator==(iterator const& other) const { return (current == other.current); }
    
    template<typename T>
	Node<T>& iterator<T>::operator*()
	{
		return *current;
	}

}