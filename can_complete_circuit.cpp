#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
Start at station 3 (index 3) and fill up with 4 unit of gas. 
Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.


vector<int>gas = {1,2,3,4,5};
vector<int>cost = {3,4,5,1,2};

*/


int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    
    for (int i = 0; i < n; i++) {
        int tank = 0;
        int j = i;
        int count = 0;
        
        while (count < n) {
            tank += gas[j] - cost[j];
            if (tank < 0)
                break;
            j = (j + 1) % n;
            count++;
        }
        
        if (count == n)
            return i;
    }
    
    return -1;
}




int main(){
	vector<int>gas = {1,2,3,4,5};
	vector<int>cost = {3,4,5,1,2};
	cout << canCompleteCircuit(gas,cost);
}

