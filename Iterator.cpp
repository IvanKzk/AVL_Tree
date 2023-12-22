
namespace AVL_Tree {

    template<typename T>
	iterator<T>::iterator(const Tree<T>& parent, Node<T>* current) : parent(parent), current(current) {}

    template<typename T>
	iterator<T>::iterator(const iterator& it) : parent(it.parent), current(it.current) {}
	
    template<typename T>
	iterator<T>& iterator<T>::operator++()
	{ 
		if (current == nullptr || parent.getRoot() == nullptr) return *this;

		if (current->getRight() != nullptr) { 
		current = parent.Min(current->getRight()); 
		return *this; 
		}

		Node<T>* Current = current;
		while(true) {
		if (Current->getParent() == nullptr) {
			current = nullptr;
			return *this;
		}

		if (Current->getParent()->getLeft() == Current){
			current = Current->getParent();
			return *this;
		}

		Current = Current->getParent();
		}

		current = nullptr;
		return *this;
	}

    template<typename T>
	iterator<T>& iterator<T>::operator++(int)
	{ 
		iterator notModified = *this;
		++(*this);
		return notModified;
	}

    template<typename T>
	iterator<T>& iterator<T>::operator--()
	{ 
		if (current == nullptr || parent.getRoot() == nullptr) return *this;

		if (current->getLeft() != nullptr) { 
		current = parent.Max(current->getLeft()); 
		return *this; 
		}

		Node<T>* Current = current;
		while(true) {
		if (Current->getParent() == nullptr) {
			current = nullptr;
			return *this;
		}

		if (Current->getParent()->getRight() == Current){
			current = Current->getParent();
			return *this;
		}

		Current = Current->getParent();
		}

		current = nullptr;
		return *this;
	}

    template<typename T>
	iterator<T>& iterator<T>::operator--(int)
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