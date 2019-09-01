#include <bits/stdc++.h>
using namespace std;
string str;

string em(string s)
{
    int j = 0, k;
    while (true)
    {
        j = s.find("_", j);
        if(j==string::npos)break;
        s = s.replace(j, 1, "<em>");
        k = s.find("_", j + 1);
        s = s.replace(k, 1, "</em>");
    }
    return s;
}

string a(string s)
{
    int j = 0, k, t;
    while (true)
    {
        j = s.find("[", j);
        if(j==string::npos)break;
        k = s.find("]", j + 1);
        string text = s.substr(j + 1, k - j - 1);
        t = s.find(")", k + 2);
        string link = s.substr(k + 2, t - k - 2);
        s = s.replace(j, t - j + 1, "<a href=\"" + link + "\">" + text + "</a>");
    }
    return s;
}


void h()
{
    int i = 0;
    while (str[i] == '#')
        i++;
    int j = i + 1;
    while (str[j] == ' ')
        j++;
    string head = str.substr(j);
    head = em(head);
    head = a(head);
    cout << "<h" << i << ">" + head + "</h"<< i<< ">\n";
}

void li()
{
    int i = 1;
    while (str[i] == ' ')
        i++;
    str = str.substr(i);
    str = em(str);
    str = a(str);
    cout << "<li>" + str << "</li>\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int flag = 0;
    while (getline(cin, str))
    {
        if (str.size() == 0)
        {
            if (flag == 1)
                cout << "</p>\n";
            else if (flag == 2)
                cout << "</ul>\n";
            flag = 0;
            continue;
        };
        if (str[0] == '#')
            h();
        else if (str[0] == '*')
        {
            if (flag == 0)
            {
                cout << "<ul>\n";
                flag = 2;
            }
            li();
        }
        else
        {
            if(flag==0){
                cout << "<p>";
                flag = 1;
            }else cout<<"\n";
            str = em(str);
            str = a(str);
            cout << str;
            
        }
    }
    if (flag == 1)
        cout << "</p>\n";
    else if (flag == 2)
        cout << "</ul>\n";
}
