enum Apple {
  Jonathan(10), GoldenDel(9), RedDel, Winesap(15), Cortland(8);

  private int price; // price of each apple

  // Constructor
  Apple(int p) { price = p; }

  // Overloaded constructor
  Apple() { price = -1; }

  int getPrice() { return price; }
}

class EnumDemo3 {
  public static void main(String args[])
  {
    Apple ap;

    // Display price of Winesap.
    System.out.println(
        "Winesap costs " +
        Apple.Winesap.getPrice() +
        " cents.\n"
    );

    // Display all apples and prices.
    System.out.println("All apple prices:");
    for(Apple a : Apple.values())
        System.out.println(
            a +
            " costs " +
            a.getPrice() +
            " cents."
        );
  }
}
