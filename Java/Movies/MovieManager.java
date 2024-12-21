import java.util.ArrayList;

public class MovieManager {
	private static ArrayList<Movie> movieList = new ArrayList<Movie>();
	private MovieManager()
	{
		throw new UnsupportedOperationException("This is a utility class and cannot be instantiated");
	}

	public static void addMovie(Movie movie)
	{
		movieList.add(movie);
	}

	public static boolean checkEmpty()
	{
		if (movieList.isEmpty() == true)
			return true;
		else
			return false;
	}

	public static int listSize()
	{
		return (movieList.size());
	}

	public static void getInfo(int pos)
	{
		System.out.println("Movie: " + movieList.get(pos).getTitle());
		System.out.println("Genre: " + movieList.get(pos).getGenre());
		System.out.println("Rating: " + movieList.get(pos).getRating());
		System.out.println();
	}

	public static boolean movieExists(String movie, int pos)
	{
		if (movieList.get(pos).getTitle().equals(movie))
			return true;
		else
			return false;
	}
}
