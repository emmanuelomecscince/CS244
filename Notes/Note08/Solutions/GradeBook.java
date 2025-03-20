import java.util.Scanner;

class GradeBook 
{
    public static void ReadNames(String[] names,int n)
    {
        Scanner cin = new Scanner(System.in);

        for(int i = 0;i < n;i += 1)
        {
            System.out.print("Enter name of student " + (i + 1) + ": ");
            names[i] = cin.nextLine();
        }
    }

    public static void ReadGrades(String[] names,double[] grades,int n)
    {
        Scanner cin = new Scanner(System.in);
        for(int i = 0;i < n;i += 1)
        {
            System.out.print("Enter grade of " + names[i] + ": ");

            while(true)
            {
                grades[i] = cin.nextDouble();

                if(grades[i] >= 0 && grades[i] <= 100)
                {
                    break;
                }
                else
                {
                    System.out.print("Invalid grade. Reenter grade: ");
                }
            }
        }
    }
    
    public static void main(String[] args)
    {
        final int n = 5;
        String[] students = new String[n];
        double[] grades = new double[n];
        ReadNames(students,n);
        ReadGrades(students,grades,n);

        for(int i = 0;i < n;i += 1)
        {
            System.out.print(students[i] + " (" + grades[i] + ")\n");
        }
    }
}