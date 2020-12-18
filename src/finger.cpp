#include <math.h>
#include <gmp.h>
#include <string.h>
#include <iostream>

#include <chord/finger.hpp>
#include <chord/node.hpp>

void finger_id(uint8_t *n, int i, uint8_t *result)
{
    mpz_t res;  // (n + 2^i) mod 2^m
    mpz_t a;    // 2^i
    mpz_t b;    // 2^m

    mpz_init(res);
    mpz_import(res, ID_LEN, 1, sizeof(n[0]), 0, 0, n);
    
    mpz_init_set_ui(a, 2);
    mpz_init_set_ui(b, 2);

    mpz_pow_ui(a, a, i);
    mpz_pow_ui(b, b, M);

    mpz_add(res, res, a); // res= n + 2^i 
    mpz_mod(res, res, b);   

    mpz_export(result, NULL, 1, sizeof(n[0]), 0, 0, res);   
}



