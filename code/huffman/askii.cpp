#include <iostream>
using namespace std;

int main(){
    string str;
    int result;

    cout << "���ڿ� �Է� : ";
    getline(cin, str, '#');

    cout << "\n�ƽ�Ű ��ȯ ���� : ";

    for(int i=0; i<str.length(); i++) {
        for(int j=7; j>=0; --j){
            result = str[i] >> j & 1;
            cout << result;
        }
    }
}