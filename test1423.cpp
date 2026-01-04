#include <stdio.h>
#include <algorithm>
#include <cctype>
#include <clocale>
#include <iostream>
#include <bits/stdc++.h>


int main(){
    std::string s = "no";
    std::string temp;
    for (const char c : s){
        if (std::isalnum(c)){
            temp.insert(temp.begin(), std::tolower(c));
        }
    }
    int left = 0;
    int right = temp.length() - 1;
    while (left < right){
        if (temp[left] != temp[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}