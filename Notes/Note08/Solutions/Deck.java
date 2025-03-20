
class Deck
{
    public static String[] CreateDeckEmpty(int n)
    {
        if(n == 0)
        {
            n = 52;
        }
        return new String[n];
    } 

    public static void StandardPopulate(String[] deck,int n,char[] faces,char[] suits)
    {
        if(faces.length * suits.length <= n)
        {
            for(int i = 0;i < faces.length;i += 1)
            {
                for(int j = 0;j < suits.length;j += 1)
                {
                    deck[i*suits.length+j] = "" + faces[i];
                    deck[i*suits.length+j] += suits[j];
                }
            }
        }
    }

    public static void DisplayDeck(String[] deck,int n,int sc)
    {
        for(int i = 0;i < n;i += 1)
        {
            System.out.print(deck[i]);

            if((i + 1) % sc == 0)
            {
                System.out.print('\n');
            }
            else 
            {
                System.out.print(' ');
            }
        }
    }

    public static void main(String[] args)
    {
        int n = 52;
        String[] a = CreateDeckEmpty(n);
        String faces = "A23456789TJQK";
        String suits = "SCDH";
        StandardPopulate(a,n,faces.toCharArray(),suits.toCharArray());
        DisplayDeck(a,n,4);
    }
}
