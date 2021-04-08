#include <iostream>
#include <algorithm>
#include <chrono>
#include "bst.hxx"
#include "rb.hxx"

using namespace std;

#define SIZE_LIM 10000

int main()
{
    int arr[SIZE_LIM];
    for (int i = 0; i < SIZE_LIM; i++)
    {
        arr[i] = i + 1;
    }
    random_shuffle(begin(arr), end(arr));
    BinaryTree<int>    bst_tree[10];
    RBTree<int>        rb_tree[10];
    int count = -1;
    for (int i = 0; i < SIZE_LIM; i++)
    {
        if (i % 1000 == 0)
            ++count;

        bst_tree[count].add(arr[i]);
        rb_tree[count].insert(arr[i]);
    }

    int total = 0;
    for (int i = 0; i < 10; i++)
    {
        total += rb_tree[i].getRotations();
        cout << "# of rotations in RBtree: " << i + 1 << "\t" << rb_tree[i].getRotations() << endl;
    }
    cout << "\nAvg rotaion for 1000 ints in RBtree is: " << total / 10 << endl << endl;

    count = 0;
    RBTree<int>  rb_tree100[10];
    for(int i=0; i<10; i++)
    {
       cout << "Time taken to build RBtree with 100 values: ";
       auto start = chrono::steady_clock::now();
       for(int j=0; j<100; j++)
       {
         rb_tree100[i].insert(arr[count]);
         count++;
       }
       auto end = chrono::steady_clock::now();
       auto diff = end - start;
       cout << chrono::duration <double, nano>(diff).count() << " ns" << endl;
    }

    cout << endl;
    count = 0;
    RBTree<int>  rb_tree200[10];
    for (int i = 0; i < 10; i++)
    {
        cout << "Time taken to build RBtree with 200 values: ";
        auto start = chrono::steady_clock::now();
        for (int j = 0; j < 100; j++)
        {
            rb_tree100[i].insert(arr[i]);
        }
        auto end = chrono::steady_clock::now();
        auto diff = end - start;
        cout << chrono::duration <double, nano>(diff).count() << " ns" << endl;
    }

    cout << endl;
    count = 0;
    RBTree<int>  rb_tree300[10];
    for (int i = 0; i < 10; i++)
    {
        cout << "Time taken to build RBtree with 300 values: ";
        auto start = chrono::steady_clock::now();
        for (int j = 0; j < 300; j++)
        {
            rb_tree100[i].insert(arr[i]);
        }
        auto end = chrono::steady_clock::now();
        auto diff = end - start;
        cout << chrono::duration <double, nano>(diff).count() << " ns" << endl;
    }
    
    cout << endl;
    count = 0;
    RBTree<int>  rb_tree400[10];
    for (int i = 0; i < 10; i++)
    {
        cout << "Time taken to build RBtree with 400 values: ";
        auto start = chrono::steady_clock::now();
        for (int j = 0; j < 400; j++)
        {
            rb_tree100[i].insert(arr[i]);
        }
        auto end = chrono::steady_clock::now();
        auto diff = end - start;
        cout << chrono::duration <double, nano>(diff).count() << " ns" << endl;
    }

    cout << endl;
    count = 0;
    RBTree<int>  rb_tree500[10];
    for (int i = 0; i < 10; i++)
    {
        cout << "Time taken to build RBtree with 500 values: ";
        auto start = chrono::steady_clock::now();
        for (int j = 0; j < 500; j++)
        {
            rb_tree100[i].insert(arr[i]);
        }
        auto end = chrono::steady_clock::now();
        auto diff = end - start;
        cout << chrono::duration <double, nano>(diff).count() << " ns" << endl;
    }

    cout << endl;
    count = 0;
    RBTree<int>  rb_tree600[10];
    for (int i = 0; i < 10; i++)
    {
        cout << "Time taken to build RBtree with 600 values: ";
        auto start = chrono::steady_clock::now();
        for (int j = 0; j < 600; j++)
        {
            rb_tree100[i].insert(arr[i]);
        }
        auto end = chrono::steady_clock::now();
        auto diff = end - start;
        cout << chrono::duration <double, nano>(diff).count() << " ns" << endl;
    }

    cout << endl;
    count = 0;
    RBTree<int>  rb_tree700[10];
    for (int i = 0; i < 10; i++)
    {
        cout << "Time taken to build RBtree with 700 values: ";
        auto start = chrono::steady_clock::now();
        for (int j = 0; j < 700; j++)
        {
            rb_tree100[i].insert(arr[i]);
        }
        auto end = chrono::steady_clock::now();
        auto diff = end - start;
        cout << chrono::duration <double, nano>(diff).count() << " ns" << endl;
    }

    cout << endl;
    count = 0;
    RBTree<int>  rb_tree800[10];
    for (int i = 0; i < 10; i++)
    {
        cout << "Time taken to build RBtree with 800 values: ";
        auto start = chrono::steady_clock::now();
        for (int j = 0; j < 800; j++)
        {
            rb_tree100[i].insert(arr[i]);
        }
        auto end = chrono::steady_clock::now();
        auto diff = end - start;
        cout << chrono::duration <double, nano>(diff).count() << " ns" << endl;
    }

    cout << endl;
    count = 0;
    RBTree<int>  rb_tree900[10];
    for (int i = 0; i < 10; i++)
    {
        cout << "Time taken to build RBtree with 900 values: ";
        auto start = chrono::steady_clock::now();
        for (int j = 0; j < 900; j++)
        {
            rb_tree100[i].insert(arr[i]);
        }
        auto end = chrono::steady_clock::now();
        auto diff = end - start;
        cout << chrono::duration <double, nano>(diff).count() << " ns" << endl;
    }

    cout << endl;
    count = 0;
    RBTree<int>  rb_tree1000[10];
    for (int i = 0; i < 10; i++)
    {
        cout << "Time taken to build RBtree with 1000 values: ";
        auto start = chrono::steady_clock::now();
        for (int j = 0; j < 1000; j++)
        {
            rb_tree100[i].insert(arr[i]);
        }
        auto end = chrono::steady_clock::now();
        auto diff = end - start;
        cout << chrono::duration <double, nano>(diff).count() << " ns" << endl;
    }
}