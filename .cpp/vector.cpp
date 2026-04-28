#include<bits/stdc++.h>
vector<int> a; //empty vec
vector<double> b=(5, 0); //{0,0,0,0,0}: size 5, filled with 0
vector<int> c ={1, 2, 3}; //direct initialize

//ACCESS
a[0]; //front
a.front(); //front
a[a.size() -1]; //last
a.back(); //last

//append and pop
a.push_back(1); //append at last
a.pop_back(); //delete last (return NOTHING)
a.size(); //length

//LOOP
for (int i =0; i <(int)a.size; i++){
	cout <<a[i] <<endl;
}
