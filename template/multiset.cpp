
#include <bits/stdc++.h>
using namespace std;

struct MultiSet {
   private:
    map<int, int> cnt;
    int sz = 0;

   public:
    // Insert one occurrence of x.
    void insert(int x) {
        cnt[x]++;
        sz++;
    }

    // Erase one occurrence of x, if present.
    void erase_one(int x) {
        auto it = cnt.find(x);
        if (it == cnt.end()) return;

        sz--;

        if (--it->second == 0) {
            cnt.erase(it);
        }
    }

    // Erase every occurrence of x.
    void erase_all(int x) {
        auto it = cnt.find(x);
        if (it == cnt.end()) return;

        sz -= it->second;
        cnt.erase(it);
    }

    // Return the largest element.
    // Throws runtime_error if empty.
    int max() const {
        if (cnt.empty()) {
            throw runtime_error("MultiSet is empty");
        }

        return cnt.rbegin()->first;
    }

    // Return the smallest element.
    // Throws runtime_error if empty.
    int min() const {
        if (cnt.empty()) {
            throw runtime_error("MultiSet is empty");
        }

        return cnt.begin()->first;
    }

    // Check whether the collection contains no elements.
    bool empty() const { return sz == 0; }
};
