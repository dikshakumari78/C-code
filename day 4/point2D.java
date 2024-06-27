public class Point2D {
    private double x;
    private double y;

    public Point2D(double x, double y) {
        this.x = x;
        this.y = y;
    }

    // Overload + operator for addition
    public Point2D add(Point2D other) {
        return new Point2D(this.x + other.x, this.y + other.y);
    }

    // Getter for x coordinate
    public double getX() {
        return x;
    }

    // Getter for y coordinate
    public double getY() {
        return y;
    }

    // Main method for testing
    public static void main(String[] args) {
        Point2D p1 = new Point2D(3.0, 4.0);
        Point2D p2 = new Point2D(-1.0, 2.5);

        Point2D sum = p1.add(p2);
        System.out.println("Sum of points: (" + sum.getX() + ", " + sum.getY() + ")");
    }
}
