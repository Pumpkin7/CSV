#include <iostream>
#include <string>
#include <fstream>
#include <boost/filesystem.hpp>
#include "sha224.h"
using namespace std;
using namespace boost::filesystem;

 
path main_path_get(){
	cout << "Enter your path" << endl;
	path p;
	string s;
	getline(cin, s);
	p = s;
	while (!is_directory(p)){
		cout << "Error: " << p << " is not valid path"<< endl
			<<"Enter valid path" << endl ;
		getline(cin, s);
		p = s;
	}
	return p;
} 
string sha224constructor(path p){
ifstream o;

o.open(p.string(),ifstream::in);
				string text;
				while(!o.eof()){
				text+=o.get();
				}
string a=sha224(text);
o.close();
return a;
};
 
void dir_runner(path main_p){
	ofstream o;
	o.open("output.csv",ofstream::out);
	o<<"File Name,File Size,File Path,Hash sum Keccak224"<<endl;
	for (recursive_directory_iterator dir_itr(main_p);
		dir_itr != recursive_directory_iterator();
		++dir_itr)
	{
		if (is_regular_file(*dir_itr)){
				path p = *dir_itr;
 
				o<<p.filename().string()<<",";
				o<< file_size(p) <<",";
				o<< p.string()<<",";
				o<<sha224constructor(p)<<endl;
 
 
 
 
		}
	}
	o.close();
}
 
 
int main(){
	path p=main_path_get();
	dir_runner(p);
	system("pause");
	return 0;
}