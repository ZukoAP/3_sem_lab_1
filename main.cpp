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
#include <chrono>

template<typename T>
void Sort(ISorter<T>* sorter, Sequence<T>* a, long long int& currTime) {
    if (a->length() != 0) {
        auto start = chrono::steady_clock::now();
        sorter->sort(a, &lessThan<int>);
        auto end = chrono::steady_clock::now();
        currTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        std::cout
                << "Отсортированный массив:"
                << std::endl;
        printData(a);
        std::cout << std::endl;
    }
}

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
    ISorter<int>* sorter;
    Sequence<int>* a;
    bool wasInitialized = false;
    ISorter<int>* sorters[4] = {new QuickSorter<int>, new ShellSorter<int>, new HeapSorter<int>, new MergeSorter<int>};
    std::srand(std::time(nullptr));
    long long int prevTime = -1;
    long long int currTime = -1;
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
            prevTime = -1;
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
                (anotherUserInput2 == 1) ? (a = new ListSeq<int>()) : (a = new ArraySeq<int>());
                for (unsigned int i = 0; i < n; ++i) {
                    a->append(std::rand() % n);
                }
            } else {
                std::cout
                        << "Введите числа через пробел"
                        << std::endl;
                (anotherUserInput2 == 1) ? (a = new ListSeq<int>()) : (a = new ArraySeq<int>());
                    for (unsigned int i = 0; i < n; ++i) {
                        int buff;
                        std::cin >> buff;
                        a->append(buff);
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
            Sort(sorters[anotherUserInput1], a, currTime);
            if (prevTime < 0) {
                prevTime = currTime;
            } else {
                std::cout
                        << "Если хотите сравнить с предыдущей, введите 1(иначе нажмите любую клавишу)"
                        << std::endl;
                int cmp;
                std::cin >> cmp;
                if (cmp == 1) {
                    std::cout << "Показатели " << ((prevTime > currTime) ? "улучшились" : "ухудшились")
                              << ":\n текущие: " << currTime << " ms\n предыдущие: " << prevTime << " ms\n";
                    prevTime = currTime;
                }
            }
        } else if (userInput == 3) {
            prevTime = -1;
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

