#include <vector>
#include <cassert>

using namespace std;

void smartErase(vector<int> &v, int del) {
    int j = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == del) {
            continue;
        }
        v[j] = v[i];
        j++;
    }
    v.resize(j);
}

int main() {
    {
        vector<int> v = {1, 2, 3, 4, 5, 6, 2, 3};
        vector<int> v_expected = {1, 3, 4, 5, 6, 3};
        smartErase(v, 2);
        assert(v == v_expected);
    }
    {
        vector<int> v = {2};
        vector<int> v_expected = {};
        smartErase(v, 2);
        assert(v == v_expected);
    }

    {
        vector<int> v = {2,1,2,1,2,1,2};
        vector<int> v_expected = {1,1,1};
        smartErase(v, 2);
        assert(v == v_expected);
    }
    {
        vector<int> v = {1,2,3,4,2,2,2};
        vector<int> v_expected = {1,3,4};
        smartErase(v, 2);
        assert(v == v_expected);
    }
}
