#ifndef rectangle_h
#define rectangle_h
class rectangle{
    private:
    double length;
    double width;
    public:
    rectangle();
    rectangle(double l,double w);
    void setdimensions(double l,double w);
    double area();
    double perimeter();
    void display();
};
#endif
