#pragma once
#include<iostream>
using namespace std;
const int MAX = 30;
void Input(double a[][MAX],int& m, int& n);
void Output(double a[][MAX], int m, int n);
double determinant(double matrix[][MAX], int n);
void inverse(double a[][MAX], int n, double b[][MAX]);
void Tich(double a[][MAX], double b[][MAX], double c[][MAX], int m, int n, int p);
int Rank(double a[][MAX], int soHang, int soCot);
void Solve(double a[][MAX], double b[][MAX], int m, int n);