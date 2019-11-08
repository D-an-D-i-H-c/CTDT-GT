#include <iostream>
using namespace std;

class Vector
{
private:
	int factor[100]; // Mảng chứa phần tử
	int n; // Số phần tử của vector
public:
	Vector(); // Hàm tạo 1 vector với 1 phần tử , phần tử đó bằng 0
	Vector(int a[], int n); // Hàm tạo vector với phần tử bằng phần tử mảng a và độ dài n
	~Vector(); // Hàm xóa vector
	Vector Add(const Vector); // Hàm cộng 2 vector
	Vector Multiply(int alpha); // Hàm nhân vector với một số alpha
	void Xuat();
	void Nhap();
	int KTRong();
};
