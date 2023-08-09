using System;

class Greetings
{
	static void Main(string[] args)
	{
		string	name;
		int		age;

		if (args.Length == 2)
		{
			name = args[0];
			int.TryParse(args[1], out age);
			if (age != 0)
				Console.WriteLine("Hello, {0}! It seems you're {1} years old.", name, age);
			else
				Console.WriteLine("You have entered an invalid age.");
		}
		else
			Console.WriteLine("Usage:\nGreetings Name age");
	}
}
