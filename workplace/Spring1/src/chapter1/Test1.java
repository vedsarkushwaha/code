/**
 * 
 */
package chapter1;

import java.io.FileNotFoundException;

/**
 * @author vedsar
 *
 */
public class Test1 {
	private FileReader fileReader = null;
	private String fileName = "data";
	public Test1() throws FileNotFoundException {
		fileReader = new FileReader(fileName);
	}
	private String fetchData() {
		return fileReader.read();
	}
	public static void main(String[] args) {
		try {
			Test1 ts = new Test1();
			System.out.println("Got data: "+ts.fetchData());
		}
		catch(FileNotFoundException e) {
			e.printStackTrace();
		}
	}
}