#include <iostream>
#include <sstream>
using namespace std;

class Rational {
    // Вставьте сюда реализацию класса Rational из первой части
    public:
    Rational() {
        // Реализуйте конструктор по умолчанию
        P = 0;
        Q = 1;
    }

    Rational(int numerator, int denominator) {
        // Реализуйте конструктор
        P = numerator/(nod(numerator, denominator));
        Q = denominator/(nod(numerator, denominator));
        signs(P, Q);
    }

    int Numerator() const { //Числитель
        // Реализуйте этот метод
        return P;
    }

    int Denominator() const { //Знаменатель
        // Реализуйте этот метод
        return Q;
    }

private:
    void signs(int& a, int& b){
        if((a>0 && b<0) || (a<0 && b<0)){
            a=-a;
            b=-b;
        }
    }
    int nod(int a, int b) {
        return b == 0 ? a : nod(b, a % b);
    }
    // Добавьте поля
    int P;  //P - целое число (числитель)
    int Q; //Q - натуральное число (знаменатель)
};

// Вставьте сюда реализацию operator == для класса Rational из второй части
bool operator == (const Rational& r_1, const Rational& r_2){
    if((r_1.Numerator() == r_2.Numerator()) && (r_1.Denominator() == r_2.Denominator())) return true;
    else return false;
}

// Реализуйте для класса Rational операторы << и >>
ostream& operator << (ostream& stream, const Rational& r){
    stream << r.Numerator() << "/" << r.Denominator();
    return stream;
}

istream& operator >> (istream& stream, Rational& r){
    char delenie;
    int a, b;
    stream >> a >> delenie >> b;
    if (stream && delenie == '/') {
        r = Rational(a, b);
    }
    return stream;
}

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

   {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
