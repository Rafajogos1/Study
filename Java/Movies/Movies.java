import java.util.Scanner;

public class Movies
{
	public static void main(String[] args)
	{
		Scanner scanner = new Scanner(System.in);
		String	choice;

		while (true)
		{
			System.out.println("1 - Add movie.");
			System.out.println("2 - List all movies.");
			System.out.println("3 - Find movie.");
			System.out.println("4 - Exit.");
			System.out.println();
			choice = scanner.nextLine();
			switch (choice)
			{
				case "1":
					System.out.print("\033[H\033[2J");
					System.out.flush();
					Movie	movie = new Movie("", "", "");
					System.out.println("Please input the name of the movie:");
					movie.setTitle(scanner.nextLine());
					System.out.println("Please input the genre of the movie:");
					movie.setGenre(scanner.nextLine());
					System.out.println("Please input the rating of the movie:");
					movie.setRating(scanner.nextLine());
					MovieManager.addMovie(movie);
					System.out.print("\033[H\033[2J");
					System.out.flush();
					break;
				case "2":
					System.out.print("\033[H\033[2J");
					System.out.flush();
					if (!MovieManager.checkEmpty())
						for(int i = 0; i < MovieManager.listSize(); i++)
							MovieManager.getInfo(i);
					else
						System.out.println("There are no movies to display.\n");
					break;
				case "3":
					System.out.print("\033[H\033[2J");
					System.out.flush();
					if (!MovieManager.checkEmpty())
					{
						System.out.println("Please input the title of the movie you want to find:");
						String name = scanner.nextLine();
						boolean found = false;
						for(int i = 0; i < MovieManager.listSize(); i++)
						{
							if (MovieManager.movieExists(name, i))
							{
								found = true;
								MovieManager.getInfo(i);
								break;
							}
						}
						if (!found)
							System.out.println("No movie with by the name \"" + name + "\" was found.");
						found = false;
					}
					else
						System.out.println("There are no movies to display.\n");
					break;
				case "4":
					scanner.close();
					System.exit(0);
					break;
				default:
					System.out.print("\033[H\033[2J");
					System.out.flush();
					System.out.println("Invalid choice.");
					System.out.println();
					break;
			}
		}
	}
}