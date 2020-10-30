#include <iostream>
#include "LinkList.h"
#include <typeinfo>
#include "Sorters/MergeSorter.h"
#include "Sorters/QuickSorter.h"
#include "Sorters/ShellSorter.h"
#include "Sorters/HeapSorter.h"
#include "Sorters/Comparator.h"
#include "ArraySequence.h"
#include "ListSequence.h"
#include <Windows.h>

void fillSequenceRandom(int len, Sequence<int>* seq1) {
    srand(time(NULL));
    int tmp;
    for (int i = 0; i < len; i++) {
        tmp = rand() % 200;
        seq1->append(tmp);
    }
}

template<typename T>
void printData(const Sequence<T>* a) {
    for (int i = 0; i < a->length(); i++) {
        std::cout << a->getElement(i) << std::endl;
    }
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "Использование базовых сортировок" << std::endl;
    Sequence<int>* a;
    bool wasInitialized = false;
    std::srand(std::time(nullptr));
    while (true) {
        std::cout << "Введите 0, если хотите завершить." << std::endl
                  << "Введите 1, если хотите ввести массив для сортировки." << std::endl
                  << "Введите 2, если хотите отсортировать массив." << std::endl
                  << "Введите 3, если хотите сбросить введенные данные." << std::endl;
        int userInput;
        std::cin >> userInput;
        if (userInput == 0) {
            break;
        } else if (userInput == 1) {
            wasInitialized = true;
            std::cout
                    << "Введите количество элеменетов: "
                    << std::endl;
            int n;
            std::cin >> n;
            std::cout
                    << "Если хотите рандомно заполнить, введите 1, иначе ручной ввод"
                    << std::endl;
            int anotherUserInput1;
            std::cin >> anotherUserInput1;
            std::cout
                    << "Введите базовый класс\nlinkedList: 1, иначе array"
                    << std::endl;
            int anotherUserInput2;
            std::cin >> anotherUserInput2;
            if (anotherUserInput1 == 1) {
                if (anotherUserInput2 == 1) {
                    a = new ListSeq<int>();
                    for (unsigned int i = 0; i < n; ++i) {
                        a->append(std::rand() % n);
                    }
                } else {
                    a = new ArraySeq<int>();
                    for (unsigned int i = 0; i < n; ++i) {
                        a->append(std::rand() % n);
                    }
                }
            } else {
                std::cout
                        << "Введите числа через пробел"
                        << std::endl;
                if (anotherUserInput2 == 1) {
                    a = new ListSeq<int>();
                    for (unsigned int i = 0; i < n; ++i) {
                        int buff;
                        std::cin >> buff;
                        a->append(buff);
                    }
                } else {
                    a = new ArraySeq<int>();
                    for (unsigned int i = 0; i < n; ++i) {
                        int buff;
                        std::cin >> buff;
                        a->append(buff);
                    }
                }
            }
            std::cout
                    << "Полученный массив:"
                    << std::endl;
            if (a->length() != 0) {
                printData(a);
            }
        } else if (userInput == 2) {
            if (!wasInitialized) {
                std::cout << "\nСначала иницализируйте массив!!!\n";
                continue;
            }
            std::cout << "Введите 0, если хотите отсортировать массив сортировкой Quick sort." << std::endl
                      << "Введите 1, если хотите отсортировать массив сортировкой Shell sort." << std::endl
                      << "Введите 2, если хотите отсортировать массив сортировкой Heap sort." << std::endl
                      << "Введите 3, если хотите отсортировать массив сортировкой Merge sort."
                      << std::endl;
            int anotherUserInput1;
            std::cin >> anotherUserInput1;
            if (anotherUserInput1 == 0) {
                QuickSorter<int> sorter;
                if (a->length() != 0) {
                    sorter.sort(a, &lessThan<int>);
                    std::cout
                            << "Отсортированный массив:"
                            << std::endl;
                    printData(a);
                }
            } else if (anotherUserInput1 == 1) {
                ShellSorter<int> sorter;
                if (a->length() != 0) {
                    sorter.sort(a, &lessThan<int>);
                    std::cout
                            << "Отсортированный массив:"
                            << std::endl;
                    printData(a);
                }
            } else if (anotherUserInput1 == 2) {
                HeapSorter<int> sorter;
                if (a->length() != 0) {
                    sorter.sort(a, &lessThan<int>);
                    std::cout
                            << "Отсортированный массив:"
                            << std::endl;
                    printData(a);
                }
            } else if (anotherUserInput1 == 3) {
                MergeSorter<int> sorter;
                if (a->length() != 0) {
                    sorter.sort(a, &lessThan<int>);
                    std::cout
                            << "Отсортированный массив:"
                            << std::endl;
                    printData(a);
                }
            }
        } else if (userInput == 3) {
            if (wasInitialized) {
                while (a->length() != 0) {
                    a->pop(0);
                }
                delete a;
                wasInitialized = false;
            }
        }
    }
    std::cout << "До скорых встреч!";


    return 0;
}

