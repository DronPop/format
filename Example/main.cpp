#include <iostream>
#include <complex>
#include "format.hpp"

class TestClass {
    
public:
    
    TestClass(const int a_,
              const int b_) :
    m_a(a_), m_b(b_)
    {}
    
    int getA() const { return m_a; }
    
    int getB() const { return m_b; }
    
private:
    
    int m_a = 0;
    
    int m_b = 0;
    
};

inline std::ostream& operator<<(std::ostream& out_, const TestClass& testClass_) {
    out_ << "TestClass(" << testClass_.getA() << ',' << testClass_.getB() << ')';
    return out_;
}

int main(int argc_, char** argv_) {
    
    const std::string str = "testString";
    
    // Пример со стандартными типами.
    std::string result = formated("int = %, double = %, std::string = %, const char * = %, bool = %",
                                  1,          3.14,            str,              "char*",         true);
    
    std::cout << result << '\n';
    
    // Пример с пользовательскими для которых перегружен оператор <<.
    
    std::complex<double> complex(3, 14);
    TestClass testClass(3, 4);
    result = formated("Complex = %, TestClass = %", complex, testClass);
    std::cout << result << '\n';
    
    return EXIT_SUCCESS;
}
