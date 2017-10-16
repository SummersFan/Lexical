#include<stdio.h>
#include<stdlib.h>
#include <string>
using namespace std;

char inputChar[200],token[8];
char ch;
int i,j,p;
int sum=0;
int s = 0;

int isNum(char ch){
	if('ch'>'0'&&ch<'9') return 1;
	return 0;
}

int isLetter(char ch){
	if(ch>'a'&&ch<'Z'||ch>'A'&&ch<'Z') return 2;
	return 0;
}

struct respons{  
		char *str;
		int num;
}; 

struct respons res[50];


void getRes(char *str,int num){
	res[s].str = str;
	res[s].num = num;
	s++;
}

main(){
	p=0;
	i=0;

	FILE *fp = fopen("analysis.txt","r"); 
	char *str;
	
	if(fp == NULL){
		printf("文件错误");
		return -1;
	}
	
	//获取文件长度
	fseek(fp,0,SEEK_END);
	int len = ftell(fp);
	fseek(fp,0,SEEK_SET);
	
	printf("%d\n",len);
	//将文件提取到字符串
	str = (char *)malloc(len*sizeof(char));
	if(str != NULL){
		fread(str,len*sizeof(char),1,fp);
		
	}
	//将字符串转化为数组

	
	for(int t = 0;t<len;t++){
		inputChar[t] = *(str++);
	}
	
	
//	printf("请输入字符串:\n");
//	do{
//		ch = getchar();
//		inputChar[p++] = ch;
//	}while(ch!='\n');
	
	
	i=0;/*初始化i*/
	
	while(inputChar[i]!=NULL){

		ch = inputChar[i]; 
		switch(ch){
			/*忽略非字符*/
			case ' ':
			case '\t':
			case '\r':
			case '\n':
				break;
				
			/*解析数字*/	
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':{
//				printf("%d  ",i);
				sum = 0;
				char k=i;
				int n;
				while(inputChar[k]!=' '){
					if(inputChar[k]<'z'&&inputChar[k]>'a'){
						n=0;
						break;
					}else{
						n=1;
					}
					k--;
				}

				if(n==1){
					while(ch>'0'&&ch<'9'){

					sum=sum*10+(ch-'0');
					i++;
					ch=inputChar[i];
				}
					if(inputChar[i]==' '||inputChar[i]=='\n'){
						getRes("数字",sum);
					}
				}
				
					
				break;
				
				
			}
			
			
			//标识符 
			case 'a':
			case 'b':{
				
				if((inputChar[i+1] == 'r')&&(inputChar[i+2] == 'e')&&(inputChar[i+3] == 'a')&&(inputChar[i+4] == 'k')&&!(inputChar[i-1] <'9'&&inputChar[i-1] >'0'||inputChar[i-1] <'z'&&inputChar[i-1] >'a')&&!(inputChar[i+5] <'9'&&inputChar[i+5] >'0'||inputChar[i+5] <'z'&&inputChar[i+5] >'a')){
					getRes("break",45);
					
				}
				break;
			}
			case 'c':{

				if((inputChar[i+1] == 'h')&&(inputChar[i+2] == 'a')&&(inputChar[i+3] == 'r')&&!(inputChar[i-1] <'9'&&inputChar[i-1] >'0'||inputChar[i-1] <'z'&&inputChar[i-1] >'a')&&!(inputChar[i+4] <'9'&&inputChar[i+4] >'0'||inputChar[i+4] <'z'&&inputChar[i+4] >'a')){
	
					getRes("char",30);
				}if((inputChar[i+1] == 'a')&&(inputChar[i+2] == 's')&&(inputChar[i+3] == 'e')&&!(inputChar[i-1] <'9'&&inputChar[i-1] >'0'||inputChar[i-1] <'z'&&inputChar[i-1] >'a')&&!(inputChar[i+4] <'9'&&inputChar[i+4] >'0'||inputChar[i+4] <'z'&&inputChar[i+4] >'a')){
	
					getRes("case",41);
				}
				break;
			}
			
			case 'd':{

				if((inputChar[i+1] == 'o')&&(inputChar[i+2] == 'u')&&(inputChar[i+3] == 'b')&&(inputChar[i+4] == 'l')&&(inputChar[i+5] == 'e')&&!(inputChar[i-1] <'9'&&inputChar[i-1] >'0'||inputChar[i-1] <'z'&&inputChar[i-1] >'a')&&!(inputChar[i+6] <'9'&&inputChar[i+6] >'0'||inputChar[i+6] <'z'&&inputChar[i+6] >'a')){
				
					getRes("double",29);
				}else if((inputChar[i+1] == 'o')&&!(inputChar[i-1] <'9'&&inputChar[i-1] >'0'||inputChar[i-1] <'z'&&inputChar[i-1] >'a')&&!(inputChar[i+2] <'9'&&inputChar[i+2] >'0'||inputChar[i+2] <'z'&&inputChar[i+2] >'a')){
					printf("<do,关键字,2>\n");
					getRes("do",36);
				
				}
				
				break;
			}
			
			case 'e':{

				if((inputChar[i+1] == 'l')&&(inputChar[i+2] == 's')&&(inputChar[i+3] == 'e')&&!(inputChar[i-1] <'9'&&inputChar[i-1] >'0'||inputChar[i-1] <'z'&&inputChar[i-1] >'a')&&!(inputChar[i+4] <'9'&&inputChar[i+4] >'0'||inputChar[i+4] <'z'&&inputChar[i+4] >'a')){
				
					getRes("else",39);
				}else if((inputChar[i+1] == 'n')&&(inputChar[i+2] == 'u')&&(inputChar[i+3] == 'm')&&!(inputChar[i-1] <'9'&&inputChar[i-1] >'0'||inputChar[i-1] <'z'&&inputChar[i-1] >'a')&&!(inputChar[i+4] <'9'&&inputChar[i+4] >'0'||inputChar[i+4] <'z'&&inputChar[i+4] >'a')){
			
					getRes("enum",47);
				}else if((inputChar[i+1] == 'x')&&(inputChar[i+2] == 't')&&(inputChar[i+3] == 'e')&&(inputChar[i+4] == 'r')&&(inputChar[i+5] == 'n')&&!(inputChar[i-1] <'9'&&inputChar[i-1] >'0'||inputChar[i-1] <'z'&&inputChar[i-1] >'a')&&!(inputChar[i+6] <'9'&&inputChar[i+6] >'0'||inputChar[i+6] <'z'&&inputChar[i+6] >'a')){
		
					getRes("extern",52);
				}
				break;
			}
			
			case 'f':{
				if((inputChar[i+1] == 'l')&&(inputChar[i+2] == 'o')&&(inputChar[i+3] == 'a')&&(inputChar[i+4] == 't')&&!(inputChar[i-1] <'9'&&inputChar[i-1] >'0'||inputChar[i-1] <'z'&&inputChar[i-1] >'a')&&!(inputChar[i+5] <'9'&&inputChar[i+5] >'0'||inputChar[i+5] <'z'&&inputChar[i+5] >'a')){
			
					getRes("float",28);
				}else if((inputChar[i+1] == 'o')&&(inputChar[i+2] == 'r')&&!(inputChar[i-1] <'9'&&inputChar[i-1] >'0'||inputChar[i-1] <'z'&&inputChar[i-1] >'a')&&!(inputChar[i+3] <'9'&&inputChar[i+3] >'0'||inputChar[i+3] <'z'&&inputChar[i+3] >'a')){
					getRes("for",46);
				}
				break;
			}
			
			case 'g':
			case 'h':
			
			case 'i':{
				if((inputChar[i+1] == 'f')&&!(inputChar[i-1] <'9'&&inputChar[i-1] >'0'||inputChar[i-1] <'z'&&inputChar[i-1] >'a')&&!(inputChar[i+2] <'9'&&inputChar[i+2] >'0'||inputChar[i+2] <'z'&&inputChar[i+2] >'a')){
			
					getRes("if",38);
				}else if((inputChar[i+1] == 'n')&&(inputChar[i+2] == 't')&&!(inputChar[i-1] <'9'&&inputChar[i-1] >'0'||inputChar[i-1] <'z'&&inputChar[i-1] >'a')&&!(inputChar[i+3] <'9'&&inputChar[i+3] >'0'||inputChar[i+3] <'z'&&inputChar[i+3] >'a')){
				
					getRes("int",27);
				}
				break;
			}
			
			case 'j':
            case 'k':
			
			case 'l':{
				if((inputChar[i+1] == 'o')&&(inputChar[i+2] == 'n')&&(inputChar[i+3] == 'g')&&!(inputChar[i-1] <'9'&&inputChar[i-1] >'0'||inputChar[i-1] <'z'&&inputChar[i-1] >'a')&&!(inputChar[i+4] <'9'&&inputChar[i+4] >'0'||inputChar[i+4] <'z'&&inputChar[i+4] >'a')){
				
					getRes("long",31);
				}
				break;
			}	
			
			case 'm':{
            	if((inputChar[i+1] == 'a')&&(inputChar[i+2] == 'i')&&(inputChar[i+3] == 'n')&&!(inputChar[i-1] <'9'&&inputChar[i-1] >'0'||inputChar[i-1] <'z'&&inputChar[i-1] >'a')&&!(inputChar[i+4] <'9'&&inputChar[i+4] >'0'||inputChar[i+4] <'z'&&inputChar[i+4] >'a')){
				
					getRes("main",57);
				}
				break;
			}
            case 'n':
            case 'o':
            case 'p':{
            	if((inputChar[i+1] == 'r')&&(inputChar[i+2] == 'i')&&(inputChar[i+3] == 'n')&&(inputChar[i+4] == 't')&&(inputChar[i+5] == 'f')&&!(inputChar[i-1] <'9'&&inputChar[i-1] >'0'||inputChar[i-1] <'z'&&inputChar[i-1] >'a')&&!(inputChar[i+6] <'9'&&inputChar[i+6] >'0'||inputChar[i+6] <'z'&&inputChar[i+6] >'a')){
				
					getRes("printf",55);
				}
				break;
			}
            case 'q':
            	
			case 'r':{
				if((inputChar[i+1] == 'e')&&(inputChar[i+2] == 't')&&(inputChar[i+3] == 'u')&&(inputChar[i+4] == 'r')&&(inputChar[i+5] == 'n')&&!(inputChar[i-1] <'9'&&inputChar[i-1] >'0'||inputChar[i-1] <'z'&&inputChar[i-1] >'a')&&!(inputChar[i+6] <'9'&&inputChar[i+6] >'0'||inputChar[i+6] <'z'&&inputChar[i+6] >'a')){
					
					getRes("return",42);
				}else if((inputChar[i+1] == 'e')&&(inputChar[i+2] == 'g')&&(inputChar[i+3] == 'i')&&(inputChar[i+4] == 's')&&(inputChar[i+5] == 't')&&(inputChar[i+6] == 'e')&&(inputChar[i+7] == 'r')&&!(inputChar[i-1] <'9'&&inputChar[i-1] >'0'||inputChar[i-1] <'z'&&inputChar[i-1] >'a')&&!(inputChar[i+8] <'9'&&inputChar[i+8] >'0'||inputChar[i+8] <'z'&&inputChar[i+8] >'a')){
				
					getRes("register",44);
				}
				break;
			}
			
			case 's':{
				if((inputChar[i+1] == 'h')&&(inputChar[i+2] == 'o')&&(inputChar[i+3] == 'r')&&(inputChar[i+4] == 't')&&!(inputChar[i-1] <'9'&&inputChar[i-1] >'0'||inputChar[i-1] <'z'&&inputChar[i-1] >'a')&&!(inputChar[i+5] <'9'&&inputChar[i+5] >'0'||inputChar[i+5] <'z'&&inputChar[i+5] >'a')){
				
					getRes("short",32);
				}else if((inputChar[i+1] == 't')&&(inputChar[i+2] == 'r')&&(inputChar[i+3] == 'u')&&(inputChar[i+4] == 'c')&&(inputChar[i+5] == 't')&&!(inputChar[i-1] <'9'&&inputChar[i-1] >'0'||inputChar[i-1] <'z'&&inputChar[i-1] >'a')&&!(inputChar[i+6] <'9'&&inputChar[i+6] >'0'||inputChar[i+6] <'z'&&inputChar[i+6] >'a')){
			
					getRes("struct",33);
				}else if((inputChar[i+1] == 'w')&&(inputChar[i+2] == 'i')&&(inputChar[i+3] == 't')&&(inputChar[i+4] == 'c')&&(inputChar[i+5] == 'h')&&!(inputChar[i-1] <'9'&&inputChar[i-1] >'0'||inputChar[i-1] <'z'&&inputChar[i-1] >'a')&&!(inputChar[i+6] <'9'&&inputChar[i+6] >'0'||inputChar[i+6] <'z'&&inputChar[i+6] >'a')){
				
					getRes("switch",40);
				}else if((inputChar[i+1] == 'i')&&(inputChar[i+2] == 'g')&&(inputChar[i+3] == 'n')&&(inputChar[i+4] == 'e')&&(inputChar[i+5] == 'd')&&!(inputChar[i-1] <'9'&&inputChar[i-1] >'0'||inputChar[i-1] <'z'&&inputChar[i-1] >'a')&&!(inputChar[i+6] <'9'&&inputChar[i+6] >'0'||inputChar[i+6] <'z'&&inputChar[i+6] >'a')){
		
					getRes("signed",49);
				}else if((inputChar[i+1] == 't')&&(inputChar[i+2] == 'a')&&(inputChar[i+3] == 't')&&(inputChar[i+4] == 'i')&&(inputChar[i+5] == 'c')&&!(inputChar[i-1] <'9'&&inputChar[i-1] >'0'||inputChar[i-1] <'z'&&inputChar[i-1] >'a')&&!(inputChar[i+6] <'9'&&inputChar[i+6] >'0'||inputChar[i+6] <'z'&&inputChar[i+6] >'a')){
					getRes("static",53);
				}else if((inputChar[i+1] == 'c')&&(inputChar[i+2] == 'a')&&(inputChar[i+3] == 'n')&&(inputChar[i+4] == 'f')&&!(inputChar[i-1] <'9'&&inputChar[i-1] >'0'||inputChar[i-1] <'z'&&inputChar[i-1] >'a')&&!(inputChar[i+5] <'9'&&inputChar[i+5] >'0'||inputChar[i+5] <'z'&&inputChar[i+5] >'a')){
				
					getRes("scanf",56);
				}
				break;
			}
			
			case 't':{
				if((inputChar[i+1] == 'y')&&(inputChar[i+2] == 'p')&&(inputChar[i+3] == 'e')&&(inputChar[i+4] == 'd')&&(inputChar[i+5] == 'e')&&(inputChar[i+6] == 'f')&&!(inputChar[i-1] <'9'&&inputChar[i-1] >'0'||inputChar[i-1] <'z'&&inputChar[i-1] >'a')&&!(inputChar[i+7] <'9'&&inputChar[i+7] >'0'||inputChar[i+7] <'z'&&inputChar[i+7] >'a')){
					
					getRes("typedef",48);
				}
				break;
			} 
			
			case 'u':{
				if((inputChar[i+1] == 'n')&&(inputChar[i+2] == 'i')&&(inputChar[i+3] == 'o')&&(inputChar[i+4] == 'n')&&!(inputChar[i-1] <'9'&&inputChar[i-1] >'0'||inputChar[i-1] <'z'&&inputChar[i-1] >'a')&&!(inputChar[i+5] <'9'&&inputChar[i+5] >'0'||inputChar[i+5] <'z'&&inputChar[i+5] >'a')){
					getRes("union",34);
				}else if((inputChar[i+1] == 'n')&&(inputChar[i+2] == 's')&&(inputChar[i+3] == 'i')&&(inputChar[i+4] == 'g')&&(inputChar[i+5] == 'n')&&(inputChar[i+6] == 'e')&&(inputChar[i+7] == 'd')&&!(inputChar[i-1] <'9'&&inputChar[i-1] >'0'||inputChar[i-1] <'z'&&inputChar[i-1] >'a')&&!(inputChar[i+8] <'9'&&inputChar[i+8] >'0'||inputChar[i+8] <'z'&&inputChar[i+8] >'a')){
					getRes("unsigned",35);
				}
				break;
			}
				
			case 'v':{
				if((inputChar[i+1] == 'o')&&(inputChar[i+2] == 'l')&&(inputChar[i+3] == 'a')&&(inputChar[i+4] == 't')&&(inputChar[i+5] == 'i')&&(inputChar[i+6] == 'l')&&(inputChar[i+7] == 'e')&&!(inputChar[i-1] <'9'&&inputChar[i-1] >'0'||inputChar[i-1] <'z'&&inputChar[i-1] >'a')&&!(inputChar[i+8] <'9'&&inputChar[i+8] >'0'||inputChar[i+8] <'z'&&inputChar[i+8] >'a')){
					getRes("volatile",54);
				}
				break;
			}
			
			case 'w':{
				if((inputChar[i+1] == 'h')&&(inputChar[i+2] == 'i')&&(inputChar[i+3] == 'l')&&(inputChar[i+4] == 'e')&&!(inputChar[i-1] <'9'&&inputChar[i-1] >'0'||inputChar[i-1] <'z'&&inputChar[i-1] >'a')&&!(inputChar[i+5] <'9'&&inputChar[i+5] >'0'||inputChar[i+5] <'z'&&inputChar[i+5] >'a')){
					getRes("while",37);
				}
				break;
			}
			
			case 'x':
			case 'y':
			case 'z':	
			
			case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'G':
            case 'H':
            case 'I':
            case 'J':
            case 'K':
            case 'L':
            case 'M':
            case 'N':
            case 'O':
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
            case 'V':
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
			
			/*解析字符*/
			
			case '.':{
				getRes(".",0);
				break;
			}
			case '+':{
				
				getRes("+",1);
				break;
			}
			case '-':{
				
				getRes("-",2);
				break;
			}
			case '*':{
				
				getRes("*",3);
				break;
			}
			case '/':{
				
				getRes("/",4);
				break;
			}
			case '(':{
				
				getRes("(",5);
				break;
			}
			case ')':{
				
				getRes(")",6);
				break;
			}
			case '[':{
				
				getRes("[",7);
				break;
			}
			case ']':{
				
				getRes("]",8);
				break;
			}
			case '{':{
				getRes("{",9);
				break;
			}
			case '}':{
				getRes("}",10);
				break;
			}
			case '&':{
				
				if((inputChar[i+1] == '&')&&(inputChar[i+2] !='&')){
					getRes("&&",12);
				}
				
				getRes("&",11);
				break;
			}
			case '<':{
				getRes("<",13);
				break;
			}
			case '>':{
				getRes(">",14);
				break;
			}
			case '=':{
				
				if((inputChar[i+1] == '=')&&(inputChar[i+2] != '=')){
					getRes("==",22);
				}
				
				getRes("=",15);
				break;
			}
			case ':':{
				getRes(":",16);
				break;
			}
			case '#':{
				getRes("#",17);
				break;
			}
			case '?':{
				getRes("?",18);
				break;
			}
			case '%':{
				getRes("%",19);
				break;
			}
			case '!':{
				getRes("!",20);
				break;
			}
			case '\'':{
				getRes("\'",21);
				break;
			}
			case '\"':{
				getRes("\"",10);
				break;
			}
			case '|':{
				
				if((inputChar[i+1] == '|')&&(inputChar[i+2] !='|')){
					getRes("&&",12);
				}
				
				getRes("|",11);
				break;
			}
			default:
				break;
					
		}
		i++;
		
	}
	
	i=0;
	
	
	
	

	while(res[i].str != NULL){
		printf("%s,%d\n",res[i].str,res[i].num);
		i++;
	}
} 
