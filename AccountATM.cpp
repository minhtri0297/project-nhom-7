#include <iostream>
#include "AccountATM.h"
#include <Windows.h>
using namespace std;

void Acc::setUserName(char x[])
{
	strcpy_s(UserName, x);
}
void Acc::setPassWord(char x[])
{
	strcpy_s(PassWord, x);
}
void Acc::setID(char x[])
{
	strcpy_s(ID, x);
}
void Acc::setSoDuTaiKhoan(float d)
{
	SoDuTaiKhoan = d;
}
//xuat thong tin
void Acc::Xuat()
{
	cout << "\nID: " << ID;
	cout << "\nSo du tai khoan: " << SoDuTaiKhoan;
}
//ham xuat ID
char* Acc::getID()
{
	return ID;
}
char* Acc::getUserName()
{
	return UserName;
}
char* Acc::getPassWord()
{
	return PassWord;
}
//gui tien
void Acc::CongTien(float Tien)
{
	SoDuTaiKhoan = SoDuTaiKhoan + Tien;
}
//rut tien
void Acc::TruTien(float Tien)
{
	SoDuTaiKhoan = SoDuTaiKhoan - Tien;
}
void Acc::DoiPass(char x[])
{
	strcpy_s(PassWord, x);
}
//tra ve so tien trong tai khoan
double Acc::getSoDuTaiKhoan()
{
	return SoDuTaiKhoan;
}