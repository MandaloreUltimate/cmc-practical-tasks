#include <cstdio>
#include <cmath>
#include <iomanip>

namespace numbers
{
    constexpr int BUF_SIZE = 1024;
    class complex
    {
        double re_, im_;
    public:
        complex(double re_val = 0, double im_val = 0) : re_(re_val), im_(im_val) {}
        explicit complex(std::string str) : re_(0), im_(0) {
            sscanf(str.c_str(), "(%lf,%lf)", &re_, &im_);
        }

        double re() const {
            return re_;
        }
        double im() const {
            return im_;
        }
        double abs() const {
            return sqrt(re_ * re_ + im_ * im_);
        }
        double abs2() const {
            return (re_ * re_ + im_ * im_);
        }

        std::string to_string() const
        {
            char buf[BUF_SIZE];
            snprintf(buf, BUF_SIZE, "(%.10g,%.10g)", re_, im_);
            return std::string(buf);
        }

        const complex& operator+=(const complex &v2) {
            re_ += v2.re();
            im_ += v2.im();
            return *this;
        }
        const complex& operator-=(const complex &v2) {
            re_ -= v2.re();
            im_ -= v2.im();
            return *this;
        }
        const complex& operator*=(const complex &v2) {
            double tmp_re = re_ * v2.re() - im_ * v2.im();
            double tmp_im = re_ * v2.im() + im_ * v2.re();
            re_ = tmp_re;
            im_ = tmp_im;
            return *this;
        }
        const complex& operator/=(const complex &v2) {
            double tmp_re = (re_ * v2.re() + im_ * v2.im()) / v2.abs2();
            double tmp_im = (v2.re() * im_ - re_ * v2.im()) / v2.abs2();
            re_ = tmp_re;
            im_ = tmp_im;
            return *this;
        }

        const complex operator-() const {
            return complex(-re_, -im_);
        }
        const complex operator~() const {
            return complex(re_, -im_);
        }

        friend complex operator+(const complex &v1, const complex &v2);
        friend complex operator-(const complex &v1, const complex &v2);
        friend complex operator*(const complex &v1, const complex &v2);
        friend complex operator/(const complex &v1, const complex &v2);
    };

    complex operator+(const complex &v1, const complex &v2) {
        complex res(v1.re_, v1.im_);
        res += v2;
        return res;
    }
    complex operator-(const complex &v1, const complex &v2) {
        complex res(v1.re_, v1.im_);
        res -= v2;
        return res;
    }
    complex operator*(const complex &v1, const complex &v2) {
        complex res(v1.re_, v1.im_);
        res *= v2;
        return res;
    }
    complex operator/(const complex &v1, const complex &v2) {
        complex res(v1.re_, v1.im_);
        res /= v2;
        return res;
    }
}
