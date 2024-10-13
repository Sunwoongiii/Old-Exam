// #include <cstdlib>
// #include <vector>
// #include <ctime>
// #include <iostream>
// #include <string>
// using namespace std;

// class BaseBall{
// private:
//   int answer[3];
//   int strike,ball,out,outCount;
// public:
//   BaseBall(int s, int b, int o, int oc): strike(s), ball(b), out(o), outCount(oc) {}
  
//   void getAnswer(vector<int>ans){
//     for(int i = 0; i < 3; i++) answer[i] = ans[i];
//   }

//   void getStrike(int s){
//     strike = s;
//   }

//   void getBall(int b){
//     ball = b;
//   }

//   void getOut(int o){
//     out = o;
//     if(o == 3) outCount++;
//   }

//   void showResult(vector<int>userInput){
//     if(strike == 3){
//       cout<<userInput[0]<<userInput[1]<<userInput[2]<<": "<<strike<<"S";
//       cout<<"You Win!\n";
//       return;
//     }

//     else if(out == 3)cout<<"Out!\n";

//     else if(outCount == 3){
//       cout<<"You Lose! The number is "<<answer[0]<<answer[1]<<answer[2]<<".\n";
//       return;
//     }
//     else{
//       if(strike != 0){
//         cout<<userInput[0]<<userInput[1]<<userInput[2]<<": "<<strike<<"S ";
//       }
//       if(ball != 0){
//         cout<<ball<<"B ";
//       }
//       if(out != 0) cout<<out<<"O ";
//       cout<<"\n";
//     }
//   }
// };

// BaseBall game(0,0,0,0);

// vector<int> getThreeNumber(){
//   vector<int>ans(3);
//   std::srand(static_cast<unsigned int>(time(0)));

//   while(true){
//     int a1 = std::rand()%10;
//     int a2 = std::rand()%10;
//     int a3 = std::rand()%10;

//     if(a1 != a2 && a2 != a3 && a3 != a1){
//       ans[0] = a1;
//       ans[1] = a2;
//       ans[2] = a3;
//       break;
//     }
//   }
//   return ans;
// }

// vector<int> getInputFromUser(){
//   string input;
//   vector<int>userInput(3);

//   while(true){
//     bool validInput = true;
//     cout<<"Input 3-digit numbers\n";
//     cin>>input;

//     if(input.length() != 3)validInput = false;
//     else{
//       for(int i = 0; i < 3; i++){
//         if(!isdigit(input[i])){
//           validInput = false;
//           break;
//         }
//       }

//       for(int i = 0 && validInput; i < 2; i++){
//         for(int j = i+1; j < 3; j++){
//           if(input[i] == input[j]){
//             validInput = false;
//             break;
//           }
//         }
//       }
//     }

//     if(!validInput){
//       cout<<input<<" is an invalid input. Try again.\n";
//       continue;
//     }
//     else break;
//   }
//   userInput[0] = input[0] -'0';
//   userInput[1] = input[1]-'0';
//   userInput[2] = input[2]-'0';

//   return userInput;
// }

// void checkNumber(vector<int>userInput){
//   vector<int>answer = getThreeNumber();

//   int strike = 0, ball = 0, out = 0;

//   if(answer[0] == userInput[0])strike++;
//   if(answer[1] == userInput[1])strike++;
//   if(answer[2] == userInput[2])strike++;
  
//   for(int i = 0; i < 2; i++){
//     for(int j = i+1; j < 3; j++){
//       if(answer[i] == userInput[j])ball++;
//     }
//   }
//   out = 3-(strike+ball);

//   game.getStrike(strike);
//   game.getBall(ball);
//   game.getOut(out);
// }

// int main(){
//   cout<<"Baseball game starts!\n";
//   int trials = 0;

//   game.getAnswer(getThreeNumber());
//   while(true){
//     vector<int> userInput = getInputFromUser();
//     checkNumber(userInput);
//     game.showResult(userInput);
//     trials++;

//     if(trials == 5)break;
//   }
//   return 0;
// }
#include <cstdlib>
#include <vector>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

class BaseBall {
private:
  int answer[3];
  int strike, ball, out, outCount;
public:
  BaseBall(int s, int b, int o, int oc) : strike(s), ball(b), out(o), outCount(oc) {}

  void getAnswer(vector<int> ans) {
    for (int i = 0; i < 3; i++) answer[i] = ans[i];
  }

  vector<int> provideAnswer() {
    vector<int> ans(3);
    for (int i = 0; i < 3; i++) ans[i] = answer[i];
    return ans;
  }

  void getStrike(int s) {
    strike = s;
  }

  void getBall(int b) {
    ball = b;
  }

  void getOut(int o) {
    out = o;
    if (o == 3) outCount++;
  }

  int getStrikeCount() const { // Getter for strike
    return strike;
  }

  int getOutCount() const { // Getter for outCount
    return outCount;
  }

  void showResult(vector<int> userInput) {
    if (strike == 3) {
      cout << userInput[0] << userInput[1] << userInput[2] << ": " << strike << "S";
      cout << " You Win!\n";
      return;
    }

    else if (out == 3) cout << "Out!\n";

    else if (outCount == 3) {
      cout << "You Lose! The number is " << answer[0] << answer[1] << answer[2] << ".\n";
      return;
    } else {
      if (strike != 0) {
        cout << userInput[0] << userInput[1] << userInput[2] << ": " << strike << "S ";
      }
      if (ball != 0) {
        cout << ball << "B ";
      }
      if (out != 0) cout << out << "O ";
      cout << "\n";
    }
  }
};

BaseBall game(0, 0, 0, 0);

vector<int> getThreeNumber() {
  vector<int> ans(3);
  std::srand(static_cast<unsigned int>(time(0)));

  while (true) {
    int a1 = std::rand() % 10;
    int a2 = std::rand() % 10;
    int a3 = std::rand() % 10;

    if (a1 != a2 && a2 != a3 && a3 != a1) {
      ans[0] = a1;
      ans[1] = a2;
      ans[2] = a3;
      break;
    }
  }
  return ans;
}

vector<int> getInputFromUser() {
  string input;
  vector<int> userInput(3);

  while (true) {
    bool validInput = true;
    cout << "Input 3-digit numbers\n";
    cin >> input;

    if (input.length() != 3) validInput = false;
    else {
      for (int i = 0; i < 3; i++) {
        if (!isdigit(input[i])) {
          validInput = false;
          break;
        }
      }

      for (int i = 0; i < 2 && validInput; i++) {
        for (int j = i + 1; j < 3; j++) {
          if (input[i] == input[j]) {
            validInput = false;
            break;
          }
        }
      }
    }

    if (!validInput) {
      cout << input << " is an invalid input. Try again.\n";
      continue;
    } else break;
  }

  userInput[0] = input[0] - '0';
  userInput[1] = input[1] - '0';
  userInput[2] = input[2] - '0';

  return userInput;
}

void checkNumber(vector<int> userInput) {
  vector<int> answer = game.provideAnswer();  // private answer 배열 접근 대신 getter 사용
  int strike = 0, ball = 0, out = 0;

  for (int i = 0; i < 3; i++) {
    if (answer[i] == userInput[i]) {
      strike++;
    } else if (answer[i] == userInput[(i + 1) % 3] || answer[i] == userInput[(i + 2) % 3]) {
      ball++;
    }
  }

  out = 3 - (strike + ball);

  game.getStrike(strike);
  game.getBall(ball);
  game.getOut(out);
}

int main() {
  cout << "Baseball game starts!\n";
  int trials = 0;

  game.getAnswer(getThreeNumber());  // 한 번만 답 설정
  while (trials < 5) {
    vector<int> userInput = getInputFromUser();
    checkNumber(userInput);
    game.showResult(userInput);
    trials++;

    if (game.getStrikeCount() == 3 || game.getOutCount() == 3) {  // getter 함수로 변경
      break;
    }
  }
  return 0;
}
