#include<iostream>
#include <stdexcept>

class Calculator {
public:
	Calculator() { memory = 0; }//constructor without parameters
	Calculator(int startValue) { memory = startValue; }//constructor with parameters

	int getCurrentValue() const { return memory };
	void setStartValue(int value)
	{
		memory = value;
	}
	//operators overloading
	Calculator& operator+(int value) 
	{
		return *this += value;
	}
	Calculator& operator-(int value)
	{
		return *this -= value;
	}
	Calculator& operator*(int value)
	{
		return *this *= value;
	}
	Calculator& operator/(int value)
	{
		return *this /= value;
	}
	Calculator& operator+=(int value)
	{
		memory += value;
		return *this;
	}
	Calculator& operator-=(int value)
	{
		memory -= value;
		return *this;
	}
	Calculator& operator*=(int value)
	{
		memory *= value;
		return *this;
	}
	Calculator& operator/=(int value)
	{
		if (value == 0)
		{
			std::runtime_error << "You cannot divide by 0, I`m sorry(" << std::endl;
			return *this;
		}
		memory /= value;
		return *this;
	}
private:
	int memory = 0;
};

int main() {
	Calculator obj(10);
	std::cout << "Started value: " << obj.getCurrentValue() << std::endl;

	try 
	{
		obj.setStartValue(100);
		obj /= 10;
		std::cout << "Result obj /= 10 = " << obj.getCurrentValue() << std::endl;

		// Тест ділення на нуль
		std::cout << "Trying to divide by 0..." << std::endl;
		obj /= 0;
	}
	catch (const std::runtime_error& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
}