#include "stack.h"
#include <iostream>
#include <stdexcept>

int main()
{
	try
	{
		stack s1;
		stack s2;
		stack s3;

		s1.push(5);
		s1.push(15);
		s1.push(25);
		s1.push(35);
		s1.push(45);
		
		s2.push(5);
		s2.push(10);
		s2.push(15);
		s2.push(20);
		s2.push(25);
		
		s3 = s1;

		std::cout << "Top element of s3: " << s3.Top() << std::endl;		

		std::cout << "s1 != s3: " << (s1 != s3 ? "True" : "False") << std::endl;		
		std::cout << "s1 < s2: " << (s1 < s2 ? "True" : "False") << std::endl;		

		
	}
	catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}