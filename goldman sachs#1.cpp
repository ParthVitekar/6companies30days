/*Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array.*/

#include <bits/stdc++.h>

using namespace std;

 vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string> >res;

        unordered_map<string , vector<string> >mp;

        for(int i=0 ; i<string_list.size() ; i++){
            string s = string_list[i];
            sort(s.begin() , s.end());

            mp[s].push_back(string_list[i]);

        }

        for (auto i: mp){
            res.push_back(i.second);
        }

        return res;
    }


    int main(){
        int n;
        cout<<"Enter the number of entries in array: ";
        cin>>n;

        vector<string>list(n);
        cout<<"Enter the strings: ";
        for(int i=0 ; i<n ; i++)
            cin>>list[i];

        vector<vector<string> >result = Anagrams(list);

        sort(result.begin() , result.end());

        for(int i=0 ; i<result.size(); i++){

            for(int j=0 ; j<result[i].size() ; j++){
                cout<< result[i][j]<<" ";
            }

            cout<<endl;
        }

    }
