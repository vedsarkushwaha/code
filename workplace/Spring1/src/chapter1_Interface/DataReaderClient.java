/**
 * 
 */
package chapter1_Interface;

import java.io.FileNotFoundException;

/**
 * @author vedsar
 *
 */
public class DataReaderClient {

	/**
	 * @param args
	 */
	
	private static Reader reader = null;
	public DataReaderClient(Reader reader) {
		this.reader = reader;
	}
	private String fetchData() {
		return reader.read();
	}
	public static void main(String[] args) {	
		// TODO Auto-generated method stub
		String fName = "/home/vedsar/Desktop/git/code/workplace/Spring1/src/res/data";
		try {
			reader = new FileReader(fName);
			DataReaderClient client = new DataReaderClient(reader);
			System.out.println(client.fetchData());
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}