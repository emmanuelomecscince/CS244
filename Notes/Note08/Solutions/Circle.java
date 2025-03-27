import java.text.DecimalFormat;

class Circle 
{
    private double radius;
    private static final double PI;

    public Circle()
    {
        this(1); //constructor delegation
    }

    public Circle(int r)
    {
        this.radius = (r <= 0)?(1):(r);
    }

    public Circle(final Circle obj)
    {
        radius = obj.radius;
    }
        
    public double getRadius() 
    {
        return radius;
    }


    public void setRadius(double value)
    {
        if(value > 0)
        {
            radius = value;
        }
    }

    public double circumference() {return 2 * radius * PI;}

    public double area() {return PI * radius * radius;}

    @Override
    public String toString() 
    {
        DecimalFormat two = new DecimalFormat("####.00");
        String out;

        out = "(" + two.format(radius) + ")";
        return out;
    }

    static
    {
        PI = 3.1415926;
    }

    public static void main(String[] args) 
    {
        Circle c1 = new Circle(), c2 = new Circle(6);
        System.out.println(c1 + "\n" + c2);
        System.out.println("(" + c1.area() + "," + c1.circumference() + ")");
        System.out.println("(" + c2.area() + "," + c2.circumference() + ")");
    }
}