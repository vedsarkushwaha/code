/**
 * 
 */
package chapter1;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * @author vedsar
 *
 */
public class FileReader {
	private StringBuilder builder = null;
	private Scanner scanner = null;
	public FileReader(String fName) throws FileNotFoundException {
		scanner = new Scanner(new File(fName));
		builder = new StringBuilder();
	}
	public String read() {
		while(scanner.hasNext()) {
			builder.append(scanner.next());
		}
		return builder.toString();
	}
}