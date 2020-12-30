#include <iostream>
#include <time.h>

using namespace std;

class Die {  // 6면을 갖는 주사위 객체를 나타내는 클래스

private: // 상태
	int faceValue; // 주사위의 눈을 나타내는 변수

public: // 행동
	void roll() { // 주사위를 던지는 행동
		
		faceValue = rand() % 6 + 1;

	}

	int getFaceValue() { return faceValue; }   // 주사위의 눈 반환
};

class PairOfDice {
	
private:
	Die die1, die2; // 2개의 주사위 변수

public:
	PairOfDice() {
		die1 = Die(); // 주사위 객체
		die2 = Die();
	}

	void roll() {    // 2개의 주사위를 던짐
		die1.roll();
		die2.roll();
	}

	int get1stValue() { return die1.getFaceValue(); } // die1 눈(나온 숫자) 반환
	int get2ndValue() { return die2.getFaceValue(); } // die2 눈(나온 숫자) 반환 
	int getValue() { return die1.getFaceValue() + die2.getFaceValue(); } // die1,2 눈(나온 숫자)의 합을 반환
};


int main()
{
	/*
	srand(time(NULL));	// 랜덤 함수 사용에 필요한 함수
	
	PairOfDice PO = PairOfDice(); // PairOfDice 클래스 생성자 PO 생성

	int count = 0; // 주사위를 굴려 나온 눈의 합을 카운트 하기 위한 변수 생성

	for (int i = 0; i < 200; i++) {  // i < 200으로 조건을 주어 
		PO.roll();                   // 주사위를 100번이상 굴린다

		if (PO.get1stValue() + PO.get2ndValue() == 6) // 주사위를 여러번 굴려 두 주나위 눈의 합이 6이 된다면
			count += 1; // count +1
	}
	
	cout << endl;
	cout << "합이 6이 나온 횟수는 " << count << "번 입니다." << endl << endl;
	cout << "합이 6이 나올 확률은 " << ((double)count / 200.0)*100.0 << " 입니다." << endl;
	*/

	srand(time(NULL)); // 랜덤 함수 사용에 필요한 함수

	PairOfDice user1 = PairOfDice(); // PairOfDice 클래스 생성자 user1 생성
	PairOfDice user2 = PairOfDice(); // PairOfDice 클래스 생성자 user2 생성

	int flag = 1; // 순서 조건 >> 1이면 사용자1 > 2면 사용자2
	int count1 = 0; // 점수 계산을 위한 카운트 > 사용자1
	int count2 = 0; // 점수 계산을 위한 카운트 > 사용자2
	int score = 0; // 점수 총 합계를 나타냄
	char choice; // 게임 시작 선택 여부

	while (true) {
		if (flag == 1) {  // flag가 1 이므로 user1이 첫 스타트 >> flag = 1로 초기값을 줬기 때문에 게임 시작 시, 첫 스타트는 무조건 user1이 된다.
			score = count1; // 

			while (count1 <= score + 20) { // 경기자는 한 라운드에서 20점 이상을 모아야 상대방에게 차례를 넘길 수 있다
				cout << endl << "▷▶▷▶▷▶▷▶▷▶▷▶▷▶▷▶▷▶▷▶▷▶▷ [user1 님의 차례입니다.] ◁◀◁◀◁◀◁◀◁◀◁◀◁◀◁◀◁◀◁◀◁" << endl;
				cout << endl << "▶                                             주사위를 굴리시겠습니까?                                         ◀" << endl;
				cout << endl << "                                                Y(네) / N(아니오) : "; cin >> choice; 

				if (choice == 'Y') { // y를 입력해 게임이 시작되면
					user1.roll(); // 주사위는 굴러가고
					count1 += user1.get1stValue() + user1.get2ndValue(); // 굴러간 두 개의 주사위의 눈의 합계를 구해 user1의 count1에 넣어 준다.
					cout << endl << "▷                                             [user1 님의 점수 : " << count1 << "점]                                         ◁" << endl;
					cout << endl << "                                                       ㅡ                                                         " << endl;

					if (user1.get1stValue() == 1 || user1.get2ndValue() == 1) { // 두 주사위 중에서 하나의 주사위라도 1이 나온다면 점수 리셋 및 턴 종료.
						cout << endl << "▷        하나의 주사위에서 1이 나왔습니다. 해당 라운드에서 얻은 모든 점수는 잃게 되며, 턴이 종료됩니다.        ◁" << endl << endl;
						count1 -= user1.get1stValue() + user1.get2ndValue();												

						break;
					}
					else if (user1.get1stValue() == 1 && user1.get2ndValue() == 1) { // 두 주사위가 1이 나온다면 점수 리셋 및 턴 종료.
						cout << endl << "▶          두 주사위 모두 1이 나왔습니다. 그동안 쌓은 모든 점수는 잃게 되며, 턴이 종료됩니다.           ◀" << endl << endl;
						count1 = 0;

						break;
					}
				}
				else {
					cout << endl << "                                                        ㅡ                                                         " << endl;
					cout << endl << "▶                                         다음 경기자에게 순서가 넘어갑니다.                                   ◀" << endl;
					cout << endl << "                                                        ㅡ                                                         " << endl;
					break;
				}
				choice = 'N'; // N를 입력받으면 user2 한테 턴이 넘어감
			}
			flag = 2; // user2로 턴 교체
		}

		// 아래 설명은 위와 같다
		if (flag == 2) {
			score = count2;
			while (count2 <= score + 20) {
				cout << endl << "▷▶▷▶▷▶▷▶▷▶▷▶▷▶▷▶▷▶▷▶▷▶▷ [user2 님의 차례입니다.] ◁◀◁◀◁◀◁◀◁◀◁◀◁◀◁◀◁◀◁◀◁" << endl;
				cout << endl << "▶                                             주사위를 굴리시겠습니까?                                         ◀" << endl;
				cout << endl << "                                                Y(네) / N(아니오) : "; cin >> choice;

				if (choice == 'Y') {
					user2.roll();
					count2 += user2.get1stValue() + user2.get2ndValue();
					cout << endl << "▷                                             [user2 님의 점수 : " << count2 << "점]                                         ◁" << endl;
					cout << endl << "                                                        ㅡ                                                         " << endl;

					if (user2.get1stValue() == 1 || user2.get2ndValue() == 1) {
						cout << endl << "▷        하나의 주사위에서 1이 나왔습니다. 해당 라운드에서 얻은 모든 점수는 잃게 되며, 턴이 종료됩니다.        ◁" << endl << endl;
						count2 -= user2.get1stValue() + user2.get2ndValue();

						break;
					}
					else if (user2.get1stValue() == 1 && user2.get2ndValue() == 1) {
						cout << endl << "▶          두 주사위 모두 1이 나왔습니다. 그동안 쌓은 모든 점수는 잃게 되며, 턴이 종료됩니다.           ◀" << endl << endl;
						count2 = 0;

						break;
					}
				}
				else {
					cout << endl << "                                                        ㅡ                                                         " << endl;
					cout << endl << "▶                                         다음 경기자에게 순서가 넘어갑니다.                                   ◀" << endl;
					cout << endl << "                                                        ㅡ                                                         " << endl;
					break;
				}
				choice = 'N';
			}
			flag = 1;
		}
	}
}