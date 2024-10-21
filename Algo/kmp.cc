#include <iostream>
#include <string.h>

using std::cout;
using std::cin;
using std::endl;

const int MAXN = 1000002;

char str[MAXN];
char sub[MAXN];
int n,ns;

int next[MAXN];

void getnext(){
  next[0] = 0;
  for(int i = 1;i < ns; i++){
    if(sub[i] == sub[next[i-1]]) next[i] = next[i-1]+1;
    else if(next[i-1] == 0) continue;
    else if(sub[next[next[i-1]-1]] == sub[i]){
      next[i] = next[next[i-1]-1] + 1;
    }
    else if(sub[0] == sub[i]) next[i] = 1;
  }
}

void kmp(){
  int cur = 0;
  for(int i = 0 ; i < n ; i++){
    if(str[i] == sub[cur]){
      cur ++;
      if(cur == ns){
        cout << i-ns+2 << endl;
        cur = next[cur-1];
      }
    }
    else if(cur != 0){
      cur = next[cur-1];
      i--;
    }
  }
  return;
}


int main(){

  cin >> str;
  n = strlen(str);
  cin >> sub;
  ns = strlen(sub);

  getnext();
  kmp();
  for(int i = 0 ; i < ns; i++)
    cout << next[i] << ' ';
  cout << endl;
  


  return 0;
}
