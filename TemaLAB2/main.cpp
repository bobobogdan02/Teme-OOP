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


//5
struct nrComplex
{
    float a,b;
};
float modul(float x){
    return fabs(x);
}
float modul(nrComplex x){
    return sqrt((x.a*x.a)+(x.b*x.b));
}
//--5--


//6
template <typename T>
T maxim(T a, T b, T c){
        if(a > b)
            if(a > c)
                return a;
            else
                return c;
        else
            if(b > c)
                return b;
            else
                return c;
}
//--6--

//7
template <typename T>
void swap(T& x,T& y)
{
     T aux;
     aux=x;
     x=y;
     y=aux;
}
//--7--

int main()
{
    float n;
    bool isRoundedTo100;
    cin >> n ;
    cout << f(n,0) <<endl;
    cin >> student1.nota;
    cin >> student2.nota;
    cout << Max(student1.nota , student2.nota)<<endl;
    cout << maxim(12,13,14) << endl;
}
