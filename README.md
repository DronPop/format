# format
* Getting Started
  * Simple example using format
  * Basic Installation
* Features
  * Advantages
  * Disadvantages
# Getting Started
# Simple example using format
```
std::string result = formated("int = %, double = %, std::string = %, const char * = %, bool = %",
                                     1,          3.14,            str,              "char*",  true);
//string = "int = 1, double = 3.140000, std::string = testString, const char * = char*, bool = 1".
```
# Basic Installation
1. git clone https://github.com/DronPop/format.git
1. cd format/Example
1. mkdir build
1. cd build
1. cmake .. -G "<IDA>"
1. open <SolutionName>
# Features
 # Advantages
 * Strongly typed
 * Can be used with all standard types
 * Ability to use with custom types. For that overload operator<<(std::ostream& out_, const CustomClass& obj_);
 # Disadvantages
 * May be complile time.
