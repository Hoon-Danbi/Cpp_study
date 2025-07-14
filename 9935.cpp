#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str, bomb;
    cin >> str >> bomb;
    int bombLen = bomb.length();

    
    string result = str.substr(0, bombLen - 1); // 폭탄 전 글자까지만 미리 넣기

    for (int i = bombLen - 1; i < str.length(); i++) {
        result += str[i]; 
        if (result.size() >= bombLen && result.substr(result.size() - bombLen, bombLen) == bomb) {
            result.erase(result.size() - bombLen, bombLen);
        }
    }

    if (result.empty()) cout << "FRULA\n";
    else cout << result << '\n';
}
