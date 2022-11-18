#include <iostream>
#include<fstream>
#include<cmath>
using namespace std;
class triangle
{
private:
    int a;
    int b;
    int c;

public:
    triangle(int z, int x, int v)
    {
        a = z;
        b = x;
        c = v;
    }

    void set_size(int z, int x, int v)
    {
        a = z;
        b = x;
        c = v;
    }
    void vivod()
    {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "c = " << c << endl;
    }
    double line()
    {
        return(a + b + c);
    }
    void perimetr()
    {
        cout << "perimetr raven = " << line() << endl;
    }

    void space()
    {
        cout << "ploshchad' ravna = " << sqrt((line() / 2) * ((line() / 2) - a) * ((line() / 2) - b) * ((line() / 2) - c)) << endl;;
    }

    void is_real()
    {
        bool trueQ = false;
        if (a <= b + c && b <= a + c && c <= a + b)
        {
            trueQ = true;
            cout << "triygolnik cywestvyet" << endl;

        }
        else
        {
            cout << "nema takih treygolnikov" << endl;
            exit(228);
        }
    }
    void fout()
    {

        ofstream ff;
        ff.open("file2.txt");
        ff << a << endl;
        ff << b << endl;
        ff << c << endl;
            ff.close();

    }
    void fin()
    {

        ifstream ff;
        ff.open("file1.txt");
        int z, x, v;
        ff >> z >> x >> v;
        ff.close();
        set_size(z, x, v);
    }

    triangle& operator ++ (int val)
    {
        triangle tmp(*this);

        this->a++;
        this->b++;
        this->c++;
        cout << "++" << endl;
        return (*this);
    }
    triangle& operator -- (int ff)
    {
        triangle tmp(*this);
        this->a--;
        this->b--;
        this->c--;
        cout << "--" << endl;
        return(*this);
    }
    triangle& operator *(int k)
    {
        triangle tmp(*this);
        a *= k;
        b *= k;
        c *= k;
        cout << "*" << k << endl;
        return(*this);
    }

};
int main()
{
    triangle tri(2, 2, 2); // create not null triangle
                            //int z,x,v
                           //tri.set_size(z, x, v); // set triangle size
    tri.fin();//read from file to a,b,c - storony
    tri.is_real();// can tri be real?
    tri.space();// ploshchad' of tri
    tri.perimetr();
    tri++;//tri.(a,b,c)++
    tri.vivod();
    tri--;//tri.(a,b,c)--
    tri.vivod();
    tri * 5;//tri.(a,b,c)*5
    tri.vivod();
    tri.fout();
    return 0;
}
