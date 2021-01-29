#include <iostream>
#include <string>
bool checkReal(std:: string number){
    int point=0;
    if ((number[0]<'0' || number[0]>'9' )
        && (number[0]!='-' && number[0]!='.')){
        return false;
    }
    for (int i=1; i<number.length();i++){
        if ((number[i]<'0' || number[i]>'9' ) && number[i]!='.'){
            return false;
        }
        if (number[0]!='.' && number[i]=='.'){
            point+=1;
        }
        if (point>1 || ((number[i]<'0' || number[i]>'9' )
                        && (number[i]!='.'))){
            return false;
        }
    }
    return true;
}

float convert(std::string number){
    float n=std::stof(number);
    return n;
}
int main() {
    std::cout<<"Comparision number\n\n";
    std::cout << "Input number1 and number2:\n";
    std::string number1;
    std::string number2;
    std::string compare;
    std::cin>>number1;
    std::cin>>number2;
    if (checkReal(number1) && checkReal(number2)){
        if (convert(number1) > convert(number2)){
            compare="more";
        }
        if (convert(number1) < convert(number2)){
            compare="less";
        }
        if (convert(number1) == convert(number2)){
            compare="equal";
        }
        std::cout<<compare;
    }
    else{
        std::cout<<"Incorrect";
    }
}
