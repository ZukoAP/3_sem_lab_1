#include <iostream>
#include <fstream>
#include <typeinfo>
#include <ctime>
#include <iomanip>
#include <chrono>


using namespace std;

template<typename T>
void fillQueues(Queue<T>* q1,Queue<T>* q2){
    srand(time(nullptr));
    for (int i = 0; i < 50000; ++i) {
        q1->push(rand() % 10000);
    }
    for (int i = 0; i < q1->size(); ++i) {
        q2->push(q1->data->getElement(i));
    }
}

template <typename T>
double swapTester(Queue<T> queue){
    auto start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < 500000; ++i) {
        queue.swap(rand() % 5000, rand() % 5000);
    }
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    return time_taken;
}

template <typename T>
double popTester(Queue<T> queue){
    auto start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < 50000; ++i) {
        queue.pop();
    }
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    return time_taken;
}

template <typename T>
double pushTester(Queue<T> queue){
    auto start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < 500000; ++i) {
        queue.push(rand()%5000);
    }
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    return time_taken;
}

void queueTester(){
    Queue<int> queueArr(new ArraySeq<int>);
    Queue<int> queueList(new ListSeq<int>);
    ofstream file;
    fillQueues(&queueArr,&queueList);
    file.open("intTest3.csv", ios::app);
//    file<<"swap array,swap list,append array,append list,pop array,pop list"<<endl;
    cout<<"Testing"<<endl;
        file<<fixed<<setprecision(0)<<swapTester(queueArr)<<","<<swapTester(queueList)
            <<","<<pushTester(queueArr)<<","<<pushTester(queueList)
                <<","<<popTester(queueArr)<<","<<popTester(queueList)
                    <<endl;
    cout<<"End of test"<<endl;
    file.close();
//    cout<<"queueArr: "<< queueArr<<endl;
//    cout<<"queueList: "<< queueList<<endl;
}
