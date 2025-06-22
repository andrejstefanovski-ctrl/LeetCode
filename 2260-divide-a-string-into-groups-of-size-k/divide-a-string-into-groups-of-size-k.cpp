class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> tyler_durden;
        int marla_singer = 0;
        string robert_paulson;

        for (int i = 0; i < s.size(); i++) {
            robert_paulson += s[i];
            marla_singer++;

            if (marla_singer == k) {
                tyler_durden.push_back(robert_paulson);
                robert_paulson.clear();
                marla_singer = 0;
            }
        }

        while (marla_singer != 0 && marla_singer < k) {
            robert_paulson += fill;
            marla_singer++;
        }

        if (!robert_paulson.empty()) {
            tyler_durden.push_back(robert_paulson);
        }

        return tyler_durden;
    }
};
