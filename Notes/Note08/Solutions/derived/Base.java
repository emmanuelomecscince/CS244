package derived;

class Base 
{        
    private void privateMethod() 
    {
        System.out.print("This is the base class private method\n");
    }

    public Base() 
    {
        System.out.print("This is the base class constructor\n");
    }
    
    public void publicMethod() 
    {
        System.out.print("This is the base class public method\n");
    }
    
    protected void protectedMethod() 
    {
        System.out.print("This is the base class protected method\n");
    }

    public static void main(String[] args) 
    {
        Base b = new Base();
        b.publicMethod();
    }
}
