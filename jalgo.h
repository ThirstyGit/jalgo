/**
 * @author James Hedayet Zaman
 * */

#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

#define log(x) std::cout << x << "\n"

#include "tree.cpp"

namespace jal
{
    std::vector <int> divisors(int n);

    int gcd(int x, int y);

    bool isPrime(int num); //Sieve of Eratosthenes

    int lcm(int x, int y);

    std::vector<long> primes(long num); //Sieve of Eratosthenes
}

namespace vector
{
    template <typename T>
    void print(std::vector<T> toPrint);

    template <typename T>
    void print2d(std::vector<std::vector<T>> toPrint);
}

namespace string {
    std::vector<std::string> split(std::string str, char c);
}
