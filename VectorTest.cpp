#include "vector.h"
#include <iostream>
#include <cassert>
#include <initializer_list>
#include <chrono>
#include <vector>

void test_default_constructor() {
    vector<int> v;
    assert(v.size() == 0);
    assert(v.empty());
    std::cout << "Default constructor test passed!" << std::endl;
}

void test_fill_constructor() {
    vector<int> v(10, 5);
    assert(v.size() == 10);
    for (size_t i = 0; i < v.size(); ++i) {
        assert(v[i] == 5);
    }
    std::cout << "Fill constructor test passed!" << std::endl;
}

void test_copy_constructor() {
    vector<int> v1(5, 10);
    vector<int> v2(v1);
    assert(v2.size() == 5);
    for (size_t i = 0; i < v2.size(); ++i) {
        assert(v2[i] == 10);
    }
    std::cout << "Copy constructor test passed!" << std::endl;
}

void test_move_constructor() {
    vector<int> v1(5, 10);
    vector<int> v2(std::move(v1));
    assert(v2.size() == 5);
    for (size_t i = 0; i < v2.size(); ++i) {
        assert(v2[i] == 10);
    }
    assert(v1.size() == 0);
    std::cout << "Move constructor test passed!" << std::endl;
}

void test_initializer_list_constructor() {
    vector<int> v = {1, 2, 3, 4, 5};
    std::cout << "Size of v: " << v.size() << std::endl;
    assert(v.size() == 5);
    for (vector<int>::size_type i = 0; i < v.size(); ++i) {
        std::cout << "v[" << i << "] = " << v[i] << std::endl;
        assert(v[i] == static_cast<int>(i) + 1);
    }
    std::cout << "Initializer list constructor test passed!" << std::endl;
}


void test_assignment_operator() {
    vector<int> v1(5, 10);
    vector<int> v2;
    v2 = v1;
    assert(v2.size() == 5);
    for (size_t i = 0; i < v2.size(); ++i) {
        assert(v2[i] == 10);
    }
    std::cout << "Assignment operator test passed!" << std::endl;
}

void test_move_assignment_operator() {
    vector<int> v1(5, 10);
    vector<int> v2;
    v2 = std::move(v1);
    assert(v2.size() == 5);
    for (size_t i = 0; i < v2.size(); ++i) {
        assert(v2[i] == 10);
    }
    assert(v1.size() == 0);
    std::cout << "Move assignment operator test passed!" << std::endl;
}

void test_element_access() {
    vector<int> v = {1, 2, 3, 4, 5};
    assert(v.front() == 1);
    assert(v.back() == 5);
    assert(v[2] == 3);
    try {
        v.at(10);
    } catch (const std::out_of_range& e) {
        std::cout << "Out of range exception caught as expected!" << std::endl;
    }
    std::cout << "Element access tests passed!" << std::endl;
}

void test_modifiers() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    assert(v.size() == 3);
    assert(v.back() == 3);
    v.pop_back();
    assert(v.size() == 2);
    assert(v.back() == 2);
    v.insert(v.begin(), 0); // Corrected: Insert 0 at the beginning of the vector
    assert(v.front() == 0); // Check if the front element is 0
    v.erase(v.begin());
    assert(v.front() == 1);
    std::cout << "Modifiers tests passed!" << std::endl;
}



void test_comparisons() {
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {1, 2, 3};
    vector<int> v3 = {4, 5, 6};
    assert(v1 == v2);
    assert(v1 != v3);
    assert(v1 < v3);
    assert(v3 > v1);
    assert(v1 <= v2);
    assert(v3 >= v1);
    std::cout << "Comparisons tests passed!" << std::endl;
}


void test_fill_time() {
    // Array of sizes to test
    std::vector<unsigned int> sizes = {10000, 100000, 1000000, 10000000, 100000000};

    // Print table header
    std::cout << "Size          | std::vector Time (seconds) | Custom vector Time (seconds) | std::vector Reallocations | Custom vector Reallocations" << std::endl;
    std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;

    // Iterate over each size
    for (unsigned int sz : sizes) {
        // Measure time for std::vector
        auto start_v1 = std::chrono::high_resolution_clock::now();
        std::vector<int> v1;
        int reallocations_v1 = 0;
        for (unsigned int i = 1; i <= sz; ++i) {
            v1.push_back(i);
            if (v1.capacity() == v1.size()) {
                reallocations_v1++;
            }
        }
        auto finish_v1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_v1 = finish_v1 - start_v1;

        // Measure time for custom vector
        auto start_v2 = std::chrono::high_resolution_clock::now();
        vector<int> v2;
        int reallocations_v2 = 0;
        for (unsigned int i = 1; i <= sz; ++i) {
            v2.push_back(i);
            if (v2.capacity() == v2.size()) {
                reallocations_v2++;
            }
        }
        auto finish_v2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_v2 = finish_v2 - start_v2;

        // Print results for current size
        std::cout << sz << " | " << elapsed_v1.count() << " | " << elapsed_v2.count() << " | " << v1.capacity() - v1.size() << " | " << reallocations_v1 << " | " <<reallocations_v2 << std::endl;
    }
}
