/**
 * @author James Hedayet Zaman
 * */

#pragma once

#include "jalgo.h"

std::vector<int> jal::divisors(int n)
{
    std::vector <int> vec;
        for (int i=1; i<=sqrt(n); i++)
        {
            if (n%i == 0)
            {
                if (n/i == i)
                    vec.push_back(i);

                else {
                    vec.push_back(i);
                    vec.push_back(n/i);
                }
            }
        }
        return vec;
}

int jal::gcd(int x, int y)
{
    if (!x) return y;
    return jal::gcd(y % x, x);
}

bool jal::isPrime(int num) //Sieve of Eratosthenes
{
    if(num <= 3 && num > 0) {
        return true;
    }
    else if(num%2 == 0 || num%3 == 0)
    {
        return false;
    }

    int i = 5;

    while(i*i <= num) {
        if(num%i == 0 || num%(i + 2) == 0) {
            return false;
        }
        i = i+6;
    }
    return true;

}

int jal::lcm(int x, int y)
{
    return (x * y)/jal::gcd(x, y);
}

std::vector<long> jal::primes(long num) //Sieve of Eratosthenes
{
    std::vector <long> primeList;
        bool prime[num+1];
        memset(prime, true, sizeof(prime));

        for (long p=2; p*p<=num; p++)
        {
            if (prime[p])
            {
                for (long i=p*p; i<=num; i += p)
                    prime[i] = false;
            }
        }

        for (long p=2; p<=num; p++) {
            if (prime[p]) {
                primeList.push_back(p);
            }
        }
        return primeList;
}

template <typename T>
void vector::print(std::vector<T> toPrint)
{
    for(auto a : toPrint) {
        std::cout << a << "\t";
    }
    std::cout << "\n";
}

template <typename T>
void vector::print2d(std::vector<std::vector<T>> toPrint)
{
    for(auto a : toPrint) {
        vector::print(a);
    }
    std::cout << "\n";
}

std::vector<std::string> string::split(std::string str, char c) {
    int startIndex = 0, i;
    std::vector<std::string> ret;
    for(i = 0; i < str.size(); ++i) {
        if(str.at(i) == c) {
            ret.push_back(str.substr(startIndex, i - startIndex));
            startIndex = i + 1;
        }
    }
    ret.push_back(str.substr(startIndex, i - startIndex));
    return ret;
}
