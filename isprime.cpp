#include <bits/stdc++.h>
#include "mylib.h"

using namespace std;

bool is_prime(int _TARGET){
    for(int i = 1 ; i <= sqrt(_TARGET*1.00) ; i++){
        if(_TARGET % i == 0)
            return false;
    }
    return true;
}
//haihaihaihaihaihai