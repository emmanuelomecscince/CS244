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

    @override
    public String toString() 
    {
        String out;
        out = "(" + radius + ")";
        return out;
    }

    static
    {
        PI = 3.1415926;
    }
}