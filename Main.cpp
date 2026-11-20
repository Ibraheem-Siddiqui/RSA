#include "RSA.h"
#include <iostream>


int main() 
{   
    RSA rsa(19997, 12641);

    std::cout << "Public Key: (" << rsa.getPublicKey() << ", " << (rsa.getFirstPrime() * rsa.getSecondPrime()) <<  ")" << '\n';
    std::cout << "Private Key: (" << rsa.getPrivateKey() << ", " << (rsa.getFirstPrime() * rsa.getSecondPrime()) << ")" << '\n';

    return 0;
}