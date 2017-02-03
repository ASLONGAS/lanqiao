
/*************************************************************************
	> File Name: T379.cpp
	> Author: mxy
	> Mail: 491818544@qq.com
	> Created Time: 2017年02月03日 星期五 17时15分23秒
 ************************************************************************/
/**
问题描述
　　相信经过这个学期的编程训练，大家对于字符串的操作已经掌握的相当熟练了。今天，徐老师想测试一下大家对于字符串操作的掌握情况。徐老师自己定义了1,2,3,4,5这5个参数分别指代不同的5种字符串操作，你需要根据传入的参数，按照徐老师的规定，对输入字符串进行格式转化。
　　徐老师指定的操作如下：
　　1 表示全部转化为大写字母输出，如abC 变成 ABC
　　2 表示全部转换为小写字母输出，如abC变成abc
　　3 表示将字符串整个逆序输出，如 abc 变成 cba
　　4 表示将字符串中对应的大写字母转换为小写字母，而将其中的小写字母转化为大写字母输出，如 abC变成ABc
　　5表示将全部转换为小写字母，并将其中所有的连续子串转换为对应的缩写形式输出，比如abcD 转换为a-d，其次，-至少代表1个字母，既如果是ab，则不需要转换为缩写形式。
输入格式
　　一共一行，分别是指代对应操作的数字和字符串，两者以空格分隔，字符串全部由英文字母组成
输出格式
　　输出根据上述规则转换后对应的字符串
 **/
#include<iostream>
using namespace std;
string str;
int fun1(){
    int len=str.length();
    int i;
    for (i=0;i<len;i++){
        if (str[i]>='a'&&str[i]<='z'){
            str[i]=str[i]-'a'+'A';
        }
    }
    return 0;
}
int fun2(){
    int len=str.length();
    int i;
    for (i=0;i<len;i++){
        if (str[i]>='A'&&str[i]<='Z'){
            str[i]=str[i]-'A'+'a';
        }
    }
    return 0;
}
int fun3(){
    int len=str.length();
    int i;
    for (i=0;i<len/2;i++){
        char tmp=str[i];
        str[i]=str[len-i-1];
        str[len-i-1]=tmp;
    }
    return 0;
}
int fun4(){
    int len=str.length();
    int i;
    for (i=0;i<len;i++){
        if (str[i]>='A'&&str[i]<='Z'){
            str[i]=str[i]-'A'+'a';
        }else if(str[i]>='a'&&str[i]<='z'){

            str[i]=str[i]-'a'+'A';
        }
    } 
    return 0;
}
int fun5(){
    fun2();
    int len=str.length();
    int i,j;
    int cnt=0;
    for (i=0;i<len-1;){
        for (j=i+1;j<len;j++){
            if (str[j]-str[i]==j-i){
                cnt++;
                if (j==len-1&&cnt>=2){
                    str=str.replace(str.begin()+i+1,str.end()-1,"-");
                    cnt=0;
                    goto s;
                }else if(j==len-1){
                    goto s;
                }
            }else{
                if (cnt>=2){
                    str=str.replace(str.begin()+i+1,str.begin()+j-1,"-");
                    len=str.length();
                    i=i+2;
                    cnt=0;
                    break;
                }else{
                    i=j;
                    cnt=0;
                    break;
                }
            }
        }
    }
    s: return 0;
}
int main(){
    int choice;
    cin>>choice;
    cin>>str;
    switch(choice){
        case 1:fun1();break;
        case 2:fun2();break;
        case 3:fun3();break;
        case 4:fun4();break;
        case 5:fun5();break;
    }
    cout<<str<<endl;
    return 0;
}
