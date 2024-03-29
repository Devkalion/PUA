#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <ctime>

using namespace std;

vector<wchar_t> alf;
map<wchar_t, int> dict;

int gcd(int a, int b)
{
    if(a < b)
        return gcd(b, a);
    while(b != 0)
    {
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

void code_caesar(int n, int k)
{
    while(!wcin.eof())
    {
        wstring s;
        getline(wcin, s);
        for(int i = 0; i < s.size(); i++)
            wcout << alf[(dict[s[i]] * n + k) % alf.size()];
        wcout << "\n";
    }
}

void decode_caesar(int n, int k)
{
    while(!wcin.eof())
    {
        wstring s;
        getline(wcin, s);
        for(int i = 0; i < s.size(); i++)
        {
            int B = dict[s[i]];
            int t = 1;
            while((B + t * alf.size() - k) % n != 0)
                t++;
            wcout << alf[(B + t * alf.size() - k) / n % alf.size()];
        }
        wcout << "\n";
    }
}

void make_alf_eng()
{
    for(wchar_t c = 'A'; c <= 'Z'; c++)
        alf.push_back(c);
    for(wchar_t c = 'a'; c <= 'z'; c++)
        alf.push_back(c);
    for(wchar_t c = '0'; c <= '9'; c++)
        alf.push_back(c);
    alf.push_back(',');
    alf.push_back('.');
    alf.push_back(' ');
    alf.push_back('!');
    alf.push_back('?');
    alf.push_back(';');
    alf.push_back(':');
    alf.push_back('\"');
    alf.push_back('\'');
    for(int i = 0; i < alf.size(); i++)
        dict[alf[i]] = i;
}

void make_alf_rus()
{
    setlocale(LC_ALL, "Rus");
    for(wchar_t c = L'а'; c <= L'я'; c++)
        alf.push_back(c);
    for(wchar_t c = L'А'; c <= L'Я'; c++)
        alf.push_back(c);
    for(wchar_t c = '0'; c <= '9'; c++)
        alf.push_back(c);
    alf.push_back(',');
    alf.push_back('.');
    alf.push_back(' ');
    alf.push_back('!');
    alf.push_back('?');
    alf.push_back(';');
    alf.push_back(':');
    alf.push_back('\"');
    alf.push_back('\'');
    for(int i = 0; i < alf.size(); i++)
        dict[alf[i]] = i;
}

int task1()
{
    int n, k;
    scanf("%d%d", &n, &k);
    printf("Enter the language (eng/rus):\n");
    string lang;
    cin >> lang;
    if(lang == "eng")
        make_alf_eng();
    else
        make_alf_rus();
    int m = alf.size();
    if(gcd(n, m) != 1)
        return 0;
    printf("Enter the action (code/decode):\n");
    cin >> lang;
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    if(lang == "code")
        code_caesar(n, k);
    else
        decode_caesar(n, k);
    return 0;
}

int task2()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    map<wchar_t, int> a;
    int k = 0;
    while(!wcin.eof())
    {
        wstring s;
        getline(wcin, s);
        for(int i = 0; i < s.size(); i++)
        {
            wchar_t c = s[i];
            if(c >= L'A' && c <= L'Z')
                c = wchar_t(int(c) - int(L'A') + int(L'a'));
            if(c >= L'А' && c <= L'Я')
                c = wchar_t(int(c) - int(L'А') + int(L'а'));
            a[c]++;
            k++;
        }
    }
    for(auto i = a.begin(); i != a.end(); i++)
        wcout << i->first << " " << double(i->second) / k << "\n";
    return 0;
}

int task3()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    map<pair<wchar_t, wchar_t>, int> a;
    int k = 0;
    while(!wcin.eof())
    {
        wstring s;
        getline(wcin, s);
        for(int i = 0; i < int(s.size()) - 1; i++)
        {
            wchar_t c = s[i];
            if(c >= L'A' && c <= L'Z')
                c = wchar_t(int(c) - int(L'A') + int(L'a'));
            if(c >= L'А' && c <= L'Я')
                c = wchar_t(int(c) - int(L'А') + int(L'а'));
            wchar_t c2 = s[i + 1];
            if(c2 >= L'A' && c2 <= L'Z')
                c2 = wchar_t(int(c2) - int(L'A') + int(L'a'));
            if(c2 >= L'А' && c2 <= L'Я')
                c2 = wchar_t(int(c2) - int(L'А') + int(L'а'));
            a[make_pair(c, c2)]++;
            k++;
        }
    }
    for(auto i = a.begin(); i != a.end(); i++)
        wcout << i->first.first << i->first.second << " " << double(i->second) / k << "\n";
    return 0;
}

void code_polib(vector<vector<wchar_t >> &m, map<wchar_t, pair<int, int >> &a)
{
    while(!wcin.eof())
    {
        wstring s;
        getline(wcin, s);
        for(int i = 0; i < s.size(); i++)
            printf("%d%d", a[s[i]].first, a[s[i]].second);
        printf("\n");
    }
}

void decode_polib(vector<vector<wchar_t >> &m, map<wchar_t, pair<int, int >> &a)
{
    int prev = -1;
    while(!wcin.eof())
    {
        wstring s;
        getline(wcin, s);
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != ' ')
            {
                int k = 0;
                while(s[i] != ' ')
                {
                    k = k * 10 + (s[i] - L'0');
                    i++;
                }
                if(prev != -1)
                    wcout << m[prev][k];
                prev = k;
            }
        }
        wcout << "\n";
    }
}

int task4()
{
    printf("Enter the language (eng/rus):\n");
    string lang;
    cin >> lang;
    if(lang == "eng")
        make_alf_eng();
    else
        make_alf_rus();
    unsigned int k = sqrt(alf.size());
    unsigned int l = k;
    while(l * k < alf.size())
        l++;
    vector<vector<wchar_t >> m(l, vector<wchar_t>(k));
    map<wchar_t, pair<int, int >> a;
    for(int i = 0; i < alf.size(); i++)
    {
        m[i % l][i / l] = alf[i];
        a[alf[i]] = make_pair(i % l, i / l);
    }
    printf("Enter the action (code/decode):\n");
    cin >> lang;
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    if(lang == "code")
        code_polib(m, a);
    else
        decode_polib(m, a);
    return 0;
}

void code_vijin(const vector<vector<wchar_t>> &m)
{
    int j = 0;
    while(!wcin.eof())
    {
        wstring s;
        getline(wcin, s);
        for(int i = 0; i < s.size(); i++, j++)
        {
            if(j == m.size())
                j = 0;
            wcout << m[j][dict[s[i]]];
        }
        wcout << L"\n";
    }
}

void decode_vijin(const vector<vector<wchar_t>> &m)
{
    int j = 0;
    while(!wcin.eof())
    {
        wstring s;
        getline(wcin, s);
        for(int i = 0; i < s.size(); i++, j++)
        {
            if(j == m.size())
                j = 0;
            int k = -1;
            for(int p = 0; k == -1 && p < m[j].size(); p++)
                if(m[j][p] == s[i])
                    k = p;
            wcout << alf[k];
        }
        wcout << L"\n";
    }
}

int task5()
{
    printf("Enter the language (eng/rus):\n");
    string lang;
    cin >> lang;
    if(lang == "eng")
        make_alf_eng();
    else
        make_alf_rus();
    printf("Enter the action (code/decode):\n");
    cin >> lang;
    freopen("code", "r", stdin);
    wstring s;
    getline(wcin, s);
    freopen("in", "r", stdin);
    wcin.clear();
    vector<vector<wchar_t>> m(s.size(), alf);
    for(int i = 1; i < m.size(); i++)
    {
        for(int j = 0; j < alf.size() - 1; j++)
            m[i][j] = m[i - 1][j + 1];
        m[i][alf.size() - 1] = m[i - 1][0];
    }
    freopen("out", "w", stdout);
    if(lang == "code")
        code_vijin(m);
    else
        decode_vijin(m);
    return 0;
}

void code_Keycaesar(wstring code)
{
    int n = alf.size();
    int j = 0;
    while(!wcin.eof())
    {
        wstring s;
        getline(wcin, s);
        for(int i = 0; i < s.size(); i++, j++)
        {
            if(j == code.size())
                j = 0;
            int k = (dict[code[j]] + dict[s[i]]) % n;
            wcout << alf[k];
        }
        wcout << L"\n";
    }
}

void decode_Keycaesar(wstring code)
{
    int n = alf.size();
    int j = 0;
    while(!wcin.eof())
    {
        wstring s;
        getline(wcin, s);
        for(int i = 0; i < s.size(); i++, j++)
        {
            if(j == code.size())
                j = 0;
            int k = (n - dict[code[j]] + dict[s[i]]) % n;
            wcout << alf[k];
        }
        wcout << L"\n";
    }
}

int task6()
{
    printf("Enter the language (eng/rus):\n");
    string lang;
    cin >> lang;
    if(lang == "eng")
        make_alf_eng();
    else
        make_alf_rus();
    printf("Enter the action (code/decode):\n");
    cin >> lang;
    freopen("code", "r", stdin);
    wstring s;
    getline(wcin, s);
    freopen("in", "r", stdin);
    wcin.clear();
    freopen("out", "w", stdout);
    if(lang == "code")
        code_Keycaesar(s);
    else
        decode_Keycaesar(s);
    return 0;
}

void code_pair(map<wchar_t, wchar_t> d)
{
    while(!wcin.eof())
    {
        wstring s;
        getline(wcin, s);
        for(int i = 0; i < s.size(); i++)
            wcout << d[s[i]];
        wcout << L"\n";
    }
}

int task7()
{
    printf("Enter the language (eng/rus):\n");
    string lang;
    cin >> lang;
    if(lang == "eng")
        make_alf_eng();
    else
        make_alf_rus();
    printf("Enter the action (code/decode):\n");
    cin >> lang;
    freopen("code", "r", stdin);
    wstring s;
    getline(wcin, s);
    freopen("in", "r", stdin);
    wcin.clear();
    set<wchar_t> st;
    for(int i = 0; i < s.size(); i++)
        st.insert(s[i]);
    if(st.size() < alf.size() / 2)
        return !(cout << "Incorrect code phrase");
    vector<wchar_t> code_symbols;
    vector<wchar_t> not_code_symbols;
    for(int i = 0; i < alf.size(); i++)
    {
        if(st.find(alf[i]) != st.end())
            code_symbols.push_back(alf[i]);
        else
            not_code_symbols.push_back(alf[i]);
    }
    while(code_symbols.size() - 1 > not_code_symbols.size())
    {
        not_code_symbols.push_back(code_symbols[code_symbols.size() - 1]);
        code_symbols.pop_back();
    }
    map<wchar_t, wchar_t> dir;
    for(int i = 0; i < not_code_symbols.size(); i++)
    {
        dir[code_symbols[i]] = not_code_symbols[i];
        dir[not_code_symbols[i]] = code_symbols[i];
    }
    if(code_symbols.size() > not_code_symbols.size())
    {
        wchar_t tmp = code_symbols[code_symbols.size() - 1];
        dir[tmp] = tmp;
    }
    code_symbols.clear();
    not_code_symbols.clear();
    freopen("out", "w", stdout);
    code_pair(dir);
    return 0;
}

void XOR(wstring code)
{
    int j = 0;
    while(!wcin.eof())
    {
        wstring s;
        getline(wcin, s);
        for(int i = 0; i < s.size(); i++)
        {
            wchar_t c = s[i] ^code[j];
            wcout << c;
            j = (j + 1) % code.size();
        }
        if(!wcin.eof())
        {
            wchar_t c = '\n' ^code[j];
            wcout << c;
            j = (j + 1) % code.size();
        }
    }
}

int task8()
{
    freopen("code", "r", stdin);
    wstring s;
    getline(wcin, s);
    freopen("in", "r", stdin);
    wcin.clear();
    freopen("out", "w", stdout);
    XOR(s);
    return 0;
}

void trans(wstring code, vector<int> perm)
{
    int j = 0;
    vector<wchar_t> ans(code.size());
    while(!wcin.eof())
    {
        wstring s;
        getline(wcin, s);
        for(int i = 0; i < s.size(); i++, j++)
        {
            if(j == code.size())
            {
                for(int k = 0; k < j; k++)
                {
                    wcout << ans[k];
                    ans[k] = 0;
                }
                j = 0;
            }
            ans[perm[j]] = s[i];
        }
        if(!wcin.eof())
        {
            if(j == code.size())
            {
                for(int k = 0; k < j; k++)
                    wcout << ans[k];
                j = 0;
            }
            ans[perm[j]] = '\n';
            j++;
        }
    }
    for(int i = 0; i < ans.size(); i++)
        if(ans[i] != 0)
            wcout << ans[i];
}

int task9()
{
    string lang;
    printf("Enter the action (code/decode):\n");
    cin >> lang;
    freopen("code", "r", stdin);
    wstring s;
    getline(wcin, s);
    vector<pair<wchar_t, int>> code;
    for(int i = 0; i < s.size(); i++)
        code.push_back(make_pair(s[i], i));
    sort(code.begin(), code.end());
    vector<int> perm(code.size());
    vector<int> perm2(code.size());
    for(int i = 0; i < s.size(); i++)
    {
        perm[i] = code[i].second;
        perm2[perm[i]] = i;
    }
    freopen("in", "r", stdin);
    wcin.clear();
    freopen("out", "w", stdout);
    if(lang == "code")
        trans(s, perm);
    else
        trans(s, perm2);
    return 0;
}

void code_k(wstring code, int k)
{
    int j = 0;
    while(!wcin.eof())
    {
        wstring s;
        getline(wcin, s);
        for(int i = 0; i < s.size(); i++)
        {
            int c = s[i] + code[j];
            int val = 0;
            int p = 1;
            wstring s1 = L"";
            while(c > 0)
            {
                int r = c % k;
                s1 = s1 + wchar_t(r + 32);
                c = c / k;
            }
            wcout << s1 << " ";
            j = (j + 1) % code.size();
        }
        if(!wcin.eof())
        {
            wchar_t c = '\n' ^code[j];
            wcout << c;
            j = (j + 1) % code.size();
        }
    }

}

int task10()
{
    printf("Enter the language (eng/rus):\n");
    string lang;
    cin >> lang;
    if(lang == "eng")
        make_alf_eng();
    else
        make_alf_rus();
    printf("Enter the action (code/decode):\n");
    cin >> lang;
    freopen("code", "r", stdin);
    wstring s;
    getline(wcin, s);
    freopen("in", "r", stdin);
    wcin.clear();
    freopen("out", "w", stdout);
    if(lang == "code")
        XOR(s);
    else
        XOR(s);
    return 0;

}

wstring gen(wstring s)
{
    wstring ans = L"";
    for(int i = 0; i < s.size(); i++)
    {
        unsigned int gamma = 0;
        unsigned int k = s[i];
        for(int j = 0; j < 105; j++)
        {
            int c = k % 2;
            gamma = gamma * 2 + c;
            k = k >> 1;
            c = (c + k) % 2;
            k += 1024 * 1024 * 1024 * c;
        }
        ans += wchar_t(gamma);
    }
    return ans;
}

int task11()
{
    string lang;
    printf("Enter the action (code/decode):\n");
    cin >> lang;
    freopen("code", "r", stdin);
    wstring s;
    getline(wcin, s);
    s = gen(s);
    freopen("in", "r", stdin);
    wcin.clear();
    freopen("out", "w", stdout);
    XOR(s);
    return 0;
}

void XOR(wchar_t prev, int a, int c)
{
    while(!wcin.eof())
    {
        wstring s;
        getline(wcin, s);
        for(int i = 0; i < s.size(); i++)
        {
            wchar_t tmp = s[i] ^prev;
            wcout << tmp;
            prev = alf[(a * dict[prev] + c) % alf.size()];
        }
        if(!wcin.eof())
        {
            wchar_t tmp = '\n' ^prev;
            wcout << tmp;
            prev = alf[(a * dict[prev] + c) % alf.size()];
        }
    }
}

int task12()
{
    printf("Enter the language (eng/rus):\n");
    string lang;
    cin >> lang;
    if(lang == "eng")
        make_alf_eng();
    else
        make_alf_rus();
    printf("Enter the action (code/decode):\n");
    cin >> lang;
    printf("Enter A and C:\n");
    int a, c;
    scanf("%d %d", &a, &c);
    srand(clock());
    int k = rand() % alf.size();
    if(lang == "code")
        printf("Seed = %d\n", k);
    else
    {
        printf("Enter the seed:\n");
        scanf("%d", &k);
    }
    wcin.clear();
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    XOR(alf[k], a, c);
    return 0;
}

int main()
{
    locale::global(locale(""));
    printf("Enter the task (1-9, 12):\n");
    int k;
    scanf("%d", &k);
    switch(k)
    {
        case 1:
            return task1();
        case 2:
            return task2();
        case 3:
            return task3();
        case 4:
            return task4();
        case 5:
            return task5();
        case 6:
            return task6();
        case 7:
            return task7();
        case 8:
            return task8();
        case 9:
            return task9();
        case 11:
            return task11();
        case 12:
            return task12();
        default:
            return 0;
    }
}