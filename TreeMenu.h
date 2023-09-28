#include <iostream>
#include <limits>

#define ADD_ELEMENT '1'
#define REMOVE_ELEMENT '2'
#define OUTPUT_TREE '3'
#define OUTPUT_PREORDER '1'
#define OUTPUT_INORDER '2'
#define OUTPUT_POSTORDER '3'
#define FIND '4'
#define FIND_MAX '5'
#define FIND_MIN '6'
#define FILL_TREE '7'
#define FIND_BY_KEY '8'
#define ADV_OUTPUT '9'

#define EXIT '0'

void printMenu() {
    std::cout   << "Выберите требуемое действие:\n"
                << ADD_ELEMENT << " Добавить элемент в дерево\n"
                << REMOVE_ELEMENT << " Удалить элемент из дерева\n"
                << OUTPUT_TREE << " Вывод дерева\n"
                << FIND << " Поиск элемента в дереве\n"
                << FIND_MAX << " Поиск максимума в дереве\n"
                << FIND_MIN << " Поиск минимума в дереве\n"
                << FILL_TREE << " Заполнить дерево примерами\n"
                << FIND_BY_KEY << " Поиск по ключу\n"
                << ADV_OUTPUT << " Подробный вывод\n"
                << EXIT << " Выход\n\n";
}

void printTreePrintTypes() {
    std::cout
                << OUTPUT_PREORDER << " PreOrder обход\n"
                << OUTPUT_INORDER << " InOrder обход\n"
                << OUTPUT_POSTORDER << " PostOrder обход\n\n";
}

template<typename T>
void readFromCin(T& to) {
    if (!(std::cin >> to)) {
        std::cerr << "\nОшибка чтения данных\n";
        throw std::runtime_error("Error reading data from std::cin");
    }
}
