#include <iostream>
using namespace std;
void Hanoi(int n,char from,char to,char t){
    if(n<1){
        return; 
    } 
    Hanoi(n-1,from,t,to); 
    cout << from << " -> " << to << endl; 
    Hanoi(n-1,t,to,from); 
}
int main(){
    // 请在下一行补全代码
    int a;
    cin >> a;
    Hanoi(a,'A','C','B');
    return 0;
}