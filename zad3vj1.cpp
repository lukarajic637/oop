#include <iostream>
#include <string>
#include <cctype>

int main(){
    std::string s;
    std::getline(std::cin,s);
    for (char &ch : s){
        if (isalpha(ch)){
            ch = toupper(ch);
        }
        else if (ch == ' ' || ch == '\t'){
            ch = '_';
        }
        else if (isdigit(ch)){
            ch = '*';
        }
    }
    std::cout << s << std::endl;
    return 0;
}

