#include <iostream>
#include <time.h>

using namespace std;

class Die {  // 6���� ���� �ֻ��� ��ü�� ��Ÿ���� Ŭ����

private: // ����
	int faceValue; // �ֻ����� ���� ��Ÿ���� ����

public: // �ൿ
	void roll() { // �ֻ����� ������ �ൿ
		
		faceValue = rand() % 6 + 1;

	}

	int getFaceValue() { return faceValue; }   // �ֻ����� �� ��ȯ
};

class PairOfDice {
	
private:
	Die die1, die2; // 2���� �ֻ��� ����

public:
	PairOfDice() {
		die1 = Die(); // �ֻ��� ��ü
		die2 = Die();
	}

	void roll() {    // 2���� �ֻ����� ����
		die1.roll();
		die2.roll();
	}

	int get1stValue() { return die1.getFaceValue(); } // die1 ��(���� ����) ��ȯ
	int get2ndValue() { return die2.getFaceValue(); } // die2 ��(���� ����) ��ȯ 
	int getValue() { return die1.getFaceValue() + die2.getFaceValue(); } // die1,2 ��(���� ����)�� ���� ��ȯ
};


int main()
{
	/*
	srand(time(NULL));	// ���� �Լ� ��뿡 �ʿ��� �Լ�
	
	PairOfDice PO = PairOfDice(); // PairOfDice Ŭ���� ������ PO ����

	int count = 0; // �ֻ����� ���� ���� ���� ���� ī��Ʈ �ϱ� ���� ���� ����

	for (int i = 0; i < 200; i++) {  // i < 200���� ������ �־� 
		PO.roll();                   // �ֻ����� 100���̻� ������

		if (PO.get1stValue() + PO.get2ndValue() == 6) // �ֻ����� ������ ���� �� �ֳ��� ���� ���� 6�� �ȴٸ�
			count += 1; // count +1
	}
	
	cout << endl;
	cout << "���� 6�� ���� Ƚ���� " << count << "�� �Դϴ�." << endl << endl;
	cout << "���� 6�� ���� Ȯ���� " << ((double)count / 200.0)*100.0 << " �Դϴ�." << endl;
	*/

	srand(time(NULL)); // ���� �Լ� ��뿡 �ʿ��� �Լ�

	PairOfDice user1 = PairOfDice(); // PairOfDice Ŭ���� ������ user1 ����
	PairOfDice user2 = PairOfDice(); // PairOfDice Ŭ���� ������ user2 ����

	int flag = 1; // ���� ���� >> 1�̸� �����1 > 2�� �����2
	int count1 = 0; // ���� ����� ���� ī��Ʈ > �����1
	int count2 = 0; // ���� ����� ���� ī��Ʈ > �����2
	int score = 0; // ���� �� �հ踦 ��Ÿ��
	char choice; // ���� ���� ���� ����

	while (true) {
		if (flag == 1) {  // flag�� 1 �̹Ƿ� user1�� ù ��ŸƮ >> flag = 1�� �ʱⰪ�� ��� ������ ���� ���� ��, ù ��ŸƮ�� ������ user1�� �ȴ�.
			score = count1; // 

			while (count1 <= score + 20) { // ����ڴ� �� ���忡�� 20�� �̻��� ��ƾ� ���濡�� ���ʸ� �ѱ� �� �ִ�
				cout << endl << "���������������������������������������������� [user1 ���� �����Դϴ�.] ������������������������������������������" << endl;
				cout << endl << "��                                             �ֻ����� �����ðڽ��ϱ�?                                         ��" << endl;
				cout << endl << "                                                Y(��) / N(�ƴϿ�) : "; cin >> choice; 

				if (choice == 'Y') { // y�� �Է��� ������ ���۵Ǹ�
					user1.roll(); // �ֻ����� ��������
					count1 += user1.get1stValue() + user1.get2ndValue(); // ������ �� ���� �ֻ����� ���� �հ踦 ���� user1�� count1�� �־� �ش�.
					cout << endl << "��                                             [user1 ���� ���� : " << count1 << "��]                                         ��" << endl;
					cout << endl << "                                                       ��                                                         " << endl;

					if (user1.get1stValue() == 1 || user1.get2ndValue() == 1) { // �� �ֻ��� �߿��� �ϳ��� �ֻ����� 1�� ���´ٸ� ���� ���� �� �� ����.
						cout << endl << "��        �ϳ��� �ֻ������� 1�� ���Խ��ϴ�. �ش� ���忡�� ���� ��� ������ �Ұ� �Ǹ�, ���� ����˴ϴ�.        ��" << endl << endl;
						count1 -= user1.get1stValue() + user1.get2ndValue();												

						break;
					}
					else if (user1.get1stValue() == 1 && user1.get2ndValue() == 1) { // �� �ֻ����� 1�� ���´ٸ� ���� ���� �� �� ����.
						cout << endl << "��          �� �ֻ��� ��� 1�� ���Խ��ϴ�. �׵��� ���� ��� ������ �Ұ� �Ǹ�, ���� ����˴ϴ�.           ��" << endl << endl;
						count1 = 0;

						break;
					}
				}
				else {
					cout << endl << "                                                        ��                                                         " << endl;
					cout << endl << "��                                         ���� ����ڿ��� ������ �Ѿ�ϴ�.                                   ��" << endl;
					cout << endl << "                                                        ��                                                         " << endl;
					break;
				}
				choice = 'N'; // N�� �Է¹����� user2 ���� ���� �Ѿ
			}
			flag = 2; // user2�� �� ��ü
		}

		// �Ʒ� ������ ���� ����
		if (flag == 2) {
			score = count2;
			while (count2 <= score + 20) {
				cout << endl << "���������������������������������������������� [user2 ���� �����Դϴ�.] ������������������������������������������" << endl;
				cout << endl << "��                                             �ֻ����� �����ðڽ��ϱ�?                                         ��" << endl;
				cout << endl << "                                                Y(��) / N(�ƴϿ�) : "; cin >> choice;

				if (choice == 'Y') {
					user2.roll();
					count2 += user2.get1stValue() + user2.get2ndValue();
					cout << endl << "��                                             [user2 ���� ���� : " << count2 << "��]                                         ��" << endl;
					cout << endl << "                                                        ��                                                         " << endl;

					if (user2.get1stValue() == 1 || user2.get2ndValue() == 1) {
						cout << endl << "��        �ϳ��� �ֻ������� 1�� ���Խ��ϴ�. �ش� ���忡�� ���� ��� ������ �Ұ� �Ǹ�, ���� ����˴ϴ�.        ��" << endl << endl;
						count2 -= user2.get1stValue() + user2.get2ndValue();

						break;
					}
					else if (user2.get1stValue() == 1 && user2.get2ndValue() == 1) {
						cout << endl << "��          �� �ֻ��� ��� 1�� ���Խ��ϴ�. �׵��� ���� ��� ������ �Ұ� �Ǹ�, ���� ����˴ϴ�.           ��" << endl << endl;
						count2 = 0;

						break;
					}
				}
				else {
					cout << endl << "                                                        ��                                                         " << endl;
					cout << endl << "��                                         ���� ����ڿ��� ������ �Ѿ�ϴ�.                                   ��" << endl;
					cout << endl << "                                                        ��                                                         " << endl;
					break;
				}
				choice = 'N';
			}
			flag = 1;
		}
	}
}