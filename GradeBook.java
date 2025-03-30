import java.util.Scanner; 

class GradeBook 
{
    public static void ReadNames(String[] names, int n)
    {
        Scanner cin = new Scanner 
        for(int i = 0;i < n;i += 1)
        {
            system.out.print("Enter name of student " + (i + 1) + ": "); 
            names[i] = cin.next(); 
            
            std::getline(std::cin,names[i]); 
        }
    }

    
    {
        Scanner cin = new 
        public static void ReadGrades(String[] names,double[] grade,int n)
    
    } 

void 

      pubic static void main(String[] names, double[] grade, int n java )
      Scanner cin = new scanner 
      for(int i = 0;i < n;i += 1)
      {
        system.out.print("Enter name of student " (i + 1) + ": "); 
        names[i] = cin.next();

        std::getline(std::cin, names[i]); 
      }

      Run main | Detug main 
      pubic static void main(string[] args)
      {
        final int n = 5; 
        String[] students = new String[n]; 
        double[] grades = new double[n]; 
        ReadGrades(students, n);
        ReadGrades(students, grades, n); 

        for(int i = 0;i < n;i += 1)
        {
            System.out.print("Invlid grade. Reenter grade: "); 
        }
      }
}