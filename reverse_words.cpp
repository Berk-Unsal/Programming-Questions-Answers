#include <iostream>
#include <vector>
#include <string>




using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        int s_size = s.size();
        string new_string;
        vector<string> words;
        int index = 0;
        bool start = true;
        for(auto i:s){
            if(start && i == ' '){
                continue;
            }
            if(i != ' ' && start){
                new_string.push_back(i);
                start = false;
                continue;
            }
            if(i == ' ' && !start){
                words.push_back(new_string);
                new_string.clear();
            }
            if(i != ' ' && !start){
                new_string.push_back(i);
            }
            if(index == s_size - 1){
                words.push_back(new_string);
            }
            index++;
        }   

        string end_string;

        for(int i=words.size()-1;i>-1;i--){
            if(i ==  words.size()-1){
                end_string += words[i];
            }
            else{
                end_string += " " + words[i];
            }
        }
        return end_string;
    }
};



int main(){
    Solution berk;

    cout << berk.reverseWords("    ali       topu     atsana    dost");

}