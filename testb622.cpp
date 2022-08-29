<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
int i,j,k,n,m,f[10010],p1,p2,p3;
int find(int k){
    if(f[k]==k) return k;
    return f[k]=find(f[k]);
}
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=m;i++){
        cin>>p1>>p2>>p3;
        if(p1==1){
            f[find(p2)]=find(p3);
        }
        if(p1==2)
            if(find(p2)==find(p3))
                printf("Y\n");
            else
                printf("N\n");
    }
    return 0;
=======
#include <bits/stdc++.h>
using namespace std;
int i,j,k,n,m,f[10010],p1,p2,p3;
int find(int k){
    if(f[k]==k) return k;
    return f[k]=find(f[k]);
}
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=m;i++){
        cin>>p1>>p2>>p3;
        if(p1==1){
            f[find(p2)]=find(p3);
        }
        if(p1==2)
            if(find(p2)==find(p3))
                printf("Y\n");
            else
                printf("N\n");
    }
    return 0;
>>>>>>> b94a7582cb8f34520937eb18c02a6205232bbc12
}