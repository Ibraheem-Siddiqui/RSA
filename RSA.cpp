#include "RSA.h"
#include <iostream>

std::pair<int,int> RSA::EEA(int a, int b)
{
    int x_0, y_0, q {};
    int x_1 = 0;
    int x_2 = 1;
    int y_1 = 1;
    int y_2 = 0;
    int r_0 = 1;
    int r_1 = b;
    int r_2 = a;

    while(r_0 != 0)
    {
        q = r_2/r_1;

        x_0 = x_2 - q * x_1;
        y_0 = y_2 - q * y_1;
        r_0 = r_2 - q * r_1;

        x_2 = x_1;
        x_1 = x_0;

        y_2 = y_1;
        y_1 = y_0;

        r_2 = r_1;
        r_1 = r_0;
    }

    return {x_2, y_2};
}

int RSA::gcd(int a, int b)
{
    if(b == 0) return a;

    return RSA::gcd(b, a - (a/b)*b);
}

int RSA::generate_public_key(int p, int q)
{
    int e{};

    for(int i = 2; i < (p-1)*(q-1); ++i)
    {
        if (RSA::gcd(i, (p-1)*(q-1)) == 1)
        {
            e = i;
            break;
        }
    }

    return e;
}

int RSA::generate_private_key(int e, int p, int q)
{
    int d = RSA::EEA(e, (p-1)*(q-1)).first;
    while(!((d>=0) && (d<(p-1)*(q-1))))
    {
        d+=((p-1)*(q-1));
    }
    return d;
}

RSA::RSA(int p1, int p2)
{
    p = p1;
    q = p2;
    public_key = RSA::generate_public_key(p, q);
    private_key = RSA::generate_private_key(public_key, p, q);
}

int RSA::getFirstPrime() const { return p; }
int RSA::getSecondPrime() const { return q; }
int RSA::getPublicKey() const { return public_key; }
int RSA::getPrivateKey() const { return private_key; }