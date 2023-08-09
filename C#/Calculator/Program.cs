using System;

class Calculator
{
	public double sum(double num1, double num2)
	{
		return (num1 + num2);
	}
	public double subtraction(double num1, double num2)
	{
		return (num1 - num2);
	}
	public double multiplication(double num1, double num2)
	{
		return (num1 * num2);
	}
	public double division(double num1, double num2)
	{
		return (num1 / num2);
	}
}

class Program
{
	static void Main(string[] args)
	{
		double result = 0;
		Calculator calc = new Calculator();

		Console.WriteLine("Please input a number:");
		double num1 = double.Parse(Console.ReadLine() ?? "0");
		Console.WriteLine("Please input a second number:");
		double num2 = double.Parse(Console.ReadLine() ?? "0");
		Console.WriteLine("Please input the operator of the operation you want to execute:");
		char op = char.Parse(Console.ReadLine() ?? "+");

		try
		{
			switch(op)
			{
				case '+':
					result = calc.sum(num1, num2);
					break;
				case '-':
					result = calc.subtraction(num1, num2);
					break;
				case '*':
					result = calc.multiplication(num1, num2);
					break;
				case '/':
					if (num2 == 0)
						throw new DivideByZeroException();
					result = calc.division(num1, num2);
					break;
			}
			Console.WriteLine("{0} {1} {2} = {3}", num1, op, num2, result);
		}
		catch (DivideByZeroException)
		{
			Console.WriteLine("It is not possible to divide a number by 0.");
		}
	}
}