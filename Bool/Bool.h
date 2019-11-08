#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Kar
{
private:
	int Matrix[4][4];
public:
	Kar(); // Hàm tạo bảng Kar không đối số , phẩn tử bằng 0
	void GetMatrix(int matrix[4][4]); // Hàm gán giá trị matrix của Kar cho tham số matrix[4][4]
	void SetMatrix(); // Hàm nhập matrix bằng các đa thức
	void Solve(string); // Hàm xử lí chuỗi đa thức nhập vào bảng Kar
	void SolveString(string); // Hàm xử lí 1 đa thức nhập vào bảng Kar
	void drawKar(); // Hàm in bảng Kar
};
