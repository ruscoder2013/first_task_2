#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#include "filter.h"

#define UNUSED(x) (void)(x)

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

std::vector<int> split_to_int(const std::string &str, char d)
{
    std::vector<int> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    try {
        while (stop != std::string::npos) {
            auto ip_part = stoi(str.substr(start, stop - start));
            if ((ip_part < 0) || (ip_part > 255))
                return {};
            r.push_back(ip_part);

            start = stop + 1;
            stop = str.find_first_of(d, start);
        }
        auto ip_part = stoi(str.substr(start));
        if ((ip_part < 0) || (ip_part > 255))
            return {};
        r.push_back(ip_part);
    }
    catch (const std::invalid_argument& ia) {
        return {};
    }
    if (r.size() == 4)
        return r;
    else
        return {};
}

void print_ip(std::vector<std::vector<int>> ip_pool) {
    for(auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
    {
        for(auto ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
        {
            if (ip_part != ip->cbegin())
            {
                std::cout << ".";
            }
            std::cout << *ip_part;
        }
        std::cout << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    UNUSED(argc);
    UNUSED(argv);

    try
    {
        std::vector<std::vector<int> > ip_pool;

        for(std::string line; std::getline(std::cin, line);) {
            std::vector<std::string> v = split(line, '\t');

                auto ip_addr = split_to_int(v.at(0), '.');
                if (!ip_addr.empty())
                    ip_pool.push_back(ip_addr);
        }

        // TODO reverse lexicographically sort
        std::sort(ip_pool.begin(), ip_pool.end(),
                  [](auto a, auto b) -> bool
                  {
                      return a > b;
                  });

        print_ip(ip_pool);

        // 222.173.235.246
        // 222.130.177.64
        // 222.82.198.61
        // ...
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first byte and output
        // ip = filter(1)

        auto ip = filter(ip_pool, 1);
        print_ip(ip);


        // 1.231.69.33
        // 1.87.203.225
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first and second bytes and output
        // ip = filter(46, 70)
        ip = filter(ip_pool, 46, 70);
        print_ip(ip);
//        // 46.70.225.39
//        // 46.70.147.26
//        // 46.70.113.73
//        // 46.70.29.76
//
//        // TODO filter by any byte and output
//        // ip = filter_any(46)
        ip = filter_any(ip_pool, 46);
        print_ip(ip);
        // 186.204.34.46
        // 186.46.222.194
        // 185.46.87.231
        // 185.46.86.132
        // 185.46.86.131
        // 185.46.86.131
        // 185.46.86.22
        // 185.46.85.204
        // 185.46.85.78
        // 68.46.218.208
        // 46.251.197.23
        // 46.223.254.56
        // 46.223.254.56
        // 46.182.19.219
        // 46.161.63.66
        // 46.161.61.51
        // 46.161.60.92
        // 46.161.60.35
        // 46.161.58.202
        // 46.161.56.241
        // 46.161.56.203
        // 46.161.56.174
        // 46.161.56.106
        // 46.161.56.106
        // 46.101.163.119
        // 46.101.127.145
        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76
        // 46.55.46.98
        // 46.49.43.85
        // 39.46.86.85
        // 5.189.203.46
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
