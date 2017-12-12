#include "AccountATM.h"
#include "iostream"
#include <Windows.h>
#include <fstream>
using namespace std;
void setThongTin(Acc p[], int &n);
int chiSoI(Acc p[], int n, char ten[], char pass[]);
void chuyenTien(Acc p[], int n, char ten[], char pass[], HANDLE hConsoleColor);
int dangNhap(Acc p[], int n, char ten[], char pass[], HANDLE hConsoleColor);
void doiPass(Acc p[], int n, char ten[], char pass[], HANDLE hConsoleColor);
void ghiFile(Acc p[], int n);
int isID(Acc p[], int n, char x[]);
void Menu(Acc p[], int n, HANDLE hConsoleColor);
void rutTien(Acc p[], int n, char ten[], char pass[], HANDLE hConsoleColor);


//void XuatThongTin(Acc p[], int n);

int main()
{
	//*doi mau chu
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	//**************************************************
	///////////////////////////////////////////////////

	Acc *p = new Acc[20];
	int n = 0; //so luong account sau khi doc file 

	setThongTin(p, n);
	
	Menu(p, n, hConsoleColor);

	cout << endl;
	system("pause");
	return 0;
}

//ham doc thong tin tu file vao bo nho
void setThongTin(Acc p[], int &n)
{
	fstream f;
	f.open("file[ID].dat", ios::in);//vi chac chan co file nen khong can kiem tra
	int i = 0;
	
	n = 0;
	while (!f.eof())
	{
		if (i % 4 == 0)
		{
			char x[20];
			f >> x;
			p[n].setUserName(x);
			
		}
		if (i % 4 == 1)
		{
			char x[20];
			f >> x;
			p[n].setPassWord(x);
			
		}
		if (i % 4 == 2)
		{
			char x[20];
			f >> x;
			p[n].setID(x);
			
		}
		if (i % 4 == 3)
		{
			char x[20];
			f >> x;
			float tam = atof(x);
			p[n].setSoDuTaiKhoan(tam);
			
			n++;
		}
		i++;
	}
	f.close();
}
//void XuatThongTin(Acc p[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		p[i].Xuat();
//	}
//}
//ham dang nhap
int dangNhap(Acc p[], int n, char ten[], char pass[], HANDLE hConsoleColor)
{
	int dem = 1;
	int tam = 0;
	do
	{
		system("cls");
		cout << "\nLuu y: nhap sai toi da 3 lan !";
		SetConsoleTextAttribute(hConsoleColor, 9);
		cout << "\t\t\n******************************";
		cout << "\t\t\n*        ";
		SetConsoleTextAttribute(hConsoleColor, 12);
		cout << "DANG NHAP";
		SetConsoleTextAttribute(hConsoleColor, 9);
		cout << "           *";
		cout << "\t\t\n******************************";
		SetConsoleTextAttribute(hConsoleColor, 7);
		SetConsoleTextAttribute(hConsoleColor, 11);
		cout << "\nUserName: ";
		cin.getline(ten, 20);
		cout << "\nPassWord: ";
		cin.getline(pass, 20);;
		SetConsoleTextAttribute(hConsoleColor, 7);
		for (int i = 0; i < n; i++)
		{
			if (_strcmpi(ten, p[i].getUserName()) == 0 && _strcmpi(pass, p[i].getPassWord()) == 0)
			{
				cout << "\nLoading...";
				Sleep(1500);
				system("cls");
				SetConsoleTextAttribute(hConsoleColor, 10);
				cout << "\nDang nhap thanh cong !";
				SetConsoleTextAttribute(hConsoleColor, 7);
				return 1;
				
			}
		}
		dem++;
	} while (dem <= 3);
	cout << "\nDang nhap that bai ! ...";
	Sleep(2000);
	exit(1);
}
//ghi file sau moi lan thuc hien giao dich
void ghiFile(Acc p[], int n)
{
	fstream f;
	f.open("file[ID].dat", ios::out);
	for (int i = 0; i < n; i++)
	{
		f << p[i].getUserName() << "\n";
		f << p[i].getPassWord() << "\n";
		f << p[i].getID() << "\n";
		f << p[i].getSoDuTaiKhoan() << "\n";
	}
	f.close();
}
//tim vi tri i cua account cua mang dang dang nhap
int chiSoI(Acc p[], int n, char ten[], char pass[])
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (_strcmpi(ten, p[i].getUserName()) == 0 && _strcmpi(pass, p[i].getPassWord()) == 0)
		{
			return i;
		}
	}
	return -1;
}
void doiPass(Acc p[], int n, char ten[], char pass[], HANDLE hConsoleColor)
{
	char mkCu[20], mkMoi[20];
	cin.ignore();
	cout << "\nNhap mat khau cu: ";
	cin.getline(mkCu, 20);
	if (_strcmpi(mkCu, p[chiSoI(p, n, ten, pass)].getPassWord()) == 0)
	{
		cout << "\nNhap mat khau moi: ";
		cin.getline(mkMoi, 20);
		p[chiSoI(p, n, ten, pass)].DoiPass(mkMoi);
		cout << "\nLoading...";
		Sleep(1500);
		SetConsoleTextAttribute(hConsoleColor, 10);
		cout << "\nGiao dich thanh cong !";
		SetConsoleTextAttribute(hConsoleColor, 7);
	}
	else
	{
		cout << "\nMat khau cu khong dung !";
		Sleep(1500);
	}
}
void chuyenTien(Acc p[], int n, char ten[], char pass[], HANDLE hConsoleColor)
{
	char IDtam[20];
	float tien;
	do
	{
		cout << "\nNhap so tien can chuyen: ";
		cin >> tien;
		cin.ignore();
		cout << "\nNhap ID nguoi nhan: ";
		cin.getline(IDtam, 20);
		cout << "\nLoading...";
		Sleep(1000);
		if (_strcmpi(IDtam, p[chiSoI(p, n, ten, pass)].getID()) == 0)
		{
			cout << "\nKhong the nhap ID cua ban than";
			break;
		}
		else
		{
			if (tien > 50000 && tien < p[chiSoI(p, n, ten, pass)].getSoDuTaiKhoan() - 50000)
			{
				p[chiSoI(p, n, ten, pass)].TruTien(tien);
				p[isID(p, n, IDtam)].CongTien(tien);
				cout << "\nLoading...";
				Sleep(1000);
				SetConsoleTextAttribute(hConsoleColor, 10);
				cout << "\nGiao dich thanh cong !";
				SetConsoleTextAttribute(hConsoleColor, 7);
				break; //dung vong lap
			}
			else
			{
				cout << "\nGiao dich that bai";
				break;
			}
		}
	} while (tien <= 50000 && tien >= p[chiSoI(p, n, ten, pass)].getSoDuTaiKhoan() - 50000);
}
//ham kiem tra ID nguoi nhan tien co trong hw thong khong va tra ve chi so i
int isID(Acc p[], int n, char x[])
{
	for (int i = 0; i < n; i++)
	{
		if (_strcmpi(x, p[i].getID()) == 0)
		{
			return i;
		}
	}
	return -1;
}
void rutTien(Acc p[], int n, char ten[], char pass[], HANDLE hConsoleColor)
{
	float tien;
	cout << "\nNhap so tien muon rut: ";
	cin >> tien;
	if ((tien >= 50000) && (tien <= p[chiSoI(p, n, ten, pass)].getSoDuTaiKhoan() - 50000))
	{
		p[chiSoI(p, n, ten, pass)].TruTien(tien);
		cout << "\nLoading...";
		Sleep(1500);
		SetConsoleTextAttribute(hConsoleColor, 10);
		cout << "\nGiao dich thanh cong !";
		SetConsoleTextAttribute(hConsoleColor, 7);
	}
	else
	{
		cout << "\nGiao dich that bai !";
		Sleep(1500);
	}
}
void Menu(Acc p[], int n, HANDLE hConsoleColor)
{
	char ten[20], pass[20];
	int chon;
	if (dangNhap(p, n, ten, pass, hConsoleColor) == 1)
		cout << "\nLoading...";
	do
	{
		
		Sleep(2000);
		system("cls");
		SetConsoleTextAttribute(hConsoleColor, 14);
		cout << "\n\t\t***********************************************";
		cout << "\n\t\t**   ";
		SetConsoleTextAttribute(hConsoleColor, 9);
		cout << "CHAO MUNG BAN DEN VOI ATM VINCOMBANK";
		SetConsoleTextAttribute(hConsoleColor, 14);
		cout << "    **";
		cout << "\n\t\t***********************************************";
		SetConsoleTextAttribute(hConsoleColor, 7);
		Sleep(1000);
		cout << "\n1. Rut tien";
		cout << "\n2. Chuyen tien";
		cout << "\n3. Doi mat khau";
		cout << "\n4. Kiem tra so du TK";
		cout << "\n0. Exit";
		cout << "\nBan chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1 :
		{
			rutTien(p, n, ten, pass, hConsoleColor);
			ghiFile(p, n);
			break;
		}
		case 2 :
		{
			chuyenTien(p, n, ten, pass, hConsoleColor);
			ghiFile(p, n);
			break;
		}
		case 3 :
		{
			doiPass(p, n, ten, pass, hConsoleColor);
			ghiFile(p, n);
			break;
		}
		case 4 :
		{
			cout << "\nID: " << p[chiSoI(p, n, ten, pass)].getID() << endl;
			cout << "\nSo du tai khoan: " << p[chiSoI(p, n, ten, pass)].getSoDuTaiKhoan() << endl;
			ghiFile(p, n);
			break;
		}
		case 0 :
			SetConsoleTextAttribute(hConsoleColor, 14);
			cout << "\nCam on quy khach da su dung dich vu !";
			SetConsoleTextAttribute(hConsoleColor, 7);
			Sleep(2000);
			exit(1);
		
		}
	} while (chon);

}
