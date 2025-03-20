import java.awt.desktop.SystemEventListener;
import java.awt.geom.CubicCurve2D;
import java.util.Random;

class Customer
{
    public String name;
    public String number;
    public static int num_gen; 
    public static int count;

    public Customer() 
    {
        name = "John Smith";
        number = AccountNumberGenerator();
        count += 1;
        System.out.print("account: " + number + "\ncalled the default constructor\n");
    }

    public Customer(final Customer obj) 
    {
        this.name = obj.name;
        this.number = AccountNumberGenerator();
        count += 1;
        System.out.print("account: " + number + "\ncalled the copy constructor\n");
    } 
        
    public static String AccountNumberGenerator() 
    {
        Random rand = new Random();
        String result = "8";
        result += rand.nextInt(10);
        result += rand.nextInt(10);
        result += rand.nextInt(10);
        result += num_gen;
        num_gen += 1;
        result += rand.nextInt(10);
        result += rand.nextInt(10);
        result += rand.nextInt(10);
        result += rand.nextInt(10);
        return result;
    }

    static 
    {
        num_gen = 1000;
        count = 0;
    }

    public static void main(String[] args)
    {
        Customer c = new Customer();
        Customer d = new Customer(c);
        System.out.println(Customer.count);
        System.out.println(c.number + "\n" + d.number);
    }
}
