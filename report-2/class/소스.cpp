#include <iostream>

using namespace std;

class character { // 클래스 생성

	private:           // 상태를 나타내는 private
		string name;   // 캐릭터 이름을 나타내는 변수 name
		int x, y, HP;  // 캐릭터의 위치를 나타내는 변수 x,y 와 활력을 나타내는 HP

	public:  // 행동을 나타내는 public

		// 각 생성자 마다 이름은 필수로 제공해 주었으며, 좌표나 활력은 선택할 수 있도록 총 4가지의 생성자를 만들었음.
		// 또한, 선택되지 않은 변수들은 초기값 0을 줌

		character(string M) {  // 생성자 1 => 이름
			name = M;

			x = y = HP = 0;
		}

		character(string M, int X, int Y, int hp) { // 생성자 2 => 이름, 위치, 활력
			name = M;
			x = X;
			y = Y;
			HP = hp;
		}

		character(string M, int X, int Y) { // 생성자 3 => 이름, 위치
			name = M;
			x = X;
			y = Y;

			HP = 0;
		}

		character(string M, int hp) { // 생성자 4 => 이름, 활력
			name = M;
			HP = hp;

			x = y = 0;
		}

	
		// get=접근자, set=설정자 => 이를 통해 캐릭터의 상태를 참조하거나 수정 가능
		string getname() { return name; }
		void setname(string M2) { name = M2; }

		int getx() { return x; }
		void setx(int X2) { x = X2; }

		int gety() { return y; }
		void sety(int Y2) { y = Y2; }

		int getHP() { return HP; }
		void setHP(int hp2) { HP = hp2; }
	 
		void print() {  // 캐릭터들의 상태를 호출해주는 출력 함수
			cout << "Name : " << name << "," << " Coordinate : (" << x << "," << y << ")," << " HP : " << HP << endl; 
		}
};

int main() {
	
	cout << endl;
	cout << "==================================================== ch 1 ====================================================" << endl;

	character ch1("Gildong Hong", 100, 200); // 캐릭터 1
	ch1.print(); // 캐릭터 1 상태 출력 함수 호출

	cout << endl;

	// 캐릭터 1의 위치 변경 및 활력에 행동을 줌 으로써 상태변화를 줌
	cout << "Gildong Hong은 비행기를 타고 x 방향으로 400, y 방향으로 400 만큼 이동하면서 피자를 먹어 HP를 100 회복하였다!" << endl << endl;
	// 설정자에 매개변수 전달
	ch1.setx(500);
	ch1.sety(600);
	ch1.setHP(100);
	ch1.print();

	cout << "==============================================================================================================" << endl << endl;

	cout << "==================================================== ch 2 ====================================================" << endl;

	character ch2("Gildong Hong", 300);  // 캐릭터 2
	ch2.print(); // 캐릭터 2 상태 출력 함수 호출

	cout << endl;

	// 캐릭터 2의 위치 변경 및 활력에 행동을 줌 으로써 상태변화를 줌
	cout << "Gildong Hong은 자동차를 타고 x 방향으로 100, y 방향으로 -100 만큼 이동하면서 독사과를 먹어 HP가 200 감소하였다!" << endl << endl;
	// 설정자에 매개변수 전달
	ch2.setx(200);
	ch2.sety(100);
	ch2.setHP(100);
	ch2.print(); 

	cout << "==============================================================================================================" << endl;
	return 0;
}

