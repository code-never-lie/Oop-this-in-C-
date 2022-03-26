this
- keyword
- object reference(address)
- c++ defined pointer

Why this pointer ?
- Data member are exclusive
- methods shared
- this should be appended before each non static    data  members

...................................
class A {
private:
  int d1;
public :
 void m1(){
     if (d1==10)
        cout<<"msg";<<endl;
 }
};
...............................
before  Compilation
class A {
private:
  int d1;
public :
 void m1(){
     if (this->d1==10)
        cout<<"msg";<<endl;
 }
};
........................................
Why we use/study this ?

1- same name parameters as data members

class A {
private:
  int d1;
public :
 A(int d1) {  this->d1=d1;}
 void m1(){
     if (this->d1==10)
        cout<<"msg";<<endl;
 }
};
...............................................
2- Copy Constructor
   -implicitly called at three places
    i) declaration time intialization
         Student ob(10,"Ahmed");
         Student ob2=ob;
    ii) Object passing by value
         
          void f(Student p) { ...}
          
          Student ob;
          f(ob);
   iii) return type as object
            Student f() {...return ob;}
       
            Student x;
            x=f();
   

- Copy copies(shallow) all object to other object
- By default written in clsses

- can be overridden
.................................................
class A {
public:
 A( ) {cout<<" normal constructor"<<endl;}
 A(A &p){cout<<" Copy constructor"<<endl;}
 void m1(A p) { cout<<" m1 method"<<endl;}
 A m2() { A ob;
         cout<<" m2 method"<<endl;
         return ob;}
};
void main() {
A ob1,ob3;
A ob2=ob1;
ob1.m1(ob3);
ob3=ob1.m2();
}

........................................................
Why override copyConstructor?
 - two methods for coping data
   i) Shallow Copy 
     copy only stack contents
     by default
   ii) Deep Copy
        copy all heap contents
        Should copy constructor
Memory Types
1- Static  static int a=5;
2- Stack   int a=5;
3- heap    int *p=new int[b];
4- register reg int a=5;
..................................................

class Array{
private:
int size;
int *a;
public :
  Array() { }
  Array(int s) {size=s;
             a=new int[size];
       for (int i=0;i<size;i++)
              a[i]=i+10;
  } 
 ~Array() {delete []a;}
void print () {
   for (int i=0;i<size;i++)
             cout<< a[i]<<endl;
}
  
};


void main() {
Array *p;

{ Array ob2(5);
  p=new Array(ob2);
}//expire ob2

p->print();

}
..........................................
It Will print Grabage
 Why?
See diagram on Board
.............................................
Solution : Implement Copy Construtor for deep copy
class Array{
private:
int size;
int *a;
public :
  Array() { }
  Array(Array &p) {
   size=p.size;
   a=new int[size];
   for (int i=0;i<size;i++)
        a[i]=p.a[i];
   cout<<"copy constructor"<<endl;

  }
  Array(int s) {size=s;
             a=new int[size];
       for (int i=0;i<size;i++)
              a[i]=i+10;
  } 
 ~Array() {delete []a;}
void print () {
   for (int i=0;i<size;i++)
             cout<< a[i]<<endl;
}
  
};


void main() {
Array *p;

{ Array ob2(5);
  p=new Array(ob2);
}//expire ob2

p->print();

}
................................................
