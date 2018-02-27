#include <iostream> // cout to debug
#include <cstdlib> // rand
#include <stdexcept> // domain_error

int nrand(int n){
    if (n <= 0 || n > RAND_MAX)
        throw std::domain_error("Argument to nrand is out of range.");

    //    We do not simply modulate to rand() % n because of two reasons:
    //    1. pseudo random numbers sometimes alternate even and odd, and if n = 2, then it will alterate 0 and 1
    //    2. if n is large, some randomly generated numbers will modulate to a number more frequently than others
    //       (e.g. n = 20000, then result of rand() could be 30000 or 10000 to modulate to 10000)
    //
    //    Therefore, we partition available random numbers into n equal-sized buckets
    //    then we receive a random number, and see which bucket it falls into.
    //    If number is outside of the bucket range, then try again

    const int bucket_size = RAND_MAX / n;
    int r;

    do r = rand() / bucket_size;
    while (r >= n);
    std::cout << r << std::endl;
    return r;
}
