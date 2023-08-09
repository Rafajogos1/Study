using System;

class Hello
{
	static void Main(string[] args)
	{
		if (args.Length == 1)
			Console.WriteLine("Hello, {0}!", args[0]);
		else
			Console.WriteLine("To run this program pass only your name as an argument.");
	}
}
