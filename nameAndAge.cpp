#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  string _name, _age;
  vector<string>name;
  int maxAge = -1,sum=0,idx_max, n = 0,minAge = 101, idx_min;

  while(true){
    cout<<"Input["<<n+1<<"]: \n";
    cin>>_name>>_age;

    if(_name == "END" && _age == "-1") break;

    bool validAge = true;
    bool validName = true;
    for(int i = 0; i < _age.length(); i++){
      if(!isdigit(_age[i])){
        validAge = false;
        break;
      }
    }
    
    int tempAge = stoi(_age);
    if(tempAge < 1 || tempAge > 100){
      validAge = false;
    }

    for(int i = 0; i < _name.length(); i++){
      if(!isalpha(_name[i])){
        validName = false;
        break;
      }
    }

    if(!validName || !validAge){
      cout<<"Invalid input!\n";
      continue;
    }

    name.push_back(_name);
    sum+=tempAge;

    if(maxAge<tempAge){
      maxAge = tempAge;
      idx_max = n;
    }
    if(minAge > tempAge){
      minAge = tempAge;
      idx_min = n;
    }
    n++;
  }

  cout<<"\n\n";
  cout<<"=== RESULT ===\n";
  cout<<"Average age: "<<static_cast<double>(sum)/n<<"\n";
  cout<<"Youngest person: "<<name[idx_min]<<" "<<minAge<<"\n";
  cout<<"Oldest person: "<<name[idx_max]<<" "<<maxAge<<"\n";
  return 0;
}