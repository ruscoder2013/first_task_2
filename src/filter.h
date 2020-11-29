//
// Created by Android on 13.10.2020.
//

#ifndef UNTITLED_FILTER_H
#define UNTITLED_FILTER_H
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

std::vector<std::vector<int>> filter(const std::vector<std::vector<int>> &ip_pool, int addr);
std::vector<std::vector<int>> filter(const std::vector<std::vector<int>> &ip_pool, int addr_0, int addr_1);
std::vector<std::vector<int>> filter_any(const std::vector<std::vector<int>> &ip_pool, int addr);

#endif //UNTITLED_FILTER_H
