import java.text.DecimalFormat;

class Rectangle 
{
    private double length;
    private double width;

    public Rectangle()
    { 
        width = 1; 
        length = 1;
    }

    public Rectangle(double value) 
    {
        this(value,value);
    }

    public Rectangle(double x,double y)
    {
        this();
        if(x > 0 && y > 0)
        {
            width = (x < y)?(x):(y);
            length = (x > y)?(x):(y);
        }
    }
 
    public Rectangle(final Rectangle obj)
    {
        width = obj.width;
        length = obj.length;
    }

    public double Length() {return length;}

    public double Width() {return width;}

    public void setLength(double value)
    {
        if(value > 0 && value >= width)
        {
            length = value;
        }
    }

    public void setWidth(double value)
    {
        if(value > 0 && value <= length)
        {
            width = value;
        }
    }

    public double perimeter() {return 2 * (length + width);}

    public double area() {return length * width;}

    @Override
    public String toString() 
    {
        String out;
        DecimalFormat two = new DecimalFormat("####.00");

        out = "[" + two.format(width) + "," + two.format(length) + "]";
        return out;
    }

    public static void main(String[] args)
    {
        Rectangle[] rs = {new Rectangle(), new Rectangle(6), new Rectangle(7,10), new Rectangle(10,7)};

        for(int i = 0;i < rs.length;i += 1)
        {
            System.out.println(rs[i]);
            System.out.println("(" + rs[i].perimeter() + "," + rs[i].area() + ")");
        }
    }
}