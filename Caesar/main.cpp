#include <iostream>
std::string encryptCaesar(const std::string str,int a){
    std::string string=str;
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
std::string decryptCaesar(const std::string str,int b){
    return encryptCaesar(str,26-b);
}
int main() {
    std::string string;
    int a;
    std::cout<<"input massage\n";
    std::getline(std::cin,string);
    std::cout<<"\ninput number\n";
    std::cin>>a;
    std::cout<<encryptCaesar(string,a)<<"\n\n";
    std::cout<<decryptCaesar(encryptCaesar(string,a),a);
    return 0;
}
