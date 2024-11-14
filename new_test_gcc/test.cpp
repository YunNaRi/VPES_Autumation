class A {
        

    public:
    int m_a;
    int m_b;
    A(int a, int b) {
        m_a = a;
        m_b = b;
    }
};

class B {
    public:
        int m_a;
        int m_b;
        A *m_A;

    public:
    B(int a, int b){
        m_a = a;
        m_b = b;
        m_A = new A(1,2);
    }

    int getA_a() {
        return m_A->m_a;
    }
};

class C {
    private:
        int m_a;
        int m_b;
        B *m_B;

    public:
    C(int a, int b){
        m_a = a;
        m_b = b;
        m_B = new B(1,2);
    }

    int getB_b() {
        return m_B->m_b;
    }
};


int main() {
    A a(1,2);
    B b(1,2);
    C c(1,2);
    return 0;
}