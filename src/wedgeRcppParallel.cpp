#include <Rcpp.h>
#include <math.h>
// [[Rcpp::depends(RcppParallel)]]
#include <RcppParallel.h>
// [[Rcpp::depends(wedge)]]
#include <wedgeC.h>

using namespace Rcpp;
using namespace RcppParallel;

struct Wedge : public Worker { //------------------------ functor
 const RVector<double> a1,b1,a2,b2; //------------------- source
 RVector<double> wp;   //-------------------------------- target
 double tau;
 int N;
 bool lower_tail;
 Wedge(const NumericVector a1,const NumericVector b1,const NumericVector a2,const NumericVector b2,
    NumericVector wp, double tau, int N, bool lower_tail) : a1(a1),b1(b1),a2(a2),b2(b2), wp(wp), tau(tau), N(N), lower_tail(lower_tail) {} // constructeur du foncteur
 // operation on the chunk [beg,end]
 void operator()(std::size_t beg, std::size_t end) {
  for (size_t i=beg; i<end; i++) wp[i] = wedgeC(a1[i],b1[i],a2[i],b2[i],tau,N,lower_tail) ;
 }
};

// [[Rcpp::export]]
NumericVector wedgeRcppParallel(NumericVector a1, NumericVector b1, NumericVector a2, NumericVector b2, int size_vect, double tau, int N, bool lower_tail) {
  NumericVector wp(size_vect);
  Wedge functor(a1,b1,a2,b2,wp,tau,N,lower_tail);
  parallelFor(0, size_vect, functor);
  return(wp) ;
}
