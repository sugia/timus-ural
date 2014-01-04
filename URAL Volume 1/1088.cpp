//#include "stdafx.h"
#include <cstdio>
#include <cstring>
#include <iostream>
 
using namespace std;
int D, E, F, Dp, Ep, H;
int D_a[31], E_a[31];
int main(){
    cin >> D >> E >> F >> Dp >> Ep >> H;
    Dp --;
    Ep --;
 
    for (int i = 0; i <= F; ++i)
        if (i >= D && i >= E && ((Dp >> i) << i) == ((Ep >> i) << i) ){
            puts( i * 2 - D - E <= H ? "YES" : "NO" );
            return 0;
        }
    return 0;
}
