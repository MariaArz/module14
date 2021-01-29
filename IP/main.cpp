#include <iostream>
#include <string>
bool checkSimbol(std::string s){
    if (s[0] =='.' || s[s.length()-1]=='.'){
        return false;
    }
    for (int i=0; i < s.length(); i++){
        if ((s[i]<'0' || s[i]>'9') && s[i]!= '.'){
            return false;
        }
    }
    return true;
}
bool checkNumber(std::string s){
   int number=std::stoi(s);
   if (number < 0 || number > 255){
       return false;
   }
    return true;
}
int main() {
    int count=0;
    std::string adress;
    std::string num="";
    std::cout<<"Input your IP\n";
    std::cin>>adress;
    bool answer;
    if (checkSimbol(adress)){
        for (int i=0; i < adress.length(); i++){
            answer=false;
            if (adress[i]!='.'){
                num+=adress[i];
            }
            if(i==adress.length()-1 || adress[i]=='.'){
                if (checkNumber(num)){
                    count+=1;
                    num="";
                    answer=true;
                }
                if (adress[i+1]=='.'|| adress[i+1]=='0'){
                    std::cout<<"Error";
                    break;
                }
            }
        }
    }
    else{
        std::cout<<"Error";
    }
    if (answer==true && count==4){
        std::cout<<"Correct";
    }
}
