#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>
#include <string>

boost::gregorian::date convert(std::string date_str) {
    std::vector<int> date_vec(3, 0);
    std::istringstream din(date_str);
    char c;
    din >> date_vec[0] >> c >> date_vec[1] >> c >> date_vec[2];
    return boost::gregorian::date(date_vec[0], date_vec[1], date_vec[2]);
}

int main()
{
    long long sum{};
    std::string date_str;
    std::cin >> date_str;
    boost::gregorian::date prev = convert(date_str);
    boost::gregorian::date next{};

    while(std::cin >> date_str) {
        next = convert(date_str);
        sum += std::abs((next - prev).days());
        prev = next;
    }
    std::cout << sum << std::endl;
    return 0;
}
