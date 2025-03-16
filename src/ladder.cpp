#include "ladder.h"
#include <cctype>
void error(string word1, string word2, string msg){
    cout << "Offending word1: " << word1 << ", ";
    cout << "Offending word2: " << word2 << ", ";
    cout << "Reason: " << msg << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    size_t i = 0;
    size_t j = 0;
    int count = 0;
    while(count <= d && i < str1.size() && j < str2.size()){
        if(tolower(str1[i]) != tolower(str2[j])){
            if(str1.size()<str2.size()){
                --i;
            }else if(str1.size()>str2.size()){
                --j;
            }
            ++count;
        }
        ++i;
        ++j;
    }
    if(i == str1.size()){
        count += str2.size() - j;
    }else if(j == str2.size()){
        count += str1.size() - i;
    }
    if(count > d)
        return false;
    return true;
}

bool is_adjacent(const string& word1, const string& word2){
    return edit_distance_within(word1, word2, 1);
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    queue<vector<string>> ladder_queue;
    vector<string> first = {begin_word};
    ladder_queue.push(first);
    set<string> visited;
    visited.insert(begin_word);
    while(!ladder_queue.empty()){
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder[ladder.size()-1];
        for(string word : word_list){
            if(is_adjacent(last_word,word)){
                if(!visited.contains(word)){
                    visited.insert(word);
                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(word);
                    if(word == end_word)
                        return new_ladder;
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }
    return first;
}

void load_words(set<string> & word_list, const string& file_name){
    ifstream inFile(file_name);
    if(inFile.is_open()){
        string line;
        while(getline(inFile,line))
            word_list.insert(line);
        inFile.close();
    }
}

void print_word_ladder(const vector<string>& ladder){
    for(string word : ladder)
        cout << word << ' ';
}

#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}
void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "src/words.txt");
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}