#include "Vector.h"

Vector::Vector()
{
	int n = 1;
	this->factor[0] = 0;
}
Vector::Vector(int a[], int n)
{
	this->n = n; // Cho n của class Vector bằng với biến n 
	for (int i = 0; i < n; i++)
	{
		this->factor[i] = a[i]; // Gán giá trị của a[i] cho class Vector
	}
}
Vector::~Vector()
{}
Vector Vector::Add(Vector temp)
{
	Vector KQ;
	KQ.n = 0;
	KQ.factor[0] = NULL;
	// Xét độ dài của temp và của class , nếu khác nhau thì không cộng được
	if (temp.n != this->n) return KQ;
	// Gán độ dài của this cho KQ
	KQ.n = this->n;
	// Duyệt qua mảng , cộng 2 phần tử lưu vào KQ
	for (int i = 0; i < this->n; i++)
	{
		KQ.factor[i] = this->factor[i] + temp.factor[i];
	}
	return KQ;
}
Vector Vector::Multiply(int alpha)
{
	Vector KQ;
	KQ.n = this->n;
	// Duyệt qua mảng , nhân từng phần tử với alpha
	for (int i = 0; i < this->n; i++)
	{
		KQ.factor[i] = alpha*this->factor[i];
	}
	return KQ;
}
void Vector::Xuat()
{
	// Duyet qua mang , xuat ra phan tu cua vector
	for (int i = 0; i < this->n; i++)
	{
		cout << this->factor[i] << " ";
	}
	cout << endl;
}
void Vector::Nhap()
{
	// Yeu cau nhap vao phan tu cua mang
	cout << "Nhap so phan tu cua vector : ";
	cin >> this->n;
	cout << endl;
	for (int i = 0; i < this->n; i++)
	{
		// Duyet qua mang, yeu cau nhap vao tung phan tu
		cout << "Nhap phan tu thu " << i + 1 << " : ";
		cin >> this->factor[i];
		cout << endl;
	}
}
int Vector::KTRong()
{
	if (this->n == 0) return 1;
	return 0;
}
