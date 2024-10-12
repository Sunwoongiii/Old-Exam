#include <iostream>
using namespace std;

class Gomoku {
private:
  string board[9][9] = {
    {". ", ". ", ". ", ". ", ". ", ". ", ". ", ". ", ". "},
    {". ", ". ", ". ", ". ", ". ", ". ", ". ", ". ", ". "},
    {". ", ". ", ". ", ". ", ". ", ". ", ". ", ". ", ". "},
    {". ", ". ", ". ", ". ", ". ", ". ", ". ", ". ", ". "},
    {". ", ". ", ". ", ". ", ". ", ". ", ". ", ". ", ". "},
    {". ", ". ", ". ", ". ", ". ", ". ", ". ", ". ", ". "},
    {". ", ". ", ". ", ". ", ". ", ". ", ". ", ". ", ". "},
    {". ", ". ", ". ", ". ", ". ", ". ", ". ", ". ", ". "},
    {". ", ". ", ". ", ". ", ". ", ". ", ". ", ". ", ". "}
  };
public:
  void p1Emplace(int x, int y){
    board[x][y] = "O ";
  }
  void p2Emplace(int x, int y){
    board[x][y] = "X ";
  }
  void showBoard(){
    for(int i = 0; i < 9; i++){
      for(int j = 0; j < 9; j++){
        cout<<board[i][j];
      }
      cout<<"\n";
    }
  }
  bool checkWinner(string ox);
  bool rowChecker(string ox);
  bool columnChecker(string ox);
  bool diagonalChecker(string ox);
};

Gomoku game;

bool isInside(int x, int y){
  return(x>=0&&y>=0&&x<9&&y<9);
}

bool p1Emplace(){
  cout<<"\n";
  int x,y;

  while(true){
    cout<<"Input P1's move\n";
    cin>>x>>y;
    if(!isInside(x,y)){
      cout<<"Invalid move. Try again.\n";
      continue;
    }
    else{
      game.p1Emplace(x,y);
      game.showBoard();
      break;
    }
  }

  bool result = game.checkWinner("O ");
  if(result){
    cout<<"P1 wins!\n";
    return result;
  }
  return result;
}

bool p2Emplace(){
  cout<<"\n";
  int x,y;

  while(true){
    cout<<"Input P2's move\n";
    cin>>x>>y;
    if(!isInside(x,y)){
      cout<<"Invalid move. Try again.\n";
      continue;
    }
    else{
      game.p2Emplace(x,y);
      game.showBoard();
      break;
    }
  }

  bool result = game.checkWinner("X ");
  if(result){
    cout<<"P2 wins!\n";
    return result;
  }
  return result;
}

int main(){
  cout<<"Gomoku starts!\n";
  game.showBoard();

  while(true){
    if(p1Emplace()) return 0;
    else if(p2Emplace()) return 0;
  }
}

bool Gomoku::checkWinner(string ox){
  return(rowChecker(ox) || columnChecker(ox) || diagonalChecker(ox));
}

bool Gomoku::columnChecker(string ox){//열 체크
  for(int i = 0; i <= 4; i++){
    for(int j  = 0; j < 9;j++){
      int cnt = 0;
      for(int k = 0; k < 5; k++){
        if(board[i+k][j] == ox) cnt++;
        else break;
      }
      if(cnt == 5) return true;
    }
  }
  return false;
}

bool Gomoku::rowChecker(string ox){
  for(int i = 0; i < 9; i++){
    for(int j = 0; j <= 4; j++){
      int cnt = 0;
      for(int k = 0; k < 5; k++){
        if(board[i][k+j] == ox) cnt++;
        else break;
      }
      if(cnt == 5) return true;
    }
  }
  return false;
}

bool Gomoku::diagonalChecker(string ox){
  for(int i = 0; i <= 4; i++){
    for(int j = 0; j <= 4; j++){
      int cnt = 0;
      for(int k = 0; k < 5; k++){
        if(board[i+k][j+k] == ox)cnt++;
        else break;
      }
      if(cnt == 5) return true;
    }
  }
  for(int i = 0; i <= 4; i++){
    for(int j = 4; j < 9; j++){
      int cnt = 0;
      for(int k = 0; k < 5; k++){
        if(board[i+k][j-k] == ox)cnt++;
        else break;
      }
      if(cnt == 5) return true;
    }
  }
  return false;
}