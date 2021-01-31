#include <iostream>
bool check (std::string s){
    for (int i=0; i < s.length(); i++){
        if (s.length() > 3
           ||(s[i]!='X' && s[i]!='O' && s[i]!='.')){
            return false;
        }
    }
    return true;
}
void gameEnter(std::string s, int number, char game[][4]){
    for (int i=number; i < 4; i++){
        for (int j=1; j < 4; j++){
            game[i][j]=s[j-1];
        }
    }
}
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
bool winX(char game[][4]){
    for (int i=1; i<4; i++){
        if ((game[i][1]!='.'&& game[i][1]==game[i][2] && game[i][1]==game[i][3] && game[i][1]=='X')
            || (game[1][i]!='.'&& game[1][i]==game[2][i] && game[1][i]==game[3][i] && game[1][i]=='X')
            || (game[1][1]!='.'&& game[1][1]==game[2][2] && game[1][1]==game[3][3] && game[1][1]=='X')
            || (game[3][1]!='.'&& game[3][1]==game[2][2] && game[3][1]==game[1][3] && game[3][1]=='X')){
            return true;
        }
    }
    return false;
}
bool winO(char game[][4]){
    for (int i=1; i<4; i++){
        if ((game[i][1]!='.'&& game[i][1]==game[i][2] && game[i][1]==game[i][3] && game[i][1]=='O')
            || (game[1][i]!='.'&& game[1][i]==game[2][i] && game[1][i]==game[3][i] && game[1][i]=='O')
            || (game[1][1]!='.'&& game[1][1]==game[2][2] && game[1][1]==game[3][3] && game[1][1]=='O')
            || (game[3][1]!='.'&& game[3][1]==game[2][2] && game[3][1]==game[1][3] && game[3][1]=='O')){
            return true;
        }
    }
    return false;
}


int main() {
    char game[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            game[i][j] = '.';
        }
    }
    std::string XO, first, second, third;
    for (int i = 1; i < 4; i++) {
        std::cout << "input strings";
        std::cin >> XO;
        if (!(check(XO))) {
            std::cout << "Incorrect\n";
            break;
        }
        gameEnter(XO, i, game);
    }
    gamePresent(game);
    if (winX(game)){
        std::cout << "Petya won";
    }
    else if (winO(game)) {
        std::cout << "Vanya won";
    }
    else {
        std::cout << "Nobody";
    }
}
