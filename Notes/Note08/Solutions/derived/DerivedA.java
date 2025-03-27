package derived;

class DerivedA extends Base 
{
    public DerivedA() 
    {
        System.out.print("This is the derived A class constructor\n");
    }
        
    @Override
    public void publicMethod()
    {
        System.out.print("This is the derived A class public method\n"); 
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
        DerivedA a = new DerivedA();
        a.publicMethod();
        a.DerivedPublicMethod();
        a.DerivedProtectedMethod();
    }
}
