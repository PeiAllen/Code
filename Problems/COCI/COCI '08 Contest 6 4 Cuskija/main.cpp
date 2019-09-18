/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: allen
 *
 * Created on September 24, 2018, 7:37 PM
 */

#include <cstdlib>
#include <queue>
#include <stdio.h>
#include <iostream>
using namespace std;

/*
 *
 */
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	queue<int> nums[3];
	int in;
	for(int i=0;i<n;i++){
		cin>>in;
		nums[in%3].push(in);
	}
	if(nums[1].size()+nums[2].size()+1>=nums[0].size()){
		if(!nums[1].empty()&&!nums[2].empty()&&nums[0].empty()){
			printf("impossible\n");
		}
		else{
			vector<int> top;
			while(!nums[1].empty()){
				if(nums[0].size()>1){
					top.push_back(nums[0].front());
					nums[0].pop();
				}
				top.push_back(nums[1].front());
				nums[1].pop();
			}
			if(!nums[0].empty()){
				top.push_back(nums[0].front());
				nums[0].pop();
			}
			while(!nums[2].empty()){
				top.push_back(nums[2].front());
				nums[2].pop();
				if(!nums[0].empty()){
					top.push_back(nums[0].front());
					nums[0].pop();
				}
			}
			if(!nums[0].empty()){
				top.push_back(nums[0].front());
				nums[0].pop();
			}
			for(int i=0;i<top.size()-1;i++)printf("%d ",top[i]);
			printf("%d\n",top.back());
		}
	}
	else{
		printf("impossible\n");
	}
	return 0;
}