#include <stdio.h>
#include <stdlib.h>

struct Zero {};

template <typename N>
struct Succ{};

template <typename N, typename M>
struct Add{};

/* Create new template specializations of
   Add here
   so that this code compiles and works.
*/

template <typename T>
struct Lit{};

template <typename M>
struct Eval {};

template <typename T>
struct Eval<Lit<T>>
{
  T typedef result;
};

template <>
struct Eval<Zero>
{
  enum { value = 0 };
};

template <typename N>
struct Eval<Succ<N>>
{
  enum { value = Eval<N>::value + 1};
};

template <typename N, typename M>
struct Eval<Add<N, M>>
{
  enum { value = Eval<N>::value + Eval<M>::value};
};

int main() {
  /* This should print `2 + 3 = 5`: */
  printf("2 + 3 = %i\n",
         Eval<Add<Succ<Succ<Zero>>,
         Succ<Succ<Succ<Zero>>>>> :: value );

  return EXIT_SUCCESS;
}
