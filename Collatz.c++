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
int cache [50000] = {};
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
    if (n < 50000 && cache[n] != 0)
        return cache[n];
    int c = 1;
    while (n > 1) {
        int new_n;
        if ((n%2) == 0) {
            new_n = n/2;
        }
        else {
            new_n = (3 * n) + 1;
        }
        
        if (new_n < 50000 && cache[new_n] != 0) {
            cache[n] = cache[new_n] + 1;
            return cache[n];
        }
        n = new_n;
        ++c;
    }
    assert (c > 0);
    return c;} 

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    assert (i > 0 && j > 0);
    assert (i < 1000000 && j < 1000000);
    
    int max = 0;
    if (i > j) {
        int temp = i;
        i = j;
        j = temp;}

    for (int a = i; a <= j; ++a) {
        int evaluate = collatz_eval_helper(a);
        if (evaluate > max)
            max = evaluate;}
 
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

