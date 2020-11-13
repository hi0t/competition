#pragma once

#include <chrono>
#include <functional>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool __reportData(const std::string &want, const std::string &fact, int ms)
{
    const std::string titleWant = "want", titleFact = "fact";
    std::istringstream ssWant(want), ssFact(fact);
    std::vector<std::string> colWant, colFact;
    size_t sizeWant = 0, sizeFact = 0;
    std::string sWant, sFact;

    while (std::getline(ssWant, sWant) || std::getline(ssFact, sFact))
    {
        if (!sWant.empty())
        {
            sizeWant = std::max(sizeWant, sWant.size());
            colWant.push_back(sWant);
        }
        if (!sFact.empty())
        {
            sFact.erase(std::find_if(sFact.rbegin(), sFact.rend(), std::bind1st(std::not_equal_to<char>(), ' ')).base(), sFact.end());
            sizeFact = std::max(sizeFact, sFact.size());
            colFact.push_back(sFact);
        }
    }
    sizeWant = std::max(sizeWant, titleWant.size()) + 1;
    sizeFact = std::max(sizeFact, titleFact.size()) + 1;

    std::cout << std::setw(sizeWant) << titleWant << std::setw(sizeFact) << titleFact << std::endl;
    for (size_t i = 0; i < sizeWant + sizeFact; i++)
    {
        std::cout << '-';
    }
    std::cout << std::endl;

    bool res = true;

    size_t i = 0;
    while (i < colWant.size() || i < colFact.size())
    {
        std::string lastWant;
        if (i < colWant.size())
        {
            lastWant = colWant[i];
            std::cout << std::setw(sizeWant) << colWant[i];
        }
        if (i < colFact.size())
        {
            if (colFact[i] != lastWant)
            {
                res = false;
            }
            std::cout << (colFact[i] == lastWant ? "\033[32m" : "\033[31m")
                      << std::setw(sizeFact) << colFact[i]
                      << "\033[0m";
        }
        else
        {
            res = false;
        }
        std::cout << std::endl;
        i++;
    }

    for (size_t i = 0; i < sizeWant + sizeFact; i++)
    {
        std::cout << '-';
    }
    std::cout << std::endl;
    std::cout << std::setw(sizeWant + sizeFact) << (std::to_string(ms) + " ms") << std::endl;

    return res;
}

bool check(const std::function<int(void)> &mainFn, const std::string &test, const std::string &want)
{
    std::istringstream in(test);
    auto cinbuf = std::cin.rdbuf(in.rdbuf());

    std::ostringstream out;
    auto coutbuf = std::cout.rdbuf(out.rdbuf());

    auto start = std::chrono::high_resolution_clock::now();
    mainFn();
    auto stop = std::chrono::high_resolution_clock::now();

    auto fact = out.str();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    return __reportData(want, fact, duration.count());
}

void __reportResult(const char *file, unsigned int line, bool valid)
{
    std::cout << file << ":" << line << "\t"
              << (valid ? "\033[32mPASSED\033[0m" : "\033[31mFAILED\033[0m")
              << std::endl;
}

#define ASSERT(expr)                                \
    (static_cast<bool>(expr)                        \
         ? __reportResult(__FILE__, __LINE__, true) \
         : [] { __reportResult(__FILE__, __LINE__, false); asm("int3"); }())
