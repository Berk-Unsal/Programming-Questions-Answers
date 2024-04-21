#include <iostream>
#include <vector>




using namespace std;

int candy(vector<int>& ratings){
	int size = ratings.size();
	if(size == 0){
		return 0;
	}
	else if(size == 1){
		return 1;
	}

	int init = 1;
	int total = init;
	
	
	for(int i=1;i<size;i++){
		if(ratings[i] > ratings[i-1]){
			init++;
			cout << init << endl;
			total += init;
		}
		if(ratings[i] <= ratings[i-1]){
			init = 1;
			cout << init << endl;
			total+= init;
		}
	}

	
	return total;
}

int main(){
	vector<int> rates = {1,0,2};
	cout << candy(rates);
}