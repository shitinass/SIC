#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<cmath>
#include<list>
#include<cstdlib>
using namespace std;

class TreeNode{
	public:
		string str;
		int key;
  		TreeNode  *leftChild=NULL;
  		TreeNode  *rightChild=NULL;
  		
};

class binary_tree{
//	friend class TreeNode;
	public:
		TreeNode *root;
		void binary_tree2(string s,int LOC);
		inorder_traversal(TreeNode *parent,int i);
		Search2(TreeNode *parent,string str2,int *loc);
		void setbinary(string a,int LOC);
		TreeNode *x;
		TreeNode *y;
};


void binary_tree::setbinary(string a,int LOC){
	root= new TreeNode;
	root->str=a;
	root->key=LOC;
	x=root;
	
}




void binary_tree::binary_tree2(string s,int LOC){
//	root= new TreeNode;
//	root->str=s;
//	root->key=LOC;
//	TreeNode *y;
//	TreeNode *x=root;
	
	
		while(x!=NULL){
			y=x;
			if(s>x->str){
				x=x->rightChild;
			
			}
			else if(s<x->str){
				x=x->leftChild;
			
			}
			else if(s==x->str){
			
				break;
			}
		}
		if(s<y->str){
			y->leftChild=new TreeNode;
			y->leftChild->str=s;
			y->leftChild->key=LOC;
		
		}
		else if(s>y->str){
			y->rightChild=new TreeNode;
			y->rightChild->str=s;
			y->rightChild->key=LOC;
		
		}
		
		
		x=root;
		y=NULL;
	
}


binary_tree::inorder_traversal(TreeNode *parent,int i){
	string s;
	int loc;
	if(parent!= NULL){
		inorder_traversal(parent->leftChild,i);
		s=parent->str;
		loc=parent->key;
		cout<<s<<" "<<loc<<endl;
	//	i++;
		inorder_traversal(parent->rightChild,i);
	}
}

binary_tree::Search2(TreeNode *parent,string str2,int *loc){
	string s;
	int ans=50;
	
	if(parent!= NULL){
		Search2(parent->leftChild,str2,loc);
		s=parent->str;
		
		
		if(s==str2){
		//	cout<<s<<" "<<str2<<" "<<endl;
			*loc=parent->key;
		}
	//	cout<<s<<" "<<loc<<endl;
	//	i++;
		Search2(parent->rightChild,str2,loc);
	}
}



int operand_check(string str){
	int n=str.size();
	string str1="";
	if(isdigit(str[0])==1){
		for(int k=0;k<n;k++){
		if(isdigit(str[k])==1){
			str1+=str[k];
		}
	}
		cout<<str1<<endl;
		int a=atoi(str1.c_str());
		return a;
	}
}




string operand(string str){
	int n=str.size(),i=-1,j=0;
	string str1="",str2="";
	for(int i=14;i<n;i++){
		if(str[i]!=' ')
		str1+=str[i];
	}
/*	while(j!=n){
		i++;
		str1+=str[j];
		if(str1[i]==' '){
			str1.clear();
			i=-1;
		}
		j++;
		
	}*/ 
	/*
	if(isdigit(str1[0])==1){
		for(int k=0;k<str1.size();k++){
		if(isdigit(str1[k])==1){
			str2+=str1[k];
		}
	}

	int a=atoi(str2.c_str());
	return a;
	}*/
	
	return str1;
	
}


string decToHex(int num)
{
    stringstream stream;
    stream << hex << num;
    return stream.str();
}



int HexToDec(string str1)
{	
	int a;
    stringstream stream;
    stream << hex << str1;
    stream >> a;
    return a;
}



bool symbol_check(string str){
	if(str[0]==' ') return false;
	else return true;
}

string getsym(string str){
	int n = str.size();
	string s="";
	for(int i=0;i<n;i++){
		if(str[i]==' ') break;
		else s+=str[i];
	}
	return s;
}


struct dict{
	public:
		string opkey;
		string opvalue;	 
};

dict optable[60]={
	{   "ADD", "18"},
	{   "ADDF", "58"},
	{   "ADDR", "90"},
	{   "AND", "40"},
    { "CLEAR", "B4"},
    {  "COMP", "28"},
    {  "COMPF", "88"},
    { "COMPR", "A0"},
    {   "DIV", "24"},
    {   "DIVF", "64"},
    {   "DIVR", "9C"},
    {   "FIX", "C4"},
    {   "FLOAT", "C0"},
    {   "HIO", "F4"},
    {     "J", "3C"},
    {   "JEQ", "30"},
    {   "JGT", "34"},
    {   "JLT", "38"},
    {  "JSUB", "48"},
    {   "LDA", "00"},
    {   "LDB", "68"},
    {  "LDCH", "50"},
    {  "LDF", "70"},
    {   "LDL", "08"},
    {   "LDT", "74"},
    {   "LDX", "04"},
    {   "LDS", "6C"},
    {  "LPS", "D0"},
    {   "UML", "20"},
    {   "MULF", "60"},
    {   "MULR", "98"},
    {   "NORM", "C8"},
    {   "OR", "44"},
    {    "RD", "D8"},
    {    "RMO", "AC"},
    {  "RSUB", "4C"},
    {  "SHIFTL", "A4"},
    {  "SHIFTR", "A8"},
    {  "SIO", "F0"},
    {  "SSK", "EC"},
    {   "STA", "0C"},
    {   "STB", "78"},
    {  "STCH", "54"},
    {   "STF", "80"},
    {   "STI", "D4"},
    {   "STL", "14"},
    {   "STSW", "E8"},
    {   "STT", "84"},
    {   "STS", "7C"},
    {   "STX", "10"},
    {   "SUB", "1C"},
    {   "SUBF", "5C"},
	{   "SUBR", "94"},
	{   "SVC", "B0"},
    {    "TD", "E0"},
    {   "TIO", "F8"},
    {   "TIX", "2C"},
    {  "TIXR", "B8"},
    {    "WD", "DC"},

};

struct Node{
    string key;                    
    string value;                    
    Node *next;                 

    Node():key(""),value(""),next(0){};
	Node(string Key, string Value):key(Key),value(Value),next(0){};

};



class HashChainNode{
	friend struct dict;
	friend struct Node;
    
public:
	int size,                
        count;                
    Node **table;              
	
	
    int HashFunction(string str);      

	int FirstHashing(string str);
    HashChainNode(){};
    HashChainNode(int m):size(m),count(0){
        table = new Node *[size];           
        for (int i = 0; i < size; i++) {    
            table[i] = 0;                   
        }
    }

    void Insert();        

    string Search(string str);
    void ShowTable();
};

void HashChainNode::Insert(){

    for(int i=0;i<59;i++){
		int index=HashFunction(optable[i].opkey);

    
    	Node *newNode = new Node (optable[i].opkey,optable[i].opvalue);       

    	// push_front()
    	if (table[index] == NULL) {           
        table[index] = newNode; 
   	 	}
    	else {
    	      
        Node *next = table[index]->next;  
        table[index]->next = newNode;
        newNode->next = next;		
    	}	
}
}

 
string HashChainNode::Search(string str){

    int index = HashFunction(str);      
    Node *current = table[index];       

    while (current != NULL) {           
        if ( current->key == str) {
            return current->value;
        }
        current = current->next;
    }
    return "NOT FOUND";
}



void HashChainNode::ShowTable(){

    for (int i = 0; i < size; i++) {    
    //    cout << "#slot#" << i << ": ";
        Node *current = table[i];
        while (current != NULL) {
            cout << "(" << current->key << "," << hex << current->value << ") ";
            current = current->next;
        }
        cout << endl;
    }
    cout << endl;
}


int HashChainNode::FirstHashing(string key_str){
   
												  	      // division Method
    int exp = 9,         
        key_int = 0,
        p = 1;

    for (int i = (int)key_str.size()-1; i >= 0; i--) {
        key_int += key_str[i]*p;
        p *= exp;
    }
    return key_int;
}

int HashChainNode::HashFunction(string key_str){

   
   return (FirstHashing(key_str) % this->size);     // division Method
}



string getopcode(string str){
	int n=str.size()-operand(str).size();
	int n1=getsym(str).size();
	
	string str1="";
	if(str[0]==' '){
		for(int i=0;i<=13;i++){
			if(str[i]!=' ') 
			str1+=str[i];
		}
	}
	else{
		for(int j=n1;j<=13;j++){
			if(str[j]!=' ')
			str1+=str[j];
		}
	}
	return str1;
}


string getopcode2(string str);
string getsym2(string str);
string getoperand2(string str);
string getloc(string str);


int main(){
	// PASS 1
	HashChainNode hash1(61);
	int start_addr,LOC=0,check,n=0,min=999999,max=0,len;
	string str,oper,oper1,q,w,output;
	ifstream ifs;
	ofstream ofs;
	stringstream ss;
	binary_tree data;
	hash1.Insert();
	hash1.ShowTable();
	ifs.open("input.txt");
	ofs.open("output.txt");
	
	
	while(getline(ifs,str)){
		q="";
		
		
		if(str.find("START")!=string::npos){
			oper=operand(str);                 //OPERAND:原始敘述 
			LOC=HexToDec(oper);
			cout<<"LOCCTR = "<<hex<<LOC<<endl;
		//	continue;
		}
		//else LOC=0;
		check=symbol_check(str);
//													SYMTAB:符號表，用來存放程式中標記符號的值(位址)
//													OPTAB:運算碼表，用來查詢助憶碼，並將其轉譯成對應的機器語言 
		string test=getopcode(str);				//  LOCCTR:程式位置計數器，此變數用來協助進行位址的分配 
		if(hash1.Search(test)!="NOT FOUND" || test=="WORD"|| test=="START"|| test=="BYTE"|| test=="RESW"|| test=="RESB" ||test=="END"){
	
			
			if(check){
															
				if(n==0){
	            n++;
				data.setbinary(getsym(str),LOC);   			  //	在符號表插入(LABEL,LOC) 
				}	
				else data.binary_tree2(getsym(str),LOC);
			//	data.inorder_traversal(data.root,0);			
			}
			
			w=operand(str);
			ofs<<hex<<LOC<<"  "<<str<<endl;
			if(test=="RESW"){
				LOC=LOC+3*atoi(operand(str).c_str());
			}
			else if(test=="RESB"){
				int oow=atoi(operand(str).c_str());
				LOC=LOC+oow;
			}
			else if(test=="BYTE"){
				if(w[0]=='C'){
					//string r="'";
					for(int i=1;i<w.size();i++){
						if(w[i]!='\'') q+=w[i];
					}
					
					LOC=LOC+q.size();
				}
				if(w[0]=='X'){
					//string r="'";
					for(int i=1;i<w.size();i++){
						if(w[i]!='\'') q+=w[i];
					}
					
					LOC=LOC+(q.size()/2);
				} 
			}
			else if(test!="START" && test!=""){
				if(test=="END")break;
				else LOC=LOC+3;
			}
			
		//	cout<<LOC<<endl;
		
			
		}
		else{
			cout<<"opcode輸入錯誤"<<endl;
			ofs<<"ERROR"<<endl;
			break; 
		}
		if(LOC<min) min=LOC;
		if(LOC>max) max=LOC;
	}
	data.inorder_traversal(data.root,0);
	len=max-min;
	
	//PASS 2
	ifstream ifs2;
	ofstream ofs2,ofs3;
	int tx=0;
	bool f=0;
	string purpose="",zero="T";
	ifs2.open("output.txt");
	ofs2.open("output2.txt");
	ofs3.open("record.txt");
	while(getline(ifs2,str)){
		if(str=="ERROR"){
			ofs2<<"ERROR";
			ofs3<<"ERROR";
			break;
		}
		int opervalue=0;
		string test=getopcode2(str);
		if(test=="START"){
			ofs2<<str<<endl;
			ofs3<<"H"<<getsym2(str)<<hex<<" 00"<<min<<"00"<<len<<endl;
		}
		string sav="";
		string oper=getoperand2(str);
		string object="";
		if(hash1.Search(test)!="NOT FOUND" || test=="WORD" || test=="BYTE"|| test=="RESW"|| test=="RESB"){
			string op_value=hash1.Search(test);
			data.Search2(data.root,oper,&opervalue);
		//	cout<<oper;
			if(opervalue!=0){
				object+=op_value;
				sav=decToHex(opervalue);
				object+=sav;
			//	if(object[0]=='0' && object.size()==5) object="0"+object;
				ofs2<<str<<"   "<<object<<endl;
			}
			
			else if(oper[oper.size()-1]=='X' && oper[oper.size()-2]==','){
				oper.pop_back();oper.pop_back();
				data.Search2(data.root,oper,&opervalue);
				object+=op_value;
				sav=decToHex(opervalue+32768);
				object+=sav;
				ofs2<<str<<"   "<<object<<endl;
			}
			
			else if(test=="BYTE" || test=="WORD"){
				if(test=="WORD"){
					int word=atoi(oper.c_str());
					string words=decToHex(word);
					for(int i=1;i<=6-words.size();i++){
						object+="0";
					}	
					object+=words;
					ofs2<<str<<"   "<<object<<endl;
				}
				if(test=="BYTE"){
					if(oper[0]=='C'){
						for(int i=2;i<=oper.size()-2;i++){
							object+=decToHex((int)(oper[i]));
						}
						ofs2<<str<<"   "<<object<<endl;
					}
					if(oper[0]=='X'){
						for(int i=2;i<=oper.size()-2;i++){
							object+=oper[i];
						}
						ofs2<<str<<"   "<<object<<endl;
					}
				}
			}
			else if(test=="RSUB"){
				object="4C0000";
				ofs2<<str<<"   "<<object<<endl;
			}
			else if(test=="RESW"||test=="RESB"){
				ofs2<<str<<endl; 
			}
			
			if(test!="BYTE" && test!="WORD" && test!="RESW" && test!="RESB" && test!="START" && test!="RSUB" && opervalue==0){
			//	cout<<test<<endl;
				ofs2<<"ERROR"<<endl;
				ofs3<<"ERROR"<<endl;
				break; 
			}
			
			
			if(object!=""){
				if(f==0){
					string sav=getloc(str);
					for(int i=0;i<6-sav.size();i++){
					zero+="0";
					}
					zero+=sav;
				//	cout<<zero<<endl;
					f=true;
				}
				if(test=="BYTE"){
					purpose+=object;
					oper=getoperand2(str);
					string sav="";
					if(oper[0]=='C'){
						for(int i=2;i<=4;i++){
							if(oper[i]!='\'')sav+=oper[i];
						}
					//	cout<<tx<<": "<<test<<" and "<<object<<" ";
						tx+=sav.size();
						
					}
					if(oper[0]=='X'){
						for(int i=2;i<=5;i++){
							if(oper[i]!='\'')sav+=oper[i];
						}
					//	cout<<tx<<": "<<test<<" and "<<object<<" ";
						tx+=sav.size()/2;
						
					}
				}
				
				else if(f==1){
					if(tx+3<=30){
					//	cout<<tx<<": "<<test<<" and "<<object<<" ";
						tx+=3;
						
						purpose+=object;
					}
					else{
						ofs3<<zero<<decToHex(tx)<<purpose<<endl;
						tx=0;
						purpose="";purpose+=object;
					//	cout<<tx<<": "<<test<<" and "<<object<<" ";
						tx+=3;
					//	f=0;
						zero="T00"+getloc(str);
					}
				}
				
			}
			if(test=="RESB"){
				ofs3<<zero<<decToHex(tx)<<purpose<<endl;
				tx=0;
				purpose="";
				f=0;
				zero="T";
			}
			
		}
		
		
		
		if(test=="END"){
			if(tx<16)ofs3<<zero<<"0"+decToHex(tx)<<purpose<<endl;
			else ofs3<<zero<<decToHex(tx)<<purpose<<endl;
			ofs3<<"E00"<<min<<endl;
			ofs2<<str<<endl;
			break;
		}
	}
		
	return 0;
}


string getopcode2(string str){
	string str1="";
	for(int i=14;i<=19;i++){
		if(str[i]!=' ') str1+=str[i];
	}
	return str1;
}
string getsym2(string str){
	string str1="";
	for(int i=5;i<=12;i++){
		if(str[i]!=' ')str1+=str[i];
	}
	return str1;
}


string getoperand2(string str){
	string str1="";
	for(int i=21;i<=28;i++){
		if(str[i]!=' ')str1+=str[i];
	}
	return str1;
}

string getloc(string str){
	string s="";
	for(int i=0;i<=5;i++){
		if(str[i]!=' ') s+=str[i];
	}
	return s;
}






