#include <iostream>
bool beforeA (std::string adress1){
    if (adress1.length()<=1 || adress1.length()>=64) {
        return false;
    }
        for (int i = 0; i < adress1.length(); i++) {
            if (adress1[i] != '!' && adress1[i] != '$'
                && adress1[i] != '#' && adress1[i] != '&'
                && adress1[i] != '%'
                && adress1[i] != '*' && adress1[i] != '+'
                && adress1[i] != '-' && adress1[i] != '/'
                && adress1[i] != '=' && adress1[i] != '?'
                && adress1[i] != '^' && adress1[i] != '_'
                && adress1[i] != '`' && adress1[i] != '{'
                && adress1[i] != '|' && adress1[i] != '}'
                && adress1[i] != '~'
                && (!(adress1[i] >= '0' && adress1[i] <= '9'))
                && (!(adress1[i] >= 'A' && adress1[i] <= 'Z'))
                && (!(adress1[i] >= 'a' && adress1[i] <= 'z'))
                && adress1[i] != '.') {
                return false;
            }
            if ((i != 0 && i != adress1.length() - 1)
                && adress1[i] == '.'
                && (adress1[i + 1] == '.' || adress1[i - 1] == '.')) {
                return false;
            }
        }
    return true;
}
bool afterA(std::string adress, int mid){
    if (adress.length()-mid-1<=1 || adress.length()-mid-1>=63) {
        return false;
    }
    for (int i=mid+1; i<adress.length(); i++){
        if (adress[i]=='@'
            || ((!(adress[i]>='0' && adress[i]<='9'))
                && (!(adress[i]>='A' && adress[i]<='Z'))
                && (!(adress[i]>='a' && adress[i]<='z'))
                && adress[i]!='.' && adress[i]!='-')) {
            return false;
        }
    }
    return true;
}
int main() {
    std::cout << "E-mail\n\n";
    std::string adress;
    std::string adress1="";
    std::cout<<"Input your e-mail\n";
    std::cin>>adress;
    bool answer= true;
    int mid;
    if (adress.length()>=3 && adress.length()<=128){
        for (int i=0; i<adress.length(); i++){
            if (adress[i]!='@'){
                answer=false;
                adress1+=adress[i];
            }
            if (adress[i]=='@'){
                answer=beforeA(adress1);
                mid=i;
                if (mid<adress.length()-1){
                    answer=afterA(adress,mid);
                    break;
                }
            }
        }
    }
    else {
        answer=false;
    }
    std::cout<<((answer)?"Yes":"No");
}
