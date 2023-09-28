#include "AVL_Tree.h"
#include "TreeMenu.h"
#include <string>

using namespace std;
using namespace AVL_Tree;

struct patient {
	string name;
	string birth_date;
	string phone_number;
	string address;
	size_t card_number;
	string blood_group;
	
	friend ostream& operator<<(ostream &stream, const patient &right) {
		stream << 
				right.name << ", " << 
				right.birth_date << ", " << 
				right.phone_number << ", " << 
				right.address << ", " << 
				right.card_number << ", " <<
				right.blood_group << '\n';
		return stream;
	}

    friend istream& operator>>(istream &stream, patient &right) {
        if (!(stream >> right.name >> right.birth_date >> right.phone_number >> right.address >> right.card_number >> right.blood_group)) 
            std::cout << "Ошибка чтения, пожалуйста, повторите ввод...\n";
        return stream;
    }
	
	friend bool operator<(const patient &left, const patient &right) {
		return left.card_number<right.card_number;
	}

    friend bool operator>(const patient &left, const patient &right) {
		return left.card_number>right.card_number;
	}
	
	friend bool operator==(const patient &left, const patient &right) {
		return left.card_number==right.card_number;
	}
	
};

template<typename T, typename U>
pair<T, U> findByKey(const T key, const Tree<pair<T, U> >& container, Node<pair<T, U>>* Current) {
	//база рекурсии
	if (Current->getData().first == key) return Current->getData();
	//рекурсивный вызов
	if (Current->getLeft() != NULL) {
		pair<T, U> result = findByKey(key, container, Current->getLeft());
		if (result != pair<T, U>()) return result;
	}
	if (Current->getRight() != NULL) {
		pair<T, U> result = findByKey(key, container, Current->getRight());
		if (result != pair<T, U>()) return result;
	}
	return pair<T, U>();
}

template<typename T, typename U>
pair<T, U> findByKey(const T key, const Tree<pair<T, U> >& container) {
	return findByKey(key, container, container.getRoot());
}

template<typename T, typename U>
ostream& operator<<(ostream &stream, const pair<T, U> &right) {
    std::cout << "\nKey: " << right.first << ", value: " << right.second << '\n';
    return stream;
}

int main() {
    printMenu();
    char user_decision;
    Tree<std::pair<size_t, patient> > tree;

    while(user_decision != EXIT) {
        readFromCin(user_decision);

        switch(user_decision) {
            case EXIT:
                break;

            case ADD_ELEMENT:
            {
                patient new_element;
                std::cout << "\nВвод нового элемента..\nВведите имя, дату рождения, номер телефона, адрес, номер карты, группу крови\n";
                std::cin >> new_element;
                tree.Add(std::pair<size_t, patient>(new_element.card_number, new_element));
                std::cout << "\nДобавление завершено\n";
                break;
            }
            case REMOVE_ELEMENT:
            {
                patient element;
                std::cout << "\nВвод удаляемого элемента..\nВведите имя, дату рождения, номер телефона, адрес, номер карты, группу крови\n";
                std::cin >> element;
                tree.Remove(std::pair<size_t, patient>(element.card_number, element));
                std::cout << "\nУдаление завершено\n";
                break;
            }
            case OUTPUT_TREE:
                printTreePrintTypes();
                readFromCin(user_decision);
                {
                    switch(user_decision) {
                        case OUTPUT_PREORDER:
                            tree.PreOrder(tree.getRoot(), cout);
                            break;

                        case OUTPUT_INORDER:
                            tree.InOrder(tree.getRoot(), cout);
                            break;

                        case OUTPUT_POSTORDER:
                            tree.PostOrder(tree.getRoot(), cout);
                            break;

                        default:
                            std::cout << "Введен неверный пункт, пожалуйста, повторите ввод...\n";
                    }
                    std::cout << "\nВывод завершен\n";
                }
                break;
            
            case FIND: 
            {
                patient element;
                std::cout << "\nВвод элемента для поиска..\nВведите имя, дату рождения, номер телефона, адрес, номер карты, группу крови\n";
                std::cin >> element;
                auto find_result = tree.Find(std::pair<size_t, patient>(element.card_number, element), tree.getRoot());
                if (find_result == nullptr) std::cout << "\nЭлемент не найден\n";
                else std::cout << "\nРезультат поиска:\n" << *find_result << '\n';
                break;
            }

            case FIND_MAX: 
            {
                auto find_result = tree.Max();
                if (find_result == nullptr) std::cout << "\nДерево пустое\n";
                else std::cout << "\nРезультат поиска:\n" << *find_result << '\n';
                break;
            }

            case FIND_MIN:
            {
                auto find_result = tree.Min();
                if (find_result == nullptr) std::cout << "\nДерево пустое\n";
                else std::cout << "\nРезультат поиска:\n" << *find_result << '\n';
                break;
            }
            
            case FILL_TREE:
            {
                tree.Add(pair<size_t, patient>(2,{"Petrov", "01.01.2000", "+79991234567", "smth_Street", 2, "I"}));
	            tree.Add(pair<size_t, patient>(4,{"Ivanov", "01.01.2000", "+79991234567", "smth_Street", 4, "III"}));
                tree.Add(pair<size_t, patient>(6,{"Kozhak", "01.01.2002", "+79991234567", "smth_Street", 6, "II"}));
                std::cout << "\nЗаполнение завершено\n";
                break;
            }

            case FIND_BY_KEY:
            {
                size_t key;
                std::cout << "\nВведите ключ: ";
                if (!(std::cin >> key)) {
                    std::cout << "Ошибка чтения, пожалуйста, повторите ввод...\n";
                    break;
                }
                auto find_result = findByKey(key, tree, tree.getRoot());
                if (find_result == pair<size_t, patient>()) std::cout << "\nЭлемент не найден\n";
                else std::cout << "\nРезультат поиска:\n" << find_result << '\n';
                break;
            }

            case ADV_OUTPUT:
            {
                tree.AdvOutput(tree.getRoot(), cout);
                std::cout << "\nВывод завершен\n";
                break;
            }
            
            default:
                std::cout << "Введен неверный пункт, пожалуйста, повторите ввод...\n";
        }

        std::cin.clear();
	    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}