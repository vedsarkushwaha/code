/**
 * 
 */
package chapter1_spring;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

/**
 * @author vedsar
 *
 */
public class DataReaderClient {

	private ApplicationContext ctx = null;
	private ReaderService service = null;
	public DataReaderClient() {
		ctx = new ClassPathXmlApplicationContext("reader-beans.xml");
	}
	
	public String getData() {
		service = (ReaderService) ctx.getBean("readerService");
		return service.read();
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		DataReaderClient client = new DataReaderClient();
		System.out.println(client.getData());
	}
}