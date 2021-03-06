#include "avl.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char** argv) {
  vector<string> input;
  string keywords[] = {"search", "insert", "delete", "approx_search", "in_order", "pre_order", "in_order,", "pre_order,"};
  string argument = argv[1];

  string word;
  for(int i = 0; i < argument.size(); i++){
    if(argument[i] == ' '){
      input.push_back(word);
      word = "";
    }
    else if(i == argument.size() - 1){
      word += argument[i];
      input.push_back(word);
    }
    else{
      word += argument[i];
    }
  }
  
  string h = input[0];
  h.erase(remove(h.begin(), h.end(), ','), h.end());
  int hNum = stoi(h);
  AVL* avl = new AVL(hNum);

  for(int i = 1; i < input.size(); i++){
    if (find(begin(keywords), end(keywords), input[i]) != end(keywords)){
      if(input[i] == "search"){
        int param1 = stoi(input[i+1]);
        string param2 = input[i+2];
        param2.erase(remove(param2.begin(), param2.end(), ','), param2.end());
        int param2Num = stoi(param2);
        tuple<int, int> target = make_tuple(param1, param2Num);
        avl->search(target);
        i+=2;
      }
      else if(input[i] == "insert"){
        int param1 = stoi(input[i+1]);
        string param2 = input[i+2];
        param2.erase(remove(param2.begin(), param2.end(), ','), param2.end());
        int param2Num = stoi(param2);
        tuple<int, int> target = make_tuple(param1, param2Num);
        avl->insert(target);
        i+=2;
      }
      else if(input[i] == "delete"){
        int param1 = stoi(input[i+1]);
        string param2 = input[i+2];
        param2.erase(remove(param2.begin(), param2.end(), ','), param2.end());
        int param2Num = stoi(param2);
        tuple<int, int> target = make_tuple(param1, param2Num);
        avl->remove(target);
        i+=2;
      }
      else if(input[i] == "approx_search"){
        int param1 = stoi(input[i+1]);
        string param2 = input[i+2];
        param2.erase(remove(param2.begin(), param2.end(), ','), param2.end());
        int param2Num = stoi(param2);
        tuple<int, int> target = make_tuple(param1, param2Num);
        avl->approximateSearch(target);
        i+=2;
      }
      else if(input[i] == "in_order" || input[i] == "in_order,"){
        avl->printInOrder();
      }
      else if(input[i] == "pre_order" || input[i] == "pre_order,"){
        avl->printPreOrder();
      }
    }
  }
  return 0;
}