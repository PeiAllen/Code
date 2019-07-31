/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Allen
 *
 * Created on January 4, 2019, 12:32 PM
 */

#include <bits/stdc++.h>
using namespace std;
random_device rd;
template <class t>
struct node {
    t data;
    int amount;
    unsigned int priority;
    struct node *child[2];
    node(t a=INT_MAX, int b=1) {//b=1 may be bad for some cases, but now now
        data = a; amount = b;priority = rd();child[0] = NULL;child[1] = NULL;
    }
    void calcamount() {
        amount = (child[1] == NULL ? 0 : child[1]->amount)+(child[0] == NULL ? 0 : child[0]->amount) + 1;
    }
    struct node* Rotate(int a) {
        auto temp = child[!a];
        child[!a] = child[!a]->child[a];
        temp->child[a] = this;
        calcamount();
        temp->calcamount();
        return temp;
    }
    struct node* insert(t a, bool root=true) {
        if (root && data == INT_MAX)return new node(a);
        int ch = a >= data;
        if (child[ch] == NULL) {
            amount += 1;
            child[ch]=new node(a);
            if (child[ch]->priority > priority)return Rotate(!ch);
            return this;
        }
        child[ch] = child[ch]->insert(a, false);
        calcamount();
        if (child[ch]->priority > priority)return Rotate(!ch);
        return this;
    }
    struct node* search(t a) {
        if (data == a) return this;
        if (child[!(a < data)] == NULL)  return NULL;
        return child[!(a < data)]->search(a);
    }
    struct node* del(t a, bool root=true){
        if(data==a){
            if (child[0] == NULL || child[1] == NULL) {
                if(root&&amount==1){
                    data = INT_MAX;
                    amount = 0;
                    return this;
                }
                free(this);
                return child[(child[0] == NULL)];
            }
            int te = !(child[1]->priority > child[0]->priority);
            auto temp = Rotate(te);
            temp->child[te]=del(a,false);
            temp->calcamount();
            return temp;
        }
        int ch = a >= data;
        if(child[ch]){
        child[ch] = child[ch]->del(a,false);
        calcamount();
        }
        return this;
    }
    void inOrder() {
        if (child[0] != NULL)child[0]->inOrder();
        if (data != INT_MAX) printf("%d ", data); //change this
        if (child[1] != NULL)child[1]->inOrder();
    }
    t at(t a) {
        t lefty = child[0] == NULL ? 0 : child[0]->amount;
        if (a == lefty + 1)  return data;
        int ch=a > lefty;
        if (child[ch] == NULL) return -1;
        return child[ch]->at(a-(ch?lefty+1:0));
    }
    t find(t a, int smaller) {
        t lefty = child[0] == NULL ? 0 : child[0]->amount;
        if (data == a) {
            if (child[0] != NULL) {
                t temp = child[0]->find(a, smaller);
                if (temp != -1)return temp;
            }
            return lefty + smaller + 1;
        }
        int ch=data<=a;
        if (child[ch] == NULL)return -1;
        return child[ch]->find(a, smaller+(ch?lefty+1:0));
    }
};

/*
 * 
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    node<int>* root = new node<int>();
    int n, m;
    cin >> n>>m;
    int in;
    for (int i = 0; i < n; i++) {
        cin>>in;
        root=root->insert(in);
    }
    int last = 0;
    char c;
    for (int i = 0; i < m; i++) {
        cin>>c;
        cin>>in;
        in ^= last;
        if (c == 'I') {
            root=root->insert(in);
        } else if (c == 'R') {
            root=root->del(in);
        } else if (c == 'S') {
            last = root->at(in);
            printf("%d\n", last);
        } else {
            last = root->find(in, 0);
            printf("%d\n", last);
        }
    }
    root->inOrder();
    return 0;
}