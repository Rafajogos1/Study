import java.util.ArrayList;
import java.util.Scanner;

class Movie 
{
	public String	title;
	public String	genre;
	public String	rating;
}

public class Movies
{
	public static void main(String[] args)
	{
		ArrayList<Movie> movieList = new ArrayList<Movie>();
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
					Movie	movie = new Movie();
					System.out.println("Please input the name of the movie:");
					movie.title = scanner.nextLine();
					System.out.println("Please input the genre of the movie:");
					movie.genre = scanner.nextLine();
					System.out.println("Please input the rating of the movie:");
					movie.rating = scanner.nextLine();
					movieList.add(movie);
					System.out.print("\033[H\033[2J");
					System.out.flush();
					break;
				case "2":
					System.out.print("\033[H\033[2J");
					System.out.flush();
					if (!movieList.isEmpty())
						for(int i = 0; i < movieList.size(); i++)
						{
							System.out.println("Movie: " + movieList.get(i).title);
							System.out.println("Genre: " + movieList.get(i).genre);
							System.out.println("Rating: " + movieList.get(i).rating);
							System.out.println();
						}
					else
						System.out.println("There are no movies to display.\n");
					break;
				case "3":
					System.out.print("\033[H\033[2J");
					System.out.flush();
					if (!movieList.isEmpty())
					{
						System.out.println("Please input the title of the movie you want to find:");
						String name = scanner.nextLine();
						for(int i = 0; i < movieList.size(); i++)
						{

							if (movieList.get(i).title.equals(name))
							{
								System.out.println("Movie: " + movieList.get(i).title);
								System.out.println("Genre: " + movieList.get(i).genre);
								System.out.println("Rating: " + movieList.get(i).rating);
								System.out.println();
								break;
							}
						}
						System.out.println("No movie named " + name + " was found.");
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