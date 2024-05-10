#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string s;


  cout << "여러 줄의 문자열을 입력하세요. 입력의 끝은 '&' 문자입니다." << endl;
  getline(cin, s,'&');
  cin.ignore();
 

  string finder;
  string replace;
  cout << "find: ";
  cin >> finder;
  cout << "replace: ";
  cin >> replace;

  
size_t pos = 0;
while(true){
    pos = s.find(finder,pos);
    if(pos==-1)break;
    s.replace(pos,finder.size(),replace);
    pos += finder.size();
}

  cout << s << endl;

  return 0;
}
