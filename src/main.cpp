// Note to Myself, in C++ Philosoy, dont use functions to the rendrer system but methods where the polymorphism is better represented


#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdarg>


/*
template <typename T>
void func(T t) 
{
    std::cout << t << std::endl ;
}

template<typename T, typename... Args>
void func(T t, Args... args) // recursive variadic function
{
    std::cout << t <<std::endl ;

    func(args...) ;
}

template <class T>
void func2( std::initializer_list<T> list )
{
    for( auto elem : list )
    {
        std::cout << elem << std::endl ;
    }
}
*/

void setStr(std::string, std::string ...);

void setStr(std::string T){
	std::cout << T << std::endl ;
}

void setStr(std::string T, std::string args...){
	std::cout << T <<std::endl ;
	setStr(args) ;
}

int main()
{
	int x_2D;
	return 0; 
} 
