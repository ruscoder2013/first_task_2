//
// Created by Android on 13.10.2020.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include "filter.h"

std::vector<std::vector<int>> filter(const std::vector<std::vector<int>> &ip_pool, int addr)
{
    std::vector<std::vector<int>> ip_finder;
    auto ip = ip_pool.begin();
    auto filt {
            [addr](const auto & a) -> bool
            {
                return a[0] == addr;
            }
    };
    ip = std::find_if (ip, ip_pool.end(), filt);

    while(ip != ip_pool.end()) {
        ip_finder.push_back(*ip);
        ip++;
        ip = std::find_if (ip, ip_pool.end(), filt);
    }
    return ip_finder;
}

std::vector<std::vector<int>> filter(const std::vector<std::vector<int>> &ip_pool, int addr_0, int addr_1)
{
    std::vector<std::vector<int>> ip_finder;
    auto ip = ip_pool.begin();
    auto filt {
            [addr_0, addr_1](const auto & a) -> bool
            {
                return a[0] == addr_0 and a[1] == addr_1;
            }
    };
    ip = std::find_if (ip, ip_pool.end(), filt);

    while(ip != ip_pool.end()) {
        ip_finder.push_back(*ip);
        ip++;
        ip = std::find_if (ip, ip_pool.end(), filt);
    }
    return ip_finder;
}

std::vector<std::vector<int>> filter_any(const std::vector<std::vector<int>> &ip_pool, int addr)
{
    std::vector<std::vector<int>> ip_finder;
    auto ip = ip_pool.begin();
    auto filt {
            [addr](const auto & a) -> bool
            {
                return a[0] == addr or a[1] == addr or a[2] == addr or a[3] == addr;
            }
    };
    ip = std::find_if (ip, ip_pool.end(), filt);

    while(ip != ip_pool.end()) {
        ip_finder.push_back(*ip);
        ip++;
        ip = std::find_if (ip, ip_pool.end(), filt);
    }
    return ip_finder;
}