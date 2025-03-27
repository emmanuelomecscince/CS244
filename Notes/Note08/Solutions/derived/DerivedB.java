package derived;

class DerivedB extends Base 
{
    public DerivedB() 
    {
        System.out.print("This is the derived B class constructor\n");
    }
       
    public void DerivedPublicMethod() 
    {
        System.out.print("This is a derived public method that invokes the base public method\n");
        super.publicMethod();
    }
    
    public void DerivedProtectedMethod() 
    {
        System.out.print("This is a derived public method that invokes the base protected method\n");
        super.protectedMethod();
    }

    public static void main(String[] args) 
    {
        DerivedB b = new DerivedB();
        b.publicMethod();
        b.DerivedPublicMethod();
        b.DerivedProtectedMethod();
    }
}
