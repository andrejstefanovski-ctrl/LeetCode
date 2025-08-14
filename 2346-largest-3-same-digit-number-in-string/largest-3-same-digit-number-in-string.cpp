class Solution {
public:
    string largestGoodInteger(string num) {
        string res="", curmax="";
        for (int i=0; i<num.size()-2; i++)
        {
            if (num[i] == num[i+1] && num[i] == num[i+2])
            {
                char c = num[i];
                res+=c;
                res+=c;
                res+=c;
                if (curmax.empty())
                {
                    curmax=res;
                    res="";
                }
                else
                {
                    int r;
                    if (res[0]=='0')
                    {
                        r=0;
                    }
                    else
                    {
                        r = stoi(res);
                    }
                    int cm = stoi(curmax);
                    if (r > cm)
                    {
                        curmax = res;
                    }
                    res="";
                }
            }
        }
        return curmax;
    }
};