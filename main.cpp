#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;

void replace2place(fstream& file,string outputFile);
int main(){
	fstream file("in.txt");

	replace2place(file,"out.txt");
	file.close();
	file.open("out.txt");

	map<string,size_t> word_count;
	string word;
	while(file>>word){
		auto ret=word_count.insert({word,1});
		if(!ret.second)
			++ret.first->second;
	}
	file.close();
	system("touch result.txt");
	file.open("result.txt");

	for(auto it=word_count.begin();it!=word_count.end();++it){
		if(it->first.size()>3){
		cout<<it->first<<"\t\t"<<it->second<<endl;
		file<<it->first<<"\t\t"<<it->second<<endl;
		}
	}
}


void replace2place(fstream& file,string outputFile){
	string strBuf;
	string str;
	while(file>>str){
		str.append(" ");
		strBuf+=str;
	}
	cout<<strBuf<<endl;
	for(size_t i=0;i<strBuf.size();++i){
		if(strBuf[i]>='A'&&strBuf[i]<='Z')
			strBuf[i]=strBuf[i]+'a'-'A';
		else if((strBuf[i]>='a'&&strBuf[i]<='z')||strBuf[i]=='\'')
			;
		else strBuf[i]=' ';
	}
	cout<<strBuf<<endl;

	system(("touch "+outputFile).c_str());
	fstream outFile(outputFile);
	outFile<<strBuf;
	outFile.close();
}
