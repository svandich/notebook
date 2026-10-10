#include "../../template.h"
/* -
name = "Iterative Segment Tree - JOliva"
[info]
description = "Iterative segment tree, with point update and range queries."
time = "$O(log n)$"
- */
template<class T, T op(T, T)> struct SegmentTree{
  int n; vec<T> ST;
  SegmentTree(){}
  SegmentTree(vec<T> &a){
    n = a.size(); ST.resize(n << 1);
    for (int i=n;i<(n<<1);i++)ST[i]=a[i-n];
    for (int i=n-1;i>0;i--)ST[i]=op(ST[i<<1],ST[i<<1|1]);
  }
  void upd(int pos, T val){ // replace with val
    ST[pos += n] = val;
    for (pos >>= 1; pos > 0; pos >>= 1)
      ST[pos] = op(ST[pos<<1], ST[pos<<1|1]);
  }
  T query(int l, int r){ // [l, r]
    T aL, aR; bool hL = 0, hR = 0; // ansL, ansR, hasL, hasR
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) 
        aL=(hL?op(aL,ST[l++]):ST[l++]),hL=1;
      if (r & 1) 
        aR=(hR?op(ST[--r],aR):ST[--r]),hR=1;
    }
    if (!hL) return aR; if (!hR) return aL;
    return op(aL, aR);
  }
}; // Give vec of leaves and merge function

template<class T>
T merge(T a, T b){
  return a;
}  
