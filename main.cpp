// FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: xxxxxx.cpp
// Program Description: ………
// Last Modification Date: xx/xx/xxxx
// Author1 and ID and Group: xxxxx xxxxx
// Author2 and ID and Group: xxxxx xxxxx
// Author3 and ID and Group: xxxxx xxxxx
// Teaching Assistant: xxxxx xxxxx
// Purpose:..........
#include <iostream>
#include <math.h>
#include<bits/stdc++.h>
#include <string.h>
#include<string>
#include <map>
using namespace std;
string o;

void AffineCipher(int a,int b,int c) {
    string s,ns;
    cout<<"enter your massage :\n";
    cin.clear(); cin.sync(); getline(cin,s);
    ns=s;
    for (int i=0 ;i<s.size();i++){
              if (s[i]>122 || s[i]<97){ns[i] = s[i];}
else {
        ns[i]=char(  ((( a *(towlower(s[i])-97) +b  )%26 + 26)%26)+97);
    }
    }
    cout<<" your massage after encryption is: "<<ns<<endl;

}

void AffineDecipher (int a,int b,int c) {
    string s,ns;
    cout<<"enter your massage : \n";
    cin.clear(); cin.sync(); getline(cin,s);
    ns=s;
    for (int i=0 ;i<s.size();i++){
              if (s[i]>122 || s[i]<97){ns[i] = s[i];}
              else {
        ns[i]= char ((( c *(  (towlower(s[i])-97)- b  )%26 + 26)%26)+97);
    }
    }
    cout<<" your massage after decryption is: "<<ns<<endl;
}
void Affine (){
int a=5,b=8,c=21;
int n;

    while (1){

    cout << "welcome to Affine cipher. \n What do you like to do today? \n 1- Cipher a message \n 2- Decipher a message \n 3- Change the cipher and decipher constants a,b and c \n type any other thing to go to ciphers main menu " << endl;
    cin>>o;
    n=o[0]-48;
    if (n==1) {AffineCipher(a,b,c);}
    else if (n==2) {AffineDecipher(a,b,c);}
    else if (n==3) {cout<<"enter a,b and c constants space-separated, cipher formula is (a x+ b)%26 and decipher formula is c*(y - b)%26 : "<<endl;
    while (1){
    cin>>a >> b>> c;
    if ((a * c) % 26 == 1 ) break;
    cout<<"non valid numbers please enter a,b and c constants again satisfying the condition (a * c) mod 26 = 1 :\n";
    }
    }
    else  { return; }
}
}
int shift(int x,int a){
    if (x<123  && (x+a)>122 ) return {x+a-26};
    else return (x+a);
}
int ShiftBack(int x,int a){
    if (x>96  && (x-a)<97 ) return {x-a+26};
    else return x-a;
}
void CaesarCipher(int a) {
    string s,ns;
    cout<<"enter your massage :\n";
    cin.clear(); cin.sync(); getline(cin,s);
    ns=s;
    for (int i=0 ;i<s.size();i++){
              if (towlower(s[i])>122 || towlower(s[i])<97){ns[i] = s[i];}
              else {
        ns[i]=char(  shift(towlower(s[i])-0,a)   );
              }
    }
    cout<<" your massage after encryption is: "<<ns<<endl;

}


void CaesarDecipher (int a) {
    string s,ns;
    cout<<"enter your massage : \n";
    cin.clear(); cin.sync(); getline(cin,s);
    ns=s;
    for (int i=0 ;i<s.size();i++){
        if (towlower(s[i])-0>122 || towlower(s[i])-0<97){ns[i] = s[i];}
        else {
        ns[i]= char(  ShiftBack(towlower(s[i])-0,a)   );
        }
    }
    cout<<" your massage after decryption is: "<<ns<<endl;
}
void Caesar (){
int a;
int n;
while (1){
        cout << "welcome to Caesar cipher. \n enter constant a, indicates how many times every letter will be shifted : " << endl;
    cin>>o;
    a=o[0]-48;
    if (a < 27 ) {break;}

    cout<<"non valid numbers please enter a constant again satisfying the condition (a < 27 ) :\n";

    }

    while (1){

     cout<<"What do you like to do today? \n 1- Cipher a message \n 2- Decipher a message \n type any other thing to go to ciphers main menu : "<<endl;
        cin>>o;
    n=o[0]-48;
    if (n==1) {CaesarCipher(a);}
    else if (n==2) {CaesarDecipher(a);}

    else  { return; }
}
}

void AtbashCipher(int x){

    string s,ns;
    cout<<"enter your massage : "<<endl;
    cin.clear(); cin.sync(); getline(cin,s);
    ns=s;
    for (int i=0 ; i<s.size();i++)
    {
      if ((towlower(s[i])-0)>122 || (towlower(s[i])-0)<97){ns[i] = char((s[i]));}
      else { ns[i]= char(towlower(s[i])+219-2*towlower(s[i])); }


    }
    if (x){    cout<<" your massage after Encryption is: "<<ns<<endl;}
    else { cout<<" your massage after Decryption is: "<<ns<<endl;}
}
void Atbash(){
    int n;
    while (1){
    cout<<"welcome in AtbashCipher, what do you want to do? \n 1- do encryption  \n 2- do Decryption  \n *type any other thing to go to ciphers main menu "<<endl;
    cin>>o;
    n=o[0]-48;
    if  (n==1){AtbashCipher(1);}
    else if  (n==2){AtbashCipher(0);}
    else {return;}
    }
}
void VignereDecipher(string s2){

    string s,ns;
    cout<<"enter the massage to be Decrypted :"<<endl;

      while (1){
      cin.clear(); cin.sync(); getline(cin,s);
        if (s.size()< 81) break;
        cout<<"too many characters , try again with maximum 80 characters : "<<endl;

    }


    ns=s;
    for (int i=0 ; i<s2.size();i++){s2[i]=toupper(s2[i]);}
    for (int i=0 ; i<s.size();i++)
    {
        if ((towlower(s[i])-0)>122 || (towlower(s[i])-0)<97){ns[i] = char(s[i]);}
      else{
      int a=0;
      if (   (toupper(s[i])-0) < (toupper( s2[i -(  s2.size()* ( (int) (i/s2.size())  ))])-0  ) ){a=26;}

      ns[i]= char(( ( toupper(s[i]) +a ) - toupper( s2[i -(  s2.size()* ( (int) (i/s2.size())  )   )   ]   ) )  +65 );
      }
    }
    cout<<" your massage after Decryption is: "<<ns<<endl;
}

void VignereCipher(string s2){

    string s,ns;
    cout<<"enter the massage to be encrypted :"<<endl;

      while (1){
        cin.clear(); cin.sync(); getline(cin,s);
        if (s.size()< 81) break;
        cout<<"too many characters , try again with maximum 80 characters : "<<endl;
    }
    ns=s;
    for (int i=0 ; i<s2.size();i++){s2[i]=toupper(s2[i]);}
    for (int i=0 ; i<s.size();i++)
    {
        if ((towlower(s[i])-0)>122 || (towlower(s[i])-0)<97){ns[i] = char(s[i]);}
      else{
      ns[i]= char(((toupper(s[i])  + toupper( s2[i -(  s2.size()* ( (int) (i/s2.size())  )   )   ] ))%26)+65);

      }
    }
    cout<<" your massage after encryption is: "<<ns<<endl;
}
void Vignere(){
    int n;
    string s;
            cout<<"welcome in VignereCipher, enter the keyword of encryption :"<<endl;
      while (1){
      cin.clear(); cin.sync(); getline(cin,s);
        if (s.size()<9) break;
        cout<<"too many charercters , try again with maximum 8 characters : "<<endl;
    }
    while (1){
    cout<<"what do you want to do? \n 1- do encryption  \n 2- do Decryption  \n *type any other thing to go to ciphers main menu "<<endl;
    cin>>o;
    n=o[0]-48;
    if  (n==1){VignereCipher(s);}
    else if  (n==2){VignereDecipher(s);}
    else {return;}
    }
}
void SimpleSubstitutionDecipher(char key [26]){

    string s,ns;
    cout<<"enter the massage to be Decrypted :"<<endl;

      while (1){
      cin.clear(); cin.sync(); getline(cin,s);
        if (s.size()< 81) break;
        cout<<"too many characters , try again with maximum 80 characters : "<<endl;

    }


    ns=s;
    for (int i=0 ; i<s.size();i++)
    {
        if ((towlower(s[i])-0)>122 || (towlower(s[i])-0)<97){ns[i] = char(s[i]);}
      else{
          ns[i]=char( key[tolower(s[i])-97] +97);

      }
    }
    cout<<" your massage after Decryption is: "<<ns<<endl;
}

void SimpleSubstitutionCipher( char key [26] ){

    string s,ns;
    cout<<"enter the massage to be encrypted :"<<endl;

      while (1){
      cin.clear(); cin.sync(); getline(cin,s);
        if (s.size()< 81) break;
        cout<<"too many characters , try again with maximum 80 characters : "<<endl;
    }
    ns=s;
    for (int i=0 ; i<s.size();i++)
    {
        if ((towlower(s[i])-0)>122 || (towlower(s[i])-0)<97){ns[i] = char(s[i]);}
      else{
      ns[i]= key[towlower(s[i])-97];

      }
    }
    cout<<" your massage after encryption is: "<<ns<<endl;
}
void SimpleSubstitution(){
    pair <char,bool> arr[26];
    for (int i=0 ; i<26; i++){arr[i].first=char(97+i);  arr[i].second=false;}
    char key [26];
    char key2 [26];
    int n;
            cout<<"welcome SimpleSubstitutionCipher, enter the keyword of encryption consisting of 5 characters :"<<endl;
            string s;
      while (1){
      cin.clear(); cin.sync(); getline(cin,s);
        if (s.size()==5) break;
        cout<<"non-valid number of characters , try again with exactly 5 characters : "<<endl;
    }
    for (int i=0 ; i<5; i++){    key[i]=towlower(s[i]);  arr[ (tolower(s[i])-97) ].second=true; key2[towlower(s[i])-97]=i;}
    int a=5;
    for (int i=0 ; i<26; i++){if (arr[i].second) {a--;continue;}key[ i+a ]=arr[i].first ; key2[arr[i].first-97]=i+a; }

    while (1){
    cout<<"what do you want to do? \n 1- do encryption  \n 2- do Decryption  \n *type any other thing to go to ciphers main menu "<<endl;
    cin>>o;
    n=o[0]-48;
    if  (n==1){SimpleSubstitutionCipher(key);}
    else if  (n==2){ SimpleSubstitutionDecipher(key2);}
    else {return;}
    }
}
void BaconianDecipher( ){

    string s,ns;
    cout<<"enter the massage to be Decrypted, note it should be only a combination of a and b :"<<endl;
    cin.clear(); cin.sync(); getline(cin,s);
    ns="";
                    for (int a=0;a<s.size();a+=6){
        if (  ! (s[a] == 'b' || s[a] == 'a' ) ){ ns+=s[a]; a-=5;}
        else {

            int x=0;
            for (int i=0; i<5; i++){if (s[i+a]=='b') x+=pow(2,4-i);}
            ns+=char(x+97);
        }
        }



    cout<<" your massage after Decryption is: "<<ns<<endl;
}

void BaconianCipher(  ){

    string s,ns="",x;
    cout<<"enter the massage to be encrypted :"<<endl;
    cin.clear(); cin.sync(); getline(cin,s);
    for (int i=0 ; i<s.size();i++)
    {

        if ((towlower(s[i])-0)>122 || (towlower(s[i])-0)<97){ns+=s[i];}
      else{
        x="12345";
        for (int d=4;d>=0;d--){
        int a=((towlower(s[i])-97)>>d);
        if (a&1) {x[4-d]='b';}
        else {x[4-d]='a';}
        }
      ns+= x +' ';

      }
    }
    cout<<" your massage after encryption is: "<<ns<<endl;
}
void Baconian(){
    int n;
    while (1){
    cout<<"welcome to BaconianCipher, what do you want to do? \n 1- do encryption  \n 2- do Decryption  \n *type any other thing to go to ciphers main menu "<<endl;
    cin>>o;
    n=o[0]-48;
    if  (n==1){BaconianCipher();}
    else if  (n==2){ BaconianDecipher();}
    else {return;}
    }
}
void PolybiusSquareDecipher(char arr [10][10]){

    string s,ns="";
    cout<<"enter the massage to be Decrypted :"<<endl;
    cin.clear(); cin.sync(); getline(cin,s);
    for (int i=0 ; i<s.size();i+=2)
    {
        if ((s[i]-0)>58 ||(s[i]-0)<49){ns+= s[i];  i--;}

      else{
          ns+= arr[ s[i]-48 ] [s[i+1]-48];
      }
    }
    cout<<" your massage after Decryption is: "<<ns<<endl;
}
void PolybiusSquareCipher( int arr  [26] ){

    string s,ns="";
    cout<<"enter the massage to be encrypted :"<<endl;
    cin.clear(); cin.sync(); getline(cin,s);
    for (int i=0 ; i<s.size();i++)
    {
        if ((towlower(s[i])-0)>122 || (towlower(s[i])-0)<97){ns+=s[i];}
      else{
      ns+= to_string(arr[toupper(s[i])-65]);

      }
    }
    cout<<" your massage after encryption is: "<<ns<<endl;
}
void PolybiusSquare(){
    char arr [10][10];
    int arrr [26];
    int n;
            cout<<"welcome SimpleSubstitutionCipher, enter the keyword of encryption consisting of 5 characters :"<<endl;
            string s;
      while (1){
    cin>>s;
        if (s.size()==5) break;
        cout<<"non-valid number of characters , try again with exactly 5 characters : "<<endl;
    }
    for (int a=0; a<5; a++) {
        for (int i=0 ; i<5 ; i++){
            arr[ s[a]-48][s[i]-48 ]=char(65+5*a+i);
            arrr[5*a+i]=(10* ( s[a]-48)  ) +  (s[i]-48 ) ;
        }

    }

    while (1){
    cout<<"what do you want to do? \n 1- do encryption  \n 2- do Decryption  \n *type any other thing to go to ciphers main menu "<<endl;
   cin>>o;
    n=o[0]-48;
    if  (n==1){PolybiusSquareCipher(arrr);}
   else if  (n==2){ PolybiusSquareDecipher(arr);}
    else {return;}
    }
}
 void MorseCodeDecipher(map <string,char> key){

    string s,ns="";
    cout<<"enter the massage to be Decrypted :"<<endl;
    cin.clear(); cin.sync(); getline(cin,s);
    string x="";
    for (int i=0 ; i<s.size();i++)
    {
      if (s[i]==' '){
       ns+=key[x];
       if (s[i+1]==' ') {ns+=' '; i+=2;}
       x="";
       continue;
      }
      x+=s[i];
    }
    ns+=key[x];
    cout<<" your massage after Decryption is: "<<ns<<endl;
}
void MorseCodeCipher( map <char,string> key ){

    string s,ns="";
    cout<<"enter the massage to be encrypted :"<<endl;
    cin.clear(); cin.sync(); getline(cin,s);
    for (int i=0 ; i<s.size();i++)
    {
        if( (towlower(s[i])-0)>122 || (towlower(s[i])-0) < 97   ) {ns+=key[s[i]]+' ';}
      else {
      ns+= key[toupper(s[i])]+' ';
      }

    }
    cout<<" your massage after encryption is: "<<ns<<endl;
}
void MorseCode(){
    int n;
    map  <char,string> key1 = {
    {' ',"  "},{',', "--..--"},{'.', ".-.-.-"},
     {'?', "..--.."},{'0', "-----"},{'1', ".----"},
      {'2', "..---"},{'3', "...--"},{'4', "....-"},
       {'5', "....."},{'6', "-...."},{'7', "--..."},
        {'8', "---.."},{'9', "----."},{'A', ".-"},
         {'B', "-..."},{'C', "-.-."},{'D', "-.."},
          {'E', "."},{'F', "..-."},{'G', "--."},
           {'H', "...."},{'I', ".."},{'J', ".---"},
            {'K', "-.-"},{'L', ".-.."},{'M', "--"},
             {'N', "-."},{'O', "---"},{'P', ".--."},
              {'Q', "--.-"},{'R', ".-."},{'S', "..."},
               {'T', "-"},{'U', "..-"},{'V', "...-"},
                {'W', ".--"},{'X', "-..-"},{'Y', "-.--"},{'Z', "--.."},
};
    map <string,char> key2  ;
    key2["--..--"]=','; key2["  "]=' ';
    key2[".-.-.-"]='.'; key2["..--.."]='?';

for (int i=0 ;i<(10);i++){
    key2[key1[char(i+48)]]=char(i+48);
}
for (int i=0 ;i<(26);i++){
    key2[key1[char(i+65)]]=char(i+65);
}

    while (1){
    cout<<"welcome to MorseCode, what do you want to do? \n 1- do encryption  \n 2- do Decryption  \n *type any other thing to go to ciphers main menu "<<endl;
   cin>>o;
    n=o[0]-48;
    if  (n==1){MorseCodeCipher(key1);}
    else if  (n==2){ MorseCodeDecipher(key2);}
    else {return;}
    }
}


  void XORDecipher(int k){
    string s,ns="";
    cout<<"enter the massage to be Decrypted ( in hexadecimal ) :"<<endl;
    cin.clear(); cin.sync(); getline(cin,s);
   for (int i=0 ; i<s.size()-1;i+=2)
    {
    string y="";y+=s[i];y+=s[i+1];
      int x=stoi(y,nullptr,16);
      x^=k;
      ns+=char(x);
    }
    cout<<" your massage after Decryption is: "<<ns<<endl;
}

void XORCipher( int k ){

    string s,ns;
    cout<<"enter the massage to be encrypted :"<<endl;
    cin.clear(); cin.sync(); getline(cin,s);
    ns=s;
    for (int i=0 ; i<s.size();i++)
    {
      int x=toupper(s[i])-0;
      x^=k;
      ns[i]=char(x+65);
    }
    cout<<" your massage after encryption is: "<<ns<<"  (Hexa: ";
    for(int i=0; i<ns.size();i++){ if ((ns[i]-65)<16) cout<<0;cout<<hex<<(ns[i]-65);} cout<<')'<<endl;
}
void XOR(){
    int n;
    string s;
    cout<<"welcome to XORCipher, enter the secret letter to start\n";
    while (1) {
        cin>>s;
        if (s.size()==1) break;
        cout<<"non-valid letter, please enter one valid letter\n"<<endl;
    }
    while (1){
    cout<<"what do you want to do? \n 1- do encryption  \n 2- do Decryption  \n *type any other thing to go to ciphers main menu "<<endl;
   cin>>o;
    n=o[0]-48;
    if  (n==1){XORCipher(toupper(s[0])-0);}
    else if  (n==2){ XORDecipher(toupper(s[0])-0);}
    else {return;}
    }
}
void rail_fence_enc(string s) {

    char arr[3][(s.length())];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < s.length(); j++)
            arr[i][j] = '\n';

    bool down = false;
    int row = 0, column = 0;

    for (int i = 0; i < s.length(); i++) {

        if (row == 0 || row == 2)
            down = !down;


        arr[row][column++] = s[i];

        if (down) row++;
        else row--;
    }


    string result;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < s.length(); j++)
            if (arr[i][j] != '\n')
                result.push_back(arr[i][j]);

    cout<<result<<endl<<endl;
}

void rail_fence_dec(string cipher) {

    char arr[3][cipher.length()];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < cipher.length(); j++)
            arr[i][j] = '\n';

    bool down;

    int row = 0, column = 0;

    for (int i = 0; i < cipher.length(); i++) {

        if (row == 0)
            down = true;
        if (row == 2)
            down = false;


        arr[row][column++] = '-';


        if (down) row++;
        else row--;
    }


    int n = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < cipher.length(); j++)
            if (arr[i][j] == '-' && n < cipher.length())
                arr[i][j] = cipher[n++];


    string result;

    row = 0, column = 0;
    for (int i = 0; i < cipher.length(); i++) {

        if (row == 0)
            down = true;
        if (row == 2)
            down = false;

        if (arr[row][column] != '-')
            result.push_back(arr[row][column++]);


        if (down) row++;
        else row--;
    }
     cout<<result<<endl<<endl;
}

void Rail_fence () {
    string message;
    int choice;
    while (1){
    cout << "ahlan ya habibi in Rail_fance , what do you like to do \n 1) Cipher \n 2) Decipher \n *press any other key to go back to Ciphers list\n" << endl;
    cin >> choice;
    if (choice == 1) {
        cout << "Enter a message to cipher: " << endl;
        cin.clear(); cin.sync();
        getline(cin, message);
        message.erase(remove(message.begin(), message.end(), ' '), message.end());
        rail_fence_enc(message);
    } else if (choice == 2) {
        cout << "Enter a message to decipher: " << endl;
        cin.clear(); cin.sync();
        getline(cin, message);
        rail_fence_dec(message);
    }
    else break;
    }
}

int main()
{
    int q;
    while (1){
    cout<<"Hello, chose your cipher method :\n 0-Affine \n 1-Caesar \n 2-Atbash \n 3-Vignere \n 4-Baconian \n 5-SimpleSubstitution \n 6-PolybiusSquare \n 7-MorseCode \n 8-XOR \n 9-Rail_fence \n \n*type any other thing to exit the program :"<<endl;
    cin>>o;
    q=o[0]-48;
    if (q==0){Affine();}
    else if (q==1){Caesar();}
    else if (q==2) {Atbash();}
    else if (q==3) {Vignere();}
    else if (q==4) {Baconian();}
    else if (q==5){SimpleSubstitution();}
    else if (q==6){PolybiusSquare();}
    else if (q==7){MorseCode();}
    else if (q==8){XOR();}
    else if (q==9){Rail_fence();}
    else {break;}
    }

    return 0;
}
