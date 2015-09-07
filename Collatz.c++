// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair

#include "Collatz.h"

using namespace std;

// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

// helper method for collatz_eval

int collatz_eval_helper (int n) {
    assert (n > 0);
    int c = 1;
    while (n > 1) {
        if ((n%2) == 0)
            n = n/2;
        else 
            n = (3 * n) + 1;
        ++c;
    }
    assert (c > 0);
    return c;
}
// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    // <your code>
    int max = 0;

    for (int a = i; a <= j; ++a) {
        int evaluate = collatz_eval_helper(a);
        if (evaluate > max)
            max = evaluate;
    } 
    return max;}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
