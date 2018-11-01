#include <iostream>
#include <string.h>
#include <math.h>
#include <time.h>

using namespace std;



// 1
int f(float n , bool isRoundedTo100=false){
    if(isRoundedTo100==false)
        if( (int)(n+0.5)>int(n) )
            n=(int)n+1;
        else
            n=(int)n;
    else
        if((int)n%100<50)
            n=(int)n - (int)n%100;
        else
            n=(int)n + (100-(int)n%100);

    return n;
}
//--1--

//2
struct student{
    string nume;
    int nota;
}student1,student2;
template <typename student>
student Max(student a,student b) {
	return a < b ? b : a;
}
//--2--

//3
int f(int x){
    return sizeof(x);
}

int f(double x){
    return sizeof(x);
}

int f(char* x){

    return strlen(x);
}
//--3--



int main()
{
    float n;
    bool isRoundedTo100;
    cin>>n ;
    cout<<f(n,0)<<endl;
    cin>>student1.nota;
    cin>>student2.nota;
    cout << Max(student1.nota , student2.nota);
}
