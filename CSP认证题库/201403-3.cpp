#include<bits/stdc++.h>
using namespace std;

int type[26]; // 0:������ 1:�޲���ѡ�� 2:�в���ѡ�� 
string argument[26];

int main() {
    string patten;
    cin >> patten;
    for(int i=0; i<patten.length(); i++) {
        int last_arg;
        if(patten[i] == ':') {
            type[last_arg] = 2;
        }
        else {
            last_arg = patten[i] - 'a';
            type[last_arg] = 1;
        }
    }

    int n;
    cin >> n;
    cin.ignore();
    for(int i=1; i<=n; i++) {
        string temp;
        getline(cin, temp);
        stringstream ss(temp);
        ss >> temp;
        while(ss >> temp) {
            if(temp[0] == '-') {
                int last_arg = temp[1] - 'a';
                if(type[last_arg] == 0) { // �ǺϷ�ѡ�� 
                    break;
                }
                else if(type[last_arg] == 1) {
                    argument[last_arg] = " ";
                }
                else if(type[last_arg] == 2) {
                    if(ss.eof()) break; // �в���ѡ��û��������� 
                    ss >> temp;
                    argument[last_arg] = temp;
                }
            }
            else { // �ǺϷ�����
                break;
            }
        }

        cout << "Case " << i << ":";
        for(int j=0; j<26; j++) {
            if(type[j] == 1 && argument[j] != "") {
                cout << " -" << char(j + 'a');
            }
            if(type[j] == 2 && argument[j] != "") {
                cout << " -" << char(j + 'a') << ' ' << argument[j];
            }
            argument[j] = "";
        }
        cout << endl;

    }

}
