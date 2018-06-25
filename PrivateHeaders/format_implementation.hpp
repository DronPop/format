#pragma once

#include <string>
#include <exception>
#include <sstream>

void __format(std::string& result_);

template <typename... Args>
void __format(std::string& result_, const char* arg_, const Args& ...args_);

template <typename... Args>
void __format(std::string& result_, const std::string& arg_, const Args& ...args_);

template <typename Arg, typename... Args>
void __format(std::string& result_, const Arg& arg_, const Args& ...args_);

inline void __format(std::string& result_) {
    using size_type = std::string::size_type;
    
    const size_type index = result_.find('%');
    if (index != std::string::npos) {
        throw std::exception(); //< количество '%' не равно количеству аргументов.
    }
}

template <typename... Args>
void __format(std::string& result_,
              const char* arg_,
              const Args& ...args_) {
    using size_type = std::string::size_type;
    
    size_type index = result_.find('%');
    if (index == std::string::npos) {
        return;
    }
    
    result_.replace(index, 1, arg_);
    __format(result_, args_...);
}

template <typename... Args>
void __format(std::string& result_,
              const std::string& arg_,
              const Args& ...args_) {
    using size_type = std::string::size_type;
    
    const size_type index = result_.find('%');
    if (index == std::string::npos) {
        return;
    }
    
    result_.replace(index, 1, arg_);
    __format(result_, args_...);
}

namespace std {
    template <typename Type>
    inline std::string to_string(const Type& value_) {
        std::stringstream sstream;
        sstream << value_;
        return sstream.str();
    }
}

template <typename Arg, typename... Args>
void __format(std::string& result_,
              const Arg& arg_,
              const Args& ...args_) {
    using size_type = std::string::size_type;
    
    const size_type index = result_.find('%');
    if (index == std::string::npos) {
        return;
    }
    
    result_.replace(index, 1, std::to_string(arg_));
    __format(result_, args_...);
}
