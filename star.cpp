#include <iostream>

using namespace std;


int main(){
    int x;
    cin>>x;
    
    for(int i =x-1;i>=0;i--){
        
      for(int j=0;j<i;j++){
          cout<<" ";
      }
      for(int k=i;k<x;k++)cout<<"#";
      cout<<"\n";
    }

    return 0;
}