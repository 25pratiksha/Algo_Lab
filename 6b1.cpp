
#include<bits/stdc++.h>
using namespace std;

vector<int> chptr;
vector<int> indx;
vector<int> chc1;

int permute(vector<int> conff, vector<bool> left, vector<vector<int> > nbr) {
    if (conff.size() == left.size()) {
        return 1;
    }

    bool allClear = true;
    int sum = 0;
    for (int i=0; i<left.size(); ++i) {
        if (left[i] && (nbr[i].size() != 0 || (conff.size() > 0 && chc1[i] == chc1[conff[conff.size()-1]]))) {
            allClear = false;
            break;
        }
    }
    if (allClear) {
        sum = 1;
        for (int i=1; i<=left.size()-conff.size(); ++i) {
            sum *= i;
        }
        return sum;
    }
    for (int i=0; i<left.size(); ++i) {
        if (!left[i] or nbr[i].size() != 0 or (conff.size() > 0 && chc1[i] == chc1[conff[conff.size()-1]])) continue;
        vector<vector<int> > newAdj = nbr;
        conff.push_back(i);
        left[i] = false;
        for (int j=0; j<newAdj.size(); ++j) {
            newAdj[j].erase(remove(newAdj[j].begin(), newAdj[j].end(), i), newAdj[j].end());
        }
        sum += permute(conff, left, newAdj);
        conff.pop_back();
        left[i] = true;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i1=1; i1<=t; ++i1) {
        int n,m;
        cin >> n >> m;
        chptr = vector<int>(n);
        indx = vector<int>(n);
        chc1 = vector<int>();
        int sumC = 0;
        for (int i=0; i<n; ++i) {
            cin >> chptr[i];
            indx[i] = sumC;
            sumC += chptr[i];
            for (int j=0; j<chptr[i]; ++j) {
                chc1.push_back(i);
            }
        }
        vector<vector<int> > nbr(sumC);
        for (int i=0; i<n; ++i) {
            for (int j=1; j<chptr[i]; ++j) {
                for (int k=0; k<j; ++k) {
                    nbr[indx[i]+j].push_back(indx[i]+k);
                }
            }
        }
        for (int i=0; i<m; ++i) {
            int c,p,d,q;
            cin >> c >> p >> d >> q;
            nbr[indx[d-1]+q-1].push_back(indx[c-1]+p-1);
        }

        int sum = permute(vector<int>(), vector<bool>(sumC,1), nbr);


        cout << "Case #" << i1 << ": " << sum << "\n";
    }
    return 0;
}
