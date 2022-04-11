/*
Итак, задание лабораторной работы №3 следующее:
++ 1) Реализовать абстрактный класс «Point» (точка), который наследуют классы «Point2D» и «Point3D».
2) Создать абстрактный класс «Figure» (фигура), у которого есть методы нахождения периметра и площади/объема фигуры, 
а также метод print(), т.е. вывод информации о точках фигуры. 

 - Атрибутами класса «Figure» являются множество точек, а также поле name (имя фигуры). 
 - Все они должны быть защищенными, а взаимодействие с ними должно быть реализовано через set и get методы.


3) От класса «Figure» наследуются классы «Треугольник», «Окружность», «Прямоугольник», «Сфера», «Тетраэдр» и 
«Параллелепипед» и реализуют соответствующие методы. 

 - У всех классов должны быть реализованы конструктор, конструктор копирования и деструктор. 
 - В каждом из них, помимо необходимых операций (если таковые имеются), нужно выводить сообщение о том, 
какой конструктор/деструктор вызывается.

Небольшое пояснение. Решить проблему с тем, что есть как 2D, так и 3D фигуры, 
из-за чего нужно использовать разные типы точек, можно различными способами:


Cамый топорный - всегда использовать 3D точки.
Вместо определения множества точек в классе «Figure», определять -множество точек соответствующего типа- внутри классов-наследников.
Использовать std::vector<Point*>. В данной лабораторной работе вы можете его использовать.


*/


#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Point //АБСТРАКТНЫЙ КЛАСС POINT
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
	void setZ(double y_)override { cout<<"Error!"; }
	void print() { cout << x << " " << y <<"\n"; }
	Point2D() :x(0), y(0) {}
	Point2D(double a, double b) :x(a), y(b) {} //констурктор класса Point3D

};

class Point3D:public Point {
	
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
	Point3D(double a, double b, double c) :x(a), y(b), z(c) {} //констурктор класса Point3D

};

class Figure //АБСТРАКТНЫЙ КЛАСС FIGURE
{
protected:
	string name;
public:
	string get_name() { return name; }
	Figure() {
		name = ""; cout << "This is Figure default constructor\n"; }
	Figure(const Figure& other)
	{
		cout << "Called Figure copy constructor\n";
		this->name = other.name;
	}
	Figure(string n) { name = n; cout << "This is Figure constructor\n"; }
	virtual ~Figure() { cout << "This is Figure destructor\n"; }
	virtual void print() { cout << "This Figure is called " << name << endl; }
	virtual void Area() = 0; //метод площади
	virtual void Perimeter() = 0; //метод параметра
	virtual void Circumference() = 0;//метод длины окружности
	virtual void Volume() = 0; //метод объёма
};

class Rectangle :public virtual Figure
{
private:
	//Point2D** data[];
	Point2D v1_, v2_, v3_,v4_;
public:
	Rectangle(Point2D v1, Point2D v2, Point2D v3, Point2D v4, string n=" ")
	{
		name = n;
		v1_.setX(v1.getX()); v1_.setY(v1.getY()); 
		v2_.setX(v2.getX()); v2_.setY(v2.getY()); 
		v3_.setX(v3.getX()); v3_.setY(v3.getY()); 
		v4_.setX(v4.getX()); v4_.setY(v4.getY()); 
		cout << "This is RECTANGLE constructor\n";
	}

	Rectangle(const Rectangle& other)
	{
		cout << "Called RECTANGLE copy constructor\n";
		this->name = other.name;
		this->v1_ = other.v1_;
		this->v2_=other.v2_;
		this->v3_ = other.v3_;
		this->v4_ = other.v4_;
	}
	
	~Rectangle() { cout << "This is RECTANGLE destructor\n"; }
	void Area() override {
		double a = (sqrt(pow(v4_.getX() - v1_.getX(), 2) + pow(v4_.getY() - v1_.getY(), 2)));
		double b = (sqrt((pow(v2_.getX() - v1_.getX(), 2) + pow(v2_.getY() - v1_.getY(), 2))));
		cout << "Area of RECTANGLE: " << a*b <<"\n";}

	void print() override { cout << "RECTANGLE is called " << name << endl; }
	void Perimeter() override { 
		double a = (sqrt(pow(v4_.getX() - v1_.getX(), 2) + pow(v4_.getY() - v1_.getY(), 2)));
		double b = (sqrt((pow(v2_.getX() - v1_.getX(), 2) + pow(v2_.getY() - v1_.getY(), 2))));
		cout << "Perimeter of RECTANGLE: "<<(a+b)*2<<"\n"; }

	void Circumference() override { cout << "It is NOT a circle!" << endl; }
	void Volume() override { cout << "It is NOT 3D figure!" << endl;}
}; 




class Triangle :public virtual Figure
{
private:
	Point2D v1_, v2_, v3_;
public:
	Triangle(Point2D v1, Point2D v2, Point2D v3,string n="")
	{
		name = n;
		v1_.setX(v1.getX()); v1_.setY(v1.getY()); 
		v2_.setX(v2.getX()); v2_.setY(v2.getY()); 
		v3_.setX(v3.getX()); v3_.setY(v3.getY());
		cout << "This is TRIANGLE constructor\n";
	}

	Triangle(const Triangle& other)
	{
		cout << "Called Triangle copy constructor\n";
		this->name = other.name;
		this->v1_ = other.v1_;
		this->v2_ = other.v2_;
		this->v3_ = other.v3_;
	}
	~Triangle() { cout << "This is Triangle destructor\n"; }

	void Area() override { 
		double a = sqrt(pow(v2_.getX() - v1_.getX(), 2) + pow(v2_.getY() - v1_.getY(), 2));
		double b = sqrt(pow(v3_.getX() - v1_.getX(), 2) + pow(v3_.getY() - v1_.getY(), 2));
		double c = sqrt(pow(v3_.getX() - v2_.getX(), 2) + pow(v3_.getY() - v2_.getY(), 2));
		double pr = ((a + b + c) / 2);
		double area_ = (sqrt(pr * (pr - a) * (pr - b) * (pr - c)));
		cout <<"Area of TRIANGLE: "<<area_<<"\n"; }
	void print() override { cout << "TRIANGLE is called " << name << endl; }
	void Circumference() override {cout << "It is not a Circle!" << endl; }
	void Perimeter() override { 
		double a = sqrt(pow(v2_.getX() - v1_.getX(), 2) + pow(v2_.getY() - v1_.getY(), 2));
		double b = sqrt(pow(v3_.getX() - v1_.getX(), 2) + pow(v3_.getY() - v1_.getY(), 2));
		double c = sqrt(pow(v3_.getX() - v2_.getX(), 2) + pow(v3_.getY() - v2_.getY(), 2));
		double sum = a + b + c;
		cout <<"Perimeter of TRIANGLE: "<<sum<<"\n"; }
	void Volume() override { cout << "It's NOT a 3D FIGURE!" << endl; }
};

class Circle :public virtual Figure
{
private:
	Point2D v1_; Point2D v2_;
public:
	Circle(Point2D a, Point2D b,string n=" ") { 
		v1_.setX(a.getX()); v1_.setY(a.getY());
		v2_.setX(b.getX()); v2_.setY(b.getY());
		name = n;
		cout << "This is CIRCLE constructor\n";
		}

	Circle(const Circle& other)
	{
		cout << "Called Circle copy constructor\n";
		this->name = other.name;
		this->v1_ = other.v1_;
		this->v2_ = other.v2_;
	}
	~Circle() { cout << "This is Circle destructor\n"; }

	void Circumference () override {  //метод длины окружности
		double radius = sqrt(pow(v2_.getX() - v1_.getX(), 2) + pow(v2_.getY() - v1_.getY(), 2));
		cout << "Radius of CIRCLE is: " << radius << endl;
		cout << "The Circumference of CIRCLE is: " << (2 * 3.14 * radius)<< endl;
	}
	void Area() override { cout << "No area for circle!" << endl; }
	void Perimeter() override { cout << "No perimeter for circle!" << endl; }
	void Volume() override { cout << "No volume for Circle!" << endl; }
	void print() override { cout << "CIRCLE is called " << name << endl; }
};


class Sphere :public virtual Figure {
private:
	Point3D v1_, v2_;
public:
	Sphere(Point3D a, Point3D b, string n="") {
		v1_.setX(a.getX()); v1_.setY(a.getY()); v1_.setZ(a.getZ());
		v2_.setX(b.getX()); v2_.setY(b.getY()); v2_.setZ(b.getZ());
		name = n;
		cout << "This is Sphere constructor\n";
	}

	Sphere(const Sphere& other)
	{
		cout << "Called Sphere copy constructor\n";
		this->name = other.name;
		this->v1_ = other.v1_; this->v2_ = other.v2_;
	}
	~Sphere() { cout << "This is Sphere destructor\n"; }

	void Area() override { 
		double diam = sqrt(pow(v2_.getX() - v1_.getX(), 2) + pow(v2_.getY() - v1_.getY(), 2) + pow(v2_.getZ() - v1_.getZ(), 2)) * 2;
		double area_ = pow(diam, 2) * 3.14;
		cout << "Area of sphere surface: "<<area_<< endl; }
	void Circumference() override { cout << "Not sircumference for spere";}
	void Perimeter() override { cout << "No perimeter for sphere" << endl; }
	void print() override { cout << "SPHERE is called " << name << endl; }
	void Volume() override { 
		double radius = sqrt(pow(v2_.getX() - v1_.getX(), 2) + pow(v2_.getY() - v1_.getY(), 2) + pow(v2_.getZ() - v1_.getZ(), 2));
		double vol = pow(radius, 3) * (4.0 / 3.0) * 3.14;
		cout << "Volume of Sphere: " << vol<<endl; }


};

class Tetrahedron :public virtual Figure {
	Point3D v1_, v2_, v3_,v4_;
public:
	Tetrahedron(Point3D a, Point3D b, Point3D c, Point3D d, string n="") {
		v1_.setX(a.getX()); v1_.setY(a.getY()); v1_.setZ(a.getZ());
		v2_.setX(b.getX()); v2_.setY(b.getY()); v2_.setZ(b.getZ());
		v3_.setX(c.getX()); v3_.setY(c.getY()); v3_.setZ(c.getZ());
		v4_.setX(d.getX()); v4_.setY(d.getY()); v4_.setZ(d.getZ());
		name = n;
		cout << "This is TETRAHEDRON constructor\n";
	}

	Tetrahedron(const Tetrahedron& other)
	{
		cout << "Called Tetrahedron copy constructor\n";
		this->name = other.name;
		this->v1_ = other.v1_; this->v2_ = other.v2_;
		this->v3_ = other.v3_; this->v4_ = other.v4_;
	}
	~Tetrahedron() { cout << "This is Tetrahedron destructor\n"; }

	void Area() override { 
		cout << "Area of Tetrahedron surface" << "\n" << endl; }
	void Circumference() override { cout << "No sircumference for Tetrahedron"; }
	void Perimeter() override { 
		double r1 = sqrt(pow(v2_.getX() - v3_.getX(), 2) + pow(v2_.getY() - v3_.getY(), 2) + pow(v2_.getZ() - v3_.getZ(), 2));
		double r2 = sqrt(pow(v3_.getX() - v4_.getX(), 2) + pow(v3_.getY() - v4_.getY(), 2) + pow(v3_.getZ() - v4_.getZ(), 2));
		double r3 = sqrt(pow(v4_.getX() - v1_.getX(), 2) + pow(v4_.getY() - v1_.getY(), 2) + pow(v4_.getZ() - v1_.getZ(), 2));
		double r4 = sqrt(pow(v2_.getX() - v1_.getX(), 2) + pow(v2_.getY() - v1_.getY(), 2) + pow(v2_.getZ() - v1_.getZ(), 2));
		double r5 = sqrt(pow(v1_.getX() - v3_.getX(), 2) + pow(v1_.getY() - v3_.getY(), 2) + pow(v1_.getZ() - v3_.getZ(), 2));
		double r6 = sqrt(pow(v1_.getX() - v4_.getX(), 2) + pow(v1_.getY() - v4_.getY(), 2) + pow(v1_.getZ() - v4_.getZ(), 2));
		double p = r1 + r2 + r3 + r4 + r5 + r6;
		
		cout << "Perimeter of Tetrahedron: " <<p<< endl; }
	void print() override { cout << "TETRAHEDRON is called " << name << endl; }
	void Volume() override {
		double height = sqrt(2.0 / 3.0) * sqrt(pow(v2_.getX() - v1_.getX(), 2) + pow(v2_.getY() - v1_.getY(), 2) + pow(v2_.getZ() - v1_.getZ(), 2));
		cout << "HEIGHT: " << height << endl;
		double a = sqrt(pow(v2_.getX() - v3_.getX(), 2) + pow(v2_.getY() - v3_.getY(), 2) + pow(v2_.getZ() - v3_.getZ(), 2));
		double b = sqrt(pow(v3_.getX() - v4_.getX(), 2) + pow(v3_.getY() - v4_.getY(), 2) + pow(v3_.getZ() - v4_.getZ(), 2));
		double c = sqrt(pow(v4_.getX() - v2_.getX(), 2) + pow(v4_.getY() - v2_.getY(), 2) + pow(v4_.getZ() - v2_.getZ(), 2));
		double pr = ((a + b + c) / 2);
		double area_ = (sqrt(pr * (pr - a) * (pr - b) * (pr - c)));
		cout << "ploshad " << area_ << endl;
		cout << "Volume of TETRAHEDRON: " << (area_*(1.0/3.0))*height<<endl;
		
	}

};

class Parallelepiped :public virtual Figure {
	Point3D v1_, v2_, v3_,v4_;
public:
	Parallelepiped(Point3D a, Point3D b, Point3D c,Point3D d,string n=" ") {
		v1_.setX(a.getX()); v1_.setY(a.getY()); v1_.setZ(a.getZ());
		v2_.setX(b.getX()); v2_.setY(b.getY()); v2_.setZ(b.getZ());
		v3_.setX(c.getX()); v3_.setY(c.getY()); v3_.setZ(c.getZ());
		v4_.setX(d.getX()); v4_.setY(d.getY()); v4_.setZ(d.getZ());
		name = n;
		cout << "This is PARALLELEPIPED constructor\n";
	}

	Parallelepiped(const Parallelepiped& other)
	{
		cout << "Called Parallelepiped copy constructor\n";
		this->name = other.name;
		this->v1_ = other.v1_; this->v2_ = other.v2_; this->v3_ = other.v3_; this->v4_ = other.v4_;

	}
	~Parallelepiped() { cout << "This is Parallelepiped destructor\n"; }

	void Area() override { 
		double r1 = sqrt(pow(v1_.getX() - v2_.getX(), 2) + pow(v1_.getY() - v2_.getY(), 2) + pow(v1_.getZ() - v2_.getZ(), 2));
		double r2 = sqrt(pow(v1_.getX() - v3_.getX(), 2) + pow(v1_.getY() - v3_.getY(), 2) + pow(v1_.getZ() - v3_.getZ(), 2));
		double r3 = sqrt(pow(v1_.getX() - v4_.getX(), 2) + pow(v1_.getY() - v4_.getY(), 2) + pow(v1_.getZ() - v4_.getZ(), 2));
		
		double s_pov1 = r3 * r2;
		double s_pov2 = r1 * r2;
		double s_pov3 = r3 * r1;
		
		double it_pov = (s_pov1 * 2) + (s_pov2 * 2) + (s_pov3 * 2);
		cout << "Area of Parallelepiped surface: " <<it_pov<< endl; }
	void Circumference() override { cout << "No sircumference for Parallelepiped"; }
	void Perimeter() override {
		double r1 = sqrt(pow(v1_.getX() - v2_.getX(), 2) + pow(v1_.getY() - v2_.getY(), 2) + pow(v1_.getZ() - v2_.getZ(), 2));
		double r2 = sqrt(pow(v1_.getX() - v3_.getX(), 2) + pow(v1_.getY() - v3_.getY(), 2) + pow(v1_.getZ() - v3_.getZ(), 2));
		double r3 = sqrt(pow(v1_.getX() - v4_.getX(), 2) + pow(v1_.getY() - v4_.getY(), 2) + pow(v1_.getZ() - v4_.getZ(), 2));

		double p = (r1 * 4) + (r2 * 4) + (r3 * 4);
		cout << "Perimeter of Parallelepiped: " << p << endl;
	}
	void print() override { cout << "Parallelepiped is called " << name << endl; }
	void Volume() override {
		double r1 = sqrt(pow(v1_.getX() - v2_.getX(), 2) + pow(v1_.getY() - v2_.getY(), 2) + pow(v1_.getZ() - v2_.getZ(), 2));
		double r2 = sqrt(pow(v1_.getX() - v4_.getX(), 2) + pow(v1_.getY() - v4_.getY(), 2) + pow(v1_.getZ() - v4_.getZ(), 2));
		double r3 = sqrt(pow(v1_.getX() - v3_.getX(), 2) + pow(v1_.getY() - v3_.getY(), 2) + pow(v1_.getZ() - v3_.getZ(), 2));
		double S_osn = r1*r2;
		double vol = S_osn * r3;
		cout << "Volume of Parallelepiped: " <<vol << endl;

	}

};


int main(){

	//double x = 1; double y = 1;
	//Figure* rec1 = new Rectangle();

	//ТЕСТ НА RECTANGLE
	Point2D A(0, 0);
	Point2D B(0, 5);
	Point2D C(10, 5);
	Point2D D(10, 0);
	Rectangle R(A,B,C,D,"first rectangle");
	R.print();
	R.Area();
	R.Perimeter();
	cout <<endl << "--------------------" << endl<<endl;

	Point2D A2(0, 0);
	Point2D B2(0, 5);
	Point2D C2(10, 5);
	Point2D D2(10, 0);
	Rectangle R2(A2, B2, C2, D2, "second rectangle");
	R2.print();
	R2.Area();
	R2.Perimeter();
	cout << endl << "--------------------" << endl << endl;


	//ТЕСТ НА TRIANGLE
	Point2D Q (0, 0);
	Point2D W (0,5);
	Point2D E(5, 0);
	Triangle T(Q, W, E,"new triangle");
	T.print();
	T.Perimeter();
	T.Area();
	cout << endl<< "--------------------" << endl<<endl;

	//ТЕСТ НА CIRCLE

	Point2D S(0, 0);
	Point2D tochka(5, 0);
	Circle cir(S, tochka,"new circle");
	cir.print();
	cir.Circumference();
	cout << "--------------------" << endl << endl;

	Point3D center(0, 0, 0);
	Point3D sp(5, 0, 0);
	Sphere SS(center, sp, "new sphere");
	SS.print();
	SS.Volume();
	SS.Area();

	cout << "--------------------" << endl << endl;


	//ТЕСТ НА ТЕТРАЭДР

	Point3D t1(2,5,7); //a найти площадь основания bcd
	Point3D t2(1,-3,2);//b
	Point3D t3(2,3,7);//c
	Point3D t4(3,6,0);//d
	Tetrahedron n (t1, t2, t3, t4, "new tetraedr");
	n.Volume();
	n.Area();
	n.Perimeter();

	cout << "--------------------" << endl << endl;
	Point3D p1(0, 0, 0); //a найти площадь основания bcd
	Point3D p2(10, 0, 0);//b
	Point3D p3(0, 5, 0);//c
	Point3D p4(0, 0, 2);//d
	Parallelepiped p0(p1, p2, p3, p4,"new parallelepiped");
	p0.Volume();
	p0.Area();
	p0.Perimeter();
	cout << "--------------------" << endl << endl;



	//Rectangle R((0, 0), (0, 5), (10, 5), (10, 0));
	//R.Description();
	return 0;
}