#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Point //абстрактный класс point
{
public:
	Point() {}
	virtual double getX() = 0;
	virtual double getY() = 0;
	virtual double getZ() = 0;
	virtual void setX(double x_) = 0;
	virtual void setY(double y_) = 0;
	virtual void setZ(double z_) = 0;
	virtual void print() {}
protected:
	virtual ~Point() {}
};

class Point2D :public Point {

public:
	double x; double y;
	double getX() { return x; }
	double getY() { return y; }
	double getZ()override { return 0; }
	void setX(double  x_) override { x = x_; }
	void setY(double y_)override { y = y_; }
	void setZ(double y_)override { cout << "Error!"; }
	void print() { cout << x << " " << y << "\n"; }
	Point2D() :x(0), y(0) {}
	Point2D(double a, double b) :x(a), y(b) {} 

};

class Point3D :public Point {

public:
	double x; double y; double z;
	double getX() override { return x; }
	double getY() override { return y; }
	double getZ() override { return z; }
	void setX(double  x_) override { x = x_; }
	void setY(double y_) override { y = y_; }
	void setZ(double z_) override { z = z_; }
	void print() { cout << x << " " << y << " " << z << "\n"; }
	Point3D() :x(0), y(0), z(0) {}
	Point3D(double a, double b, double c) :x(a), y(b), z(c) {} 

};
class Figure //абстрактный класс figure
{
protected:
	int n;
	string name;
public:
	string get_name() { return name; }
	Figure() {
		name = ""; cout << "This is Figure default constructor\n";
	}
	Figure(const Figure& other)
	{
		cout << "Called Figure copy constructor\n";
		this->name = other.name;
	}
	Figure(string n) { name = n; cout << "This is Figure constructor\n"; }
	virtual ~Figure() { cout << "This is Figure destructor\n"; }
	virtual void print() { cout << "This Figure is called " << name << endl; }
	virtual void Perimetr() = 0;
	virtual void Area() = 0; 
	virtual void Circumference() = 0;
	virtual void Volume() = 0;
};

class Rectangle :public virtual Figure {
protected:
	vector<Point2D>local;
public:
	int n;
	Rectangle() { //сделать проверку на корректность ввода?
		std::cout << "The Rectangle constructor is called" << endl;
		std::cout << "Name of your rectangle: ";
		cin >> name;
		std::cout << "How many points do you want to put? ";
		std::cin >> n;
		vector<Point2D>local2(n);
		local = local2;
		for (int i = 0; i < n; i++) {
			double x; double y;
			std::cout << "Enter X and Y of "<<i+1<<" point: ";
			std::cin >> x >> y;
			local[i].setX(x); local[i].setY(y);
		}

		for (int i = 0; i < n; i++) {
			local[i].print();
		}
	}

	Rectangle(const Rectangle& other)
	{
		cout << "Called Rectangle copy constructor\n";
		this->name = other.name;
		for (int i = 0; i < local.size(); i++)
			this->local[i] = other.local[i];
	}

	~Rectangle() { std::cout << "The Rectangle destructor is called" << endl; }
	void Circumference() override { cout << "It is not a circle! "; }
	void Perimetr() override {
		cout << "Perimetr search method is called" << endl;
		double result = 0; int k = n - 1;
		for (int i = 0; i < k; i++)
		{
			result += (sqrt(pow((local[i + 1].getX() - local[i].getX()), 2) +
				pow(local[i + 1].getY() - local[i].getY(), 2)));

		}
		result += (sqrt(pow((local[0].getX() - local[n - 1].getX()), 2) +
			(pow(local[0].getY() - local[n - 1].getY(), 2))));
		std::cout << "Perimeter: " << result << endl;
	}
	void Area() override {
		cout << "Area search method is called" << endl;
		cout << "Set the 4 vertices of the rectangle :"<<endl;
		for (int i = 0; i < 4; i++) {
			double x; double y;
			std::cout << "Enter X and Y of " << i + 1 << " point: ";
			std::cin >> x >> y;
			local[i].setX(x); local[i].setY(y);
		}
		double area_ = 1;
		for (int i = 0; i < 2; i++) {
			area_ *= sqrt(pow(local[i].getX() - local[i+1].getX(), 2) + pow(local[i].getY() - local[i+1].getY(), 2));
		}
		std::cout << "Area of rectangle: " << area_<< endl;
	}
	void Volume() override { cout << "No volume for rectangle!"; }
	void print() override { cout << "RECTANGLE with name [" << name <<"] is called "<< endl; }
};

class Triangle :public virtual Figure {
protected:
	vector<Point2D>local;
public:
	Triangle() { //сделать проверку на правильност ввода?
		std::cout << "The Triangle constructor is called" << endl;
		std::cout << "Name of your triangle: ";
		cin >> name;
		std::cout << "How many points do you want to put? ";
		std::cin >> n;
		vector<Point2D>local2(n);
		local = local2;
		for (int i = 0; i < n; i++) {
			double x; double y;
			std::cout << "Enter X and Y of " << i + 1 << " point: ";
			std::cin >> x >> y;
			local[i].setX(x); local[i].setY(y);
		}

		for (int i = 0; i < n; i++) {
			local[i].print();
		}
	}
	Triangle(const Triangle& other)
	{
		cout << "Called Triangle copy constructor\n";
		this->name = other.name;
		for (int i = 0; i < local.size(); i++)
			this->local[i] = other.local[i];
	}

	~Triangle() { std::cout << "The Triangle destructor is called" << endl; }

	void Perimetr() override {
		double result = 0; int k = n - 1;
		for (int i = 0; i < k; i++)
		{
			result += (sqrt(pow((local[i + 1].getX() - local[i].getX()), 2) +
				pow(local[i + 1].getY() - local[i].getY(), 2)));

		}
		result += (sqrt(pow((local[0].getX() - local[n - 1].getX()), 2) +
			(pow(local[0].getY() - local[n - 1].getY(), 2))));
		std::cout << "Perimeter: " << result << endl;
	}
	void Circumference() override { cout << "It is not a circle! "; }
	void Area() override {
		cout << "Area search method is called" << endl;
		cout << "Set the 3 vertices of the triangle :" << endl;
		for (int i = 0; i < 3; i++) {
			double x; double y;
			std::cout << "Enter X and Y of " << i + 1 << " point: ";
			std::cin >> x >> y;
			local[i].setX(x); local[i].setY(y);
		}
		double a = sqrt(pow(local[0].getX() - local[1].getX(), 2) + pow(local[0].getY() - local[1].getY(), 2));
		double b = sqrt(pow(local[1].getX() - local[2].getX(), 2) + pow(local[1].getY() - local[2].getY(), 2));
		double c = sqrt(pow(local[0].getX() - local[2].getX(), 2) + pow(local[0].getY() - local[2].getY(), 2));
		double pr = (a + b + c) / 2;
		std::cout << "Area of triangle: " << sqrt(pr*(pr-a)*(pr-b)*(pr-c))<< endl;
	}
	void Volume() override { cout << "No volume for circle!"; }
	void print() override { cout << "Triangle with name [" << name << "] is called " << endl; }
};

class Circle :public virtual Figure
{
protected:
	vector<Point2D>local;
public:
	Circle() { //сделать проверку на прямоугольник??
		std::cout << "The Circle constructor is called" << endl;
		std::cout << "Name of your circle: ";
		cin >> name;
		std::cout << "How many points do you want to put? ";
		std::cin >> n;
		vector<Point2D>local2(n);
		local = local2;
		for (int i = 0; i < n; i++) {
			double x; double y;
			std::cout << "Enter X and Y of " << i + 1 << " point of circle: ";
			std::cin >> x >> y;
			local[i].setX(x); local[i].setY(y);
		}

		for (int i = 0; i < n; i++) {
			local[i].print();
		}
	}
	Circle(const Circle& other)
	{
		cout << "Called Circle copy constructor\n";
		this->name = other.name;
		for (int i=0;i<local.size();i++)
		this->local[i] = other.local[i];
	}
	~Circle() { cout << "This is Circle destructor\n"; }

	void Circumference() override {  //метод длины окружности
		std::cout << "Circumference search method is called" << endl;
		cout << "Set 2 points of circle (point on circle and center point): " << endl;
		for (int i = 0; i < 2; i++) {
			double x; double y;
			std::cout << "Enter X and Y of " << i + 1 << " point: ";
			std::cin >> x >> y;
			local[i].setX(x); local[i].setY(y);
		}
		double radius = sqrt(pow(local[1].getX() - local[0].getX(), 2) + pow(local[1].getY() - local[0].getY(), 2));
		cout << "Radius of circle is: " << radius << endl;
		cout << "The Circumference of circle is: " << (2 * 3.14 * radius) << endl;
	}
	void Area() override { cout << "No area for circle!" << endl; }
	void Perimetr() override { cout << "No perimeter for circle!" << endl; }
	void Volume() override { cout << "No volume for circle!"; }
	void print() override { cout << "Circle with name [" << name << "] is called " << endl; }
};

class Sphere :public virtual Figure {
protected:
	vector<Point3D>local;
public:
	Sphere() { //сделать проверку на прямоугольник??
		std::cout << "The Sphere constructor is called" << endl;
		std::cout << "Name of your sphere: ";
		cin >> name;
		std::cout << "How many points do you want to put? ";
		std::cin >> n;
		vector<Point3D>local2(n);
		local = local2;
		for (int i = 0; i < n; i++) {
			double x; double y; double z;
			std::cout << "Enter X, Y and Z of " << i + 1 << " point of sphere: ";
			std::cin >> x >> y>>z;
			local[i].setX(x); local[i].setY(y); local[i].setZ(z);
		}

		for (int i = 0; i < n; i++) {
			local[i].print();
		}
	}
	Sphere(const Sphere& other)
	{
		cout << "Sphere copy constructor is called\n";
		this->name = other.name;
		for (int i = 0; i < local.size(); i++)
			this->local[i] = other.local[i];
	}
	~Sphere() { cout << "This is Sphere destructor\n"; }

	void Area() override {
		std::cout << "Area search method is called" << endl;
		cout << "Set 2 points of sphere (point on sphere and center): " << endl;
		for (int i = 0; i < 2; i++) {
			double x; double y; double z;
			std::cout << "Enter X,Y and Z of " << i + 1 << " point of sphere: ";
			std::cin >> x >> y>>z;
			local[i].setX(x); local[i].setY(y); local[i].setZ(z);
		}

		double diam = sqrt(pow(local[1].getX() - local[0].getX(), 2) + pow(local[1].getY() - local[0].getY(), 2) + pow(local[1].getZ() - local[0].getZ(), 2)) * 2;
		double area_ = pow(diam, 2) * 3.14;
		cout << "Area of sphere surface: " << area_ << endl;
	}
	void Circumference() override { cout << "Not sircumference for spere"; }
	void Perimetr() override { cout << "No perimeter for sphere" << endl; }
	void print() override { cout << "Sphere with name [" << name << "] is called " << endl; }
	void Volume() override {
		std::cout << "Volume search method is called" << endl;
		cout << "Set 2 points of sphere (point on sphere and center): " << endl;
		for (int i = 0; i < 2; i++) {
			double x; double y; double z;
			std::cout << "Enter X,Y and Z of " << i + 1 << " point of sphere: ";
			std::cin >> x >> y>>z;
			local[i].setX(x); local[i].setY(y); local[i].setZ(z);
		}
		double radius = sqrt(pow(local[1].getX() - local[0].getX(), 2) + pow(local[1].getY() - local[0].getY(), 2) + pow(local[1].getZ() - local[0].getZ(), 2));
		double vol = pow(radius, 3) * (4.0 / 3.0) * 3.14;
		cout << "Volume of Sphere: " << vol << endl;
	}
};

class Tetrahedron :public virtual Figure {
protected:
	vector<Point3D>local;
public:
	Tetrahedron() {
		std::cout << "The Tetrahedron constructor is called" << endl;
		std::cout << "Name of your tetrahedron: ";
		cin >> name;
		std::cout << "How many points do you want to put? ";
		std::cin >> n;
		vector<Point3D>local2(n);
		local = local2;
		for (int i = 0; i < n; i++) {
			double x; double y; double z;
			std::cout << "Enter X, Y and Z of " << i + 1 << " point of tetrahedron: ";
			std::cin >> x >> y >> z;
			local[i].setX(x); local[i].setY(y); local[i].setZ(z);
		}

		for (int i = 0; i < n; i++) {
			local[i].print();
		}
	}
	Tetrahedron(const Tetrahedron& other)
	{
		cout << "Tetrahedron copy constructor is called\n";
		this->name = other.name;
		for (int i = 0; i < local.size(); i++)
			this->local[i] = other.local[i];
	}
	~Tetrahedron() { cout << "Tetrahedron destructor is called\n"; }

	void Area() override {

		cout << "Area search method is called"<<endl;
		for (int i = 0; i < n; i++) {
			double x; double y; double z;
			std::cout << "Enter X, Y and Z of " << i + 1 << " vertice of tetrahedron: ";
			std::cin >> x >> y >> z;
			local[i].setX(x); local[i].setY(y); local[i].setZ(z);
		}
		double area_ = sqrt(3) * pow(sqrt(pow((local[1].getX() - local[0].getX()), 2) + pow((local[1].getY() - local[0].getY()), 2)+ pow((local[1].getZ() - local[0].getZ()), 2)), 2);
		cout << "Area of Tetrahedron surface " << area_ << endl;
	}
	void Circumference() override { cout << "No sircumference for Tetrahedron"; }
	void Perimetr() override { "Tetrahedron is a 3D figure! Better calculate the volume"; }
	void print() override { cout << "Tetrahedron with name [" << name << "] is called " << endl; }
	void Volume() override {
		cout << "Volume search method is called" << endl;
		for (int i = 0; i < n; i++) {
			double x; double y; double z;
			std::cout << "Enter X, Y and Z of " << i + 1 << " vertice of tetrahedron: ";
			std::cin >> x >> y >> z;
			local[i].setX(x); local[i].setY(y); local[i].setZ(z);
		}
		double volume_ = (pow(sqrt((pow((local[1].getX() - local[0].getX()), 2) + (pow((local[1].getY() - local[0].getY()), 2))+ (pow((local[1].getZ() - local[0].getZ()), 2)))), 3))/(6.0*sqrt(2.0));
		cout << "Volume of tetrahedron: " << volume_<< endl;
	}
};

class Parallelepiped :public virtual Figure {
protected:
	vector<Point3D>local;
public:
	Parallelepiped() {
		std::cout << "The Parallelepiped constructor is called" << endl;
		std::cout << "Name of your parallelepiped: ";
		cin >> name;
		std::cout << "How many points do you want to put? ";
		std::cin >> n;
		vector<Point3D>local2(n);
		local = local2;
		for (int i = 0; i < n; i++) {
			double x; double y; double z;
			std::cout << "Enter X, Y and Z of " << i + 1 << " point of parallelepiped: ";
			std::cin >> x >> y >> z;
			local[i].setX(x); local[i].setY(y); local[i].setZ(z);
		}

		for (int i = 0; i < n; i++) {
			local[i].print();
		}
	}
	Parallelepiped(const Parallelepiped& other)
	{
		std::cout << "Parallelepiped copy constructor is called\n";
		this->name = other.name;
		for (int i = 0; i < local.size(); i++)
			this->local[i] = other.local[i];
	}
	~Parallelepiped() { std::cout << "Parallelepiped destructor is called\n"; }

	void Area() override {

		std::cout << "Area search method is called" << endl;
		for (int i = 0; i < 4; i++) {
			double x; double y; double z;
			std::cout << "Enter X, Y and Z of " << i + 1 << " vertice of parallelepiped: ";
			std::cin >> x >> y >> z;
			local[i].setX(x); local[i].setY(y); local[i].setZ(z);
		}

		double r1 = sqrt(pow(local[0].getX() - local[1].getX(), 2) + pow(local[0].getY() - local[1].getY(), 2) + pow(local[0].getZ() - local[1].getZ(), 2));
		double r2 = sqrt(pow(local[0].getX() - local[2].getX(), 2) + pow(local[0].getY() - local[2].getY(), 2) + pow(local[0].getZ() - local[2].getZ(), 2));
		double r3 = sqrt(pow(local[0].getX() - local[3].getX(), 2) + pow(local[0].getY() - local[3].getY(), 2) + pow(local[0].getZ() - local[3].getZ(), 2));


		cout << "Area of Parallelepiped surface " << (r1*r2)*2+(r1*r3)*2+(r2*r3)*2 << endl;
	}

	void Circumference() override { cout << "No sircumference for Parallelepiped"; }
	void Perimetr() override { "Parallelepiped is a 3D figure! Better calculate the volume"; }
	void print() override { cout << "Parallelepiped with name [" << name << "] is called " << endl; }
	void Volume() override {
		cout << "Volume search method is called" << endl;
		for (int i = 0; i < 4; i++) {
			double x; double y; double z;
			std::cout << "Enter X, Y and Z of " << i + 1 << " vertice of parallelepiped: ";
			std::cin >> x >> y >> z;
			local[i].setX(x); local[i].setY(y); local[i].setZ(z);
		}
		double volume_ = 0;
		for (int i = 1; i < 4; i++) {
			volume_*= sqrt(pow(local[0].getX() - local[i].getX(), 2) + pow(local[0].getY() - local[i].getY(), 2) + pow(local[0].getZ() - local[i].getZ(), 2));
		}
		cout << "Volume of Parallelepiped: " << volume_<< endl;
	}
};

class Random_Figure:public virtual Figure {
public:
	int n;
	vector<Point2D>local;
	Random_Figure() {
		std::cout << "The RANDOM FIGURE constructor is called" << endl;
		std::cout << "Name of your Random Figure: ";
		cin >> name;
		std::cout << "How many points do you want to put? ";
		std::cin >> n;
		vector<Point2D>local2(n);
		local = local2;
		for (int i = 0; i < n; i++) {
			double x; double y; 
			std::cout << "Enter X and Y of " << i + 1 << " point: ";
			std::cin >> x >> y;
			local[i].setX(x); local[i].setY(y);
		}
	}
	Random_Figure(const Random_Figure& other)
	{
		std::cout << "Random_Figure copy constructor is called\n";
		this->name = other.name;
		for (int i = 0; i < local.size(); i++)
			this->local[i] = other.local[i];
	}

	~Random_Figure() {std::cout << "This is destructor of Random Figure;" << endl;}
	void Perimetr() override {
		std::cout << "Perimetr search method is called" << endl;
		double result = 0; int k = n - 1;
		for (int i = 0; i <k; i++)
		{
			result += (sqrt(pow((local[i+1].getX() - local[i].getX()), 2) +
				pow(local[i + 1].getY() - local[i].getY(), 2)));
		}
		result += (sqrt(pow((local[0].getX() - local[n - 1].getX()), 2) + 
			(pow(local[0].getY() - local[n - 1].getY(), 2))));
		std::cout << "Perimeter: " << result << endl;
	}
	void Circumference() override { cout << "No sircumference for Random Figure"; }
	void print() override { cout << "Random Figure with name [" << name << "] is called " << endl; }
	void Volume() override {};
	void Area() override {};
};

string What_Figure(Random_Figure A) {
	std::cout << "Find the type of figure"<<endl;
	bool cond_side = 1; bool cond_diag = 1;
	string figure_type;
	int i; int k = A.n - 1;
	vector<float>sides(A.n);
	for (i = 0; i < k; i++) {
		sides[i]=(sqrt(pow((A.local[i + 1].getX() - A.local[i].getX()), 2) + pow((A.local[i + 1].getY() - A.local [i] .getY()), 2)));
	}
	sides[A.n-1]= sqrt(pow((A.local[0].getX() - A.local[A.n-1].getX()), 2) + pow((A.local[0].getY() - A.local[A.n-1].getY()), 2));
	float d1=0; float d2=0;
	d1 = sqrt(pow(A.local[2].getX() - A.local[0].getX(), 2) + (pow(A.local[2].getY() - A.local[0].getY(), 2)));
	d2 = sqrt(pow(A.local[1].getX() - A.local[3].getX(), 2) + (pow(A.local[1].getY() - A.local[3].getY(), 2)));

	float index_ = sides[0];
	for (i = 1; i < A.n; i++) {
		if (sides[i] != index_) { cond_side = 0; }
		else cond_side = 1;
	}
	if (d1 != d2) { cond_diag = 0; }
	else cond_diag = 1;
	if ((cond_diag == 1) && (cond_side == 1)) { figure_type = "Square"; }
	if ((cond_diag == 0) && (cond_side == 1)) { figure_type = "Rhombus"; }
	if ((cond_diag == 1) && (cond_side == 0)) { figure_type = "Rectangle"; }
	if ((cond_diag == 0) && (cond_side == 0)) { figure_type = "Geometric figure"; }
	
	return figure_type;
	sides.clear();
}

string Triangle_Type(Random_Figure A) {
	std::cout << "Find the type of triangle";
	string tr_type;
	int i; int i2 = A.n - 1;
	vector<float>sides(A.n);
	for (i = 0; i < i2; i++) {
		sides[i] = (sqrt(pow((A.local[i + 1].getX() - A.local[i].getX()), 2) + pow((A.local[i + 1].getY() - A.local[i].getY()), 2)));
	}
	sides[A.n-1]= (sqrt(pow((A.local[0].getX() - A.local[A.n-1].getX()), 2) + pow((A.local[0].getY() - A.local[A.n-1].getY()), 2)));


	if (sides[0] >= sides[1] + sides[2] || sides[1] >= sides[0] + sides[2] || sides[2] >= sides[0] + sides[1])
	{
		tr_type = "This is not a triangle";
		return tr_type;
		sides.clear();
	}
	else
		if (pow(sides[0],2) == pow(sides[1],2)+ pow(sides[2],2)|| pow(sides[1],2) == pow(sides[0],2) + pow(sides[2],2) || pow(sides[2],2) ==pow(sides[0],2) + pow(sides[1],2))
			tr_type ="Right triangle";
		else
			if (pow(sides[0],2) > pow(sides[1],2) + pow(sides[2],2) || pow(sides[1],2) > pow(sides[0],2) + pow(sides[2],2) || pow(sides[2],2) > pow(sides[0],2) + pow(sides[1],2))
				tr_type = "Obtuse triangle";
			else
				tr_type="Acute-angled triangle";

	return tr_type;
	sides.clear();
}

int main() {

	//Random_Figure R;
	//R.Perimetr();
	//cout << "----------------------------------" << endl;


	//Rectangle new_rectangle;
	//new_rectangle.print();
	//new_rectangle.Perimetr();
	//new_rectangle.Area();
	//cout << "----------------------------------" << endl;
	

	/*Triangle new_triangle;
	new_triangle.print();
	new_triangle.Perimetr();
	new_triangle.Area();
	cout << "----------------------------------" << endl;*/

	/*Circle new_circle;
	new_circle.print();
	new_circle.Circumference();
	cout << "----------------------------------" << endl;*/

	/*Sphere new_sphere;
	new_sphere.print();
	new_sphere.Area();
	new_sphere.Volume();
	cout << "----------------------------------" << endl; */

	/*Tetrahedron new_tetra;
	new_tetra.print();
	new_tetra.Volume();
	new_tetra.Area();
	cout << "----------------------------------" << endl; */


	/*Parallelepiped new_par;
	new_par.print();
	new_par.Area();
	new_par.Volume();*/


	Random_Figure new_figure0;
	new_figure0.print();
	new_figure0.Perimetr();


	Random_Figure new_figure;
	cout << "----------------------------------" << endl;
	std::cout << "What's the figure? It's " << What_Figure(new_figure) << endl;;
	cout << "----------------------------------" << endl;

	Random_Figure new_figure2;
	cout << "----------------------------------" << endl;
	std::cout << "What type of triangle? It's " << Triangle_Type(new_figure2) << endl;;
	cout << "----------------------------------" << endl;
}








