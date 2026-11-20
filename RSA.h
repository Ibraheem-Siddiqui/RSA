#ifndef RSA_H
#define RSA_H

#include <utility>

class RSA
{

private:
    // Private fields
    int p{};
    int q{};
    int public_key{};
    int private_key{};

    // Privates methods
    std::pair<int,int> EEA(int a, int b);
    int gcd(int a, int b);
    int generate_public_key(int p, int q);
    int generate_private_key(int e, int p, int q);

public: 
    // Public methods
    RSA(int p, int q);
    int getFirstPrime() const;
    int getSecondPrime() const;
    int getPublicKey() const;
    int getPrivateKey() const;
};

#endif