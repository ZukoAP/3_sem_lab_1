#include "gtest/gtest.h"
#include "../Sorters/QuickSorter.h"
#include "../ArraySequence.h"
#include "../ListSequence.h"
#include <vector>
#include <random>
#include <chrono>

static std::vector<int> generateDataLarge(size_t size) {
    using value_type = int;
    // We use static in order to instantiate the random engine
    // and the distribution once only.
    // It may provoke some thread-safety issues.
    static std::uniform_int_distribution<value_type> distribution(
            std::numeric_limits<value_type>::min(),
            std::numeric_limits<value_type>::max());
    std::random_device rd;
    static std::default_random_engine generator(rd());

    std::vector<value_type> data(size);
    std::generate(data.begin(), data.end(), []() { return distribution(generator); });
    return data;
}

static std::vector<int> generateDataSmall(size_t size) {
    using value_type = int;
    static std::uniform_int_distribution<value_type> distribution(-100, 100);
    std::random_device rd;
    static std::default_random_engine generator(rd());

    std::vector<value_type> data(size);
    std::generate(data.begin(), data.end(), []() { return distribution(generator); });
    return data;
}

template<typename T>
void printVector(const vector<T>& v) {
    cout << "[ ";
    for (const auto& elem : v) {
        cout << elem << " ";
    }
    cout << "]" << endl;
}


TEST(QuickSorterTestSuite, ArraySeqNullSize) {
    ArraySeq<int> seq;
    auto* sorter = new QuickSorter<int>;
    Sequence<int>* res = sorter->sort(&seq, &lessThan<>);
    ASSERT_EQ(0, res->length()) << "Resultant sequence is not empty";
}

TEST(QuickSorterTestSuite, ArraySequenceEqualElements) {
    std::vector<int> initial(200, 1);
    ArraySeq<int> seq;
    for (const auto& elem: initial) {
        seq.append(elem);
    }
    std::sort(initial.begin(), initial.end(), less<>());
    auto* sorter = new QuickSorter<int>;
    auto start = chrono::steady_clock::now();
    Sequence<int>* res = sorter->sort(&seq, &lessThan<>);
    auto end = chrono::steady_clock::now();
    cout << "Sorting time: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms" << endl;
    ASSERT_EQ(initial.size(), res->length()) << "Resultant and initial's sequence's lengths doesn't match";
    for (int i = 0; i < initial.size(); i++) {
        ASSERT_EQ(initial[i], res->getElement(i));
    }
}

TEST(QuickSorterTestSuite, ArraySequenceUsualAscending) {
    std::vector<int> initial = {1, 5, 2, 7, 3, 234, 4564364, 465, 2243, 890, 45, 56, 345, 98, 0};
    ArraySeq<int> seq;
    for (const auto& elem: initial) {
        seq.append(elem);
    }
    std::sort(initial.begin(), initial.end(), less<>());
    auto* sorter = new QuickSorter<int>;
    auto start = chrono::steady_clock::now();
    Sequence<int>* res = sorter->sort(&seq, &lessThan<>);
    auto end = chrono::steady_clock::now();
    cout << "Sorting time: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms" << endl;
    ASSERT_EQ(initial.size(), res->length()) << "Resultant and initial's sequence's lengths doesn't match";
    for (int i = 0; i < initial.size(); i++) {
        ASSERT_EQ(initial[i], res->getElement(i));
    }
    printVector(initial);
}

TEST(QuickSorterTestSuite, ArraySequenceUsualDescending) {
    std::vector<int> initial = {1, 5, 2, 7, 3, 234, 4564364, 465, 2243, 890, 45, 56, 345, 98, 0};
    ArraySeq<int> seq;
    for (const auto& elem: initial) {
        seq.append(elem);
    }
    std::sort(initial.begin(), initial.end(), greater<>());
    auto* sorter = new QuickSorter<int>;
    auto start = chrono::steady_clock::now();
    Sequence<int>* res = sorter->sort(&seq, &greaterThan<>);
    auto end = chrono::steady_clock::now();
    cout << "Sorting time: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms" << endl;
    ASSERT_EQ(initial.size(), res->length()) << "Resultant and initial's sequence's lengths doesn't match";
    for (int i = 0; i < initial.size(); i++) {
        ASSERT_EQ(initial[i], res->getElement(i));
    }
    printVector(initial);
}

TEST(QuickSorterTestSuite, ArraySequenceLarge) {
    std::vector<int> initial = generateDataLarge(1000);
    ArraySeq<int> seq;
    for (const auto& elem: initial) {
        seq.append(elem);
    }
    std::sort(initial.begin(), initial.end(), less<>());
    auto* sorter = new QuickSorter<int>;
    auto start = chrono::steady_clock::now();
    Sequence<int>* res = sorter->sort(&seq, &lessThan<>);
    auto end = chrono::steady_clock::now();
    cout << "Sorting time: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms" << endl;
    ASSERT_EQ(initial.size(), res->length()) << "Resultant and initial's sequence's lengths doesn't match";
    for (int i = 0; i < initial.size(); i++) {
        ASSERT_EQ(initial[i], res->getElement(i));
    }
    printVector(initial);
}

TEST(QuickSorterTestSuite, ArraySequenceSortedDirectly) {
    std::vector<int> initial = generateDataLarge(1000);
    ArraySeq<int> seq;
    std::sort(initial.begin(), initial.end(), less<>());
    for (const auto& elem: initial) {
        seq.append(elem);
    }
    auto* sorter = new QuickSorter<int>;
    auto start = chrono::steady_clock::now();
    Sequence<int>* res = sorter->sort(&seq, &lessThan<>);
    auto end = chrono::steady_clock::now();
    cout << "Sorting time: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms" << endl;
    ASSERT_EQ(initial.size(), res->length()) << "Resultant and initial's sequence's lengths doesn't match";
    for (int i = 0; i < initial.size(); i++) {
        ASSERT_EQ(initial[i], res->getElement(i));
    }
    printVector(initial);
}

TEST(QuickSorterTestSuite, ArraySequenceSortedReverse) {
    std::vector<int> initial = generateDataLarge(1000);
    ArraySeq<int> seq;
    std::sort(initial.begin(), initial.end(), greater<>());
    for (const auto& elem: initial) {
        seq.append(elem);
    }
    auto* sorter = new QuickSorter<int>;
    auto start = chrono::steady_clock::now();
    Sequence<int>* res = sorter->sort(&seq, &lessThan<>);
    auto end = chrono::steady_clock::now();
    cout << "Sorting time: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms" << endl;
    ASSERT_EQ(initial.size(), res->length()) << "Resultant and initial's sequence's lengths doesn't match";
    for (int i = 0; i < initial.size(); i++) {
        ASSERT_EQ(initial[initial.size() - 1 - i], res->getElement(i));
    }
    printVector(initial);
}

TEST(QuickSorterTestSuite, ArraySequenceSmallValues) {
    std::vector<int> initial = generateDataSmall(10000);
    ArraySeq<int> seq;
    for (const auto& elem: initial) {
        seq.append(elem);
    }
    std::sort(initial.begin(), initial.end(), less<>());
    auto* sorter = new QuickSorter<int>;
    auto start = chrono::steady_clock::now();
    Sequence<int>* res = sorter->sort(&seq, &lessThan<>);
    auto end = chrono::steady_clock::now();
    cout << "Sorting time: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms" << endl;
    ASSERT_EQ(initial.size(), res->length()) << "Resultant and initial's sequence's lengths doesn't match";
    for (int i = 0; i < initial.size(); i++) {
        ASSERT_EQ(initial[i], res->getElement(i));
    }
    printVector(initial);
}

TEST(QuickSorterTestSuite, ArraySequenceWithNegative) {
    std::vector<int> initial = {1, 5, -2, 7, 3, -234, 4564364, -465, -2243, 890, -45, 56, 345, -98, 0};
    ArraySeq<int> seq;
    for (const auto& elem: initial) {
        seq.append(elem);
    }
    std::sort(initial.begin(), initial.end(), less<>());
    auto* sorter = new QuickSorter<int>;
    auto start = chrono::steady_clock::now();
    Sequence<int>* res = sorter->sort(&seq, &lessThan<>);
    auto end = chrono::steady_clock::now();
    cout << "Sorting time: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms" << endl;
    ASSERT_EQ(initial.size(), res->length()) << "Resultant and initial's sequence's lengths doesn't match";
    for (int i = 0; i < initial.size(); i++) {
        ASSERT_EQ(initial[i], res->getElement(i));
    }
    printVector(initial);
}

TEST(QuickSorterTestSuite, ListSeqNullSize) {
    ListSeq<int> seq;
    auto* sorter = new QuickSorter<int>;
    Sequence<int>* res = sorter->sort(&seq, &lessThan<>);
    ASSERT_EQ(0, res->length()) << "Resultant sequence is not empty";
}

TEST(QuickSorterTestSuite, ListSequenceUsualAscending) {
    std::vector<int> initial = {1, 5, 2, 7, 3, 234, 4564364, 465, 2243, 890, 45, 56, 345, 98, 0};
    ListSeq<int> seq;
    for (const auto& elem: initial) {
        seq.append(elem);
    }
    std::sort(initial.begin(), initial.end(), less<>());
    auto* sorter = new QuickSorter<int>;
    auto start = chrono::steady_clock::now();
    Sequence<int>* res = sorter->sort(&seq, &lessThan<>);
    auto end = chrono::steady_clock::now();
    cout << "Sorting time: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms" << endl;
    ASSERT_EQ(initial.size(), res->length()) << "Resultant and initial's sequence's lengths doesn't match";
    for (int i = 0; i < initial.size(); i++) {
        ASSERT_EQ(initial[i], res->getElement(i));
    }
    printVector(initial);
}

TEST(QuickSorterTestSuite, ListSequenceUsualDescending) {
    std::vector<int> initial = {1, 5, 2, 7, 3, 234, 4564364, 465, 2243, 890, 45, 56, 345, 98, 0};
    ListSeq<int> seq;
    for (const auto& elem: initial) {
        seq.append(elem);
    }
    std::sort(initial.begin(), initial.end(), greater<>());
    auto* sorter = new QuickSorter<int>;
    auto start = chrono::steady_clock::now();
    Sequence<int>* res = sorter->sort(&seq, &greaterThan<>);
    auto end = chrono::steady_clock::now();
    cout << "Sorting time: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms" << endl;
    ASSERT_EQ(initial.size(), res->length()) << "Resultant and initial's sequence's lengths doesn't match";
    for (int i = 0; i < initial.size(); i++) {
        ASSERT_EQ(initial[i], res->getElement(i));
    }
    printVector(initial);
}

TEST(QuickSorterTestSuite, ListSequenceLarge) {
    std::vector<int> initial = generateDataLarge(1000);
    ListSeq<int> seq;
    for (const auto& elem: initial) {
        seq.append(elem);
    }
    std::sort(initial.begin(), initial.end(), less<>());
    auto* sorter = new QuickSorter<int>;
    auto start = chrono::steady_clock::now();
    Sequence<int>* res = sorter->sort(&seq, &lessThan<>);
    auto end = chrono::steady_clock::now();
    cout << "Sorting time: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms" << endl;
    ASSERT_EQ(initial.size(), res->length()) << "Resultant and initial's sequence's lengths doesn't match";
    for (int i = 0; i < initial.size(); i++) {
        ASSERT_EQ(initial[i], res->getElement(i));
    }
    printVector(initial);
}

TEST(QuickSorterTestSuite, ListSequenceSortedDirectly) {
    std::vector<int> initial = generateDataLarge(1000);
    ListSeq<int> seq;
    std::sort(initial.begin(), initial.end(), less<>());
    for (const auto& elem: initial) {
        seq.append(elem);
    }
    auto* sorter = new QuickSorter<int>;
    auto start = chrono::steady_clock::now();
    Sequence<int>* res = sorter->sort(&seq, &lessThan<>);
    auto end = chrono::steady_clock::now();
    cout << "Sorting time: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms" << endl;
    ASSERT_EQ(initial.size(), res->length()) << "Resultant and initial's sequence's lengths doesn't match";
    for (int i = 0; i < initial.size(); i++) {
        ASSERT_EQ(initial[i], res->getElement(i));
    }
    printVector(initial);
}

TEST(QuickSorterTestSuite, ListSequenceSortedReverse) {
    std::vector<int> initial = generateDataLarge(1000);
    ListSeq<int> seq;
    std::sort(initial.begin(), initial.end(), greater<>());
    for (const auto& elem: initial) {
        seq.append(elem);
    }
    auto* sorter = new QuickSorter<int>;
    auto start = chrono::steady_clock::now();
    Sequence<int>* res = sorter->sort(&seq, &lessThan<>);
    auto end = chrono::steady_clock::now();
    cout << "Sorting time: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms" << endl;
    ASSERT_EQ(initial.size(), res->length()) << "Resultant and initial's sequence's lengths doesn't match";
    for (int i = 0; i < initial.size(); i++) {
        ASSERT_EQ(initial[initial.size() - 1 - i], res->getElement(i));
    }
    printVector(initial);
}

TEST(QuickSorterTestSuite, ListSequenceWithNegative) {
    std::vector<int> initial = {1, 5, -2, 7, 3, -234, 4564364, -465, -2243, 890, -45, 56, 345, -98, 0};
    ListSeq<int> seq;
    for (const auto& elem: initial) {
        seq.append(elem);
    }
    std::sort(initial.begin(), initial.end(), less<>());
    auto* sorter = new QuickSorter<int>;
    auto start = chrono::steady_clock::now();
    Sequence<int>* res = sorter->sort(&seq, &lessThan<>);
    auto end = chrono::steady_clock::now();
    cout << "Sorting time: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms" << endl;
    ASSERT_EQ(initial.size(), res->length()) << "Resultant and initial's sequence's lengths doesn't match";
    for (int i = 0; i < initial.size(); i++) {
        ASSERT_EQ(initial[i], res->getElement(i));
    }
    printVector(initial);
}

TEST(QuickSorterTestSuite, ListSequenceSmallValues) {
    std::vector<int> initial = generateDataSmall(10000);
    ListSeq<int> seq;
    for (const auto& elem: initial) {
        seq.append(elem);
    }
    std::sort(initial.begin(), initial.end(), less<>());
    auto* sorter = new QuickSorter<int>;
    auto start = chrono::steady_clock::now();
    Sequence<int>* res = sorter->sort(&seq, &lessThan<>);
    auto end = chrono::steady_clock::now();
    cout << "Sorting time: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms" << endl;
    ASSERT_EQ(initial.size(), res->length()) << "Resultant and initial's sequence's lengths doesn't match";
    for (int i = 0; i < initial.size(); i++) {
        ASSERT_EQ(initial[i], res->getElement(i));
    }
    printVector(initial);
}
