#include <iostream>
void gamePresent(char game[][4]){
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            if (i==0){
                std::cout<<j;
            }
            else if (j==0){
                std::cout<<i;
            }
            else {
                std::cout<<game[i][j];
            }
        }
        std::cout<<std::endl;
    }
}
bool win(char game[][4]){
    for (int i=1; i<4; i++){
        if ((game[i][1]!=' '&& game[i][1]==game[i][2] && game[i][1]==game[i][3])
            || (game[1][i]!=' '&& game[1][i]==game[2][i] && game[1][i]==game[3][i])) {
            return true;
        }
    }

    return false;
}


int main() {
   char game[4][4];
   for (int i=0; i<4; i++){
       for (int j=0; j<4; j++){
           game[i][j]=' ';
       }
   }
   int x,y;
   for (int i=0; i<9; i++){
       std::cout<<"input coordinate";
       std::cin>>x>>y;
       if ((x>4 || x<1) || (y>4 || y<1)
            || game[x][y]!=' '){
           std::cout<<"Error\n";
           i--;
           continue;

       }
       else{
           if (i%2==0){
               game[x][y]='X';
           }
           else{
               game[x][y]='O';
           }
       }
       gamePresent(game);
       if (win(game)){
           std::cout<<(game[x][y]=='X'?"X won":"O won");
           break;
       }
       else if (i==8 && !win(game)){
           std::cout<<"Draw";
       }
   }
}
