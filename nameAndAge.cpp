#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  string _name, _age;
  vector<string>name;
  vector<int>age;
  int maxAge = -1,sum=0,idx_max, n = 0,minAge = 101, idx_min;

  while(true){
    cout<<"Input["<<n+1<<"]: \n";
    cin>>_name>>_age;

    if(_name == "END" && _age == "-1") break;

    bool validInput = true;
    for(int i = 0; i < _age.length(); i++){
      if(!isdigit(_age[i])){
        validInput = false;
        break;
      }
    }
    if(!validInput){
      cout<<"Invalid Input!\n";
      continue;
    }

    name.push_back(_name);
    int tempAge = stoi(_age);
    age.push_back(tempAge);
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