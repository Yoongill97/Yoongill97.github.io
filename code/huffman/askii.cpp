#include <iostream>
using namespace std;

int main(){
    string str;
    int result;

    cout << "문자열 입력 : ";
    getline(cin, str, '#');

    cout << "\n아스키 변환 정보 : ";

    for(int i=0; i<str.length(); i++) {
        for(int j=7; j>=0; --j){
            result = str[i] >> j & 1;
            cout << result;
        }
    }
}