class Sum {
    int a, b;
public:
    Sum(int a_val, int b_val): a(a_val), b(b_val) {}
    Sum(const Sum &s, int b_val): a(s.get()), b(b_val) {}
    int get() const {
        return a + b;
    }
};
