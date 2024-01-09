#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <array>
#include <vector>
#include <sstream> 

using namespace std;

int main() {
  ifstream fin;
  ofstream fout1;
  ofstream fout2;
  ofstream fout3;
  ofstream fout4;
  ofstream fout5;
  ofstream fout6;
  ofstream fout7;
  ofstream fout8;
  ofstream fout9;
  ofstream fout11;
  ofstream fout21;
  ofstream fout31;
  ofstream fout41;
  ofstream fout51;
  ofstream fout61;
  ofstream fout71;
  ofstream fout81;
  ofstream fout91;
  string word;
  int num;
  string wrdArray[9999];
  string spcArray[9999];
  string rlscArray[9999];
  int numArray[9999] = {0};
  int i = 0;

  fin.open("tiny1.txt");
  while(getline(fin, word)){
    if(word == "-1"){
      break;
    }
    wrdArray[i] = word;
    i+=1;
  }

  fin.close();

  vector<string> sntceArray;
  
  for(int j = 0; j <= i; j++){
    for(int k = 0; k <= wrdArray[j].length(); k++){
      if(isupper(wrdArray[j][k])){
        wrdArray[j][k] = (char) tolower(wrdArray[j][k]);
      }
    }
  }

  int length = 0;

  
  for(int j = 0; j <= i; j++){
    string word = "";
    for (auto x : wrdArray[j]){
        if (x == ' ' || x == '.')
        {
          if(word != "" && isalpha(word[0])){
            length +=1;
          }
        }
      else{
            word = word + x;
        }
    }
  }

  int count = 0;
  
  for(int j = 0; j <= length; j++){
    string word = "";
    for (auto x : wrdArray[j])
    {
        if (x == ' ' || x == '.')
        {
            if(word != ""){
              spcArray[count] = word;
              word = "";
              count += 1;
            }
        }
        else{
            word = word + x;
        }
    }
  }


  int spc = 0;

  
  for(int j =0; j <= count; j++){
    if(find(rlscArray, rlscArray + count, spcArray[j]) != rlscArray + count){
      numArray[distance(rlscArray, find(rlscArray, rlscArray + spc, spcArray[j]))] += 1;
    }
    else if(!(find(rlscArray, rlscArray + count, spcArray[j]) != rlscArray + count)){
      rlscArray[spc] = spcArray[j];
      numArray[spc] += 1;
      spc += 1;
    }
    
  }
  
  int max = 0;
  string big;
  
  for(int j = 0; j <= spc; j++){
    if(numArray[j] > max){
      max = numArray[j];
      big = rlscArray[j];
    }
  }
  fout1.open("tiny1_1.txt");
  for(int j = 0; j < spc; j++){
    if(numArray[j] == max){
      fout1 << rlscArray[j] << ":" << numArray[j] << endl;
    }
  }
  fout1.close();

  fout11.open("out_tiny1_1.txt");
  for(int j = 0; j < spc; j++){
    if(numArray[j] == max){
      fout11 << rlscArray[j] << ":" << numArray[j] << endl;
    }
  }
  fout11.close();

  int twomax = 0;
  string twobig;
  
  for(int j = 0; j <= spc; j++){
    if(numArray[j] > twomax && numArray[j] < max){
      twomax = numArray[j];
      twobig = rlscArray[j];
    }
  }

  int threemax = 0;
  string threebig;
  
  for(int j = 0; j <= spc; j++){
    if(numArray[j] > threemax && numArray[j] < twomax){
      threemax = numArray[j];
      threebig = rlscArray[j];
    }
  }
  
  fout2.open("tiny1_2.txt");
  for(int j = 0; j < spc; j++){
    if(numArray[j] == threemax){
      fout2 << rlscArray[j] << ":" << numArray[j] << endl;
    }
  }
  fout2.close();

  fout21.open("out_tiny1_2.txt");
  for(int j = 0; j < spc; j++){
    if(numArray[j] == threemax){
      fout21 << rlscArray[j] << ":" << numArray[j] << endl;
    }
  }
  fout21.close();


  int sentenceCount = 0;
  
  for(int j = 0; j < i; j++){
    
      istringstream iss(wrdArray[j]);
      string token;
      while (std::getline(iss, token, '.')) {
        if (!token.empty()){
          sntceArray.push_back(token);
          sentenceCount++;
        }
      }
  }

  for(int j = 0; j < sentenceCount; j++){
    if(sntceArray[j][0] == ' '){
      sntceArray[j].replace(0, 1, "");
    }
  }

  for(int j = 0; j < sentenceCount; j++){
    wrdArray[j] = sntceArray[j];
  }

  for(int j = 0; j < sentenceCount; j++){
    wrdArray[j].insert(0, " ");
    wrdArray[j].insert(wrdArray[j].length(), " ");
  }

  int maxcount = 0;
  
  int numcount = 0;
  int pos = 0;
  int repeat_count = 0;
    
  vector<string> newword;
  vector<int> newnumber;
  vector<string> newsentence;
  
  for(int j = 0;  j < sentenceCount; j++){
    for(int k = 0; k < spc; k++){
      while ((pos = wrdArray[j].find(" " + rlscArray[k] + " ", pos)) != string::npos) {
      pos += rlscArray[k].size();
      numcount++;
      }
      if(numcount >= maxcount){
        newword.push_back(rlscArray[k]);
        newnumber.push_back(numcount);
        newsentence.push_back(sntceArray[j]);
        maxcount = numcount;
        repeat_count++;
      }
      numcount = 0;
      pos = 0;
    }
  }

  int sentenceMax = 0;

  for(int j = 0; j < repeat_count; j++){
    if(newnumber[j] > sentenceMax){
      sentenceMax = newnumber[j];
    }
  }
  
  fout3.open("tiny1_3.txt");
  
  for(int j = 0; j < repeat_count; j++){
    if(newnumber[j] == sentenceMax){
      fout3 << newword[j] << ":" << newnumber[j] << ":" << newsentence[j] << endl;
    }
  }

  fout3.close();

  fout31.open("out_tiny1_3.txt");
  
  for(int j = 0; j < repeat_count; j++){
    if(newnumber[j] == sentenceMax){
      fout31 << newword[j] << ":" << newnumber[j] << ":" << newsentence[j] << endl;
    }
  }

  fout31.close();

  string the = " the ";
  vector<int> thenumber;
  vector<string> thesentence;

  int maxthe = 0;
  int repeat_the = 0;
  for(int j = 0;  j < sentenceCount; j++){
    
      while ((pos = wrdArray[j].find(the, pos)) != string::npos) {
      pos += the.size();
      numcount++;
      }
      if(numcount >= maxthe){
        thenumber.push_back(numcount);
        thesentence.push_back(sntceArray[j]);
        maxthe = numcount;
        repeat_the++;
      }
      numcount = 0;
      pos = 0;
    
  }

  int theMax = 0;

  for(int j = 0; j < repeat_the; j++){
    if(thenumber[j] > theMax){
      theMax = thenumber[j];
    }
  }
  
  fout4.open("tiny1_4.txt");
  
      for(int j = 0; j < repeat_the; j++){
        if(thenumber[j] == theMax){
          fout4 << "the:" << thenumber[j] << ":" << thesentence[j] << endl;
        }
      }

  fout4.close();

  fout41.open("out_tiny1_4.txt");
  
      for(int j = 0; j < repeat_the; j++){
        if(thenumber[j] == theMax){
          fout41 << "the:" << thenumber[j] << ":" << thesentence[j] << endl;
        }
      }

  fout41.close();

  string of = " of ";
  vector<int> ofnumber;
  vector<string> ofsentence;

  int maxof = 0;
  int repeat_of = 0;
  for(int j = 0;  j < sentenceCount; j++){
    
      while ((pos = wrdArray[j].find(of, pos)) != string::npos) {
      pos += of.size();
      numcount++;
      }
      if(numcount >= maxof){
        ofnumber.push_back(numcount);
        ofsentence.push_back(sntceArray[j]);
        maxof = numcount;
        repeat_of++;
      }
      numcount = 0;
      pos = 0;
    
  }

  int ofMax = 0;

  for(int j = 0; j < repeat_of; j++){
    if(ofnumber[j] > ofMax){
      ofMax = ofnumber[j];
    }
  }
  
  fout5.open("tiny1_5.txt");
  
      for(int j = 0; j < repeat_of; j++){
        if(ofnumber[j] == ofMax){
          fout5 << "of:" << ofnumber[j] << ":" << ofsentence[j] << endl;
        }
      }

  fout5.close();

  fout51.open("out_tiny1_5.txt");
  
      for(int j = 0; j < repeat_of; j++){
        if(ofnumber[j] == ofMax){
          fout51 << "of:" << ofnumber[j] << ":" << ofsentence[j] << endl;
        }
      }

  fout51.close();

  string was = " was ";
  vector<int> wasnumber;
  vector<string> wassentence;

  int maxwas = 0;
  int repeat_was = 0;
  for(int j = 0;  j < sentenceCount; j++){
    
      while ((pos = wrdArray[j].find(was, pos)) != string::npos) {
      pos += was.size();
      numcount++;
      }
      if(numcount >= maxwas){
        wasnumber.push_back(numcount);
        wassentence.push_back(sntceArray[j]);
        maxwas = numcount;
        repeat_was++;
      }
      numcount = 0;
      pos = 0;
    
  }

  int wasMax = 0;

  for(int j = 0; j < repeat_was; j++){
    if(wasnumber[j] > wasMax){
      wasMax = wasnumber[j];
    }
  }
  
  fout6.open("tiny1_6.txt");
  
      for(int j = 0; j < repeat_was; j++){
        if(wasnumber[j] == wasMax){
          fout6 << "was:" << wasnumber[j] << ":" << wassentence[j] << endl;
        }
      }

  fout6.close();

  fout61.open("out_tiny1_6.txt");
  
      for(int j = 0; j < repeat_was; j++){
        if(wasnumber[j] == wasMax){
          fout61 << "was:" << wasnumber[j] << ":" << wassentence[j] << endl;
        }
      }

  fout61.close();

  string butthe = " but the ";
  vector<int> butthenumber;
  vector<string> butthesentence;

  int maxbutthe = 0;
  int repeat_butthe = 0;
  for(int j = 0;  j < sentenceCount; j++){
    
      while ((pos = wrdArray[j].find(butthe, pos)) != string::npos) {
      pos += butthe.size();
      numcount++;
      }
      if(numcount >= maxbutthe){
        butthenumber.push_back(numcount);
        butthesentence.push_back(sntceArray[j]);
        maxbutthe = numcount;
        repeat_butthe++;
      }
      numcount = 0;
      pos = 0;
    
  }

  int buttheMax = 0;

  for(int j = 0; j < repeat_butthe; j++){
    if(butthenumber[j] > buttheMax){
      buttheMax = butthenumber[j];
    }
  }
  
  fout7.open("tiny1_7.txt");
  
      for(int j = 0; j < repeat_butthe; j++){
        if(butthenumber[j] == buttheMax){
          fout7 << "but the:" << butthenumber[j] << ":" << butthesentence[j] << endl;
        }
      }

  fout7.close();

  fout71.open("out_tiny1_7.txt");
  
      for(int j = 0; j < repeat_butthe; j++){
        if(butthenumber[j] == buttheMax){
          fout71 << "but the:" << butthenumber[j] << ":" << butthesentence[j] << endl;
        }
      }

  fout71.close();

  string itwas = " it was ";
  vector<int> itwasnumber;
  vector<string> itwassentence;

  int maxitwas = 0;
  int repeat_itwas = 0;
  for(int j = 0;  j < sentenceCount; j++){
    
      while ((pos = wrdArray[j].find(itwas, pos)) != string::npos) {
      pos += itwas.size();
      numcount++;
      }
      if(numcount >= maxitwas){
        itwasnumber.push_back(numcount);
        itwassentence.push_back(sntceArray[j]);
        maxitwas = numcount;
        repeat_itwas++;
      }
      numcount = 0;
      pos = 0;
    
  }

  int itwasMax = 0;

  for(int j = 0; j < repeat_itwas; j++){
    if(itwasnumber[j] > itwasMax){
      itwasMax = itwasnumber[j];
    }
  }
  
  fout8.open("tiny1_8.txt");
  
      for(int j = 0; j < repeat_itwas; j++){
        if(itwasnumber[j] == itwasMax){
          fout8 << "it was:" << itwasnumber[j] << ":" << itwassentence[j] << endl;
        }
      }

  fout8.close();

  fout81.open("out_tiny1_8.txt");
  
      for(int j = 0; j < repeat_itwas; j++){
        if(itwasnumber[j] == itwasMax){
          fout81 << "it was:" << itwasnumber[j] << ":" << itwassentence[j] << endl;
        }
      }

  fout81.close();

  string inmy = " in my ";
  vector<int> inmynumber;
  vector<string> inmysentence;

  int maxinmy = 0;
  int repeat_inmy = 0;
  for(int j = 0;  j < sentenceCount; j++){
    
      while ((pos = wrdArray[j].find(inmy, pos)) != string::npos) {
      pos += inmy.size();
      numcount++;
      }
      if(numcount >= maxinmy){
        inmynumber.push_back(numcount);
        inmysentence.push_back(sntceArray[j]);
        maxinmy = numcount;
        repeat_inmy++;
      }
      numcount = 0;
      pos = 0;
    
  }

  int inmyMax = 0;

  for(int j = 0; j < repeat_inmy; j++){
    if(inmynumber[j] > inmyMax){
      inmyMax = inmynumber[j];
    }
  }
  
  fout9.open("tiny1_9.txt");
  
      for(int j = 0; j < repeat_inmy; j++){
        if(inmynumber[j] == inmyMax){
          fout9 << "in my:" << inmynumber[j] << ":" << inmysentence[j] << endl;
        }
      }

  fout9.close();

  fout91.open("out_tiny1_9.txt");
  
      for(int j = 0; j < repeat_inmy; j++){
        if(inmynumber[j] == inmyMax){
          fout91 << "in my:" << inmynumber[j] << ":" << inmysentence[j] << endl;
        }
      }

  fout91.close();

  //Start of tiny2

  ifstream fin2;
  ofstream fout12;
  ofstream fout22;
  ofstream fout32;
  ofstream fout42;
  ofstream fout52;
  ofstream fout62;
  ofstream fout72;
  ofstream fout82;
  ofstream fout92;
  ofstream fout121;
  ofstream fout221;
  ofstream fout321;
  ofstream fout421;
  ofstream fout521;
  ofstream fout621;
  ofstream fout721;
  ofstream fout821;
  ofstream fout921;
  string word2;
  int num2;
  string wrdArray2[9999];
  string spcArray2[9999];
  string rlscArray2[9999];
  int numArray2[9999] = {0};
  int i2 = 0;

  fin2.open("tiny2.txt");
  while(getline(fin2, word2)){
    if(word2 == "-1"){
      break;
    }
    wrdArray2[i2] = word2;
    i2+=1;
  }

  fin2.close();

  vector<string> sntceArray2;
  
  for(int j = 0; j <= i2; j++){
    for(int k = 0; k <= wrdArray2[j].length(); k++){
      if(isupper(wrdArray2[j][k])){
        wrdArray2[j][k] = (char) tolower(wrdArray2[j][k]);
      }
    }
  }

  int length2 = 0;

  
  for(int j = 0; j <= i2; j++){
    string word2 = "";
    for (auto x : wrdArray2[j]){
        if (x == ' ' || x == '.')
        {
          if(word2 != "" && isalpha(word2[0])){
            length2 +=1;
          }
        }
      else{
            word2 = word2 + x;
        }
    }
  }

  int count2 = 0;
  
  for(int j = 0; j <= length2; j++){
    string word2 = "";
    for (auto x : wrdArray2[j])
    {
        if (x == ' ' || x == '.')
        {
            if(word2 != ""){
              spcArray2[count2] = word2;
              word2 = "";
              count2 += 1;
            }
        }
        else{
            word2 = word2 + x;
        }
    }
  }


  int spc2 = 0;

  
  for(int j =0; j <= count2; j++){
    if(find(rlscArray2, rlscArray2 + count2, spcArray2[j]) != rlscArray2 + count2){
      numArray2[distance(rlscArray2, find(rlscArray2, rlscArray2 + spc2, spcArray2[j]))] += 1;
    }
    else if(!(find(rlscArray2, rlscArray2 + count2, spcArray2[j]) != rlscArray2 + count2)){
      rlscArray2[spc2] = spcArray2[j];
      numArray2[spc2] += 1;
      spc2 += 1;
    }
    
  }
  
  int max2 = 0;
  string big2;
  
  for(int j = 0; j <= spc2; j++){
    if(numArray2[j] > max2){
      max2 = numArray2[j];
      big2 = rlscArray2[j];
    }
  }
  fout12.open("tiny2_1.txt");
  for(int j = 0; j < spc2; j++){
    if(numArray2[j] == max2){
      fout12 << rlscArray2[j] << ":" << numArray2[j] << endl;
    }
  }
  fout12.close();

  fout121.open("out_tiny2_1.txt");
  for(int j = 0; j < spc2; j++){
    if(numArray2[j] == max2){
      fout121 << rlscArray2[j] << ":" << numArray2[j] << endl;
    }
  }
  fout121.close();
  
  int twomax2 = 0;
  string twobig2;
  
  for(int j = 0; j <= spc2; j++){
    if(numArray2[j] > twomax2 && numArray2[j] < max2){
      twomax2 = numArray2[j];
      twobig2 = rlscArray2[j];
    }
  }

  int threemax2 = 0;
  string threebig2;
  
  for(int j = 0; j <= spc2; j++){
    if(numArray2[j] > threemax2 && numArray2[j] < twomax2){
      threemax2 = numArray2[j];
      threebig2 = rlscArray2[j];
    }
  }
  
  fout22.open("tiny2_2.txt");
  for(int j = 0; j < spc2; j++){
    if(numArray2[j] == threemax2){
      fout22 << rlscArray2[j] << ":" << numArray2[j] << endl;
    }
  }
  fout22.close();

  fout221.open("out_tiny2_2.txt");
  for(int j = 0; j < spc2; j++){
    if(numArray2[j] == threemax2){
      fout221 << rlscArray2[j] << ":" << numArray2[j] << endl;
    }
  }
  fout221.close();


  int sentenceCount2 = 0;
  
  for(int j = 0; j < i2; j++){
    
      istringstream iss2(wrdArray2[j]);
      string token2;
      while (std::getline(iss2, token2, '.')) {
        if (!token2.empty()){
          sntceArray2.push_back(token2);
          sentenceCount2++;
        }
      }
  }

  for(int j = 0; j < sentenceCount2; j++){
    if(sntceArray2[j][0] == ' '){
      sntceArray2[j].replace(0, 1, "");
    }
  }

  for(int j = 0; j < sentenceCount2; j++){
    wrdArray2[j] = sntceArray2[j];
  }

  for(int j = 0; j < sentenceCount2; j++){
    wrdArray2[j].insert(0, " ");
    wrdArray2[j].insert(wrdArray2[j].length(), " ");
  }

  int maxcount2 = 0;
  
  int numcount2 = 0;
  int pos2 = 0;
  int repeat_count2 = 0;
    
  vector<string> newword2;
  vector<int> newnumber2;
  vector<string> newsentence2;
  
  for(int j = 0;  j < sentenceCount2; j++){
    for(int k = 0; k < spc2; k++){
      while ((pos2 = wrdArray2[j].find(" " + rlscArray2[k] + " ", pos2)) != string::npos) {
      pos2 += rlscArray2[k].size();
      numcount2++;
      }
      if(numcount2 >= maxcount2){
        newword2.push_back(rlscArray2[k]);
        newnumber2.push_back(numcount2);
        newsentence2.push_back(sntceArray2[j]);
        maxcount2 = numcount2;
        repeat_count2++;
      }
      numcount2 = 0;
      pos2 = 0;
    }
  }

  int sentenceMax2 = 0;

  for(int j = 0; j < repeat_count2; j++){
    if(newnumber2[j] > sentenceMax2){
      sentenceMax2 = newnumber2[j];
    }
  }
  
  fout32.open("tiny2_3.txt");
  
  for(int j = 0; j < repeat_count2; j++){
    if(newnumber2[j] == sentenceMax2){
      fout32 << newword2[j] << ":" << newnumber2[j] << ":" << newsentence2[j] << endl;
    }
  }

  fout32.close();

  fout321.open("out_tiny2_3.txt");
  
  for(int j = 0; j < repeat_count2; j++){
    if(newnumber2[j] == sentenceMax2){
      fout321 << newword2[j] << ":" << newnumber2[j] << ":" << newsentence2[j] << endl;
    }
  }

  fout321.close();

  string the2 = " the ";
  vector<int> thenumber2;
  vector<string> thesentence2;

  int maxthe2 = 0;
  int repeat_the2 = 0;
  for(int j = 0;  j < sentenceCount2; j++){
    
      while ((pos2 = wrdArray2[j].find(the2, pos2)) != string::npos) {
      pos2 += the2.size();
      numcount2++;
      }
      if(numcount2 >= maxthe2){
        thenumber2.push_back(numcount2);
        thesentence2.push_back(sntceArray2[j]);
        maxthe2 = numcount2;
        repeat_the2++;
      }
      numcount2 = 0;
      pos2 = 0;
    
  }

  int theMax2 = 0;

  for(int j = 0; j < repeat_the2; j++){
    if(thenumber2[j] > theMax2){
      theMax2 = thenumber2[j];
    }
  }
  
  fout42.open("tiny2_4.txt");
  
      for(int j = 0; j < repeat_the2; j++){
        if(thenumber2[j] == theMax2){
          fout42 << "the:" << thenumber2[j] << ":" << thesentence2[j] << endl;
        }
      }

  fout42.close();

  fout421.open("out_tiny2_4.txt");
  
      for(int j = 0; j < repeat_the2; j++){
        if(thenumber2[j] == theMax2){
          fout421 << "the:" << thenumber2[j] << ":" << thesentence2[j] << endl;
        }
      }

  fout421.close();

  string of2 = " of ";
  vector<int> ofnumber2;
  vector<string> ofsentence2;

  int maxof2 = 0;
  int repeat_of2 = 0;
  for(int j = 0;  j < sentenceCount2; j++){
    
      while ((pos2 = wrdArray2[j].find(of2, pos2)) != string::npos) {
      pos2 += of2.size();
      numcount2++;
      }
      if(numcount2 >= maxof2){
        ofnumber2.push_back(numcount2);
        ofsentence2.push_back(sntceArray2[j]);
        maxof2 = numcount2;
        repeat_of2++;
      }
      numcount2 = 0;
      pos2 = 0;
    
  }

  int ofMax2 = 0;

  for(int j = 0; j < repeat_of2; j++){
    if(ofnumber2[j] > ofMax2){
      ofMax2 = ofnumber2[j];
    }
  }
  
  fout52.open("tiny2_5.txt");
  
      for(int j = 0; j < repeat_of2; j++){
        if(ofnumber2[j] == ofMax2){
          fout52 << "of:" << ofnumber2[j] << ":" << ofsentence2[j] << endl;
        }
      }

  fout52.close();
  
  fout521.open("out_tiny2_5.txt");
  
      for(int j = 0; j < repeat_of2; j++){
        if(ofnumber2[j] == ofMax2){
          fout521 << "of:" << ofnumber2[j] << ":" << ofsentence2[j] << endl;
        }
      }

  fout521.close();

  string was2 = " was ";
  vector<int> wasnumber2;
  vector<string> wassentence2;

  int maxwas2 = 0;
  int repeat_was2 = 0;
  for(int j = 0;  j < sentenceCount2; j++){
    
      while ((pos2 = wrdArray2[j].find(was2, pos2)) != string::npos) {
      pos2 += was2.size();
      numcount2++;
      }
      if(numcount2 >= maxwas2){
        wasnumber2.push_back(numcount2);
        wassentence2.push_back(sntceArray2[j]);
        maxwas2 = numcount2;
        repeat_was2++;
      }
      numcount2 = 0;
      pos2 = 0;
    
  }

  int wasMax2 = 0;

  for(int j = 0; j < repeat_was2; j++){
    if(wasnumber2[j] > wasMax2){
      wasMax2 = wasnumber2[j];
    }
  }
  
  fout62.open("tiny2_6.txt");
  
      for(int j = 0; j < repeat_was2; j++){
        if(wasnumber2[j] == wasMax2){
          fout62 << "was:" << wasnumber2[j] << ":" << wassentence2[j] << endl;
        }
      }

  fout62.close();

  fout621.open("out_tiny2_6.txt");
  
      for(int j = 0; j < repeat_was2; j++){
        if(wasnumber2[j] == wasMax2){
          fout621 << "was:" << wasnumber2[j] << ":" << wassentence2[j] << endl;
        }
      }

  fout621.close();

  string butthe2 = " but the ";
  vector<int> butthenumber2;
  vector<string> butthesentence2;

  int maxbutthe2 = 0;
  int repeat_butthe2 = 0;
  for(int j = 0;  j < sentenceCount2; j++){
    
      while ((pos2 = wrdArray2[j].find(butthe2, pos2)) != string::npos) {
      pos2 += butthe2.size();
      numcount2++;
      }
      if(numcount2 >= maxbutthe2){
        butthenumber2.push_back(numcount2);
        butthesentence2.push_back(sntceArray2[j]);
        maxbutthe2 = numcount2;
        repeat_butthe2++;
      }
      numcount2 = 0;
      pos2 = 0;
    
  }

  int buttheMax2 = 0;

  for(int j = 0; j < repeat_butthe2; j++){
    if(butthenumber2[j] > buttheMax2){
      buttheMax2 = butthenumber2[j];
    }
  }
  
  fout72.open("tiny2_7.txt");
  
      for(int j = 0; j < repeat_butthe2; j++){
        if(butthenumber2[j] == buttheMax2){
          fout72 << "but the:" << butthenumber2[j] << ":" << butthesentence2[j] << endl;
        }
      }

  fout72.close();

  fout721.open("out_tiny2_7.txt");
  
      for(int j = 0; j < repeat_butthe2; j++){
        if(butthenumber2[j] == buttheMax2){
          fout721 << "but the:" << butthenumber2[j] << ":" << butthesentence2[j] << endl;
        }
      }

  fout721.close();

  string itwas2 = " it was ";
  vector<int> itwasnumber2;
  vector<string> itwassentence2;

  int maxitwas2 = 0;
  int repeat_itwas2 = 0;
  for(int j = 0;  j < sentenceCount2; j++){
    
      while ((pos2 = wrdArray2[j].find(itwas2, pos2)) != string::npos) {
      pos2 += itwas2.size();
      numcount2++;
      }
      if(numcount2 >= maxitwas2){
        itwasnumber2.push_back(numcount2);
        itwassentence2.push_back(sntceArray2[j]);
        maxitwas2 = numcount2;
        repeat_itwas2++;
      }
      numcount2 = 0;
      pos2 = 0;
    
  }

  int itwasMax2 = 0;

  for(int j = 0; j < repeat_itwas2; j++){
    if(itwasnumber2[j] > itwasMax2){
      itwasMax2 = itwasnumber2[j];
    }
  }
  
  fout82.open("tiny2_8.txt");
  
      for(int j = 0; j < repeat_itwas2; j++){
        if(itwasnumber2[j] == itwasMax2){
          fout82 << "it was:" << itwasnumber2[j] << ":" << itwassentence2[j] << endl;
        }
      }

  fout82.close();

  fout821.open("out_tiny2_8.txt");
  
      for(int j = 0; j < repeat_itwas2; j++){
        if(itwasnumber2[j] == itwasMax2){
          fout821 << "it was:" << itwasnumber2[j] << ":" << itwassentence2[j] << endl;
        }
      }

  fout821.close();

  string inmy2 = " in my ";
  vector<int> inmynumber2;
  vector<string> inmysentence2;

  int maxinmy2 = 0;
  int repeat_inmy2 = 0;
  for(int j = 0;  j < sentenceCount2; j++){
    
      while ((pos2 = wrdArray2[j].find(inmy2, pos2)) != string::npos) {
      pos2 += inmy2.size();
      numcount2++;
      }
      if(numcount2 >= maxinmy2){
        inmynumber2.push_back(numcount2);
        inmysentence2.push_back(sntceArray2[j]);
        maxinmy2 = numcount2;
        repeat_inmy2++;
      }
      numcount2 = 0;
      pos2 = 0;
    
  }

  int inmyMax2 = 0;

  for(int j = 0; j < repeat_inmy2; j++){
    if(inmynumber2[j] > inmyMax2){
      inmyMax2 = inmynumber2[j];
    }
  }
  
  fout92.open("tiny2_9.txt");
  
      for(int j = 0; j < repeat_inmy2; j++){
        if(inmynumber2[j] == inmyMax2){
          fout92 << "in my:" << inmynumber2[j] << ":" << inmysentence2[j] << endl;
        }
      }

  fout92.close();

  fout921.open("out_tiny2_9.txt");
  
      for(int j = 0; j < repeat_inmy2; j++){
        if(inmynumber2[j] == inmyMax2){
          fout921 << "in my:" << inmynumber2[j] << ":" << inmysentence2[j] << endl;
        }
      }

  fout921.close();
  
  return 0;
}
