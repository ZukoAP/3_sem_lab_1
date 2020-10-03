#include <iostream>
#include "not_needed/DynArray.h"
#include "LinkList.h"
#include "not_needed/Queue.h"
#include <typeinfo>
#include "not_needed/SingleLinkList.h"
#include "not_needed/Tree.h"
#include "not_needed/queueTester.h"
#include "Sorters/MergeSorter.h"
#include "Sorters/QuickSorter.h"
#include "Sorters/ShellSorter.h"
#include "Sorters/HeapSorter.h"
#include "Sorters/Comparator.h"

void fillSequenceRandom(int len, Sequence<int> *seq1) {
    srand(time(NULL));
    int tmp;
    for (int i = 0; i < len; i++){
        tmp = rand() % 200;
        seq1->append(tmp);
    }
}

int main() {


  /*  LinkList<int> a;
    for (int i = 0; i < 7; ++i) {
        a.prepend(i);
    }

    LinkList<int> b = *(a.sublist(3, 4));
    b.append(10);
    a.insert(75, 7);
    std::cout << a << std::endl;
    a.concat(&b);
    b.pop(2);
    b[1] = 50;*/



    /*DynArray<LinkList<std::string>> a;
    LinkList<std::string> b;
    for (int i = 0; i < 7; ++i) {
        b.append(std::to_string(i)+"me");
    }
    a.append(b);
    LinkList<std::string> c;
    for (int i = 0; i < 7; ++i) {
        c.append(std::to_string(i)+"one");
    }
    a.prepend(c);
//    a.swap(0,1);
    std::cout << a << std::endl;*/


/*    Queue<int> a(new ListSeq<int>);
    Queue<int> g(new ArraySeq<int>);
    for (int i = 10; i < 16; ++i) {
        g.push(i);
    }

    for (int i = 1; i < 6; ++i) {
        a.push(i);
    }
    std::cout << a << std::endl;
    Queue<int> h = a+g;

    Queue<int> b(a);
    a.swap(0, 4);
//    a.pop();
    b = b + a;
    Queue<int> c = a.slice(0, 4);

    a.map([](int &a) { a = a + 1; });

    Queue<int> d = a.where([](int &a){
        if(a%2 == 0)
            return 1;
        else
            return 0;
    });

    int m = 2;
    int f = a.reduce([](int &a, int m){
        return a*m;
        },1);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    std::cout << f << std::endl;
    std::cout << g << std::endl;
    std::cout << "h: " <<h << std::endl;*/

//    std::cout << (typeid(a)== typeid(Queue<int>)) << std::endl;

    /*SLinkList<int> a;

    for (int i = 0; i < 7; ++i) {
        a.append(i);
    }
    a.reverse();
    std::cout << a << std::endl;*/

    /*Tree<int> a(50);

    addNode(&a, 55);
    addNode(&a, 6);
    addNode(&a, 12);
    addNode(&a, 15);
    addNode(&a, 2);
    addNode(&a, 3);
    addNode(&a, 67);

    inorderPrint(&a);
    std::cout<<std::endl;
    levelOrderPrint(&a);
    std::cout<<std::endl;
    BFS(&a);*/

    //queueTester();
/*
    ArraySeq<int> a;
    fillSequenceRandom(15, &a);
    auto *mergeSorter = new MergeSorter<int>;
    auto *quickSorter = new QuickSorter<int>;
    auto *shellSorter = new ShellSorter<int>;
    auto *heapSorter = new HeapSorter<int>;
    for (int i = 0; i < a.length(); ++i) {
        cout<<a.getElement(i)<<" ";
    }
    cout<<endl;
    heapSorter->sort(&a, &lessThan<int>);
    for (int i = 0; i < a.length(); ++i) {
        cout<<a.getElement(i)<<" ";
    }*/

    return 0;
}
