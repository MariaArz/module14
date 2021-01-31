#include <iostream>
std::string encryptCaesar(std::string string,int a){
    int b;
    for (int i=0; i < string.length(); i++){
        if (string[i]!=' ' && string[i]!=',' && string[i]!='.'){
            b=(int)string[i];
            b+=a;
            if ((string[i] >'a' && b > (int)'z')
                || (string[i] <'a' && b > (int)'Z')){
                b-=26;
            }
            string[i]=(char)b;
        }
    }
    return string;
}
std::string decryptCaesar(std::string string,int a){
    a=26-a;
    string=encryptCaesar(string,a);
    return string;
}
int main() {
    std::string string,over;
    int a,b;
    std::cout<<"input massage\n";
    std::getline(std::cin,string);
    std::cout<<"\ninput number\n";
    std::cin>>a;
    string=encryptCaesar(string,a);
    std::cout<<string;
    std::cout<<"\ninput massage\n";
    std::getline(std::cin,over);
    std::cout<<"\ninput number\n";
    std::cin>>b;
    over=decryptCaesar(over,b);
    std::cout<<over;
    return 0;
}
