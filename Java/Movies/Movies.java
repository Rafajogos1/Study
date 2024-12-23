import java.util.Scanner;

public class Movies
{
	final static int ADD_MOVIE = 1;
	final static int LIST_MOVIES = 2;
	final static int FIND_MOVIE = 3;
	final static int DELETE_MOVIE = 4;
	final static int EXIT = 5;

	public static void main(String[] args)
	{
		Scanner scanner = new Scanner(System.in);
		String	choice;

		/* The main loop. */
		while (true)
		{
			System.out.println("1 - Add movie.");
			System.out.println("2 - List all movies.");
			System.out.println("3 - Find movie.");
			System.out.println("4 - Delete movie.");
			System.out.println("5 - Exit.");
			System.out.println();
			choice = scanner.nextLine();
			switch (Integer.parseInt(choice))
			{
				case ADD_MOVIE:
					System.out.println("---------------------------------------");
					Movie	movie = new Movie("", "", "");
					System.out.println("Please input the name of the movie:");
					movie.setTitle(scanner.nextLine());
					System.out.println("Please input the genre of the movie:");
					movie.setGenre(scanner.nextLine());
					System.out.println("Please input the rating of the movie:");
					movie.setRating(scanner.nextLine());
					MovieManager.addMovie(movie);
					System.out.println("---------------------------------------");
					break;
				case LIST_MOVIES:
					System.out.println("---------------------------------------");
					if (!MovieManager.checkEmpty())
						for(int i = 0; i < MovieManager.listSize(); i++)
							MovieManager.getInfo(i);
					else
						System.out.println("There are no movies to display.\n");
					break;
				case FIND_MOVIE:
					System.out.println("---------------------------------------");
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
				case DELETE_MOVIE:
					System.out.println("---------------------------------------");
					if (!MovieManager.checkEmpty())
					{
						System.out.println("Please input the title of the movie you want to delete:");
						String name = scanner.nextLine();
						boolean found = false;
						for(int i = 0; i < MovieManager.listSize(); i++)
						{
							if (MovieManager.movieExists(name, i))
							{
								found = true;
								MovieManager.deleteMovie(i);
								System.out.println("Successfully deleted the movie \"" + name + "\".");
								break;
							}
						}
						if (!found)
							System.out.println("No movie with by the name \"" + name + "\" was found.");
						found = false;
					}
					else
						System.out.println("There are no movies to delete.\n");
					break;
				case EXIT:
					scanner.close();
					System.exit(0);
					break;
				default:
					System.out.println("---------------------------------------");
					System.out.println("Invalid choice.");
					System.out.println();
					break;
			}
		}
	}
}