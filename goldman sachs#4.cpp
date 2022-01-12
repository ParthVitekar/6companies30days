 /*Given a string, Your task is to  complete the function encode that returns the run length encoded string for the given string.
eg if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6″.  */

 #include <bits/stdc++.h>

using namespace std;

string encode(string src)
{
  //Your code here
 string str = "";
 str= str + src[0];
int count = 1;

 for (int i = 1 ; i < src.length() ; i ++){
     if(src[i] == src[i-1]){
         count = count +1;
     }
     else {
         str = str + to_string(count);
         str = str + src[i];
         count = 1;
     }
 }
    return str+ to_string(count);
}

int main(){
    string src;
    cin>>src;

    string res = encode(src);

    cout<<res<<endl;

    return 0;
}
