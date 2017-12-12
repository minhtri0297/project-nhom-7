#ifndef TAIKHOAN
#define TAIKHOAN


class Acc
{
private:
	char UserName[20];
	char ID[20];
	char PassWord[20];
	float SoDuTaiKhoan;

public:
	void setUserName(char x[]);
	void setPassWord(char x[]);
	void setID(char x[]);
	void setSoDuTaiKhoan(float d);
	void Xuat();
	char* getID(); // Xuat ID ra de so sanh
	char* getUserName();
	char* getPassWord();
	double getSoDuTaiKhoan(); //xuat so du tai khoan de so sanh so tien du dk gd hay khong?

	// cac chuc nang ATM
	void CongTien(float Tien);
	void TruTien(float Tien);
	void DoiPass(char x[]);
};
#endif // !TAIKHOAN
