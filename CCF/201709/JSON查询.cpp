#include <bits/stdc++.h>
using namespace std;
int n, m, state = 0;
map<string, string> str;
string s, key;
void f()
{
    int j;
    for (j = key.size() - 1; j >= 0; --j)
    {
        if (key[j] == '.')
            break;
    }
    if (j >= 0)
        key = key.substr(0, j);
    else
        key = "";
}//读取一个'}'，回退到上一层对象中

int main()
{
    cin >> n >> m;
    cin.ignore();//忽略掉读取第一行后面的'\n'
    while (n--)
    {
        getline(cin, s);
        int len = s.size();
        for (int i = 0; i < len; ++i)
        {
            if (s[i] == '{')//遇到对象
            {
                if (state == 0)//第一层对象
                    key = "";
                else
                    str[key] = "OBJECT";
                state = 1;//下一个处理字符串为键key
            }
            else if (s[i] == '}')
                f();
            else if (s[i] == ':')
                state = 2;//下一个处理字符串为键值value
            else if (s[i] == ',')
                state = 1;//读取下一行，并下一个处理字符串为键值key
            else if (s[i] == '"')//字符串处理开始
            {
                string temp;
                for (i++; i < len; ++i)
                {
                    if (s[i] == '\\')//去掉字符串的转义字符
                        temp += s[++i];
                    else if (s[i] == '"')//字符串处理结束
                        break;
                    else
                        temp += s[i];
                }
                if (state == 1)
                {
                    if (key == "")
                        key = temp;
                    else
                        key += '.' + temp;
                    state = 2;//下一个处理字符串为键值value
                }
                else if (state == 2)
                {
                    str[key] = "STRING " + temp;
                    f();//处理完要回退到上一层对象
                    state = 1;
                }
            }
        }
    }
    while (m--)
    {
        cin >> s;
        key = str[s];
        cout << (key == "" ? "NOTEXIST" : key) << endl;
    }
}
