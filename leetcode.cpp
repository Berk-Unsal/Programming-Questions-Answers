#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>


using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        for(int i=0;s[i]!='\0';i++){
            int count = 0;
            for(int y=i;s[y]!= '\0';y++){
                ++map[y];
                if(map[y]>1){
                    break;
                }
                cout << map[y] << endl;
                ++count;
            }
            if(count > max){
                max = count;
            }
            setZero(map);
        }


        return max;
    }
    Solution(){
        for(int i=0;i<256;i++){
            map[i] = 0;
        }
    }

    void setZero(int map[]){
        for(int i=0;i<256;i++){
            map[i] = 0;
        }
    }
private:
    int map[256];
};



int findMaj(int array[],int size){
    unordered_map<int,int> map;
    for(int i=0;i<size;i++){
        map[array[i]] += 1;
    }
    int max = map[array[0]];
    int index = array[0];
    for(auto& pair:map){
        if(pair.second > max){
            max = map[pair.first];
            index = pair.first;
        }
    }
    return index;
    

}


template<class T>
T findAverage(vector<T> numbers){
    T sum = 0;
    for(auto i : numbers){
        sum += i;

    }

    return sum / numbers.size();
}


template<class T>
T findMax(vector<T> numbers){
    T max = numbers[0];
    for(auto i : numbers){
        if(i > max){
            max = i;
        }
    }
    return max;

}

int searchString(vector<string> v,string target){
    int index = 0;
    for(auto i:v){
        
        if(i == target){
            return index;
        }
        index++;
    }
    return -1;
}



int main(){
    cout << "Enter how many numbrs you want to enter\n";

    int num;
    cin >> num;
    
    vector<int> v;
    int sum = 0;
    for(int i=0;i<num;i++){
        int temp;
        cin >> temp;
        sum += temp;
        v.push_back(temp);
    }


    cout << "Original vector: \n";
    for(auto i:v){
        cout << i << endl;
    }

    cout << "Sum of all the numbers: " << sum;


    cout << "Maximum element: ";
    int max = v.at(0);
    int min = v.at(0);
    for(auto i :v){
        if(i > max){
            max = i;
        }
        if(i < min){
            min = i;
        }
    }
    cout << max;

    cout << " Minimum element: " << min << endl;
    unordered_map<int,int> map;
    vector<int> newmap;
    for(auto i : v){

        if(map[i] == 0){
            map[i] = 1;
            newmap.push_back(i);
        }
    }

    cout << "Modified map:\n";
    for(auto i:newmap){
        cout << i << endl;
    }

    
    cout << "Enter a number to search";
    int num2;
    cin >> num2;
    bool found = false;
    for(auto i: v){
        if(i == num2){
            cout <<"Exists";
            found = true;
        }
    }
    if(!found){
        cout << "Doesn't exists";
    }



    



    return 0;
}