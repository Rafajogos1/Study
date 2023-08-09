using System;

namespace Stuff
{
	public class Person
	{
		int age { get; set; } = 18;

		public void Introduction(string name, int p_age)
		{
			Console.WriteLine("Hello, I'm {0} and I'm {1}.", name, p_age);
			if (p_age < age)
				Console.WriteLine("I'm underaged.");
			else
				Console.WriteLine("I'm not underaged.");
		}
	}
}