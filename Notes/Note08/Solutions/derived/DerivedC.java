package derived;

class DerivedC extends Base 
{
    public DerivedC() 
    {
        System.out.print("This is the derived C class constructor\n");
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
        DerivedC c = new DerivedC();
        c.publicMethod();
        c.DerivedPublicMethod();
        c.DerivedProtectedMethod();
    }    
}
