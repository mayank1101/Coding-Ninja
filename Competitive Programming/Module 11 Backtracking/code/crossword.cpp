#include<bits/stdc++.h>
using namespace std;

#define N 10


void printCrossword(char crossword[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++){
            cout <<  crossword[i][j];
        }
        cout << "\n";
    }
    return;
}


bool isVerticalValid(char crossword[N][N], int row, int col, string word)
{
    //check for available vertical length
    if(N - row < word.length()){
        return false;
    }

    //check for + and invalid char
    for(int i=row,j=0;j<word.length();i++,j++)
    {
        if((crossword[i][col] != '-') && (crossword[i][col] != word[j])){
            return false;
        }
    }
    return true;
}


bool isHorizontalValid(char crossword[N][N], int row, int col, string word)
{
    if(N-col < word.length()){
        return false;
    }
    for(int i=col,j=0;j<word.length();i++,j++)
    {
        if((crossword[row][i] != '-') && (crossword[row][i] != word[j])){
            return false;
        }
    }
    return true;
}

void setVertical(char crossword[N][N], int row, int col, string word, bool state[])
{
    //i iterate over row in a col and j itearate over word
    for(int i=row,j=0;j<word.length();i++,j++)
    {
        if(crossword[i][col] != '+'){
            if(crossword[i][col] == word[j]){
                state[j] = false;
            }
            else{
                state[j] = true;
                crossword[i][col] = word[j];
            }
        }
    }
    return;
}

void setHorizontal(char crossword[N][N], int row, int col, string word, bool state[])
{
    for(int i=col,j=0;j<word.length();i++,j++)
    {
        if(crossword[row][i] != '+')
        {
            if(crossword[row][i] == word[j]){
                state[j] = false;
            }
            else{
                state[j] = true;
                crossword[row][i] = word[j];
            }
        }
    }
    return;
}

void resetVertical(char crossword[N][N], int row, int col, bool state[], int word_length)
{
    for(int i=row,j=0;j<word_length;i++,j++)
    {
        if(state[j] == true){
            crossword[i][col] = '-';
        }
    }
    return;
}

void resetHorizontal(char crossword[N][N], int row, int col, bool state[], int word_len)
{
    for(int i=col,j=0;j<word_len;i++,j++)
    {
        if(state[j] == true){
            crossword[row][i] = '-';
        }
    }
    return;
}

bool solveCrossword(char crossword[N][N], vector<string>& wordList, int index)
{
    if(index == wordList.size()){
        return true;
    }
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if((crossword[i][j] == '-') || (crossword[i][j] == wordList[index][0])){
                int word_len = wordList[index].size();
                bool state[word_len]; //keep track of the position where word is filled up
                memset(state,false,sizeof(state)); // initialize state array to false
                
                //check vertically possible to fill the word
                if(isVerticalValid(crossword, i, j, wordList[index])){
                    setVertical(crossword, i, j, wordList[index], state);
                    if(solveCrossword(crossword, wordList, index+1));
                    {
                        return true;
                    }
                    resetVertical(crossword, i, j, state, word_len);
                }
                
                //check horizontally possible to fill the word
                if(isHorizontalValid(crossword, i, j, wordList[index])){
                    setHorizontal(crossword, i, j, wordList[index], state);
                    if(solveCrossword(crossword, wordList, index+1)){
                        return true;
                    }
                    resetHorizontal(crossword, i, j, state, word_len);
                }
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char crossword[N][N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++){
            cin>>crossword[i][j];
        }
    }
    string word=""; //string of words separated by ;
    cin>>word;
    vector<string> wordList;
    stringstream ss(word); //to input ; separsted words
    while(ss.good()){
        string s;
        getline(ss, s, ';');
        wordList.push_back(s);
    }
    bool ans = solveCrossword(crossword,wordList,0); //starting index i.e index of first word
    printCrossword(crossword);
    return 0;
}