#include "BitUtil.h"

int hamming_weight_1(unsigned int n) {
  int cnt;
  while (n) {
    n &= (n - 1);
    cnt++;
  }
  return cnt;
}

int hamming_weight_2(unsigned int n) {

    unsigned long long int table = 0x4332322132212110;
    // Table of hamming weights of 4-bit numbers (16 entries, 4 bits per entry)
    //        Number  Hamming weight
    //        0       0
    //        1       1
    //        10      1
    //        11      2
    //        100     1
    //        101     2
    //        110     2
    //        111     3
    //        1000    1
    //        1001    2
    //        1010    2
    //        1011    3
    //        1100    2
    //        1101    3
    //        1110    3
    //        1111    4
    return
      ((table >> (4*((n >> 28) & 0xf))) & 0xf) +
      ((table >> (4*((n >> 24) & 0xf))) & 0xf) +
      ((table >> (4*((n >> 20) & 0xf))) & 0xf) +
      ((table >> (4*((n >> 16) & 0xf))) & 0xf) +
      ((table >> (4*((n >> 12) & 0xf))) & 0xf) +
      ((table >> (4*((n >>  8) & 0xf))) & 0xf) +
      ((table >> (4*((n >>  4) & 0xf))) & 0xf) +
      ((table >> (4*((n      ) & 0xf))) & 0xf);
}

int reverse_integer(int n)
{
  long long int result = 0;
  while (n) {
    result = 10 * result + n % 10;
    n = n / 10;
  }
  return result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min() ? 0 : result;
}

unsigned int reverse_bits_1(unsigned int n)
{
  int i = 0, j = 31;
  while (i < j) {
    if (((n >> i) & 1) != ((n >> j) & 1)) {
      n ^= ((1 << i) | (1 << j));
    }
    i++, j--;
  }
  return n;
}

unsigned int reverse_bits_2(unsigned int n)
{
  unordered_map<unsigned short, unsigned short> sixteen_bit_reverse_table;
  // Use do while with extra step to avoid overflow in unsigned short
  unsigned short i = 0;
  do {
    sixteen_bit_reverse_table[i] = reverse_bits_1(i);
    i++;
  } while (i != 65535);
  sixteen_bit_reverse_table[i] = reverse_bits_1(i);

  return
    (sixteen_bit_reverse_table[(n >> 16)         ]      ) |
    (sixteen_bit_reverse_table[(n      ) & 0xffff] << 16) ;
}

bool palindromic_integer_1(int n)
{
  return reverse_integer(n) == n;
}

bool palindromic_integer_2(int x)
{
  if (x < 0) return false;

  int num_digits = static_cast<int>(floor(log10(x)) + 1);
  int msb_shift = static_cast<int>(pow(10, num_digits - 1));
  int temp_x = x;
  for (int i = 0; i < num_digits / 2; ++i) {
    if (x / msb_shift != temp_x % 10) {
      return false;
    }
    x %= msb_shift; // eliminate most significant digit
    msb_shift /= 10;
    temp_x /= 10; // eliminate least significant digit
  }
  return true;
}

bool palindromic_integer_3(int x)
{
  if (x < 0) { return false; }
  int num_digit = static_cast<int>(floor(log10(x)) + 1);
  int msb_shift = static_cast<int>(pow(10, num_digit - 1));
  while (x) {
    if (x / msb_shift != x % 10) { return false; }
    x %= msb_shift, x /= 10;
    msb_shift /= 100;
  }

  return true;
}

int bitwise_and_range(int m, int n)
{
  unsigned int x = m ^ n;
  x |= x >> 1, x |= x >> 2, x |= x >> 4, x |= x >> 8, x |= x >> 16;
  return m & ~x;
}

bool power_of_two(int n) {
  return n > 0 && !(n & (n - 1));
}
