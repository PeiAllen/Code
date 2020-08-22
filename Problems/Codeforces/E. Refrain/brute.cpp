#include <bits/stdc++.h>
using namespace std;

vector<int> SAIS_suffix_array(vector<int> &A){
    int n = A.size(), mx = 0;
    vector<bool> isL(n + 1, true);
    for(int i : A) mx = max(mx, i + 2);
    vector<int> buckets(mx), LMS, SA, TMP, TMP2;
    for(int i : A) ++buckets[i + 1];
    partial_sum(buckets.begin(), buckets.end(), buckets.begin());
    isL[n - 1] = 1;
    for(int i = n - 2; i >= 0; --i) isL[i] = A[i] != A[i + 1] ? A[i] > A[i + 1] : isL[i + 1];
    auto induced_sort = [n, A, isL, buckets](vector<int> &LMS){
        vector<int> SA(n, -1); SA.push_back(n);
        vector<int> temp = vector<int>(buckets.begin() + 1, buckets.end());
        for(auto it = LMS.rbegin(); it != LMS.rend(); ++it) SA[--temp[A[*it]]] = *it;
        temp = vector<int>(buckets.begin(), buckets.end() - 1);
        for(int j, i = -1; i < n; ++i){
            j = SA[i == -1 ? SA.size() - 1 : i] - 1;
            if(j >= 0 && isL[j]) SA[temp[A[j]]++] = j;
        }
        SA.pop_back();
        temp = vector<int>(buckets.begin() + 1, buckets.end());
        for(int j, i = n - 1; i >= 0; --i){
            j = SA[i] - 1;
            if(j >= 0 && !isL[j]) SA[--temp[A[j]]] = j;
        }
        return SA;
    };
    for(int i = n - 1; i > 0; --i) if(isL[i] = isL[i - 1] && !isL[i]) LMS.push_back(i);
    isL[n] = 1; isL[0] = 0; reverse(LMS.begin(), LMS.end());
    if(LMS.size() > 1){
        TMP2 = SA = induced_sort(LMS);
        int i1, i2, prev = -1, j = 0;
        for(int i : TMP2){
            if(!isL[i]) continue;
            i1 = prev; i2 = i;
            while(prev >= 0 && A[i1] == A[i2]){
                ++i1; ++i2;
                if(isL[i1] || isL[i2]){
                    j -= isL[i1] && isL[i2];
                    break;
                }
            }
            ++j; prev = i; SA[i] = j;
        }
        TMP2 = vector<int>();
        for(int i : LMS) TMP.push_back(SA[i]);
        for(int i : SAIS_suffix_array(TMP)) TMP2.push_back(LMS[i]);
        LMS = TMP2; TMP = vector<int>(); TMP2 = vector<int>();
    }
    return induced_sort(LMS);
}

vector<int> get_vector(string s){
    vector<int> arr; for(auto i : s) arr.push_back(i);
    return arr;
}
vector<int> get_suffix_array(vector<int> arr){
    vector<int> ans = SAIS_suffix_array(arr);
    ans.insert(ans.begin(), arr.size());
    return ans;
}
vector<long long> get_lcp(vector<int> &SA, vector<int> A){
    int n = SA.size(); A.push_back(-1); // Make sure nothing else in A is < 0
    vector<long long> lcp(n - 1), rank(n);
    for(int i = 0; i < SA.size(); ++i) rank[SA[i]] = i;
    for(int ind, i = 0, k = 0; i < n; ++i){
        ind = rank[i]; if(ind == n - 1) continue;
        for(int j = SA[ind + 1]; i + k < n && A[i + k] == A[j + k];) ++k;
        lcp[ind] = k; k -= k > 0;
    }
    return lcp;
}
int lower_bound(vector<int> &SA, vector<int> &A, vector<int> &B){
    int mid, pos, left = -1, right = SA.size();
    while(right - left > 1){
        mid = (left + right) / 2;
        if(B <= vector<int>(A.begin() + SA[mid], A.begin() + min(A.size(), SA[mid] + B.size()))) right = mid;
        else left = mid;
    }
    return right;
}
int upper_bound(vector<int> &SA, vector<int> &A, vector<int> &B){
    int mid, pos, left = -1, right = SA.size();
    while(right - left > 1){
        mid = (left + right) / 2;
        if(B < vector<int>(A.begin() + SA[mid], A.begin() + min(A.size(), SA[mid] + B.size()))) right = mid;
        else left = mid;
    }
    return right;
}
bool contains(vector<int> &SA, vector<int> &A, vector<int> &B){
    int pos = lower_bound(SA, A, B);
    return pos != SA.size() && vector<int>(A.begin() + SA[pos], A.begin() + min(A.size(), SA[pos] + B.size())) == B;
}

void solve(vector<int> &A){

    /*
    Represent LCP as a histogram.
    If LCP(i, j) = K, then a substring of K appears twice
    */

    vector<int> SA  = get_suffix_array(A);
    vector<long long> lcp = get_lcp(SA, A);
    int n = lcp.size();
    vector<int> ID(n + 1);
    for(int i = 0; i < SA.size(); ++i) ID[SA[i]] = i;

    vector<int> st;
    long long top, area, best = A.size(); int ind = 0, sz = n;
    for(int pos = 0; pos < n;){
        if(st.empty() || lcp[st.back()] <= lcp[pos]){
            st.push_back(pos); ++pos;
        } else {
            top = st.back(); st.pop_back();
            if(!st.empty()) area = lcp[top] * (pos - st.back());
            else area = lcp[top] * (pos + 1);
            if(area > best){
                best = area;
                sz   = lcp[top];
                ind  = SA[pos];
            }
        }
    }
    while(!st.empty()){
        top = st.back(); st.pop_back();
        if(!st.empty()) area = lcp[top] * (n - st.back());
        else area = lcp[top] * (n + 1);
        if(area > best){
            best = area;
            sz   = lcp[top];
            ind  = SA[n];
        }
    }
    cout << best << "\n" <<sz<<"\n";

    for(int i = ind; i < ind + sz; ++i) cout << A[i] << " ";
}

int main() {

    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    vector<int> A(n);
    for(int i = 0; i < n; ++i) cin >> A[i];
    solve(A);

    return 0;
}
