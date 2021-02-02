#include <iostream>
std::string encryptCaesar(std::string string,int a){
    int b;
    for (int i=0; i < string.length(); i++){
        if (string[i]!=' ' && string[i]!=',' && string[i]!='.'){
            b=(int)string[i];
            b+=a;
            if ((string[i] >'a' && b > (int)'z')
                || (string[i] >'A' && string[i] <'Z' && b > (int)'Z')){
                b-=26;
            }
            string[i]=(char)b;
        }
    }
    return string;
}
std::string decryptCaesar(std::string str,int b){
    b=26-b;
    str=encryptCaesar(str,b);
    return str;
}
int main() {
    std::string string;
    std::string over;
    int a;
    int n;
    std::cout<<"input massage\n";
    std::getline(std::cin,string);
    std::cout<<"\ninput number\n";
    std::cin>>a;
    string=encryptCaesar(string,a);
    std::cout<<string;
    std::cout<<"\ninput massage\n";
    std::getline(std::cin,over);
    std::cout<<"\ninput number\n";
    std::cin>>n;
    over=decryptCaesar(over,n);
    std::cout<<over;
    return 0;
}
