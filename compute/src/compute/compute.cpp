#include "compute.hpp"
#include <tensor/ts.hpp>

int compute()
{
  ts::Matrix A = {
      {3, 1, 3},
      {1, 5, 9},
  };
  ts::Matrix B = {
      {3, 1},
      {1, 5},
      {2, 6}
  };
  ts::Matrix C = ts::dot(A, B);

  return 0;
}
