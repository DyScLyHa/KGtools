
#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector rcppcor(NumericVector vec, NumericMatrix mat) {
  int n_rows = mat.nrow();
  int n_cols = mat.ncol();
  NumericVector result(n_rows);
  
  for (int i = 0; i < n_rows; ++i) {
    NumericVector row = mat.row(i);
    double sum_x = 0.0;
    double sum_y = 0.0;
    double sum_xy = 0.0;
    double sum_x2 = 0.0;
    double sum_y2 = 0.0;
    
    for (int j = 0; j < n_cols; ++j) {
      double x = vec[j];
      double y = row[j];
      sum_x += x;
      sum_y += y;
      sum_xy += x * y;
      sum_x2 += x * x;
      sum_y2 += y * y;
    }
    
    double numerator = n_cols * sum_xy - sum_x * sum_y;
    double denominator = sqrt(n_cols * sum_x2 - sum_x * sum_x) *
      sqrt(n_cols * sum_y2 - sum_y * sum_y);
    result[i] = numerator / denominator;
  }
  
  return result;
}