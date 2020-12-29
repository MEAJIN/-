#include <iostream>

using namespace std;

class character { // Ŭ���� ����

	private:           // ���¸� ��Ÿ���� private
		string name;   // ĳ���� �̸��� ��Ÿ���� ���� name
		int x, y, HP;  // ĳ������ ��ġ�� ��Ÿ���� ���� x,y �� Ȱ���� ��Ÿ���� HP

	public:  // �ൿ�� ��Ÿ���� public

		// �� ������ ���� �̸��� �ʼ��� ������ �־�����, ��ǥ�� Ȱ���� ������ �� �ֵ��� �� 4������ �����ڸ� �������.
		// ����, ���õ��� ���� �������� �ʱⰪ 0�� ��

		character(string M) {  // ������ 1 => �̸�
			name = M;

			x = y = HP = 0;
		}

		character(string M, int X, int Y, int hp) { // ������ 2 => �̸�, ��ġ, Ȱ��
			name = M;
			x = X;
			y = Y;
			HP = hp;
		}

		character(string M, int X, int Y) { // ������ 3 => �̸�, ��ġ
			name = M;
			x = X;
			y = Y;

			HP = 0;
		}

		character(string M, int hp) { // ������ 4 => �̸�, Ȱ��
			name = M;
			HP = hp;

			x = y = 0;
		}

	
		// get=������, set=������ => �̸� ���� ĳ������ ���¸� �����ϰų� ���� ����
		string getname() { return name; }
		void setname(string M2) { name = M2; }

		int getx() { return x; }
		void setx(int X2) { x = X2; }

		int gety() { return y; }
		void sety(int Y2) { y = Y2; }

		int getHP() { return HP; }
		void setHP(int hp2) { HP = hp2; }
	 
		void print() {  // ĳ���͵��� ���¸� ȣ�����ִ� ��� �Լ�
			cout << "Name : " << name << "," << " Coordinate : (" << x << "," << y << ")," << " HP : " << HP << endl; 
		}
};

int main() {
	
	cout << endl;
	cout << "==================================================== ch 1 ====================================================" << endl;

	character ch1("Gildong Hong", 100, 200); // ĳ���� 1
	ch1.print(); // ĳ���� 1 ���� ��� �Լ� ȣ��

	cout << endl;

	// ĳ���� 1�� ��ġ ���� �� Ȱ�¿� �ൿ�� �� ���ν� ���º�ȭ�� ��
	cout << "Gildong Hong�� ����⸦ Ÿ�� x �������� 400, y �������� 400 ��ŭ �̵��ϸ鼭 ���ڸ� �Ծ� HP�� 100 ȸ���Ͽ���!" << endl << endl;
	// �����ڿ� �Ű����� ����
	ch1.setx(500);
	ch1.sety(600);
	ch1.setHP(100);
	ch1.print();

	cout << "==============================================================================================================" << endl << endl;

	cout << "==================================================== ch 2 ====================================================" << endl;

	character ch2("Gildong Hong", 300);  // ĳ���� 2
	ch2.print(); // ĳ���� 2 ���� ��� �Լ� ȣ��

	cout << endl;

	// ĳ���� 2�� ��ġ ���� �� Ȱ�¿� �ൿ�� �� ���ν� ���º�ȭ�� ��
	cout << "Gildong Hong�� �ڵ����� Ÿ�� x �������� 100, y �������� -100 ��ŭ �̵��ϸ鼭 ������� �Ծ� HP�� 200 �����Ͽ���!" << endl << endl;
	// �����ڿ� �Ű����� ����
	ch2.setx(200);
	ch2.sety(100);
	ch2.setHP(100);
	ch2.print(); 

	cout << "==============================================================================================================" << endl;
	return 0;
}

