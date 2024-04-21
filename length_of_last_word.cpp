#include <iostream>
#include <vector>
#include <string>



using namespace std;

class Solution{
public:
	int lengthOfLastWord(string s){
		int Size = s.size();
		int word = 0;
		bool encountered_word = false;
		bool currently_in_word = false;
		for(int i=0;i<Size;i++){
			if(s[i] != ' ' && !encountered_word){
				encountered_word = true;
			}
			if(encountered_word && !currently_in_word){
				word++;
				currently_in_word = true;
			}
			if(s[i] == ' '){
				encountered_word = false;
				currently_in_word = false;
			}
		}
		int word2 = 0;
		encountered_word = false;
		currently_in_word = false;
		bool encountered_last = false;
		int length = 1;
		for(int i=0;i<Size;i++){
			if(encountered_last && s[i] != ' '){

				length++;
			}
			if(s[i] != ' ' && !encountered_word){
				encountered_word = true;
			}
			if(encountered_word && !currently_in_word){
				word2++;
				currently_in_word = true;
			}
			if(s[i] == ' '){
				encountered_word = false;
				currently_in_word = false;
			}
			if(word2 == word){
				encountered_last = true;
			}
		}


		return length;

	}

};



int main(){
	Solution berk;
	cout << berk.lengthOfLastWord("   fly me   to   the moon  ");
}