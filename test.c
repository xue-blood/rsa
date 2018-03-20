#include <stdio.h>
#include "rsa.h"
#include <string.h>
#include <stdlib.h>


char *PRIME_SOURCE_FILE = "primes.txt";

int main(int argc, char **argv)
{
  struct public_key_class pub[1] = {1985220949, 65537};
  struct private_key_class priv[1] = {1985220949, 1108470373};
  //rsa_gen_keys(pub, priv, PRIME_SOURCE_FILE);

  printf("Private Key:\n Modulus: %lld\n Exponent: %lld\n", (long long)priv->modulus, (long long)priv->exponent);
  printf("Public Key:\n Modulus: %lld\n Exponent: %lld\n", (long long)pub->modulus, (long long)pub->exponent);

  char message[] = "123abc";
  int i;

  printf("Original:\n");
  for (i = 0; i < strlen(message); i++)
  {
    printf("%lld\n", (long long)message[i]);
  }

  long long encrypted[6] = {0};
  if (!rsa_encrypt(message, 6, encrypted,6 * sizeof(long long), pub))
  {
    fprintf(stderr, "Error in encryption!\n");
    return 1;
  }
  printf("Encrypted:\n");
  for (i = 0; i < strlen(message); i++)
  {
    printf("%lld\n", (long long)encrypted[i]);
  }

  char decrypted[7] = {0};
  if (!rsa_decrypt(decrypted, 6, encrypted, 6 * sizeof(long long), priv))
  {
    fprintf(stderr, "Error in decryption!\n");
    return 1;
  }
  printf("Decrypted:\n");
  for (i = 0; i < strlen(decrypted); i++)
  {
    printf("%lld\n", (long long)decrypted[i]);
  }

  printf("\n");
  return 0;
}
