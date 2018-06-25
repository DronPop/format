#pragma once
#include "format_implementation.hpp"

template <typename... Args>
std::string formated(const std::string& string_,
                     const Args& ...args_) {
    std::string result = string_;
    __format(result, args_...);
    return result;
}

template <typename... Args>
void format(std::string& string_,
            const Args& ...args_) {
    std::string result = string_;
    __format(result, args_...);
    string_ = std::move(result);
}
