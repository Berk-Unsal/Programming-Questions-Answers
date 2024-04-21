#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>




using namespace std;
void transformIntoSweeper(char** tablo, int col, int row) {
    for (int i = 0; i < row; i++) {
        for (int y = 0; y < col; y++) {
            if (tablo[i][y] == '.') {
                int count = 0;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        int ni = i + dx;
                        int nj = y + dy;
                        if (ni >= 0 && ni < row && nj >= 0 && nj < col && tablo[ni][nj] == '*') {
                            count++;
                        }
                    }
                }
                tablo[i][y] = '0' + count;
            }
        }
    }

    for (int i = 0; i < row; i++) {
        for (int y = 0; y < col; y++) {
            std::cout << tablo[i][y] << " ";
        }
        std::cout << "\n";
    }
}


void howManyTimesOccurs(string input){
    size_t found = input.find("'re");
    while(found != string::npos){
        input.replace(found, 3, " are"); 
        found = input.find("'re", found + 4);
    }
    size_t found2 = input.find("n't");
    while(found2 != string::npos){
        input.replace(found2,3," not");
        found2 = input.find("n't",found2 + 4);
    }
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    int size = input.length();
    int words = 0;
    vector<string> Kelimeler;
    for(int i=0;i<size;i++){
        if(input[i] != ' '){
            
        }
        if(input[i] == ' '){
            words++;
        }
    }

}


vector<string> isAnagram(const string& input,const vector<string>& anagramCandicates){
    vector<string> ANAGRAMS;
    char map[26];
    for(int i=0;i<26;i++){
        map[i] = 'a' + i;
    }

    for(auto anagram:anagramCandicates){
        for(char& c : anagram){
            c = std::tolower(c);
        }
    }
    
    int inputS[26] = {0};
    int size = input.length();

    for (int i = 0; i < size; i++) {
        char lowerInputChar = std::tolower(input[i]);
        if (std::isalpha(lowerInputChar)) {
            inputS[lowerInputChar - 'a']++;
        }
    }

    for(int i=0;i<size;i++){
        if(input[i] == map[i]){
            inputS[i] += 1;
        }
    }

    for(auto anagram:anagramCandicates){
        if(anagram != input && anagram.length() == size){
            int candidateS[26];
            for(int i=0;i<size;i++){
                if(anagram[i] == map[i]){
                    candidateS[i] += 1;
                }
            }
            bool anagramBOOL = true;
            for(int i=0;i<26;i++){
                if(candidateS[i] != inputS[i]){
                    anagramBOOL = false;
                    break;
                }
            }
            if(anagramBOOL){
                ANAGRAMS.push_back(anagram);
            }
        }
    }   
    return ANAGRAMS;
}

int main(){
    
    

    
    
    
}
