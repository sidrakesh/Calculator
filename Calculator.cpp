//Siddharth Rakesh
//11CS30036

#include<iostream>
#include<conio.h>
#include<cmath>
#include<cstddef>
#include<cstdlib>

using namespace std;

/************************Part A***********************************/

class Complex
{
   public:
   // CONSTRUCTOR
   // -----------

   // Overloads to
   Complex(double r = 0.0, double i = 0.0) : re_(r), im_(i) {};
   Complex(double);
   Complex();
   // Copy Constructor - needed for efficient parameter passing
   Complex(const Complex&); // Param cannot be changed (const)
   // DESTRUCTOR
   // ----------
   //~Complex(); // No virtual destructor needed
   // BASIC ASSIGNEMENT OPERATOR
   // --------------------------
   Complex& operator=(const Complex&);
   // BINARY ARITHMETIC OPERATORS
   // ---------------------------
   Complex operator+(const Complex &);
   Complex operator-(const Complex&);
   Complex operator*(const Complex&);
   Complex operator/(const Complex&);
   Complex operator/(double d);
   // UNARY ARITHMETIC OPERATORS
   // --------------------------
   Complex operator-(); // Operand 'this' implicit
   Complex operator+();
   Complex& operator--(); // Decrement real part by unity
   Complex& operator++(); // Increment real part by unity
   Complex operator--(int); // Decrement imaginary part by unity
   Complex operator++(int); // Increment imaginary part by unity
   // BINARY RELATIONAL OPERATORS
   // ---------------------------
   // Comparisons are based on the norms of the Complex numbers
   bool operator==(const Complex&);
   bool operator!=(const Complex&);
   bool operator<(const Complex&);
   bool operator<=(const Complex&);
   bool operator>(const Complex&);
   bool operator>=(const Complex&);
   // ADVANCED ASSIGNEMENT OPERATORS
   // ------------------------------
   Complex& operator+=(const Complex&);
   Complex& operator-=(const Complex&);
   Complex& operator*=(const Complex&);
   Complex& operator/=(const Complex&);
   // ARRAY INDEX OPERATOR
   // --------------------
   Complex const& operator[](unsigned int) const; // Read-only access
   Complex& operator[](unsigned int); // Read/Write access:
   // CONVERSION OPERATORS
   // --------------------
   double operator*() const; // Computes the norm
   // SPECIAL OPERATORS
   // -----------------
   Complex operator!() const; // Complex conjugate
   // BASIC I/O using FRIEND FUNCTIONS
   // --------------------------------
   friend ostream& operator<<(ostream&, const Complex&);
   friend istream& operator>>(istream&, Complex&);
   // DYNAMIC MEMORY OPERATORS
   // ------------------------
   void *operator new(size_t s);
   void operator delete(void *ptr) throw();
   // CONSTANTS OF DATATYPE
   // ---------------------
   static const Complex sc_cUnityR; // Defines 1+j0
   static const Complex sc_cUnityI; // Defines 0+j1
   static const Complex sc_cZero; // Defines 0+j0
   // COMPONENT FUNCTIONS
   //--------------------
   double GetReal() { return re_; }
   double GetImg() { return im_; }
   private:
   // DATA MEMBERS
   // ------------
   double re_; // The real part
   double im_; // The imaginary part
};

Complex& Complex::operator=(const Complex &other)
{
   re_ = other.re_;
   im_ = other.im_;
   return (*this);
}

Complex Complex::operator+( const Complex &other )
{
   return Complex( re_ + other.re_, im_ + other.im_ );
}

Complex Complex::operator-( const Complex &other )
{
   return Complex( re_ - other.re_, im_ - other.im_ );
}

Complex Complex::operator*( const Complex &other )
{
   return Complex( (re_ * other.re_) - (im_ * other.im_) , (re_ * other.im_) + (im_ * other.re_));
}

Complex Complex::operator/( const Complex &other )
{
   return Complex( ((re_ * other.re_) + (im_ * other.im_))/((other.re_*other.re_)+(other.im_*other.im_)), ((im_ * other.re_) - (re_ * other.im_))/((other.re_*other.re_)+(other.im_*other.im_)));
}

Complex Complex::operator/( double d)
{
   return Complex( (re_/d) , (im_/d) );
}

Complex Complex::operator+()
{
   return Complex( (1.0*re_) , (1.0*im_) );
}

Complex Complex::operator-()
{
   return Complex( (-1.0*re_) , (-1.0*im_) );
}

Complex& Complex::operator--()
{
   re_ = re_ - 1.0;
   return (*this);
}

Complex& Complex::operator++()
{
   re_ = re_ + 1.0;
   return (*this);
}

Complex Complex::operator--(int i)
{
   return Complex( re_,im_ - 1.0);
}

Complex Complex::operator++(int i)
{
   return Complex( re_,im_ + 1.0);
}

bool Complex::operator==(const Complex& other)
{
   return ((re_*re_+im_*im_)==(other.re_*other.re_+other.im_*other.im_));
}

bool Complex::operator!=(const Complex& other)
{
   return !((re_*re_+im_*im_)==(other.re_*other.re_+other.im_*other.im_));
}

bool Complex::operator<(const Complex& other)
{
   return ((re_*re_ + im_*im_)<(other.re_*other.re_+other.im_*other.im_));
}

bool Complex::operator<=(const Complex& other)
{
   return ((re_*re_ + im_*im_)<=(other.re_*other.re_+other.im_*other.im_));
}

bool Complex::operator>(const Complex& other)
{
   return ((other.re_*other.re_+other.im_*other.im_)<(re_*re_ + im_*im_));
}

bool Complex::operator>=(const Complex& other)
{
   return ((other.re_*other.re_+other.im_*other.im_)<=(re_*re_ + im_*im_));
}

Complex& Complex::operator+=(const Complex& other)
{
   re_ = re_ + other.re_;
   im_ = im_ + other.im_;
   return (*this);
}

Complex& Complex::operator-=(const Complex& other)
{
   re_ = re_ - other.re_;
   im_ = im_ - other.im_;
   return (*this);
}

Complex& Complex::operator*=(const Complex& other)
{
   re_ = (re_ * other.re_) - (im_ * other.im_);
   im_ = (re_ * other.im_) + (im_ * other.re_);
   return (*this);
}

Complex& Complex::operator/=(const Complex& other)
{
   re_ = ((re_ * other.re_) + (im_ * other.im_))/((other.re_*other.re_)+(other.im_*other.im_));
   im_ = ((im_ * other.re_) - (re_ * other.im_))/((other.re_*other.re_)+(other.im_*other.im_));
   return (*this);
}

const Complex& Complex::operator[](unsigned int i) const
{
    const Complex* temp = this+i;
    return *temp;
}
Complex& Complex::operator [](unsigned int i)
{
    Complex* temp = this+i;
    return *temp;
}

double Complex::operator*() const
{
   return sqrt(re_*re_+im_*im_);
}

Complex Complex::operator!() const
{
   return Complex(re_, -1.0*im_);
}

ostream& operator<<(ostream& os, const Complex& param)
{
    if(param.im_>=0)
    {
        if(param.re_!=0&&param.im_!=0)
            os << param.re_ << " + " << param.im_ << "i";
        else if(param.re_==0&&param.im_!=0)
            os << param.im_ << "i";
        else if(param.im_==0&&param.re_!=0)
            os << param.re_;
        else os <<"0";
    }
    else
    {
        if(param.re_!=0&&param.im_!=0)
            os << param.re_ << " - " << -1*param.im_ << "i";
        else if(param.re_==0&&param.im_!=0)
            os << param.im_ << "i";
        else if(param.im_==0&&param.re_!=0)
            os << param.re_;
        else os <<"0";
    }
    return os;
}

istream& operator>>(istream& is, Complex& param)
{
    string s,sr,sim;
    int i;
   is>>s;

   if(s[0]=='-'&&s[1]=='('&&s[s.length()-1]==')')
   {
      for(i=2;s[i]!='+'&&s[i]!='-'&&s[i]!='i'&&i<s.length()-1;i++)
      sr.push_back(s[i]);

      if(s[i]=='i')
          {
             param.im_ = atof(sr.c_str());

             if(s[2]=='i')
                 param.im_ = 1;
             param.re_ = 0;
          }
      else if(i==s.length()-1)
          {
             param.re_ = atof(sr.c_str());
             param.im_ = 0;
          }
      else
      {

        for(;i<s.length()-2;i++)
        sim.push_back(s[i]);

        param.re_ = atof(sr.c_str());
        param.im_ = atof(sim.c_str());

        if(param.im_==0&&s[s.length()-2]=='i'&&s[s.length()-3]=='+')
            param.im_ = 1;
        else if(param.im_==0&&s[s.length()-2]=='i'&&s[s.length()-3]=='-')
            param.im_ = -1;

        param = -(param);
      }
   }
   else
   {
      for(i=0;s[i]!='+'&&s[i]!='-'&&s[i]!='i'&&i<s.length();i++)
      sr.push_back(s[i]);

      if(s[i]=='i')
          {
             param.im_ = atof(sr.c_str());

             if(s[0]=='i')
                param.im_ = 1;

             param.re_ = 0;
          }
      else if(i==s.length())
          {
             param.re_ = atof(sr.c_str());
             param.im_ = 0;
          }

      else
      {

        for(;i<s.length()-1;i++)
        sim.push_back(s[i]);

        param.re_ = atof(sr.c_str());
        param.im_ = atof(sim.c_str());

        if(param.im_==0&&s[s.length()-1]=='i'&&s[s.length()-2]=='+')
            param.im_ = 1;
        else if(param.im_==0&&s[s.length()-1]=='i'&&s[s.length()-2]=='-')
            param.im_ = -1;
      }
   }
   return is;
}

void* Complex::operator new(size_t s)
{
   void *storage = malloc(s);
    if(NULL == storage) {
            throw "allocation fail : no free memory";
    }
}

void Complex::operator delete(void *ptr) throw()
{
   free(ptr);
}

/********************************Part B**************************************/

int main()
{
    char resb,ans;
    Complex a(0,0);
    Complex b(0,0);

    cout<<"Welcome to the calculator!!\n\nChoose any of the following options by pressing\n\nBinary operator: + to Add\nBinary operator: - to Subtract\nBinary operator: * to muliply\nBinary operator: / to divide\nBinary operator: e to get trichotomy of norm\n\nUnary operator: m to get modulus (norm)\nUnary operator: z to get conjugate\nUnary operator: n to get negative\n\nc to clear\n\n";

do{
    cin>>a;
    while(1)
    {
       resb = getch();
       cout<<resb<<"\n";

       if(resb == '=')
       {
         cout<<a<<"\n";
         continue;
       }
       else if(resb == 'm')
       {
         cout<<"= "<<*a<<"\n";
         continue;
       }
       else if(resb=='n')
       {
         cout<<"= "<<-(a)<<"\n";
         continue;
       }
       else if(resb=='z')
       {
         cout<<"= "<<!(a)<<"\n";
         continue;
       }
       else if(resb=='c')
         break;

       cin>>b;
       if(resb=='+')
       {
         a=a+b;
         cout<<"= "<<a<<"\n";
       }
       else if(resb=='-')
       {
         a=a-b;
         cout<<"= "<<a<<"\n";
       }
       else if(resb=='*')
       {
         a=a*b;
         cout<<"= "<<a<<"\n";
       }
       else if(resb=='/')
       {
         if(*b>0)
         {
          a=a/b;
          cout<<"= "<<a<<"\n";
         }
         else cout<<"\nMath error (cannot divide by zero)!!\n";
       }
       else if(resb=='e')
       {
         if(a<b)
            cout<<"\nnorm(a) is less than norm(b)\n";
         else if(a>b)
            cout<<"\nnorm(b) is less than norm(a)\n";
         else cout<<"\nnorm(a) is equal to norm(b)\n";
         break;
       }
   }
   cout<<"\nDo you want to continue?..(y/n)";
   ans = getch();
   cout<<ans<<"\n\n";
}while(ans=='y'||ans=='Y');

}

