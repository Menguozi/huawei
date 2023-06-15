#include <bits/stdc++.h>

using namespace std;

int frag_cnt[9] = {0};
int line_cnt = 0;

void frag_stat(bitset<512> &valid)
{
    int cnt = 0;
    for (int i = 0; i < valid.size(); i++)
    {
        if (valid.test(i))
        {
            cnt++;
        }
        else
        {
            if (cnt <= 8)
                frag_cnt[cnt]++;
            cnt = 0;
        }
    }
    if (cnt && (cnt <= 8))
        frag_cnt[cnt]++;
}

int main(int argc, char *argv[])
{
    cout << "frag_stat:" << argv[1] << endl;

    fstream f;
    f.open(argv[1]);
    string line;
    getline(f, line);
    getline(f, line);
    // getline(f, line);
    while (getline(f, line))
    {
        // std::cout << line << '\n';
        int cnt = 0;
        bitset<512> valid;

        line_cnt++;
        for (int i = 17; i < line.size(); i++)
        {
            if ((line[i] >= '0' && line[i] <= '9') || (line[i] >= 'a' && line[i] <= 'f'))
            {

                // cout<<endl<<cnt<<endl;
                string sub = line.substr(i, 1);
                // cout<<endl<<sub<<endl;
                bitset<4> binary(stoi(sub, nullptr, 16));
                // cout<<binary.to_string();
                for (int j = 0; j < 4; j++)
                {
                    if (binary.test(j))
                        valid.set(512 - (cnt * 4 + 4 - j));
                    // cout<<j<<"\t"<<cnt*4+j<<endl;
                }
                cnt++;
            }
        }
        // cout<<endl<<valid.to_string()<<endl;

        frag_stat(valid);
    }

    cout << endl;
    for (int i = 0; i <= 8; i++)
    {
        cout << "frag_" << i * 4 << "k_cnt: " << frag_cnt[i] << endl;
    }

    cout << endl
         << "line_cnt: " << line_cnt << endl;
    // cout << valid.to_string() << endl;
    f.close();
    return 0;
}