#include <bits/stdc++.h>

using namespace std;

int main(){
    string comp = "hello";
    string s;
    cin >> s;

    int tamanho = s.length();
    
    int j=0;
    for(int i=0; i< tamanho; i++){
        if(s[i]==comp[j]){
            j++;
        }
    }
    
    cout << (j == 5 ? "YES" : "NO") << endl;
  
    return 0;

}
