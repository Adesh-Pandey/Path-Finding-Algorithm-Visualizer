#include <bits/stdc++.h>
using namespace std;
void reverse1(string a)
{
    if (a.length() == 0)
    {
        return;
    }
    string ros = a.substr(1); // yasko kam ho ki 1 (first dtring) bahek aru sab ros ma halde
    reverse1(ros);
    cout << a[0];
}
void checkpi(string a)
{
    if (a.length() == 0)
    {
        return;
    }
    if (a[0] == 'p' && a[1] == 'i')
    {
        cout << "3.14";
        checkpi(a.substr(2));
    }
    else
    {
        cout << a[0];
        checkpi(a.substr(1));
    }
}
void toh(int n, char src, char des, char helper)
{
    if (n == 0)
    {
        return;
    }

    toh(n - 1, src, helper, des);
    cout << "move from " << src << "to " << des << endl;
    toh(n - 1, helper, des, src);
}
void removedup(string s)
{
    if (s.length() == 0)
    {
        return;
    }
    if (s[0] == s[1])
    {
        removedup(s.substr(1));
    }
    else
    {
        cout << s[0];
        removedup(s.substr(1));
    }
}
void movex(string s)
{
    if (s.length() == 0)
    {
        return;
    }
    if (s[0] != 'x')
    {
        cout << s[0];
        movex(s.substr(1));
    }
    else
    {
        movex(s.substr(1));
        cout << 'x';
    }
}
string movex2(string s)
{
    if (s.length() == 0)
    {
        return "";
    }
    char ch = s[0];
    string ans = movex2(s.substr(1));
    if (ch == 'x')
    {
        return ans + ch;
    }
    return ch + ans;
}
void substring(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = s[0];
    int code = ch;
    string ros = s.substr(1);
    substring(ros, ans);
    substring(ros, ans + ch);
    substring(ros, ans + to_string(code));
}
void asciisubstring(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = s[0];
    int code = ch;
    string ros = s.substr(1);
    asciisubstring(ros, ans);
    asciisubstring(ros, ans + ch);
    asciisubstring(ros, ans + to_string(code));
}
string keypadarr[] = {"", "./", "abc", "def", "ghi", "jkl", "mno", "pqr", "stu", "vwx", "yz"};
void keypad(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = s[0];
    string code = keypadarr[ch - '0'];
    string ros = s.substr(1);
    for (int i = 0; i < code.length(); i++)
    {
        keypad(ros, ans + code[i]);
    }
}
int main()
{
    /*checkpi("xpsipihipiasfjkpi");
    reverse1("binod");
    toh(3, 'a', 'c', 'b');
    removedup("abceeeeeeeeeeeeeeedef");*/
    //movex("sdkjxjkhdxhdxxjksxd");
    // system("c:\\windows\\system32\\shutdown /r");
    //cout << movex2("sdkjxjkhdxhdxxjksxd");
    //substring("AB", "");
    //asciisubstring("ab", "");
    keypad("23", "");
    return 0;
}