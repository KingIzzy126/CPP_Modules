#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe& source) : _vec(source._vec), _deq(source._deq)
{

}

PmergeMe& PmergeMe::operator=(const PmergeMe& source)
{
    if (this != &source)
    {
        _vec = source._vec;
        _deq = source._deq;
    }
}

PmergeMe::~PmergeMe()
{

}

void    PmergeMe::parseInput(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
    {
        char*   end;
        long    val = std::strtol(av[i], &end, 10);
        
        if (end == av[i] || *end != '\0')
        {
            std::cerr << "Error\n";
            exit (1);
        }
        if (val <= 0)
        {
            std::cerr << "Error\n";
        }
        if (val > 2147483647)
        {
            std::cerr << "Error\n";
            exit (1);
        }
        _vec.push_back(static_cast<int>(val));
        _deq.push_back(static_cast<int>(val));
    }
}

void    PmergeMe::run()
{
    std::cout << "Before:";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << " " << _vec[i];
    std::cout << "\n";

    clock_t startVec = clock();
    mergeInsertVec(_vec);
    clock_t endVec = clock();

    clock_t startDeq = clock();
    mergeInsertDeq(_deq);
    clock_t endDeq = clock();

    std::cout << "After: ";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << " " << _vec[i];
    std::cout << "\n";

    double vecTime = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0;
    double deqTime = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000.0;

    std::cout << "Time to process a range of " << _vec.size()
                << " elements with std::vector : "
                << std::fixed << std::setprecision(5)
                << vecTime << " us\n";

    std::cout << "Time to process a range of " << _deq.size()
                << " elements with std::deqie : "
                << std::fixed << std::setprecision(5)
                << deqTime << " us\n";
}

int PmergeMe::jacobsthal(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    int prev2 = 0, prev1 = 1, curr = 0;
    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + 2 * prev2; // J(n) = J(n-1) + 2*J(n-2)
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

void PmergeMe::binaryInsertVec(std::vector<int>& chain, int value, int bound)
{
    int lo = 0;
    int hi = bound;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (chain[mid] < value)
            lo = mid + 1; // place value to the right
        else
            hi = mid; // place value at mid or to the left
    }
    chain.insert(chain.begin() + lo, value);
}

void PmergeMe::insertPendingVec(std::vector<int>& chain, std::vector<int>& pending)
{
    int size = static_cast<int>(pending.size());
    if (size == 0)
        return;
    binaryInsertVec(chain, pending[0], 1);
    int k = 2;
    while (true)
    {
        int jCurr = jacobsthal(k);
        int jPrev = jacobsthal(k - 1);
        if (jPrev >= size)
            break;
        int groupEnd = (jCurr < size) ? jCurr : size;
        for (int i = groupEnd - 1; i >= jPrev; i--)
            binaryInsertVec(chain, pending[i], static_cast<int>(chain.size()));
        k++;
    }
}

void PmergeMe::mergeInsertVec(std::vector<int>& vec)
{
    int n = static_cast<int> (vec.size());

    if (n <= 1)
        return;
    bool    hasStraggler = (n % 2 != 0);
    int     straggler = 0;
    if (hasStraggler)
        straggler = vec.back();
    int pairCount = n / 2;
    std::vector<std::pair<int,int>> pairs;
    for (int i = 0; i < pairCount; i++)
    {
        int a = vec[i * 2];
        int b = vec[i * 2 + 1];
        if (a > b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }
    std::vector<int> largers;
    for (int i = 0; i < pairCount; i++)
        largers.push_back(pairs[i].second);
    mergeInsertVec(largers);
    std::vector<std::pair<int,int>> sortedPairs;
    std::vector<bool>               used(pairCount, false);
    for (int i = 0; i < pairCount; i++)
    {
        for (int j = 0; j < pairCount; j++)
        {
            if (!used[j] && pairs[j].second == largers[i])
            {
                sortedPairs.push_back(pairs[j]);
                used[j] = true;
                break;
            }
        }
    }
    std::vector<int> chain;
    std::vector<int> pending;
    for (int i = 0; i < pairCount; i++)
    {
        chain.push_back(sortedPairs[i].second);
        pending.push_back(sortedPairs[i].first);
    }
    insertPendingVec(chain, pending);
    if (hasStraggler)
        binaryInsertVec(chain, straggler, static_cast<int>(chain.size()));
    vec = chain;
}

void PmergeMe::binaryInsertDeq(std::deque<int>& chain, int val, int bound)
{
    int lo = 0;
    int hi = bound;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (chain[mid] < val)
            lo = mid + 1;
        else
            hi = mid;
    }
    chain.insert(chain.begin() + lo, val);
}

